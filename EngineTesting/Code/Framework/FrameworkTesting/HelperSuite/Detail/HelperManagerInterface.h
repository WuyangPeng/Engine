// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.1 (2020/05/27 0:08)

#ifndef FRAMEWORK_HELPER_SUITE_HELPER_MANAGER_INTERFACE_H
#define FRAMEWORK_HELPER_SUITE_HELPER_MANAGER_INTERFACE_H

#include "Framework/Helper/MiddleLayerMacro.h"
#include "Framework/MiddleLayer/EngineMiddleLayerInterface.h"  

namespace Framework
{ 
	class HelperManagerInterfaceImpl;
	enum class HelperMiddleLayer;

	class HelperManagerInterface : public EngineMiddleLayerInterface
	{
	public:		 
		NON_COPY_CLASSES_TYPE_DECLARE(HelperManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		explicit HelperManagerInterface(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_OVERRIDE_DECLARE; 

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Event);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Resource);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Audio);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(CameraSystems);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Rendering);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Engine); 

	public:
		// ����protected�ӿ�Ϊpublic���Թ����ԡ�
		const ConstMiddleLayerInterfaceSharedPtr GetManager(HelperMiddleLayer helperMiddleLayer) const;

	private:
		IMPL_TYPE_DECLARE(HelperManagerInterface);
	}; 
}

#endif // FRAMEWORK_HELPER_SUITE_HELPER_MANAGER_INTERFACE_H

