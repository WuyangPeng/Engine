/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:58)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_SYSTEMS_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_SYSTEMS_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE CameraSystemsManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using CameraSystemsManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(CameraSystemsManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        CameraSystemsManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

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

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Rendering)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(GUI)

    private:
        PackageType impl;
    };

    using CameraSystemsManagerInterfaceSharedPtr = std::shared_ptr<CameraSystemsManagerInterface>;
    using ConstCameraSystemsManagerInterfaceSharedPtr = std::shared_ptr<const CameraSystemsManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CAMERA_SYSTEMS_MANAGER_INTERFACE_H
