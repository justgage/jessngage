package; 

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxObject;

class PlayerSprite extends FlxSprite  {
	

	public var touchLeftX : Float = 0;
	public var touchLeft = false;
	public var touchRight = false;
	public var touchUp = false;
	public var touchDown = false;
	public var touchShoot = false;
	public var touchX:Float = 0.0;
	public var touchY:Float = 0.0;

	public var grabbing:Ledge = null;
	public var ax = 10;
	public var ay = 600;

	private var vxmax = 250;
	private var vymax = 800;

	public function bLeft() {
		return FlxG.keys.pressed.LEFT;
			// || this.touchLeft;
	}
	public function bRight() {
		return FlxG.keys.pressed.RIGHT ;
			// || this.touchRight; 
	}
	public function bJump() {
		return FlxG.keys.pressed.UP || this.touchUp; 
	}
	public function bFire() {
		return FlxG.keys.pressed.SPACE || this.touchDown; 
	}
	public function bFire1() {
		return FlxG.keys.justReleased.SPACE || this.touchShoot; 
	}


	override public function new(x, y) {
		super();

		this.x = x;
		this.y = y;
		acceleration.y = 200;
		this.offset.set(7,0);
		this.acceleration.y = 1600;

		maxVelocity.set(vxmax, vymax);

	}

	public function pickAnimations() {

		// determine animation
		if(grabbing != null) {
			animation.play("grab");
		}  else if (isTouching(FlxObject.FLOOR) == false) {
			animation.play("jump");
		} else if (bLeft() || bRight() || touchLeft || touchRight) {
			animation.play("run");
		} else {
			animation.play("stand");
		}

		// determine flip
		if(grabbing != null) {
			flipX = !grabbing.isLeft;
		} else if (velocity.x > 1) {
			flipX = true;
		} else if (velocity.x < -1) {
			flipX = false; 
		}
	}

	override public function update():Void {


		if(grabbing != null){
			if(y < grabbing.y || bJump() || touchUp || touchDown) {
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
			}

		} else {

			if (bLeft()) {
				this.velocity.x -= ax;
			} else if (bRight()) {
				this.velocity.x += ax;
			}  

			// don't move while trying to fire
			if (bFire() == false) {
				this.velocity.x += ax * (touchX / 50);
			} 
		}

		if (this.isTouching(FlxObject.FLOOR)) {

			if (bJump() || this.touchUp) {
				this.velocity.y -= ay;
				this.touchUp = false;
			}
		} else {
			this.touchUp = false;
		}

		velocity.x = this.velocity.x * 0.9; 
		velocity.x = Math.round(this.velocity.x);

		pickAnimations();

		super.update();
	}

}
