///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 10:58)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
    // 分为两个模块：
    // 游戏对象逻辑模块（该处理过程定义了游戏的博弈机制）
    // 人工智能模块（该机制定义了游戏对象逻辑、自适应性以及针对游戏事件或玩家输入状态的预置或动态反馈）
    // 两个模块执行除相机外的游戏对象逻辑。
    class FRAMEWORK_DEFAULT_DECLARE ObjectLogicManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using ObjectLogicManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(ObjectLogicManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        ObjectLogicManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

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

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(PhysicalModelling);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

    private:
        PackageType impl;
    };

    using ObjectLogicManagerInterfaceSharedPtr = std::shared_ptr<ObjectLogicManagerInterface>;
    using ConstObjectLogicManagerInterfaceSharedPtr = std::shared_ptr<const ObjectLogicManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_INTERFACE_H
