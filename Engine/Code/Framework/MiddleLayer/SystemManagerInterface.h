/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 22:55)

#ifndef FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/EngineConfiguration/GlobalConfig.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SharedPtrMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(SystemManagerImpl);
FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

// 任务管理（分配相关任务至多处理器、线程管理等）。
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE SystemManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using SystemManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(SystemManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

        using GlobalConfig = CoreTools::GlobalConfig;

    public:
        SystemManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        /// 渲染中间层处理
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

        /// 按键消息中间层处理
        NODISCARD bool KeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) final;

        /// 鼠标消息中间层处理
        NODISCARD bool PassiveMotion(const WindowPoint& point) final;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Event)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Resource)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Audio)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(CameraSystems)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Rendering)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Engine)

        NODISCARD GlobalConfig GetGlobalConfig() const;

        void SendSmtpTransportMessage(const std::string& title, const std::string& content);

    private:
        using SystemPackageType = CoreTools::NonCopyImpl<SystemManagerImpl>;

    private:
        PackageType impl;
        SystemPackageType system;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(SystemManagerInterface);
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_INTERFACE_H
