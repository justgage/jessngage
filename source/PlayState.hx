package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxObject;
import flixel.FlxCamera;
import flixel.FlxBasic;
import flixel.FlxState;
import flixel.group.FlxGroup;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.util.FlxColor;
import flixel.system.scaleModes.PixelPerfectScaleMode;
import flixel.system.scaleModes.FillScaleMode;
import openfl.Assets;

// my stuff 
import JessSprite;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	private var tileMap:FlxTilemap;
	static var TILE_WIDTH:Int = 24;
	static var TILE_HEIGHT:Int = 24;
	

	public var cam:TouchCamera;
	public var jess:JessSprite;
	// public var gage:GageSprite;
	public var players:FlxGroup;
	public var ground:FlxGroup;
	public var level:TiledLevel;
	public var mail:FlxGroup;
	public var shroom:FlxGroup;
	public var ledges:FlxGroup;
	public var blueDoors:FlxGroup;
	public var blueKeys:FlxGroup;
	public var arrows:FlxGroup;
	public var droplets:FlxGroup;
	public var pools:FlxGroup;
	public var exit:FlxGroup;

	// HUD
	public var mailCountText:FlxText;
	public var blueText:FlxText;
	public var messageText:FlxText;
	public var messageShow:Int = 60 * 3;


	override public function new(?MaxSize:Int = 0) {
		super(maxSize);
	}

	public function message(message) {
		messageText.text = message;
		messageShow = 60 * 4;
	}

	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{

		//FlxG.camera.bgColor = 0x333333;
		//FlxG.debugger.drawDebug = true;
		FlxG.scaleMode = new MyScaleMode();

		super.create();

		this.level= new TiledLevel("assets/data/" +  Reg.currentLevel()  + ".tmx");

		players   = new FlxGroup();
		mail      = new FlxGroup();
		shroom    = new FlxGroup();
		ledges    = new FlxGroup();
		blueDoors = new FlxGroup();
		arrows    = new FlxGroup();
		droplets    = new FlxGroup();
		pools    = new FlxGroup();
		blueKeys  = new FlxGroup();
		exit = new FlxGroup();

		this.mailCountText = new FlxText(2, 2, -1, "Mail Count: 0");
		mailCountText.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
		mailCountText.scrollFactor.set(0, 0); 

		this.blueText = new FlxText(2, 20, -1, "keys 0");
		blueText.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
		blueText.scrollFactor.set(0, 0); 

		this.messageText = new FlxText(20, 24 * 18, 24*25, "Hm... this cave seems to have some of you're mail it it!");
		messageText.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.BLACK, 1, 1);
		messageText.scrollFactor.set(0, 0); 
		messageText.alignment = "center";

		add(level.backgroundTiles);

		level.loadObjects(this);

		// must be after all the other objects have loaded
		cam = new TouchCamera(jess);

		add(level.foregroundTiles);

		add(mail);
		add(shroom);
		add(ledges);
		add(arrows);
		add(droplets);
		add(blueKeys);
		add(blueDoors);
		add(exit);
		add(jess);
		// add(gage);
		add(pools);
		add(cam);


		add(mailCountText);
		add(blueText);
		add(messageText);

		mailCountText.text = "MAIL: " + mail.countDead() + " of " + mail.countLiving();

		FlxG.camera.follow(jess, FlxCamera.STYLE_LOCKON, 2);

	}
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{

		messageShow -= 1;

		if (messageShow < 0) {
			messageText.visible = false;
		} else {
			messageText.visible = true;
		}


		var thirdW = FlxG.width / 3;
		var halfH = FlxG.height / 2;

		// for( touch in FlxG.touches.list ){
		// 	trace(touch.touchPointID, touch.screenX);
		// 	if (touch.screenY < halfH) {
		// 		jess.touchUp = true;
		// 	} else if (touch.screenX < thirdW && touch.pressed) {
		// 		jess.touchLeft = true;
		// 	} else if (touch.screenX > thirdW * 2) {
		// 		jess.touchRight = true;
		// 	} else if (touch.justReleased) {
		// 		jess.touchShoot = true;
		// 	}
      //
		// }

		//FlxG.collide(jess, gage);

		FlxG.collide(droplets, jess);
		FlxG.collide(droplets, mail);
		FlxG.collide(droplets, blueKeys);

		FlxG.collide(arrows, mail);
		FlxG.collide(arrows, blueKeys);

		FlxG.overlap(ledges, players, function(l, p) {
		      if (l.isLeft &&  p.bLeft()) {
			    p.grabbing = l;
		      } else if (!l.isLeft &&  p.bRight()) {
			    p.grabbing = l;
		      }
		});

		FlxG.overlap(mail, players, getMail);
		// FlxG.overlap(pools, gage, function (p, g) {
		// 	if (Reg.waterLevel < 100) {
		// 		Reg.waterLevel++;
		// 	}
                //
		// });
		FlxG.overlap(shroom, players, hitShroom);
		FlxG.overlap(blueDoors, players, hitBlueDoor);
		FlxG.overlap(blueKeys, players, hitBlueKey);
		FlxG.overlap(exit, players, exitRoom);
		// FlxG.overlap(level.foregroundTiles, arrows, arrowBlock);
		level.collideWithLevel(arrows, arrowBlock);
		level.collideWithLevel(droplets, waterBlock);
		level.collideWithLevel(players);
		level.collideWithLevel(mail);
		level.collideWithLevel(cam);

		if (jess.requestShoot == true) {
			var arrow = new ArrowSprite(jess.x, jess.y, jess.flipX == true);
			arrows.add(arrow);
			jess.requestShoot = false;
		}

		// if (gage.requestShoot == true) {
		// 	gage.requestShoot = false;
		// 	if (Reg.waterLevel > 0) {
		// 		var drop = new WaterSprite(gage.x, gage.y, gage.flipX == true);
		// 		droplets.add(drop);
		// 		Reg.waterLevel--;
                //
		// 	} else {
		// 		message("Hmmm... seems like your gun's out of water!");
		// 	}
		// }

		super.update();
	}	


	public function waterBlock(FlxObject, water:FlxObject):Void { }

	public function arrowBlock(block:FlxObject, arrow:FlxObject):Void
	{
		arrow.velocity.x *= 0.9;
		arrow.velocity.y = 0;
		arrow.acceleration.y = 0;
	}

	public function getMail(m:FlxObject, Player:PlayerSprite):Void
	{
		Reg.mailCount++;
		mailCountText.text = "MAIL: " + mail.countDead() + " of " + mail.countLiving();
		m.kill();
		message("You got one of your letters!");

		if (mail.countLiving() == 0) {
			FlxG.switchState(new WinState());
		}
	}

	public function hitShroom(sh:FlxObject, pl:PlayerSprite):Void
	{
		if (pl.y < sh.y && pl.velocity.y > 0) {
			pl.velocity.y = pl.velocity.y * -1.4;
			pl.y = sh.y - 24;
		} else {
			if (pl.x < sh.x) {
				pl.x = sh.x - pl.width;
			} else {
				pl.x = sh.x + 24;
			}
		}
	}

	public function hitBlueKey(key:FlxObject, pl:PlayerSprite):Void
	{
		Reg.blueKeys++;
		blueText.text = "keys: " + Reg.blueKeys;
		key.kill();
		message("You found a little blue key. This will probably come in handy.");
	}

	public function exitNext(exit, pl) {
	      Reg.level += 1;
	      changeRoom();
	}

	public function exitRoom(exit:ExitObject, pl:PlayerSprite):Void {
		function flipX() {
			Reg.enterX = level.fullWidth - pl.x;
			Reg.enterY = pl.y;
		}

		function flipY() {
			Reg.enterX = pl.x;
			Reg.enterY = level.fullHeight - pl.y;
		}

		var moveFactor = 50;

		if (exit.dir == "left")  { 
			pl.x += moveFactor;
			flipX();
		} else if (exit.dir == "right") { 
			pl.x -= moveFactor;
			flipX();
		} else if (exit.dir == "up")    { 
			pl.y += moveFactor;
			flipY();
		} else if (exit.dir == "down")  { 
			pl.y -= moveFactor;
			flipY();
		} else {
			trace("Invalid direction", exit.dir);
		}

		//changeRoom(exit.where);
	}


	public function hitBlueDoor(door:FlxObject, pl:PlayerSprite):Void
	{
		if (Reg.blueKeys > 0) {
			message("Wow, that key seems to have made the door disappear... Creepy");
			Reg.blueKeys--;
			blueText.text = "keys: " + Reg.blueKeys;
			door.destroy();
		} else {
			message("Hmm... Seems to be locked!");
			if (pl.x < door.x) {
				pl.x = door.x - pl.width;
			} else {
				pl.x = door.x + door.width;
			}
		}
	}

	public function changeRoom() {
		//FlxG.switchState(new PlayState(nextLevel));
		FlxG.switchState(new PlayState());
	}
}
