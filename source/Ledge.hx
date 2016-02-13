import flixel.FlxObject;

class Ledge extends FlxObject {

	public var isLeft : Bool;
	public function new(isL, x, y, w, h) {
		super(x, y , w, h);
		isLeft = isL;
		moves = false;
	}
}
