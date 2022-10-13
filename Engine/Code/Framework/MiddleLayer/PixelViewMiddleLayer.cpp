///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 13:53)

#include "Framework/FrameworkExport.h"

#include "PixelViewMiddleLayer.h"
#include "Detail/PixelViewMiddleLayerImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Renderers/Renderer.h"
#include "Framework/WindowCreate/WindowSize.h"

using std::make_shared;
using std::move;

namespace Framework
{
    static constexpr auto defaultWidth = 1024;
    static constexpr auto defaultHeight = 768;
}

Framework::PixelViewMiddleLayer::PixelViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ defaultWidth, defaultHeight }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::PixelViewMiddleLayer::PixelViewMiddleLayer(PixelViewMiddleLayer&& rhs) noexcept
    : ParentType{ move(rhs) }, impl{ move(rhs.impl) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::PixelViewMiddleLayer& Framework::PixelViewMiddleLayer::operator=(PixelViewMiddleLayer&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(move(rhs));

    impl = move(rhs.impl);

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, PixelViewMiddleLayer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelViewMiddleLayer, IsDoFlip, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, PixelViewMiddleLayer, DoFlip, bool, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelViewMiddleLayer, GetScreenWidth, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelViewMiddleLayer, GetScreenHeight, int);

bool Framework::PixelViewMiddleLayer::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Initialize())
    {
        auto renderer = GetRenderer();

        const WindowSize windowSize{ renderer->GetWidth(), renderer->GetHeight() };

        impl->Resize(windowSize, GetClearColor());

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::PixelViewMiddleLayer::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto renderer = GetRenderer();

    if (ParentType::Idle(timeDelta) && renderer)
    {
        if (renderer->PreDraw())
        {
            renderer->ClearBuffers();
            impl->Draw(renderer);
            ScreenOverlay();
            renderer->PostDraw();
            renderer->DisplayColorBuffer();
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::PixelViewMiddleLayer::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto width = size.GetWindowWidth();
    const auto height = size.GetWindowHeight();
    auto renderer = GetRenderer();

    if (ParentType::Resize(windowDisplay, size))
    {
        if (0 < width * height && renderer)
        {
            renderer->Resize(width, height);

            const auto colour = GetClearColor();

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
    FRAMEWORK_CLASS_IS_VALID_1;

    // 存根在派生类。
    CoreTools::DisableNoexcept();
}

void Framework::PixelViewMiddleLayer::ClearScreen()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto colour = GetClearColor();

    return impl->ClearScreen(colour);
}

void Framework::PixelViewMiddleLayer::SetPixel(int x, int y, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetPixel(x, y, colour);
}

void Framework::PixelViewMiddleLayer::SetThickPixel(int x, int y, int thick, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetThickPixel(x, y, thick, colour);
}

Framework::PixelViewMiddleLayer::Colour Framework::PixelViewMiddleLayer::GetPixel(int x, int y) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetPixel(x, y);
}

void Framework::PixelViewMiddleLayer::DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->DrawLine(xMin, yMin, xMax, yMax, colour);
}

void Framework::PixelViewMiddleLayer::DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->DrawRectangle(xMin, yMin, xMax, yMax, colour, solid);
}

void Framework::PixelViewMiddleLayer::DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->DrawCircle(xCenter, yCenter, radius, colour, solid);
}

void Framework::PixelViewMiddleLayer::Fill(int x, int y, const Colour& foreColour, const Colour& backColour)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->Fill(x, y, foreColour, backColour);
}
