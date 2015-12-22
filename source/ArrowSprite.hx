package; 

import flixel.FlxG;
import flixel.FlxSprite;

class ArrowSprite extends FlxSprite {

	private static var maxvx = 500;

	override public function new(x, y, right) {
		super();
		loadGraphic("assets/images/jess-arrow.png", true, 12, 2);
		animation.add("fly", [0]);
		animation.play("fly");
		this.x = Math.round(x);
		this.y = Math.round(y);

		if (right) {
			this.velocity.x = maxvx;
			this.flipX = true;
		} else {
			this.velocity.x = -maxvx;
		}
	}
}
