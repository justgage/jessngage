package; 

import flixel.FlxG;

class JessSprite extends PlayerSprite {

	private var maxvx = 10;
	private var maxvy = 10;

	override public function new(x:Int, y:Int) {
		super();

		loadGraphic("assets/images/jess.png", true, 24, 24);
		animation.add("stand", [0]);
		animation.play("stand");

		this.x = x;
		this.y = y;

		maxVelocity.set(80, 200);
	}

	override public function update() {
		if (FlxG.keys.pressed.LEFT) {
			this.velocity.x -= maxvx;
		}

		if (FlxG.keys.pressed.RIGHT) {
			this.velocity.x += maxvx;
		}

		if (FlxG.keys.pressed.UP) {
			this.velocity.y -= maxvx;
		}

		super.update();
	}

}
