// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:53)

#ifndef FRAMEWORK_MIDDLE_LAYER_RESOURCE_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_RESOURCE_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// ��Դ�����ڴ�ʹ�á���Ϸ״̬�Ĵ洢��ָ���ģ�͹�������������������ؿ����ݼ��صȣ���
	class FRAMEWORK_DEFAULT_DECLARE ResourceManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using ResourceManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(ResourceManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		ResourceManagerInterface();
		virtual ~ResourceManagerInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Audio);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Rendering);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(GUI);
	
	private:
		IMPL_TYPE_DECLARE(ResourceManagerInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ResourceManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_RESOURCE_MANAGER_INTERFACE_H

