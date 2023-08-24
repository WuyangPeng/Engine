///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 16:19)

#ifndef FRAMEWORK_MIDDLE_LAYER_AUDIO_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_AUDIO_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

// 音频管理（音效处理过程，包括简单的音频回放以及空间定位功能）。
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE AudioManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using AudioManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(AudioManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        AudioManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

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

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Resource)

    private:
        PackageType impl;
    };

    using AudioManagerInterfaceSharedPtr = std::shared_ptr<AudioManagerInterface>;
    using ConstAudioManagerInterfaceSharedPtr = std::shared_ptr<const AudioManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_AUDIO_MANAGER_INTERFACE_H
