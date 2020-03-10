// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:53)

#ifndef FRAMEWORK_MIDDLE_LAYER_PHYSICAL_MODELLING_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_PHYSICAL_MODELLING_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

#include <boost/shared_ptr.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// 物理模拟（作用于游戏对象之上的物理力学及其效果的数学表达方式，如对象的碰撞以及分解）。
	// 移动除相机之外的全部游戏对象。
	class FRAMEWORK_DEFAULT_DECLARE PhysicalModellingManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using PhysicalModellingManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(PhysicalModellingManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		PhysicalModellingManagerInterface();
		virtual ~PhysicalModellingManagerInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE; 	
		
		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta); 
		
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);

	private:
		IMPL_TYPE_DECLARE(PhysicalModellingManagerInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, PhysicalModellingManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_PHYSICAL_MODELLING_MANAGER_INTERFACE_H

