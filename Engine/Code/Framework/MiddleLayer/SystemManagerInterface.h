// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:54)

#ifndef FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// 任务管理（分配相关任务至多处理器、线程管理等）。
	class FRAMEWORK_DEFAULT_DECLARE SystemManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using SystemManagerInterfaceImpl= EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(SystemManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		SystemManagerInterface();
		virtual ~SystemManagerInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;	

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);		 

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Event);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Resource);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Audio);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(CameraSystems);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Rendering);	
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Engine);

	private:
		IMPL_TYPE_DECLARE(SystemManagerInterface); 
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, SystemManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_INTERFACE_H

