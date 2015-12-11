#ifndef INCLUDED_JessSprite
#define INCLUDED_JessSprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_PlayerSprite
#include <PlayerSprite.h>
#endif
HX_DECLARE_CLASS0(JessSprite)
HX_DECLARE_CLASS0(PlayerSprite)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)


class HXCPP_CLASS_ATTRIBUTES  JessSprite_obj : public ::PlayerSprite_obj{
	public:
		typedef ::PlayerSprite_obj super;
		typedef JessSprite_obj OBJ_;
		JessSprite_obj();
		Void __construct(int x,int y);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="JessSprite")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< JessSprite_obj > __new(int x,int y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~JessSprite_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("JessSprite","\xa0","\x00","\xbd","\x26"); }

		int ax;
		int ay;
		int vxmax;
		int vymax;
		virtual Void update( );

};


#endif /* INCLUDED_JessSprite */ 
