package;

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxObject;
import flixel.FlxState;
import flixel.group.FlxGroup;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
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

	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{

		bgColor = 0x5b726d;

		super.create();

		this.level =  new TiledLevel("assets/data/level1.tmx");

		this.mail = new FlxGroup();
		this.shroom = new FlxGroup();

		add(level.backgroundTiles);

		level.loadObjects(this);

		add(level.foregroundTiles);

		add(mail);
		add(shroom);
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

		super.update();
	}	
	public function getMail(m:FlxObject, Player:PlayerSprite):Void
	{
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
