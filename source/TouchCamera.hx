import flixel.FlxG;
import flixel.FlxSprite;

class TouchCamera extends FlxSprite  {

	public var startX:Float = -1;
	public var startY:Float = -1;
	public var dampening:Float = 2;
	public var deadZone:Int = 50;
	public var player:PlayerSprite;

	override public function new(p:PlayerSprite) {
		super();
		loadGraphic("assets/images/fairy.png", false, 11, 13);
		velocity.y = 10;
		maxVelocity.set(150, 150);
		x = p.x;
		y = p.y;

		this.player = p;
	}


	override public function update(): Void {

		this.flipX = player.flipX;

		var touch = FlxG.touches.getFirst();
		if(touch != null) {

			var point = touch.getWorldPosition();

			if(startX != -1) {
				x += (point.x - startX) / dampening ;
				y += (point.y - startY) / dampening;
			}

			startX = point.x;
			startY = point.y;
		}  else {
			startX = -1;
			startY = -1;

			var offset = player.flipX ? -4 : 4;

			x = (x * 4 + player.x)/ 5 + offset;
			y = (y * 4 + player.y)/ 5;
		}

		if (x - player.x > deadZone) {
			player.touchRight = true;
		}

		if (x - player.x < -deadZone) {
			player.touchLeft = true;
		}

		if (y - player.y < -deadZone) {
			player.touchUp = true;
		}

		super.update();
	}

}
