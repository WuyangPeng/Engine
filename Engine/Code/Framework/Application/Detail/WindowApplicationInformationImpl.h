///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 10:06)

#ifndef FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/Renderers/RenderersFwd.h"
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
        WindowApplicationInformationImpl(const String& windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize);
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

        void SetWindowSize(const WindowSize& aSize) noexcept;

        NODISCARD WindowName GetWindowName() const noexcept;
        NODISCARD WindowPictorial GetWindowPictorial() const noexcept;

    private:
        NODISCARD static WindowPictorial GetWindowPictorial(WindowsHInstance instance, const RendererParameter& rendererParameter);

    private:
        // ���ڲ�����
        String windowTitle;
        WindowSize size;
        WindowPoint position;
        WindowsStyles style;
        WindowName windowName;
        WindowPictorial windowPictorial;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H
