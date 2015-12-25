package; 

import flixel.FlxG;
import flixel.tile.FlxTilemap;
import flixel.group.FlxGroup;

class GageSprite extends PlayerSprite {


	public var requestShoot = false;
	override public function new(x:Int, y:Int) {
		super(x, y);

		loadGraphic("assets/images/gage.png", true, 24, 24);

		animation.add("stand", [0]);
		animation.add("jump", [1]);
		animation.add("fill", [2]);
		animation.add("aim-diag", [3]);
		animation.add("run", [4, 5, 6, 7, 8, 9], 30);
		animation.play("stand");

		this.width = 10;
		this.height = 24;

		bLeft = function () { return FlxG.keys.pressed.A; };
		bRight= function () { return FlxG.keys.pressed.D; };
		bJump = function () { return FlxG.keys.pressed.W; };
		bFire = function () { return FlxG.keys.pressed.ALT; };
	}

	override public function update() {
		super.update();

		if (bFire()) {
			this.requestShoot = true;
		}
	}

	

}
