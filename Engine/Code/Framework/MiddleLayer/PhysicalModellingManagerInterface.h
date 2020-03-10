// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:53)

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
	// ����ģ�⣨��������Ϸ����֮�ϵ�������ѧ����Ч������ѧ��﷽ʽ����������ײ�Լ��ֽ⣩��
	// �ƶ������֮���ȫ����Ϸ����
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

