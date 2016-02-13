import flixel.system.scaleModes.BaseScaleMode;
class MyScaleMode extends BaseScaleMode {
	private var landscape:Bool;	//For landscape orientation
	public function new(landscape:Bool = false){
		super();
		this.landscape = landscape;
	}	
	
	override private function updateGameSize(Width:Int, Height:Int):Void {
		var size = 0.0;

		if (Width > Height) {
			size = Math.round(Width / 24.0) * 24.0;
		} else {
			size = Math.round(Height / 24.0) * 24.0;
		}

		gameSize.y = size;
		gameSize.x = size;
	}
}
