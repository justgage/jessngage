package;

import openfl.Assets;
import haxe.io.Path;
import haxe.xml.Parser;
import flixel.FlxG;
import flixel.FlxBasic;
import flixel.FlxCamera;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.tile.FlxTilemap;
import flixel.addons.editors.tiled.TiledMap;
import flixel.addons.editors.tiled.TiledObject;
import flixel.addons.editors.tiled.TiledObjectGroup;
import flixel.addons.editors.tiled.TiledTileSet;

/**
 * @author Samuel Batista 2015
 * Edited by Gage Peterson for his own pourposes
 */
class TiledLevel extends TiledMap
{
	// For each "Tile Layer" in the map, you must define a "tileset" property which contains the name of a tile sheet image 
	// used to draw tiles in that layer (without file extension). The image file must be located in the directory specified bellow.
	private inline static var c_PATH_LEVEL_TILESHEETS = "assets/images/";
	
	// Array of tilemaps used for collision
	public var foregroundTiles:FlxGroup;
	public var backgroundTiles:FlxGroup;
	private var collidableTileLayers:Array<FlxTilemap>;
	
	public function new(tiledLevel:Dynamic)
	{
		super(tiledLevel);
		
		foregroundTiles = new FlxGroup();
		backgroundTiles = new FlxGroup();
		
		FlxG.camera.setBounds(0, 0, fullWidth, fullHeight, true);
		
		// Load Tile Maps
		for (tileLayer in layers)
		{
			var tileSheetName:String = tileLayer.properties.get("tileset");
			
			if (tileSheetName == null)
				throw "'tileset' property not defined for the '" + tileLayer.name + "' layer. Please add the property to the layer.";
				
			var tileSet:TiledTileSet = null;

			for (ts in tilesets)
			{
				if (ts.name == tileSheetName)
				{
					tileSet = ts;
					break;
				}
			}
			
			if (tileSet == null)
				throw "Tileset '" + tileSheetName + "' not found. Did you mispell the 'tilesheet' property in " + tileLayer.name + "' layer?";
				
			var imagePath = new Path(tileSet.imageSource);
			var processedPath = c_PATH_LEVEL_TILESHEETS + imagePath.file + "." + imagePath.ext;
			
			var tilemap:FlxTilemap = new FlxTilemap();
			tilemap.widthInTiles = width;
			tilemap.heightInTiles = height;
			tilemap.loadMap(tileLayer.tileArray, processedPath, tileSet.tileWidth, tileSet.tileHeight, 0, 1, 1, 1);
			
			if (tileLayer.properties.contains("nocollide"))
			{
				trace("added nocollide tilemap!");
				backgroundTiles.add(tilemap);
			}
			else
			{
				trace("added collideable tilemap!");

				if (collidableTileLayers == null)
					collidableTileLayers = new Array<FlxTilemap>();
				
				foregroundTiles.add(tilemap);
				collidableTileLayers.push(tilemap);
			}
		}
	}
	
	public function loadObjects(state:PlayState)
	{
		for (group in objectGroups)
		{
			for (o in group.objects)
			{
				loadObject(o, group, state);
			}
		}
	}
	
	private function loadObject(o:TiledObject, g:TiledObjectGroup, state:PlayState)
	{
		var x:Int = o.x;
		var y:Int = o.y;
		
		// objects in tiled are aligned bottom-left (top-left in flixel)
		if (o.gid != -1)
			y -= g.map.getGidOwner(o.gid).tileHeight;

		trace("loading object: ", o.type.toLowerCase());

		switch (o.type.toLowerCase())
		{
			case "player1_start":
				state.jess = new JessSprite(x, y, state.ground);
				state.add(state.jess);
				FlxG.camera.follow(state.jess, FlxCamera.STYLE_SCREEN_BY_SCREEN, 1);
				
			// case "floor":
				// var floor = new FlxObject(x, y, o.width, o.height);
				// state.floor = floor;
				
			case "shroom":
				var shroom = new FlxSprite(x, y);

				shroom.loadGraphic("assets/images/shroom.png", true, 24, 24);
				shroom.animation.add("bounce", [0], 10);
				shroom.animation.play("bounce");
				shroom.moves = false;
				
				state.shroom.add(shroom);

			case "blue_door":
				var blueDoor = new FlxSprite(x, y);
				blueDoor.loadGraphic("assets/images/blue-door.png", true, 5, 23);
				blueDoor.animation.add("closed", [0], 0);
				blueDoor.animation.play("closed");
				blueDoor.moves = false;

				state.blueDoors.add(blueDoor);

			case "blue_key":
				var key = new FlxSprite(x, y);

				key.loadGraphic("assets/images/blue-key.png", true, 7, 3);
				key.animation.add("key", [0,1], 0);
				key.animation.play("key");
				
				state.blueKeys.add(key);

			case "mail":
				var mail = new FlxSprite(x, y);

				mail.loadGraphic("assets/images/mail.png", true, 24, 24);
				mail.animation.add("shine", [0,1], 10);
				mail.animation.play("shine");
				
				state.mail.add(mail);
				
			case "exit":
				// Create the level exit
				var exit = new FlxSprite(x, y);
				exit.makeGraphic(32, 32, 0xff3f3f3f);
				exit.exists = false;
				// state.exit = exit;
				// state.add(exit);
			default:
				// var floor = new FlxObject(x, y, o.width, o.height);
				// state.ground.add(floor);
		}
	}
	
	public function overlapWithLevel(obj:FlxBasic,
			?notifyCallback:FlxObject->FlxObject->Void,
			?processCallback:FlxBasic->FlxBasic->Bool):Bool
	{
		if (collidableTileLayers != null) 
		{
			for (map in collidableTileLayers) {
				return FlxG.overlap(map, obj, notifyCallback);
			}
		}
		return false;
	}

	public function collideWithLevel(obj:FlxBasic,
			?notifyCallback:FlxObject->FlxObject->Void,
			?processCallback:FlxBasic->FlxBasic->Bool):Bool
	{
		if (collidableTileLayers != null)
		{
			for (map in collidableTileLayers)
			{
				// IMPORTANT: Always collide the map with objects, not the other way around. 
				//			  This prevents odd collision errors (collision separation code off by 1 px).
				return FlxG.overlap(map, obj, notifyCallback, 
						processCallback != null ? processCallback : FlxObject.separate);
			}
		}
		return false;
	}
}
