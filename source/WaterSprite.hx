package; 

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxPoint;
import flixel.util.FlxRandom;

class WaterSprite extends FlxSprite {

	private static var maxvx = 300;

	override public function new(x, y, right) {
		super();
		centerOffsets();
		centerOrigin();
		loadGraphic("assets/images/water.png", true, 7, 7);
		animation.add("fly", [0]);
		animation.play("fly");
		this.x = Math.round(x);
		this.y = Math.round(y);
		this.acceleration.y = 700;
		this.elasticity = 0.20;
		this.drag = new FlxPoint(300,0);

		this.velocity.y = FlxRandom.float() * -10 - 40;

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
