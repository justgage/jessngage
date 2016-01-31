import flixel.system.scaleModes.BaseScaleMode;
class MyScaleMode extends BaseScaleMode {
	private var landscape:Bool;	//For landscape orientation
	public function new(landscape:Bool = false){
		super();
		this.landscape = landscape;
	}	
	
	override private function updateGameSize(Width:Int, Height:Int):Void {
		if (landscape) {
			gameSize.y = Width;
			gameSize.x = Width;
		}else {
			gameSize.y = Height;
			gameSize.x = Height;
		}
	}
}
