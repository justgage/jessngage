package;

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxSprite;
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

	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		super.create();

		// trace("bgColor", this.bgColor);

		//tileMap = new FlxTilemap();
		//tileMap.loadMap(Assets.getText("assets/data/level1.csv"), "assets/images/ground-tiles.png", TILE_WIDTH, TILE_HEIGHT, 0, 0);
		//add(tileMap);

		var level =  new TiledLevel("assets/data/level1.tmx");
		add(level.foregroundTiles);

		level.loadObjects(this);

		add(level.backgroundTiles);

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
		//FlxG.collide(jess, tileMap);
		FlxG.collide(jess, ground);

		super.update();
	}	
}
