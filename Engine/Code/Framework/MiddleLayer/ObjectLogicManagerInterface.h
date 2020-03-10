// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:52)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

#include <boost/shared_ptr.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// 分为两个模块：
	// 游戏对象逻辑模块（该处理过程定义了游戏的博弈机制）
	// 人工智能模块（该机制定义了游戏对象逻辑、
	// 自适应性以及针对游戏事件或玩家输入状态的预置或动态反馈）
	// 两个模块执行除相机外的游戏对象逻辑。
	class FRAMEWORK_DEFAULT_DECLARE ObjectLogicManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using ObjectLogicManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(ObjectLogicManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		ObjectLogicManagerInterface();
		virtual ~ObjectLogicManagerInterface();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();		
		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(PhysicalModelling);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

	private:
		IMPL_TYPE_DECLARE(ObjectLogicManagerInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ObjectLogicManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_INTERFACE_H

