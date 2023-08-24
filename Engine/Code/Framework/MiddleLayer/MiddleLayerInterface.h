///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 17:43)

#ifndef FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "MiddleLayerFwd.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"
#include "Framework/WindowProcess/WindowProcessFwd.h"

template class FRAMEWORK_DEFAULT_DECLARE std::weak_ptr<Framework::MiddleLayerInterface>;
template class FRAMEWORK_DEFAULT_DECLARE std::enable_shared_from_this<Framework::MiddleLayerInterface>;

// 中间层接口类，基类提供虚函数的默认实现。
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE MiddleLayerInterface : public std::enable_shared_from_this<MiddleLayerInterface>
    {
    public:
        using ClassType = MiddleLayerInterface;

        using WindowDisplay = System::WindowsDisplay;
        using EnvironmentParameter = Rendering::EnvironmentParameter;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        MiddleLayerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory) noexcept;
        virtual ~MiddleLayerInterface() noexcept = default;

        MiddleLayerInterface(const MiddleLayerInterface& rhs) noexcept = delete;
        MiddleLayerInterface& operator=(const MiddleLayerInterface& rhs) noexcept = delete;
        MiddleLayerInterface(MiddleLayerInterface&& rhs) noexcept;
        MiddleLayerInterface& operator=(MiddleLayerInterface&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 创建窗口中间层处理
        virtual bool PreCreate();
        virtual bool Create(const EnvironmentParameter& environmentParameter);
        virtual bool Initialize();

        // 销毁窗口中间层处理
        virtual bool Destroy();
        virtual void Terminate();

        // 空闲时间中间层处理
        virtual void PreIdle();
        virtual bool Idle(int64_t timeDelta);

        // 渲染中间层处理
        virtual bool Paint();
        virtual bool Move(const WindowPoint& point);
        virtual bool Resize(WindowDisplay windowDisplay, const WindowSize& size);

        // 按键消息中间层处理
        virtual bool KeyUp(int key, const WindowPoint& point);
        virtual bool KeyDown(int key, const WindowPoint& point);
        virtual bool SpecialKeyUp(int key, const WindowPoint& point);
        virtual bool SpecialKeyDown(int key, const WindowPoint& point);

        // 鼠标消息中间层处理
        virtual bool PassiveMotion(const WindowPoint& point);
        virtual bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys);
        virtual bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys);
        virtual bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys);

        NODISCARD MiddleLayerPlatform GetMiddleLayerPlatform() const noexcept;
        NODISCARD EnvironmentDirectory GetEnvironmentDirectory() const noexcept;

    protected:
        using MiddleLayerSharedPtr = std::shared_ptr<ClassType>;
        using ConstMiddleLayerSharedPtr = std::shared_ptr<const ClassType>;

    private:
        MiddleLayerPlatform middleLayerPlatform;
        EnvironmentDirectory environmentDirectory;
    };

    using MiddleLayerInterfaceSharedPtr = std::shared_ptr<MiddleLayerInterface>;
    using ConstMiddleLayerInterfaceSharedPtr = std::shared_ptr<const MiddleLayerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H
