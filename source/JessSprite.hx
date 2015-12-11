package; 

import flixel.FlxG;

class JessSprite extends PlayerSprite {

	private var maxvx = 10;
	private var maxvy = 100;

	override public function new(x:Int, y:Int) {
		super();

		loadGraphic("assets/images/jess-tiles.png", true, 24, 24);
		animation.add("stand", [0]);
		animation.add("bow", [1]);
		animation.add("run", [2, 3,4, 5, 6]);
		animation.play("stand");

		this.x = x;
		this.y = y;
		this.width = 10;
		this.height = 24;
		this.offset.set(7,0);

		maxVelocity.set(80, 200);
	}

	override public function update() {
		if (FlxG.keys.pressed.LEFT) {
			this.velocity.x -= maxvx;
			animation.play("run");
			this.flipX = false;

		} else if (FlxG.keys.pressed.RIGHT) {
			this.velocity.x += maxvx;
			this.flipX = true;
			animation.play("run");
		} else {
			animation.play("stand");
			this.velocity.x = this.velocity.x * 0.9; 
		}

		if (FlxG.keys.pressed.UP) {
			this.velocity.y -= maxvx;
		}

		super.update();
	}

}
