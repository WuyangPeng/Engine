/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 15:18)

#ifndef RENDERING_RENDERER_ENGINE_WINDOWS_PARAMETER_H
#define RENDERING_RENDERER_ENGINE_WINDOWS_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/WindowsFwd.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(WindowsParameter, WindowsParameterImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE WindowsParameter
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(WindowsParameter);

        using String = System::String;
        using ColourType = Colour<float>;
        using WindowsBrushTypes = System::WindowsBrushTypes;
        using DisableNotThrow = CoreTools::DisableNotThrow;

    public:
        NODISCARD static WindowsParameter Create();

        CLASS_INVARIANT_DECLARE;

        NODISCARD ColourType GetClearColor() const noexcept;

        NODISCARD std::string GetWindowTitle() const;
        NODISCARD int GetXPosition() const noexcept;
        NODISCARD int GetYPosition() const noexcept;
        NODISCARD bool IsAllowResize() const noexcept;

        void SetClearColor(float red, float green, float blue, float alpha);

        void SetWindowParameter(const std::string& windowTitle, int x, int y, bool allowResize);

        NODISCARD String GetWindowClassName() const;
        void SetWindowClassName(const String& className);

        NODISCARD String GetWindowMenuName() const;
        void SetWindowMenuName(const String& menuName);

        NODISCARD int GetIcon() const noexcept;
        NODISCARD bool IsIconDefault() const noexcept;
        NODISCARD int GetCursor() const noexcept;
        NODISCARD bool IsCursorDefault() const noexcept;
        NODISCARD WindowsBrushTypes GetBackground() const noexcept;

        void SetWindowPictorialParameter(int icon, bool isIconDefault, int cursor, bool isCursorDefault, WindowsBrushTypes background);

    private:
        explicit WindowsParameter(DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_WINDOWS_PARAMETER_H
