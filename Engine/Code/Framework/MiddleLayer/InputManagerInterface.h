// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// ��ҿ��ƣ���������Ӳ������ת��Ϊ��Ϸ���
	class FRAMEWORK_DEFAULT_DECLARE InputManagerInterface : public EngineMiddleLayerInterface
	{
	public:
		using InputManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(InputManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		explicit InputManagerInterface(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// ��Ⱦ�м�㴦��
		bool Paint() final;
		bool Move(const WindowPoint& point) final;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(CameraSystems);

	private:
		IMPL_TYPE_DECLARE(InputManagerInterface);
	};

	using InputManagerInterfaceSharedPtr = std::shared_ptr<InputManagerInterface>;
	using ConstInputManagerInterfaceSharedPtr = std::shared_ptr<const InputManagerInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

