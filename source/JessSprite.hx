package; 

import flixel.FlxG;

class JessSprite extends PlayerSprite {

	private var ax = 20;
	private var ay = 100;

	private var vxmax = 100;
	private var vymax = 700;

	override public function new(x:Int, y:Int) {
		super();

		loadGraphic("assets/images/jess-tiles.png", true, 24, 24);
		animation.add("stand", [0]);
		animation.add("bow", [1]);
		animation.add("jump", [2]);
		animation.add("run", [3, 4, 5, 6]);
		animation.play("stand");

		this.x = x;
		this.y = y;
		this.width = 10;
		this.height = 24;
		this.offset.set(7,0);

		maxVelocity.set(vxmax, vymax);
	}

	override public function update() {
		if (FlxG.keys.pressed.LEFT) {
			this.velocity.x -= ax;
			animation.play("run");
			this.flipX = false;

		} else if (FlxG.keys.pressed.RIGHT) {
			this.velocity.x += ax;
			this.flipX = true;
			animation.play("run");
		} else {
			animation.play("stand");
			this.velocity.x = this.velocity.x * 0.9; 
		}

		if (FlxG.keys.pressed.UP) {
			this.velocity.y -= ay;
		}

		super.update();
	}

}
