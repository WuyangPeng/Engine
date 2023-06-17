///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:50)

#include "Framework/FrameworkExport.h"

#include "PixelScreen.h"
#include "Detail/PixelScreenImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Framework/WindowCreate/WindowSize.h"

Framework::PixelScreen::PixelScreen(const WindowSize& size)
    : impl{ size }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, PixelScreen)

COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, PixelScreen)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelScreen, GetScreenWidth, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelScreen, GetScreenHeight, int);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, PixelScreen, Draw, RendererSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, PixelScreen, ClearScreen, Colour, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, PixelScreen, DoFlip, bool, void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelScreen, IsDoFlip, bool);

void Framework::PixelScreen::SetPixel(int x, int y, const Colour& color)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetPixel(x, y, color);
}

void Framework::PixelScreen::SetThickPixel(int x, int y, int thick, const Colour& color)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetThickPixel(x, y, thick, color);
}

Framework::PixelScreen::Colour Framework::PixelScreen::GetPixel(int x, int y) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetPixel(x, y);
}

void Framework::PixelScreen::DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& color)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->DrawLine(xMin, yMin, xMax, yMax, color);
}

void Framework::PixelScreen::DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& color, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->DrawRectangle(xMin, yMin, xMax, yMax, color, solid);
}

void Framework::PixelScreen::DrawCircle(int xCenter, int yCenter, int radius, const Colour& color, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->DrawCircle(xCenter, yCenter, radius, color, solid);
}

void Framework::PixelScreen::Fill(int x, int y, const Colour& foreColor, const Colour& backColor)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->Fill(x, y, foreColor, backColor);
}

void Framework::PixelScreen::Resize(const WindowSize& size, const Colour& color)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->Resize(size, color);
}
