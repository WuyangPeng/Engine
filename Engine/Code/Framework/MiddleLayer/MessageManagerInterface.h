// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:49)

#ifndef FRAMEWORK_MIDDLE_LAYER_MESSSAGE_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_MESSSAGE_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

#include <boost/shared_ptr.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// ��Ϣ���Ƴ�������Ϸ�����Լ���Ϸ����ϵͳ֮���ͨ�š�
	class FRAMEWORK_DEFAULT_DECLARE MessageManagerInterface : public EngineMiddleLayerInterface
	{
	public:
		using MessageManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(MessageManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		MessageManagerInterface();
		virtual ~MessageManagerInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

	private:
		IMPL_TYPE_DECLARE(MessageManagerInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, MessageManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_MESSSAGE_MANAGER_INTERFACE_H

