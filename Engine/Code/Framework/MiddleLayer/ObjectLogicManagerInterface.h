// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:50)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// ��Ϊ����ģ�飺
	// ��Ϸ�����߼�ģ�飨�ô�����̶�������Ϸ�Ĳ��Ļ��ƣ�
	// �˹�����ģ�飨�û��ƶ�������Ϸ�����߼�������Ӧ���Լ������Ϸ�¼����������״̬��Ԥ�û�̬������
	// ����ģ��ִ�г���������Ϸ�����߼���
	class FRAMEWORK_DEFAULT_DECLARE ObjectLogicManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using ObjectLogicManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(ObjectLogicManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		explicit ObjectLogicManagerInterface(MiddleLayerPlatform middleLayerPlatform);
	
		CLASS_INVARIANT_OVERRIDE_DECLARE;

		// ��Ⱦ�м�㴦��
		bool Paint() final;
		bool Move(const WindowPoint& point) final;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

		// ������Ϣ�м�㴦��
		bool KeyUp(int key, const WindowPoint& point) final;
		bool KeyDown(int key, const WindowPoint& point) final;
		bool SpecialKeyUp(int key, const WindowPoint& point) final;
		bool SpecialKeyDown(int key, const WindowPoint& point) final;

		// �����Ϣ�м�㴦��
		bool PassiveMotion(const WindowPoint& point) final;
		bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(PhysicalModelling);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

	private:
		IMPL_TYPE_DECLARE(ObjectLogicManagerInterface);
	};

	using ObjectLogicManagerInterfaceSharedPtr = std::shared_ptr<ObjectLogicManagerInterface>;
	using ConstObjectLogicManagerInterfaceSharedPtr = std::shared_ptr<const ObjectLogicManagerInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_INTERFACE_H

