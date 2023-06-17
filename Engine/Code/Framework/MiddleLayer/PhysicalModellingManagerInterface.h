///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:22)

#ifndef FRAMEWORK_MIDDLE_LAYER_PHYSICAL_MODELLING_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_PHYSICAL_MODELLING_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
    // ����ģ�⣨��������Ϸ����֮�ϵ�������ѧ����Ч������ѧ��﷽ʽ����������ײ�Լ��ֽ⣩���ƶ������֮���ȫ����Ϸ����
    class FRAMEWORK_DEFAULT_DECLARE PhysicalModellingManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using PhysicalModellingManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(PhysicalModellingManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        PhysicalModellingManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ��Ⱦ�м�㴦��
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

        // ������Ϣ�м�㴦��
        NODISCARD bool KeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // �����Ϣ�м�㴦��
        NODISCARD bool PassiveMotion(const WindowPoint& point) final;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);

    private:
        PackageType impl;
    };

    using PhysicalModellingManagerInterfaceSharedPtr = std::shared_ptr<PhysicalModellingManagerInterface>;
    using ConstPhysicalModellingManagerInterfaceSharedPtr = std::shared_ptr<const PhysicalModellingManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_PHYSICAL_MODELLING_MANAGER_INTERFACE_H
