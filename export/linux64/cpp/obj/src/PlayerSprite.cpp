#include <hxcpp.h>

#ifndef INCLUDED_PlayerSprite
#include <PlayerSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void PlayerSprite_obj::__construct()
{
HX_STACK_FRAME("PlayerSprite","new",0xf88f9258,"PlayerSprite.new","PlayerSprite.hx",13,0xa1d50018)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(14)
	super::__construct(null(),null(),null());
	HX_STACK_LINE(15)
	::flixel::util::FlxPoint tmp = this->acceleration;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(15)
	tmp->set_y((int)200);
}
;
	return null();
}

//PlayerSprite_obj::~PlayerSprite_obj() { }

Dynamic PlayerSprite_obj::__CreateEmpty() { return  new PlayerSprite_obj; }
hx::ObjectPtr< PlayerSprite_obj > PlayerSprite_obj::__new()
{  hx::ObjectPtr< PlayerSprite_obj > _result_ = new PlayerSprite_obj();
	_result_->__construct();
	return _result_;}

Dynamic PlayerSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayerSprite_obj > _result_ = new PlayerSprite_obj();
	_result_->__construct();
	return _result_;}

Void PlayerSprite_obj::update( ){
{
		HX_STACK_FRAME("PlayerSprite","update",0x5bc54f11,"PlayerSprite.update","PlayerSprite.hx",21,0xa1d50018)
		HX_STACK_THIS(this)
		HX_STACK_LINE(21)
		this->super::update();
	}
return null();
}



PlayerSprite_obj::PlayerSprite_obj()
{
}

void PlayerSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayerSprite);
	HX_MARK_MEMBER_NAME(bLeft,"bLeft");
	HX_MARK_MEMBER_NAME(bRight,"bRight");
	HX_MARK_MEMBER_NAME(bJump,"bJump");
	HX_MARK_MEMBER_NAME(bItem,"bItem");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayerSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bLeft,"bLeft");
	HX_VISIT_MEMBER_NAME(bRight,"bRight");
	HX_VISIT_MEMBER_NAME(bJump,"bJump");
	HX_VISIT_MEMBER_NAME(bItem,"bItem");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayerSprite_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bLeft") ) { return bLeft; }
		if (HX_FIELD_EQ(inName,"bJump") ) { return bJump; }
		if (HX_FIELD_EQ(inName,"bItem") ) { return bItem; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bRight") ) { return bRight; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayerSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bLeft") ) { bLeft=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bJump") ) { bJump=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bItem") ) { bItem=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bRight") ) { bRight=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayerSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("bLeft","\x89","\x0d","\xce","\x9f"));
	outFields->push(HX_HCSTRING("bRight","\x1a","\xd8","\x8a","\xab"));
	outFields->push(HX_HCSTRING("bJump","\x70","\xca","\x87","\x9e"));
	outFields->push(HX_HCSTRING("bItem","\x95","\xca","\xdd","\x9d"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(PlayerSprite_obj,bLeft),HX_HCSTRING("bLeft","\x89","\x0d","\xce","\x9f")},
	{hx::fsString,(int)offsetof(PlayerSprite_obj,bRight),HX_HCSTRING("bRight","\x1a","\xd8","\x8a","\xab")},
	{hx::fsString,(int)offsetof(PlayerSprite_obj,bJump),HX_HCSTRING("bJump","\x70","\xca","\x87","\x9e")},
	{hx::fsString,(int)offsetof(PlayerSprite_obj,bItem),HX_HCSTRING("bItem","\x95","\xca","\xdd","\x9d")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("bLeft","\x89","\x0d","\xce","\x9f"),
	HX_HCSTRING("bRight","\x1a","\xd8","\x8a","\xab"),
	HX_HCSTRING("bJump","\x70","\xca","\x87","\x9e"),
	HX_HCSTRING("bItem","\x95","\xca","\xdd","\x9d"),
	HX_HCSTRING("update","\x09","\x86","\x05","\x87"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayerSprite_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayerSprite_obj::__mClass,"__mClass");
};

#endif

hx::Class PlayerSprite_obj::__mClass;

void PlayerSprite_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("PlayerSprite","\x66","\xc6","\x99","\x87");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< PlayerSprite_obj >;
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

