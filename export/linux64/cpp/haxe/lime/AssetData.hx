package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("assets/sounds/sounds-go-here.txt", "assets/sounds/sounds-go-here.txt");
			type.set ("assets/sounds/sounds-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/images/backgroud.xcf", "assets/images/backgroud.xcf");
			type.set ("assets/images/backgroud.xcf", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("assets/images/jess-run.png", "assets/images/jess-run.png");
			type.set ("assets/images/jess-run.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/gage-stand.png", "assets/images/gage-stand.png");
			type.set ("assets/images/gage-stand.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/ground-tiles.png", "assets/images/ground-tiles.png");
			type.set ("assets/images/ground-tiles.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/ground.png", "assets/images/ground.png");
			type.set ("assets/images/ground.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/jess-bow.png", "assets/images/jess-bow.png");
			type.set ("assets/images/jess-bow.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/larf.png", "assets/images/larf.png");
			type.set ("assets/images/larf.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/jess-jump.png", "assets/images/jess-jump.png");
			type.set ("assets/images/jess-jump.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/jess-stand.png", "assets/images/jess-stand.png");
			type.set ("assets/images/jess-stand.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/middle-ground.png", "assets/images/middle-ground.png");
			type.set ("assets/images/middle-ground.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/images-go-here.txt", "assets/images/images-go-here.txt");
			type.set ("assets/images/images-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/images/jess-tiles.png", "assets/images/jess-tiles.png");
			type.set ("assets/images/jess-tiles.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/jess.png", "assets/images/jess.png");
			type.set ("assets/images/jess.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/jess-tiles.xcf", "assets/images/jess-tiles.xcf");
			type.set ("assets/images/jess-tiles.xcf", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("assets/images/jess-arrow.png", "assets/images/jess-arrow.png");
			type.set ("assets/images/jess-arrow.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/gage-jump.png", "assets/images/gage-jump.png");
			type.set ("assets/images/gage-jump.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/data/level1.tmx", "assets/data/level1.tmx");
			type.set ("assets/data/level1.tmx", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/data/data-goes-here.txt", "assets/data/data-goes-here.txt");
			type.set ("assets/data/data-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/data/level1.csv", "assets/data/level1.csv");
			type.set ("assets/data/level1.csv", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/data/basic-level.tmx", "assets/data/basic-level.tmx");
			type.set ("assets/data/basic-level.tmx", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/data/basic-level.", "assets/data/basic-level.");
			type.set ("assets/data/basic-level.", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/music/music-goes-here.txt", "assets/music/music-goes-here.txt");
			type.set ("assets/music/music-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/sounds/beep.ogg", "assets/sounds/beep.ogg");
			type.set ("assets/sounds/beep.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/flixel.ogg", "assets/sounds/flixel.ogg");
			type.set ("assets/sounds/flixel.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/fonts/nokiafc22.ttf", "assets/fonts/nokiafc22.ttf");
			type.set ("assets/fonts/nokiafc22.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/arial.ttf", "assets/fonts/arial.ttf");
			type.set ("assets/fonts/arial.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData
