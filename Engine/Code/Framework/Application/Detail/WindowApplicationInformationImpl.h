/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:22)

#ifndef FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowRegister/WindowName.h"
#include "Framework/WindowRegister/WindowPictorial.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowApplicationInformationImpl
    {
    public:
        using ClassType = WindowApplicationInformationImpl;

        using String = System::String;
        using WindowsStyles = System::WindowsStyles;
        using WindowsHInstance = System::WindowsHInstance;
        using RendererParameter = Rendering::RendererParameter;

    public:
        WindowApplicationInformationImpl(String windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize);
        WindowApplicationInformationImpl(const String& windowTitle, const WindowSize& size);
        WindowApplicationInformationImpl(WindowsHInstance instance, const RendererParameter& rendererParameter);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetWindowTitle() const;
        NODISCARD std::string GetWindowTitleWithMultiByte() const;
        NODISCARD int GetXPosition() const noexcept;
        NODISCARD int GetYPosition() const noexcept;
        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD WindowSize GetWindowSize() const noexcept;
        NODISCARD float GetAspectRatio() const noexcept;
        NODISCARD WindowsStyles GetStyle() const noexcept;

        void SetWindowSize(const WindowSize& size) noexcept;

        NODISCARD WindowName GetWindowName() const noexcept;
        NODISCARD WindowPictorial GetWindowPictorial() const noexcept;

    private:
        NODISCARD static WindowPictorial GetWindowPictorial(WindowsHInstance instance, const RendererParameter& rendererParameter);

    private:
        // 窗口参数。
        String windowTitle;
        WindowSize windowSize;
        WindowPoint position;
        WindowsStyles style;
        WindowName windowName;
        WindowPictorial windowPictorial;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H
