package; 

import flixel.FlxG;
import flixel.FlxSprite;

class PlayerSprite extends FlxSprite  {
	
	private var bLeft:String;
	private var bRight:String;
	private var bJump:String;
	private var bItem:String;

	override public function new() {
		super();
		acceleration.y = 400;
	}

	override public function update(/*level:FlxTilemap*/):Void
	{
		//FlxG.collide(level, this);
		super.update();
	}

}
