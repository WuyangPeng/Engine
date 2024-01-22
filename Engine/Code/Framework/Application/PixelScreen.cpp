/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:28)

#include "Framework/FrameworkExport.h"

#include "PixelScreen.h"
#include "Detail/PixelScreenImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, PixelScreen)

Framework::PixelScreen::PixelScreen(const WindowSize& size)
    : impl{ size }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, PixelScreen)

void Framework::PixelScreen::SetPixel(int x, int y, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetPixel(x, y, colour);
}

void Framework::PixelScreen::SetThickPixel(int x, int y, int thick, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetThickPixel(x, y, thick, colour);
}

Framework::PixelScreen::Colour Framework::PixelScreen::GetPixel(int x, int y) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetPixel(x, y);
}

void Framework::PixelScreen::DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->DrawLine(xMin, yMin, xMax, yMax, colour);
}

void Framework::PixelScreen::DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->DrawRectangle(xMin, yMin, xMax, yMax, colour, solid);
}

void Framework::PixelScreen::DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->DrawCircle(xCenter, yCenter, radius, colour, solid);
}

void Framework::PixelScreen::Fill(int x, int y, const Colour& foreColor, const Colour& backColor)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->Fill(x, y, foreColor, backColor);
}

void Framework::PixelScreen::Resize(const WindowSize& size, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->Resize(size, colour);
}

int Framework::PixelScreen::GetScreenWidth() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetScreenWidth();
}

int Framework::PixelScreen::GetScreenHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetScreenHeight();
}

void Framework::PixelScreen::ClearScreen(const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->ClearScreen(colour);
}

bool Framework::PixelScreen::IsDoFlip() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsDoFlip();
}

void Framework::PixelScreen::DoFlip(bool doFlip)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->DoFlip(doFlip);
}
