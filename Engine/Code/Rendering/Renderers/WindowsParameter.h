///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/05 16:01)

#ifndef RENDERING_RENDERERS_WINDOWS_PARAMETER_H
#define RENDERING_RENDERERS_WINDOWS_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"

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

#endif  // RENDERING_RENDERERS_WINDOWS_PARAMETER_H
