import flixel.FlxG;
import flixel.FlxSprite;

class TouchCamera extends FlxSprite  {

	public var startX:Float = -1;
	public var startY:Float = -1;
	public var deadZone:Int = 40;
	public var deadZoneX:Int = 40;
	public var player:PlayerSprite;

	override public function new(p:PlayerSprite) {
		super();
		this.offset.set(-7,9);
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
				x += (point.x - startX);
				y += (point.y - startY);
			}

			startX = point.x;
			startY = point.y;
		}  else {
			startX = -1;
			startY = -1;

			//var offset = player.flipX ? -4 : 4;

			x = (x * 4 + player.x)/ 5;
			y = (y * 4 + player.y)/ 5;
		}

		if (x - player.x > deadZoneX) {
			player.touchLeft = false;
			player.touchRight = true;
		} else if (x - player.x < -deadZoneX) {
			player.touchLeft = true;
			player.touchRight = false;
		} else {
			player.touchLeft = false;
			player.touchRight = false;
		}

		if (player.touchLeft || player.touchRight) {
			player.touchX = x - player.x;
		} else {
			player.touchX = 0;
		}

		player.touchY = y - player.y;

		if (y - player.y < -deadZone) {
			player.touchUp = true;
		}

		if (y - player.y > deadZone * 3) {
			player.touchDown = true;

			if (touch != null && touch.justReleased == true) {
				player.touchShoot = true;
			}
		} else {
			player.touchDown = false;
		}


		super.update();
	}

}
