package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;

/**
 * A FlxState which can be used for the game's menu.
 */
class WinState extends FlxState
{
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		super.create();

		add(new FlxText(20, 20, 100, "They finally collected all their mail...  \n and lived happily ever after!"));
		var init_x:Int = Math.floor(FlxG.width / 2 - 40);
		var init_y:Int = Math.floor(FlxG.height / 2 - 40);

		var start_btn = new FlxButton(init_x, init_y, "Again?", start);

		add(start_btn);

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
		super.update();
	}	
	
	private function start():Void {
		FlxG.switchState(new PlayState());
  }

}
