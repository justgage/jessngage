package; 

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxObject;

class PlayerSprite extends FlxSprite  {
	
	public var bLeft = function () { return FlxG.keys.pressed.LEFT;};
	public var bRight= function () { return FlxG.keys.pressed.RIGHT; };
	public var bJump = function () { return FlxG.keys.pressed.UP; };
	public var bFire = function () { return FlxG.keys.pressed.SPACE; };
	public var bFire1 = function () { return FlxG.keys.justReleased.SPACE; };

	public var touchLeftX : Float = 0;
	public var touchLeft = false;
	public var touchRight = false;
	public var touchUp = false;
	public var touchShoot = false;

	public var grabbing = null;
	public var ax = 10;
	public var ay = 600;

	private var vxmax = 250;
	private var vymax = 800;


	override public function new(x, y) {
		super();

		this.x = x;
		this.y = y;
		acceleration.y = 200;
		this.offset.set(7,0);
		this.acceleration.y = 1600;

		maxVelocity.set(vxmax, vymax);

	}

	override public function update():Void {

		if(grabbing != null){
			if(y < grabbing.y || bJump() || touchUp) {
				if(bJump() || touchUp) {
					this.velocity.y = -400;
					this.acceleration.y = 1600;
				}
				grabbing = null;
			} else {
				var gx = grabbing.x + (grabbing.isLeft ? -1 : 12);
				x = (gx + x) / 2;
				y = (grabbing.y + y) / 2;
				this.velocity.y = 0;
				this.velocity.x = 0;
				this.acceleration.y = 0;

				this.flipX = !grabbing.isLeft;
			}
		} else if (bLeft() || this.touchLeft) {
			this.velocity.x -= ax;
			animation.play("run");
			this.flipX = false;
			this.touchLeft = false;

		} else if (bRight() || this.touchRight) {
			this.velocity.x += ax; this.flipX = true;
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
			if (grabbing == null) {
				animation.play("jump");
			} else {
				animation.play("grab");
			}
		}
		super.update();
	}

}
