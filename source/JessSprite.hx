package; 

import flixel.FlxG;
import flixel.tile.FlxTilemap;
import flixel.group.FlxGroup;

class JessSprite extends PlayerSprite {

	public var requestShoot = false;
	override public function new(x:Int, y:Int) {
		super(x, y);

		loadGraphic("assets/images/jess-tiles.png", true, 24, 24);

		animation.add("stand", [0]);
		animation.add("bow", [1]);
		animation.add("jump", [2]);
		animation.add("run", [3, 4, 5, 6], 30);
		animation.play("stand");

		this.width = 10;
		this.height = 24;

	}

	override public function update() {
		super.update();
		if (FlxG.keys.pressed.SPACE) {
			animation.play("bow");
		}

		if (FlxG.keys.justReleased.SPACE) {
			this.requestShoot = true;
		}

	}

	

}
