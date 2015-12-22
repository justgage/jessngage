package; 

import flixel.FlxG;
import flixel.tile.FlxTilemap;
import flixel.FlxObject;
import flixel.group.FlxGroup;

class JessSprite extends PlayerSprite {

	public var ax = 20;
	public var ay = 500;
	public var requestShoot = false;

	private var vxmax = 150;
	private var vymax = 800;

	private var floor : FlxGroup;

	override public function new(x:Int, y:Int, ground) {
		super();

		this.floor = ground;

		loadGraphic("assets/images/jess-tiles.png", true, 24, 24);

		animation.add("stand", [0]);
		animation.add("bow", [1]);
		animation.add("jump", [2]);
		animation.add("run", [3, 4, 5, 6], 30);
		animation.play("stand");

		this.x = x;
		this.y = y;
		this.width = 10;
		this.height = 24;
		this.offset.set(7,0);
		this.acceleration.y = 1600;

		maxVelocity.set(vxmax, vymax);

		this.x = Math.round(this.x);
		this.y = Math.round(this.y);
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

		if (this.isTouching(FlxObject.FLOOR)) {
			if (FlxG.keys.pressed.UP) {
				this.velocity.y -= ay;
			}
		} else {
			animation.play("jump");
		}

		if (FlxG.keys.pressed.SPACE) {
			animation.play("bow");
		}

		if (FlxG.keys.justReleased.SPACE) {
			this.requestShoot = true;
		}

		super.update();
	}

	

}
