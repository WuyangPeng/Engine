// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// 玩家控制
	// 将控制器硬件数据转换为游戏命令。
	class FRAMEWORK_DEFAULT_DECLARE InputManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using InputManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(InputManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		InputManagerInterface();
		virtual ~InputManagerInterface();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;	
	
		// 输入，处理玩家输入以及对应的游戏对象效果。
		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
 
		virtual bool Move(const WindowPoint& point);
		virtual bool Resize(WindowDisplayFlags type, const WindowSize& size);
		virtual bool KeyDown(uint8_t key, const WindowPoint& point);
		virtual bool KeyUp(uint8_t key, const WindowPoint& point);
		virtual bool SpecialKeyDown(int key, const WindowPoint& point);
		virtual bool SpecialKeyUp(int key, const WindowPoint& point);
		virtual bool MouseClick(MouseButtonsTypes button, MouseStateTypes state,const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes);
		virtual bool PassiveMotion(const WindowPoint& point);
		virtual bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);
	 
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(CameraSystems);
	 
	private:	
		IMPL_TYPE_DECLARE(InputManagerInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, InputManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

