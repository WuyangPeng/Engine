// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:52)

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
	// ��Ϊ����ģ�飺
	// ��Ϸ�����߼�ģ�飨�ô�����̶�������Ϸ�Ĳ��Ļ��ƣ�
	// �˹�����ģ�飨�û��ƶ�������Ϸ�����߼���
	// ����Ӧ���Լ������Ϸ�¼����������״̬��Ԥ�û�̬������
	// ����ģ��ִ�г���������Ϸ�����߼���
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

