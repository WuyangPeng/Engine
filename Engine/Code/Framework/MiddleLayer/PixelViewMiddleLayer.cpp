/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:04)

#include "Framework/FrameworkExport.h"

#include "PixelViewMiddleLayer.h"
#include "Detail/PixelViewMiddleLayerImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Framework/WindowCreate/WindowSize.h"

namespace Framework
{
    static constexpr auto defaultWidth = 1024;
    static constexpr auto defaultHeight = 768;
}

Framework::PixelViewMiddleLayer::PixelViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ defaultWidth, defaultHeight }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, PixelViewMiddleLayer)

bool Framework::PixelViewMiddleLayer::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Initialize())
    {
        const auto renderer = GetRenderer();

        const WindowSize windowSize{ renderer->GetWidth(), renderer->GetHeight() };

        impl->Resize(windowSize, GetClearColour());

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::PixelViewMiddleLayer::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (const auto renderer = GetRenderer();
        ParentType::Idle(timeDelta) && renderer != nullptr)
    {
        renderer->ClearBuffers();
        ScreenOverlay();

        renderer->DisplayColorBuffer(0);

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::PixelViewMiddleLayer::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    const auto width = size.GetWindowWidth();
    const auto height = size.GetWindowHeight();
    const auto renderer = GetRenderer();

    if (ParentType::Resize(windowDisplay, size))
    {
        if (0 < width * height && renderer != nullptr)
        {
            renderer->Resize(width, height);

            const auto colour = GetClearColour();

            impl->Resize(size, colour);
        }

        return true;
    }
    else
    {
        return false;
    }
}

void Framework::PixelViewMiddleLayer::ScreenOverlay()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    // 存根在派生类。
    CoreTools::DisableNoexcept();
}

bool Framework::PixelViewMiddleLayer::IsDoFlip() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsDoFlip();
}

void Framework::PixelViewMiddleLayer::DoFlip(bool doFlip)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->DoFlip(doFlip);
}

int Framework::PixelViewMiddleLayer::GetScreenWidth() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetScreenWidth();
}

int Framework::PixelViewMiddleLayer::GetScreenHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetScreenHeight();
}

void Framework::PixelViewMiddleLayer::ClearScreen()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    const auto colour = GetClearColour();

    return impl->ClearScreen(colour);
}

void Framework::PixelViewMiddleLayer::SetPixel(int x, int y, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetPixel(x, y, colour);
}

void Framework::PixelViewMiddleLayer::SetThickPixel(int x, int y, int thick, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetThickPixel(x, y, thick, colour);
}

Framework::PixelViewMiddleLayer::Colour Framework::PixelViewMiddleLayer::GetPixel(int x, int y) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetPixel(x, y);
}

void Framework::PixelViewMiddleLayer::DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->DrawLine(xMin, yMin, xMax, yMax, colour);
}

void Framework::PixelViewMiddleLayer::DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->DrawRectangle(xMin, yMin, xMax, yMax, colour, solid);
}

void Framework::PixelViewMiddleLayer::DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->DrawCircle(xCenter, yCenter, radius, colour, solid);
}

void Framework::PixelViewMiddleLayer::Fill(int x, int y, const Colour& foreColour, const Colour& backColour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->Fill(x, y, foreColour, backColour);
}
