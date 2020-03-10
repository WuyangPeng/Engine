// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:51)

#ifndef FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// ����ӿڡ�
	// ���ⲿʵ����ͨ�ţ����а�����Ϸ��Ӳ���豸��ƥ�����ȡ�
	class FRAMEWORK_DEFAULT_DECLARE NetworkManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using NetworkManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(NetworkManagerInterface);
		using ParentType = EngineMiddleLayerInterface;
		
	public:
		NetworkManagerInterface();
		virtual ~NetworkManagerInterface();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;		 
		
		virtual bool PreCreate();
		virtual bool Create();
		virtual bool Initialize();		
		virtual void Terminate();			
		virtual bool Destroy();
		virtual void PreIdle();
		virtual bool Idle(int64_t timeDelta);	

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic); 

	private:
		IMPL_TYPE_DECLARE(NetworkManagerInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, NetworkManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H

