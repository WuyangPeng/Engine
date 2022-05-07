///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 17:03)

#ifndef FRAMEWORK_MIDDLE_LAYER_MESSSAGE_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_MESSSAGE_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
    // 消息机制常用于游戏对象以及游戏管理系统之间的通信。
    class FRAMEWORK_DEFAULT_DECLARE MessageManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using MessageManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(MessageManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        explicit MessageManagerInterface(MiddleLayerPlatform middleLayerPlatform);

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
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

    private:
        PackageType impl;
    };

    using MessageManagerInterfaceSharedPtr = std::shared_ptr<MessageManagerInterface>;
    using ConstMessageManagerInterfaceSharedPtr = std::shared_ptr<const MessageManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MESSSAGE_MANAGER_INTERFACE_H
