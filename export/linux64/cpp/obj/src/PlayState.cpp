#include <hxcpp.h>

#ifndef INCLUDED_JessSprite
#include <JessSprite.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_PlayerSprite
#include <PlayerSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_openfl__legacy_Assets
#include <openfl/_legacy/Assets.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",18,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(18)
	Dynamic tmp = MaxSize;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(18)
	super::__construct(tmp);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > _result_ = new PlayState_obj();
	_result_->__construct(MaxSize);
	return _result_;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > _result_ = new PlayState_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",31,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(32)
		this->super::create();
		HX_STACK_LINE(34)
		this->set_bgColor((int)77777777);
		HX_STACK_LINE(36)
		::flixel::tile::FlxTilemap tmp = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(36)
		this->tileMap = tmp;
		HX_STACK_LINE(37)
		::flixel::tile::FlxTilemap tmp1 = this->tileMap;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(37)
		::String tmp2 = ::openfl::_legacy::Assets_obj::getText(HX_HCSTRING("assets/data/level1.csv","\x3e","\x8f","\xff","\xae"));		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(37)
		int tmp3 = ::PlayState_obj::TILE_WIDTH;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(37)
		int tmp4 = ::PlayState_obj::TILE_HEIGHT;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(37)
		tmp1->loadMap(tmp2,HX_HCSTRING("assets/images/ground-tiles.png","\x65","\xa2","\xae","\xb6"),tmp3,tmp4,(int)0,(int)0,null(),null());
		HX_STACK_LINE(38)
		::flixel::tile::FlxTilemap tmp5 = this->tileMap;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(38)
		this->add(tmp5);
		HX_STACK_LINE(40)
		int tmp6 = (int)72;		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(40)
		int tmp7 = (int)72;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(40)
		::JessSprite tmp8 = ::JessSprite_obj::__new(tmp6,tmp7);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(40)
		this->jess = tmp8;
		HX_STACK_LINE(42)
		::JessSprite tmp9 = this->jess;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(42)
		this->add(tmp9);
		HX_STACK_LINE(44)
		::flixel::FlxCamera tmp10 = ::flixel::FlxG_obj::camera;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(44)
		::JessSprite tmp11 = this->jess;		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(44)
		tmp10->follow(tmp11,(int)1,null(),null());
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",53,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(53)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",60,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(61)
		::JessSprite tmp = this->jess;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(61)
		::flixel::tile::FlxTilemap tmp1 = this->tileMap;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(61)
		Dynamic tmp2 = ::flixel::FlxObject_obj::separate_dyn();		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(61)
		::flixel::FlxG_obj::overlap(tmp,tmp1,null(),tmp2);
		HX_STACK_LINE(63)
		this->super::update();
	}
return null();
}


int PlayState_obj::TILE_WIDTH;

int PlayState_obj::TILE_HEIGHT;


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(tileMap,"tileMap");
	HX_MARK_MEMBER_NAME(jess,"jess");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tileMap,"tileMap");
	HX_VISIT_MEMBER_NAME(jess,"jess");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"jess") ) { return jess; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"tileMap") ) { return tileMap; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

bool PlayState_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_WIDTH") ) { outValue = TILE_WIDTH; return true;  }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TILE_HEIGHT") ) { outValue = TILE_HEIGHT; return true;  }
	}
	return false;
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"jess") ) { jess=inValue.Cast< ::JessSprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"tileMap") ) { tileMap=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool PlayState_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_WIDTH") ) { TILE_WIDTH=ioValue.Cast< int >(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TILE_HEIGHT") ) { TILE_HEIGHT=ioValue.Cast< int >(); return true; }
	}
	return false;
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("tileMap","\x0e","\xa8","\x76","\x45"));
	outFields->push(HX_HCSTRING("jess","\x1b","\xa6","\x5d","\x46"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,tileMap),HX_HCSTRING("tileMap","\x0e","\xa8","\x76","\x45")},
	{hx::fsObject /*::JessSprite*/ ,(int)offsetof(PlayState_obj,jess),HX_HCSTRING("jess","\x1b","\xa6","\x5d","\x46")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsInt,(void *) &PlayState_obj::TILE_WIDTH,HX_HCSTRING("TILE_WIDTH","\xd5","\x5e","\xc1","\xb3")},
	{hx::fsInt,(void *) &PlayState_obj::TILE_HEIGHT,HX_HCSTRING("TILE_HEIGHT","\x18","\x14","\xc1","\x4b")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("tileMap","\x0e","\xa8","\x76","\x45"),
	HX_HCSTRING("jess","\x1b","\xa6","\x5d","\x46"),
	HX_HCSTRING("create","\xfc","\x66","\x0f","\x7c"),
	HX_HCSTRING("destroy","\xfa","\x2c","\x86","\x24"),
	HX_HCSTRING("update","\x09","\x86","\x05","\x87"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PlayState_obj::TILE_WIDTH,"TILE_WIDTH");
	HX_MARK_MEMBER_NAME(PlayState_obj::TILE_HEIGHT,"TILE_HEIGHT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PlayState_obj::TILE_WIDTH,"TILE_WIDTH");
	HX_VISIT_MEMBER_NAME(PlayState_obj::TILE_HEIGHT,"TILE_HEIGHT");
};

#endif

hx::Class PlayState_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("TILE_WIDTH","\xd5","\x5e","\xc1","\xb3"),
	HX_HCSTRING("TILE_HEIGHT","\x18","\x14","\xc1","\x4b"),
	::String(null()) };

void PlayState_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("PlayState","\x5d","\x83","\xc2","\x46");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &PlayState_obj::__GetStatic;
	__mClass->mSetStaticField = &PlayState_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< PlayState_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = sStaticStorageInfo;
#endif
	hx::RegisterClass(__mClass->mName, __mClass);
}

void PlayState_obj::__boot()
{
	TILE_WIDTH= (int)24;
	TILE_HEIGHT= (int)24;
}

