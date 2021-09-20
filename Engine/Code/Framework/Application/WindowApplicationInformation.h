// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:47)

#ifndef FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H
#define FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"
#include "Framework/WindowRegister/WindowName.h"
#include "Framework/WindowRegister/WindowPictorial.h"
FRAMEWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(WindowApplicationInformation,WindowApplicationInformationImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowApplicationInformation
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(WindowApplicationInformation);
        using String = System::String;
        using WindowStyles = System::WindowsStyles;
        using HInstance = System::WindowsHInstance;
        using RendererParameter = Rendering::RendererParameter;

    public:
        WindowApplicationInformation(const String& windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize);
        WindowApplicationInformation(const String& windowTitle, const WindowSize& size);
        WindowApplicationInformation(HInstance instance, const RendererParameter& rendererParameter);

        CLASS_INVARIANT_DECLARE;

        const String GetWindowTitle() const;
        const std::string GetWindowTitleWithMultiByte() const;
        int GetXPosition() const noexcept;
        int GetYPosition() const noexcept;
        int GetWidth() const noexcept;
        int GetHeight() const noexcept;
        const WindowSize GetWindowSize() const noexcept;
        float GetAspectRatio() const noexcept;
        WindowStyles GetStyle() const noexcept;

        void SetWindowSize(const WindowSize& size);

        WindowName GetWindowName() const noexcept;
        WindowPictorial GetWindowPictorial() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H
