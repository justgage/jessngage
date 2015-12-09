#include <hxcpp.h>

#include "hxMath.h"
#ifndef INCLUDED_MenuState
#include <MenuState.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
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
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxButton
#include <flixel/ui/FlxButton.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxTypedButton
#include <flixel/ui/FlxTypedButton.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObject
#include <openfl/_legacy/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObjectContainer
#include <openfl/_legacy/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_IBitmapDrawable
#include <openfl/_legacy/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_InteractiveObject
#include <openfl/_legacy/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_Sprite
#include <openfl/_legacy/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_EventDispatcher
#include <openfl/_legacy/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_IEventDispatcher
#include <openfl/_legacy/events/IEventDispatcher.h>
#endif

Void MenuState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("MenuState","new",0xe563b1c4,"MenuState.new","MenuState.hx",13,0xdfbcb22c)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(13)
	Dynamic tmp = MaxSize;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(13)
	super::__construct(tmp);
}
;
	return null();
}

//MenuState_obj::~MenuState_obj() { }

Dynamic MenuState_obj::__CreateEmpty() { return  new MenuState_obj; }
hx::ObjectPtr< MenuState_obj > MenuState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< MenuState_obj > _result_ = new MenuState_obj();
	_result_->__construct(MaxSize);
	return _result_;}

Dynamic MenuState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MenuState_obj > _result_ = new MenuState_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

Void MenuState_obj::create( ){
{
		HX_STACK_FRAME("MenuState","create",0xe57b7c18,"MenuState.create","MenuState.hx",19,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(20)
		this->super::create();
		HX_STACK_LINE(22)
		::flixel::text::FlxText tmp = ::flixel::text::FlxText_obj::__new((int)20,(int)20,(int)100,HX_HCSTRING("Jess & Gage","\x57","\xf4","\x10","\x92"),null(),null());		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(22)
		this->add(tmp);
		HX_STACK_LINE(24)
		int tmp1 = ::flixel::FlxG_obj::width;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(24)
		Float tmp2 = (Float(tmp1) / Float((int)2));		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(24)
		Float tmp3 = (tmp2 - (int)40);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(24)
		int tmp4 = ::Math_obj::floor(tmp3);		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(24)
		int init_x = tmp4;		HX_STACK_VAR(init_x,"init_x");
		HX_STACK_LINE(25)
		int tmp5 = ::flixel::FlxG_obj::height;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(25)
		Float tmp6 = (Float(tmp5) / Float((int)2));		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(25)
		Float tmp7 = (tmp6 - (int)40);		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(25)
		int tmp8 = ::Math_obj::floor(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(25)
		int init_y = tmp8;		HX_STACK_VAR(init_y,"init_y");
		HX_STACK_LINE(27)
		int tmp9 = init_x;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(27)
		int tmp10 = init_y;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(27)
		Dynamic tmp11 = this->start_dyn();		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(27)
		::flixel::ui::FlxButton tmp12 = ::flixel::ui::FlxButton_obj::__new(tmp9,tmp10,HX_HCSTRING("Start","\x42","\xe4","\x38","\x17"),tmp11);		HX_STACK_VAR(tmp12,"tmp12");
		HX_STACK_LINE(27)
		::flixel::ui::FlxButton start_btn = tmp12;		HX_STACK_VAR(start_btn,"start_btn");
		HX_STACK_LINE(29)
		::flixel::ui::FlxButton tmp13 = start_btn;		HX_STACK_VAR(tmp13,"tmp13");
		HX_STACK_LINE(29)
		this->add(tmp13);
	}
return null();
}


Void MenuState_obj::destroy( ){
{
		HX_STACK_FRAME("MenuState","destroy",0xf9ac905e,"MenuState.destroy","MenuState.hx",39,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(39)
		this->super::destroy();
	}
return null();
}


Void MenuState_obj::update( ){
{
		HX_STACK_FRAME("MenuState","update",0xf0719b25,"MenuState.update","MenuState.hx",47,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(47)
		this->super::update();
	}
return null();
}


Void MenuState_obj::start( ){
{
		HX_STACK_FRAME("MenuState","start",0xb5e176c6,"MenuState.start","MenuState.hx",51,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(51)
		::PlayState tmp = ::PlayState_obj::__new(null());		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(51)
		::flixel::FlxState State = tmp;		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(51)
		::flixel::FlxGame tmp1 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(51)
		tmp1->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuState_obj,start,(void))


MenuState_obj::MenuState_obj()
{
}

Dynamic MenuState_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("create","\xfc","\x66","\x0f","\x7c"),
	HX_HCSTRING("destroy","\xfa","\x2c","\x86","\x24"),
	HX_HCSTRING("update","\x09","\x86","\x05","\x87"),
	HX_HCSTRING("start","\x62","\x74","\x0b","\x84"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MenuState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MenuState_obj::__mClass,"__mClass");
};

#endif

hx::Class MenuState_obj::__mClass;

void MenuState_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("MenuState","\xd2","\xbf","\xb6","\xc0");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< MenuState_obj >;
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

