package;

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxObject;
import flixel.FlxBasic;
import flixel.FlxState;
import flixel.group.FlxGroup;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.util.FlxColor;
import flixel.system.scaleModes.PixelPerfectScaleMode;
import openfl.Assets;

// my stuff 
import JessSprite;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	private var tileMap:FlxTilemap;
	static var TILE_WIDTH:Int = 24;
	static var TILE_HEIGHT:Int = 24;
	

	public var jess:JessSprite;
	public var ground:FlxGroup;
	public var level:TiledLevel;
	public var mail:FlxGroup;
	public var shroom:FlxGroup;
	public var arrows:FlxGroup;
	public var mailCount:Int;
	public var mailCountText:FlxText;

	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{

		//FlxG.camera.bgColor = 0x333333;
		FlxG.debugger.drawDebug = true;
		FlxG.scaleMode = new PixelPerfectScaleMode();

		super.create();

		this.level = new TiledLevel("assets/data/level1.tmx");
		this.mail = new FlxGroup();
		this.shroom = new FlxGroup();
		this.arrows = new FlxGroup();
		this.mailCountText = new FlxText(2, 2, -1, "Mail Count: 0");
		this.mailCountText.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);

		add(level.backgroundTiles);

		level.loadObjects(this);

		add(level.foregroundTiles);

		add(mail);
		add(shroom);
		add(arrows);
		add(mailCountText);
	}
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		// FlxG.collide(jess, level.foregroundTiles);
		level.collideWithLevel(jess);
		FlxG.overlap(mail, jess, getMail);
		FlxG.overlap(shroom, jess, hitShroom);
		// FlxG.overlap(level.foregroundTiles, arrows, arrowBlock);
		level.collideWithLevel(arrows, arrowBlock);

		if (jess.requestShoot == true) {
			var arrow = new ArrowSprite(jess.x, jess.y, jess.flipX == true);
			arrows.add(arrow);
			jess.requestShoot = false;
		}

		super.update();
	}	


	public function arrowBlock(block:FlxObject, arrow:FlxObject):Void
	{
		arrow.velocity.x *= 0.9;
		arrow.velocity.y = 0;
	}

	public function getMail(m:FlxObject, Player:PlayerSprite):Void
	{
		mailCount++;
		mailCountText.text = "Mail Count: " + mailCount;
		m.kill();
	}

	public function hitShroom(sh:FlxObject, pl:PlayerSprite):Void
	{
		if (pl.y < sh.y && pl.velocity.y != 0) {
			pl.velocity.y = pl.velocity.y * -1.2;
			pl.y = sh.y - 24;
		} else {
			if (pl.x < sh.x) {
				pl.x = sh.x - pl.width;
			} else {
				pl.x = sh.x + 24;
			}
		}
	}

}
