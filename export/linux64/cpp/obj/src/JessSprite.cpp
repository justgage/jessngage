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
	HX_STACK_LINE(11)
	this->vymax = (int)700;
	HX_STACK_LINE(10)
	this->vxmax = (int)100;
	HX_STACK_LINE(8)
	this->ay = (int)100;
	HX_STACK_LINE(7)
	this->ax = (int)20;
	HX_STACK_LINE(14)
	super::__construct();
	HX_STACK_LINE(16)
	this->loadGraphic(HX_HCSTRING("assets/images/jess-tiles.png","\x39","\x96","\x22","\x83"),true,(int)24,(int)24,null(),null());
	HX_STACK_LINE(17)
	::flixel::animation::FlxAnimationController tmp = this->animation;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(17)
	tmp->add(HX_HCSTRING("stand","\xd6","\x70","\x0b","\x84"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(18)
	::flixel::animation::FlxAnimationController tmp1 = this->animation;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(18)
	tmp1->add(HX_HCSTRING("bow","\x0a","\xbe","\x4a","\x00"),Array_obj< int >::__new().Add((int)1),null(),null());
	HX_STACK_LINE(19)
	::flixel::animation::FlxAnimationController tmp2 = this->animation;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(19)
	tmp2->add(HX_HCSTRING("jump","\xee","\xc4","\x69","\x46"),Array_obj< int >::__new().Add((int)2),null(),null());
	HX_STACK_LINE(20)
	::flixel::animation::FlxAnimationController tmp3 = this->animation;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(20)
	tmp3->add(HX_HCSTRING("run","\x4b","\xe7","\x56","\x00"),Array_obj< int >::__new().Add((int)3).Add((int)4).Add((int)5).Add((int)6),null(),null());
	HX_STACK_LINE(21)
	::flixel::animation::FlxAnimationController tmp4 = this->animation;		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(21)
	tmp4->play(HX_HCSTRING("stand","\xd6","\x70","\x0b","\x84"),null(),null());
	HX_STACK_LINE(23)
	int tmp5 = x;		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(23)
	this->set_x(tmp5);
	HX_STACK_LINE(24)
	int tmp6 = y;		HX_STACK_VAR(tmp6,"tmp6");
	HX_STACK_LINE(24)
	this->set_y(tmp6);
	HX_STACK_LINE(25)
	this->set_width((int)10);
	HX_STACK_LINE(26)
	this->set_height((int)24);
	HX_STACK_LINE(27)
	::flixel::util::FlxPoint tmp7 = this->offset;		HX_STACK_VAR(tmp7,"tmp7");
	HX_STACK_LINE(27)
	tmp7->set((int)7,(int)0);
	HX_STACK_LINE(29)
	::flixel::util::FlxPoint tmp8 = this->maxVelocity;		HX_STACK_VAR(tmp8,"tmp8");
	HX_STACK_LINE(29)
	int tmp9 = this->vxmax;		HX_STACK_VAR(tmp9,"tmp9");
	HX_STACK_LINE(29)
	int tmp10 = this->vymax;		HX_STACK_VAR(tmp10,"tmp10");
	HX_STACK_LINE(29)
	tmp8->set(tmp9,tmp10);
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
		HX_STACK_FRAME("JessSprite","update",0x9a4b3017,"JessSprite.update","JessSprite.hx",32,0x5748661e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(33)
		::flixel::input::keyboard::FlxKeyboard tmp = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(33)
		::flixel::input::keyboard::FlxKeyboard tmp1 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(33)
		int tmp2 = tmp1->pressed->checkStatus;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(33)
		bool tmp3 = tmp->checkStatus((int)37,tmp2);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(33)
		if ((tmp3)){
			HX_STACK_LINE(34)
			{
				HX_STACK_LINE(34)
				::flixel::util::FlxPoint tmp4 = this->velocity;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(34)
				::flixel::util::FlxPoint _g = tmp4;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(34)
				Float tmp5 = _g->x;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(34)
				int tmp6 = this->ax;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(34)
				Float tmp7 = (tmp5 - tmp6);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(34)
				_g->set_x(tmp7);
			}
			HX_STACK_LINE(35)
			::flixel::animation::FlxAnimationController tmp4 = this->animation;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(35)
			tmp4->play(HX_HCSTRING("run","\x4b","\xe7","\x56","\x00"),null(),null());
			HX_STACK_LINE(36)
			this->set_flipX(false);
		}
		else{
			HX_STACK_LINE(38)
			::flixel::input::keyboard::FlxKeyboard tmp4 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(38)
			::flixel::input::keyboard::FlxKeyboard tmp5 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(38)
			int tmp6 = tmp5->pressed->checkStatus;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(38)
			bool tmp7 = tmp4->checkStatus((int)39,tmp6);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(38)
			if ((tmp7)){
				HX_STACK_LINE(39)
				{
					HX_STACK_LINE(39)
					::flixel::util::FlxPoint tmp8 = this->velocity;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(39)
					::flixel::util::FlxPoint _g = tmp8;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(39)
					Float tmp9 = _g->x;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(39)
					int tmp10 = this->ax;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(39)
					Float tmp11 = (tmp9 + tmp10);		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(39)
					_g->set_x(tmp11);
				}
				HX_STACK_LINE(40)
				this->set_flipX(true);
				HX_STACK_LINE(41)
				::flixel::animation::FlxAnimationController tmp8 = this->animation;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(41)
				tmp8->play(HX_HCSTRING("run","\x4b","\xe7","\x56","\x00"),null(),null());
			}
			else{
				HX_STACK_LINE(43)
				::flixel::animation::FlxAnimationController tmp8 = this->animation;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(43)
				tmp8->play(HX_HCSTRING("stand","\xd6","\x70","\x0b","\x84"),null(),null());
				HX_STACK_LINE(44)
				::flixel::util::FlxPoint tmp9 = this->velocity;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(44)
				::flixel::util::FlxPoint tmp10 = this->velocity;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(44)
				Float tmp11 = tmp10->x;		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(44)
				Float tmp12 = (tmp11 * ((Float)0.9));		HX_STACK_VAR(tmp12,"tmp12");
				HX_STACK_LINE(44)
				tmp9->set_x(tmp12);
			}
		}
		HX_STACK_LINE(47)
		::flixel::input::keyboard::FlxKeyboard tmp4 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(47)
		::flixel::input::keyboard::FlxKeyboard tmp5 = ::flixel::FlxG_obj::keys;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(47)
		int tmp6 = tmp5->pressed->checkStatus;		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(47)
		bool tmp7 = tmp4->checkStatus((int)38,tmp6);		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(47)
		if ((tmp7)){
			HX_STACK_LINE(48)
			::flixel::util::FlxPoint tmp8 = this->velocity;		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(48)
			::flixel::util::FlxPoint _g = tmp8;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(48)
			Float tmp9 = _g->y;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(48)
			int tmp10 = this->ay;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(48)
			Float tmp11 = (tmp9 - tmp10);		HX_STACK_VAR(tmp11,"tmp11");
			HX_STACK_LINE(48)
			_g->set_y(tmp11);
		}
		HX_STACK_LINE(51)
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
	case 2:
		if (HX_FIELD_EQ(inName,"ax") ) { return ax; }
		if (HX_FIELD_EQ(inName,"ay") ) { return ay; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"vxmax") ) { return vxmax; }
		if (HX_FIELD_EQ(inName,"vymax") ) { return vymax; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic JessSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ax") ) { ax=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ay") ) { ay=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"vxmax") ) { vxmax=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vymax") ) { vymax=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void JessSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("ax","\xf7","\x54","\x00","\x00"));
	outFields->push(HX_HCSTRING("ay","\xf8","\x54","\x00","\x00"));
	outFields->push(HX_HCSTRING("vxmax","\xa2","\x18","\xed","\x40"));
	outFields->push(HX_HCSTRING("vymax","\x41","\x4f","\x96","\x41"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(JessSprite_obj,ax),HX_HCSTRING("ax","\xf7","\x54","\x00","\x00")},
	{hx::fsInt,(int)offsetof(JessSprite_obj,ay),HX_HCSTRING("ay","\xf8","\x54","\x00","\x00")},
	{hx::fsInt,(int)offsetof(JessSprite_obj,vxmax),HX_HCSTRING("vxmax","\xa2","\x18","\xed","\x40")},
	{hx::fsInt,(int)offsetof(JessSprite_obj,vymax),HX_HCSTRING("vymax","\x41","\x4f","\x96","\x41")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("ax","\xf7","\x54","\x00","\x00"),
	HX_HCSTRING("ay","\xf8","\x54","\x00","\x00"),
	HX_HCSTRING("vxmax","\xa2","\x18","\xed","\x40"),
	HX_HCSTRING("vymax","\x41","\x4f","\x96","\x41"),
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

