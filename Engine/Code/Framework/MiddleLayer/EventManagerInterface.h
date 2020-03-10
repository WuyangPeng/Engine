// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_EVENT_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_EVENT_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// 游戏事件管理（针对游戏元素中设计者所规定的操作序列进行管理）。
	class FRAMEWORK_DEFAULT_DECLARE EventManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using EventManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(EventManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		EventManagerInterface();
		virtual ~EventManagerInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

	private:
		IMPL_TYPE_DECLARE(EventManagerInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, EventManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_EVENT_MANAGER_INTERFACE_H

