///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:17)

#include "Framework/FrameworkExport.h"

#include "PixelViewMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/PixelScreen.h"
#include "Framework/WindowCreate/WindowSize.h"

Framework::PixelViewMiddleLayerImpl::PixelViewMiddleLayerImpl(int width, int height)
    : pixelScreen{ WindowSize{ width, height } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, PixelViewMiddleLayerImpl)

void Framework::PixelViewMiddleLayerImpl::Resize(const WindowSize& windowSize, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    pixelScreen.Resize(windowSize, colour);
}

void Framework::PixelViewMiddleLayerImpl::ClearScreen(const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    pixelScreen.ClearScreen(colour);
}

void Framework::PixelViewMiddleLayerImpl::DoFlip(bool doFlip)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return pixelScreen.DoFlip(doFlip);
}

bool Framework::PixelViewMiddleLayerImpl::IsDoFlip() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return pixelScreen.IsDoFlip();
}

void Framework::PixelViewMiddleLayerImpl::SetPixel(int x, int y, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return pixelScreen.SetPixel(x, y, colour);
}

void Framework::PixelViewMiddleLayerImpl::SetThickPixel(int x, int y, int thick, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return pixelScreen.SetThickPixel(x, y, thick, colour);
}

Framework::PixelViewMiddleLayerImpl::Colour Framework::PixelViewMiddleLayerImpl::GetPixel(int x, int y) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return pixelScreen.GetPixel(x, y);
}

void Framework::PixelViewMiddleLayerImpl::DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return pixelScreen.DrawLine(xMin, yMin, xMax, yMax, colour);
}

void Framework::PixelViewMiddleLayerImpl::DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return pixelScreen.DrawRectangle(xMin, yMin, xMax, yMax, colour, solid);
}

void Framework::PixelViewMiddleLayerImpl::DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return pixelScreen.DrawCircle(xCenter, yCenter, radius, colour, solid);
}

void Framework::PixelViewMiddleLayerImpl::Fill(int x, int y, const Colour& foreColour, const Colour& backColour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return pixelScreen.Fill(x, y, foreColour, backColour);
}

void Framework::PixelViewMiddleLayerImpl::Draw(const RendererSharedPtr& renderer)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return pixelScreen.Draw(renderer);
}

int Framework::PixelViewMiddleLayerImpl::GetScreenWidth() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return pixelScreen.GetScreenWidth();
}

int Framework::PixelViewMiddleLayerImpl::GetScreenHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return pixelScreen.GetScreenHeight();
}
