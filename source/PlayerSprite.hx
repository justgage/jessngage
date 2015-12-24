package; 

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxObject;

class PlayerSprite extends FlxSprite  {
	
	private var bLeft:String;
	private var bRight:String;
	private var bJump:String;
	private var bItem:String;

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
		super.update();
	}

}
