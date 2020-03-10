// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:50)

#ifndef FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"
#include "System/Window/Flags/WindowDisplayFlags.h"
#include "Framework/WindowProcess/MouseTypes.h"

#include <boost/noncopyable.hpp>

EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Framework
{
	class VirtualKeysTypes;
	class WindowSize;
	class WindowPoint;

	class  FRAMEWORK_DEFAULT_DECLARE MiddleLayerInterface : private boost::noncopyable
	{
	public:
		using ClassType = MiddleLayerInterface;
		using WindowDisplayFlags = System::WindowDisplay;

	public:
		MiddleLayerInterface();
		virtual ~MiddleLayerInterface();
		
		CLASS_INVARIANT_VIRTUAL_DECLARE; 

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
		virtual bool Paint();
		virtual bool Move(const WindowPoint& point);
		virtual bool Resize(WindowDisplayFlags type,const WindowSize& size);
		virtual bool KeyDown(uint8_t key,const WindowPoint& point);
	    virtual bool KeyUp(uint8_t key, const WindowPoint& point);
		virtual bool SpecialKeyDown (int key, const WindowPoint& point);
		virtual bool SpecialKeyUp (int key, const WindowPoint& point);
		virtual bool MouseClick(MouseButtonsTypes button,MouseStateTypes state,const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Motion(const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool PassiveMotion(const WindowPoint& point);
		virtual bool MouseWheel(int delta,const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

	protected:
		template <typename SmartPointer,typename Subclass, typename Function>
		const SmartPointer GetSmartPointer(Subclass* subClass, Function function);

		template <typename ConstSmartPointer,typename Subclass, typename Function>
		const ConstSmartPointer GetConstSmartPointer(Subclass* subClass, Function function) const;
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(First,MiddleLayerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H

