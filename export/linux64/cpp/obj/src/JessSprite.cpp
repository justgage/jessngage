#include <hxcpp.h>

#ifndef INCLUDED_JessSprite
#include <JessSprite.h>
#endif
#ifndef INCLUDED_PlayerSprite
#include <PlayerSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void JessSprite_obj::__construct(int x,int y)
{
HX_STACK_FRAME("JessSprite","new",0x08157192,"JessSprite.new","JessSprite.hx",5,0x5748661e)
HX_STACK_THIS(this)
HX_STACK_ARG(x,"x")
HX_STACK_ARG(y,"y")
{
	HX_STACK_LINE(8)
	this->maxvy = (int)10;
	HX_STACK_LINE(7)
	this->maxvx = (int)10;
	HX_STACK_LINE(11)
	super::__construct();
	HX_STACK_LINE(13)
	this->loadGraphic(HX_HCSTRING("assets/images/jess.png","\x81","\xe7","\xe2","\x25"),true,(int)24,(int)24,null(),null());
	HX_STACK_LINE(14)
	::flixel::animation::FlxAnimationController tmp = this->animation;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(14)
	tmp->add(HX_HCSTRING("stand","\xd6","\x70","\x0b","\x84"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(15)
	::flixel::animation::FlxAnimationController tmp1 = this->animation;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(15)
	tmp1->play(HX_HCSTRING("stand","\xd6","\x70","\x0b","\x84"),null(),null());
	HX_STACK_LINE(17)
	int tmp2 = x;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(17)
	this->set_x(tmp2);
	HX_STACK_LINE(18)
	int tmp3 = y;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(18)
	this->set_y(tmp3);
	HX_STACK_LINE(20)
	::flixel::util::FlxPoint tmp4 = this->maxVelocity;		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(20)
	tmp4->set((int)80,(int)200);
}
;
	return null();
}

//JessSprite_obj::~JessSprite_obj() { }

Dynamic JessSprite_obj::__CreateEmpty() { return  new JessSprite_obj; }
hx::ObjectPtr< JessSprite_obj > JessSprite_obj::__new(int x,int y)
{  hx::ObjectPtr< JessSprite_obj > _result_ = new JessSprite_obj();
	_result_->__construct(x,y);
	return _result_;}

Dynamic JessSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JessSprite_obj > _result_ = new JessSprite_obj();
	_result_->__construct(inArgs[0],inArgs[1]);
	return _result_;}

Void JessSprite_obj::update( ){
{
		HX_STACK_FRAME("JessSprite","update",0x9a4b3017,"JessSprite.update","JessSprite.hx",23,0x5748661e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(24)
		::flixel::input::keyboard::FlxKeyboard tmp = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(24)
		::flixel::input::keyboard::FlxKeyboard tmp1 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(24)
		int tmp2 = tmp1->pressed->checkStatus;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(24)
		bool tmp3 = tmp->checkStatus((int)37,tmp2);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(24)
		if ((tmp3)){
			HX_STACK_LINE(25)
			::flixel::util::FlxPoint tmp4 = this->velocity;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(25)
			::flixel::util::FlxPoint _g = tmp4;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(25)
			Float tmp5 = _g->x;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(25)
			int tmp6 = this->maxvx;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(25)
			Float tmp7 = (tmp5 - tmp6);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(25)
			_g->set_x(tmp7);
		}
		HX_STACK_LINE(28)
		::flixel::input::keyboard::FlxKeyboard tmp4 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(28)
		::flixel::input::keyboard::FlxKeyboard tmp5 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(28)
		int tmp6 = tmp5->pressed->checkStatus;		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(28)
		bool tmp7 = tmp4->checkStatus((int)39,tmp6);		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(28)
		if ((tmp7)){
			HX_STACK_LINE(29)
			::flixel::util::FlxPoint tmp8 = this->velocity;		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(29)
			::flixel::util::FlxPoint _g = tmp8;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(29)
			Float tmp9 = _g->x;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(29)
			int tmp10 = this->maxvx;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(29)
			Float tmp11 = (tmp9 + tmp10);		HX_STACK_VAR(tmp11,"tmp11");
			HX_STACK_LINE(29)
			_g->set_x(tmp11);
		}
		HX_STACK_LINE(32)
		::flixel::input::keyboard::FlxKeyboard tmp8 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(32)
		::flixel::input::keyboard::FlxKeyboard tmp9 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(32)
		int tmp10 = tmp9->pressed->checkStatus;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(32)
		bool tmp11 = tmp8->checkStatus((int)38,tmp10);		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(32)
		if ((tmp11)){
			HX_STACK_LINE(33)
			::flixel::util::FlxPoint tmp12 = this->velocity;		HX_STACK_VAR(tmp12,"tmp12");
			HX_STACK_LINE(33)
			::flixel::util::FlxPoint _g = tmp12;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(33)
			Float tmp13 = _g->y;		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(33)
			int tmp14 = this->maxvx;		HX_STACK_VAR(tmp14,"tmp14");
			HX_STACK_LINE(33)
			Float tmp15 = (tmp13 - tmp14);		HX_STACK_VAR(tmp15,"tmp15");
			HX_STACK_LINE(33)
			_g->set_y(tmp15);
		}
		HX_STACK_LINE(36)
		this->super::update();
	}
return null();
}



JessSprite_obj::JessSprite_obj()
{
}

Dynamic JessSprite_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"maxvx") ) { return maxvx; }
		if (HX_FIELD_EQ(inName,"maxvy") ) { return maxvy; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic JessSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"maxvx") ) { maxvx=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxvy") ) { maxvy=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void JessSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("maxvx","\xe6","\x62","\x26","\x03"));
	outFields->push(HX_HCSTRING("maxvy","\xe7","\x62","\x26","\x03"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(JessSprite_obj,maxvx),HX_HCSTRING("maxvx","\xe6","\x62","\x26","\x03")},
	{hx::fsInt,(int)offsetof(JessSprite_obj,maxvy),HX_HCSTRING("maxvy","\xe7","\x62","\x26","\x03")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("maxvx","\xe6","\x62","\x26","\x03"),
	HX_HCSTRING("maxvy","\xe7","\x62","\x26","\x03"),
	HX_HCSTRING("update","\x09","\x86","\x05","\x87"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JessSprite_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(JessSprite_obj::__mClass,"__mClass");
};

#endif

hx::Class JessSprite_obj::__mClass;

void JessSprite_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("JessSprite","\xa0","\x00","\xbd","\x26");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< JessSprite_obj >;
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

