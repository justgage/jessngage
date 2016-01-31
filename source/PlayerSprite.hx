package; 

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxObject;

class PlayerSprite extends FlxSprite  {
	
	private var bLeft = function () { return FlxG.keys.pressed.LEFT;};
	private var bRight= function () { return FlxG.keys.pressed.RIGHT; };
	private var bJump = function () { return FlxG.keys.pressed.UP; };
	private var bFire = function () { return FlxG.keys.pressed.SPACE; };
	private var bFire1 = function () { return FlxG.keys.justReleased.SPACE; };

	public var touchLeft = false;
	public var touchRight = false;
	public var touchUp = false;
	public var ax = 20;
	public var ay = 500;

	private var vxmax = 150;
	private var vymax = 800;


	override public function new(x, y) {
		super();

		this.x = x;
		this.y = y;
		acceleration.y = 400;
		this.offset.set(7,0);
		this.acceleration.y = 1600;

		maxVelocity.set(vxmax, vymax);

	}

	override public function update():Void
	{
		if (bLeft() || this.touchLeft) {
			this.velocity.x -= ax;
			animation.play("run");
			this.flipX = false;
			this.touchLeft = false;

		} else if (bRight() || this.touchRight) {
			this.velocity.x += ax;
			this.flipX = true;
			animation.play("run");
			this.touchRight = false;
		} else {
			animation.play("stand");
			this.velocity.x = this.velocity.x * 0.9; 
		}

		if (this.isTouching(FlxObject.FLOOR)) {
			if (bJump() || this.touchUp) {
				this.velocity.y -= ay;
				this.touchUp = false;
			}
		} else {
			this.touchUp = false;
			animation.play("jump");
		}
		super.update();
	}

}
