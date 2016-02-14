import flixel.FlxSprite;

class Sign extends FlxSprite {
	public var message = "";

	public function new(x,y, mess) {
		super(x, y);

		message = mess;
		loadGraphic("assets/images/sign.png", true, 24, 24);
		animation.add("sign", [0]);
		animation.play("sign");

	}
}
