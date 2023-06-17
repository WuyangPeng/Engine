///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:36)

#ifndef RENDERING_RENDERERS_WINDOWS_PARAMETER_IMPL_H
#define RENDERING_RENDERERS_WINDOWS_PARAMETER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WindowsParameterImpl
    {
    public:
        using ClassType = WindowsParameterImpl;

        using String = System::String;
        using ColourType = Colour<float>;
        using WindowsBrushTypes = System::WindowsBrushTypes;

    public:
        WindowsParameterImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ColourType GetClearColor() const noexcept;

        NODISCARD std::string GetWindowTitle() const;
        NODISCARD int GetXPosition() const noexcept;
        NODISCARD int GetYPosition() const noexcept;
        NODISCARD bool IsAllowResize() const noexcept;

        void SetClearColor(float red, float green, float blue, float alpha) noexcept;

        void SetWindowParameter(const std::string& aWindowTitle, int x, int y, bool allowResize);

        NODISCARD String GetWindowClassName() const;
        void SetWindowClassName(const String& aClassName);

        NODISCARD String GetWindowMenuName() const;
        void SetWindowMenuName(const String& aMenuName);

        NODISCARD int GetIcon() const noexcept;
        NODISCARD bool IsIconDefault() const noexcept;
        NODISCARD int GetCursor() const noexcept;
        NODISCARD bool IsCursorDefault() const noexcept;
        NODISCARD WindowsBrushTypes GetBackground() const noexcept;

        void SetWindowPictorialParameter(int aIcon, bool aIsIconDefault, int aCursor, bool aIsCursorDefault, WindowsBrushTypes aBackground) noexcept;

    private:
        ColourType colour;
        std::string windowTitle;
        int windowX;
        int windowY;
        bool isAllowResize;
        String className;
        String menuName;
        int icon;
        bool isIconDefault;
        int cursor;
        bool isCursorDefault;
        WindowsBrushTypes background;
    };
}

#endif  // RENDERING_RENDERERS_WINDOWS_PARAMETER_IMPL_H
