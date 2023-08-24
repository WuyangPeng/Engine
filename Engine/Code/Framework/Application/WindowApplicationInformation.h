///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 14:20)

#ifndef FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H
#define FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"
#include "Framework/WindowRegister/WindowName.h"
#include "Framework/WindowRegister/WindowPictorial.h"

FRAMEWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(WindowApplicationInformation, WindowApplicationInformationImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowApplicationInformation
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(WindowApplicationInformation);

        using String = System::String;
        using WindowStyles = System::WindowsStyles;
        using WindowsHInstance = System::WindowsHInstance;
        using RendererParameter = Rendering::RendererParameter;

    public:
        WindowApplicationInformation(const String& windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize);
        WindowApplicationInformation(const String& windowTitle, const WindowSize& size);
        WindowApplicationInformation(WindowsHInstance instance, const RendererParameter& rendererParameter);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetWindowTitle() const;
        NODISCARD std::string GetWindowTitleWithMultiByte() const;
        NODISCARD int GetXPosition() const noexcept;
        NODISCARD int GetYPosition() const noexcept;
        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD WindowSize GetWindowSize() const noexcept;
        NODISCARD float GetAspectRatio() const noexcept;
        NODISCARD WindowStyles GetStyle() const noexcept;

        void SetWindowSize(const WindowSize& size);

        NODISCARD WindowName GetWindowName() const noexcept;
        NODISCARD WindowPictorial GetWindowPictorial() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H
