package; 

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxRandom;

class ArrowSprite extends FlxSprite {

	private static var maxvx = 500;

	override public function new(x, y, right) {
		super();
		centerOffsets();
		centerOrigin();
		loadGraphic("assets/images/jess-arrow.png", true, 12, 2);
		animation.add("fly", [0]);
		animation.play("fly");
		this.x = Math.round(x);
		this.y = Math.round(y);
		this.acceleration.y = 100;
		//this.heath = 60 * 100;

		this.velocity.y = FlxRandom.float() * -10 - 10;

		if (right) {
			this.velocity.x = maxvx;
			this.flipX = true;
		} else {
			this.velocity.x = -maxvx;
		}
	}

	override public function update() {
		super.update();
		hurt(0.01);
	}
}
