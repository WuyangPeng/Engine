///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:22)

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
    // 物理模拟（作用于游戏对象之上的物理力学及其效果的数学表达方式，如对象的碰撞以及分解）。移动除相机之外的全部游戏对象。
    class FRAMEWORK_DEFAULT_DECLARE PhysicalModellingManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using PhysicalModellingManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(PhysicalModellingManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        PhysicalModellingManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 渲染中间层处理
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

        // 按键消息中间层处理
        NODISCARD bool KeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // 鼠标消息中间层处理
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
