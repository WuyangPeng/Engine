/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:59)

#ifndef FRAMEWORK_MIDDLE_LAYER_GUI_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_GUI_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE GUIManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using GUIManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(GUIManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        GUIManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

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

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Rendering)

    private:
        PackageType impl;
    };

    using GUIManagerInterfaceSharedPtr = std::shared_ptr<GUIManagerInterface>;
    using ConstGUIManagerInterfaceSharedPtr = std::shared_ptr<const GUIManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_GUI_MANAGER_INTERFACE_H
