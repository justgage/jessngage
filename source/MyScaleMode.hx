import flixel.system.scaleModes.BaseScaleMode;
class MyScaleMode extends BaseScaleMode {
	private var landscape:Bool;	//For landscape orientation
	public function new(landscape:Bool = false){
		super();
		this.landscape = landscape;
	}	
	
	override private function updateGameSize(Width:Int, Height:Int):Void {
		var size = 0;
		if (landscape) {
			size = Width;
		}else {
			size = Height;
		}

		gameSize.y = size;
		gameSize.x = size;
	}
}
