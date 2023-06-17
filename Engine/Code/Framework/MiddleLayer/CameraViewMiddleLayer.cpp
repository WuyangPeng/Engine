///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:25)

#include "Framework/FrameworkExport.h"

#include "CameraViewMiddleLayer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/Renderer.h"
#include "Framework/WindowCreate/WindowSize.h"

using namespace std::literals;

Framework::CameraViewMiddleLayer::CameraViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, multiplier{ 0.0f }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraViewMiddleLayer)

void Framework::CameraViewMiddleLayer::SetCamera(const CameraSmartPointer& camera)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto renderer = GetRenderer();

    if (renderer)
    {
        renderer->SetCamera(camera);
    }
}

Framework::WindowSize Framework::CameraViewMiddleLayer::GetWindowSize() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    auto renderer = GetRenderer();

    if (renderer)
    {
        const auto width = renderer->GetWidth();
        const auto height = renderer->GetHeight();

        return WindowSize{ width, height };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("渲染器不存在！"s));
    }
}

bool Framework::CameraViewMiddleLayer::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    if (ParentType::Resize(windowDisplay, size))
    {
        const auto width = size.GetWindowWidth();
        const auto height = size.GetWindowHeight();

        const auto minValue = std::min(height, width);

        if (0 < minValue)
        {
            multiplier = 1.0f / minValue;
        }

        return true;
    }
    else
    {
        return false;
    }
}

float Framework::CameraViewMiddleLayer::GetXTrack(int x) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    auto renderer = GetRenderer();

    if (renderer != nullptr)
    {
        const auto width = renderer->GetWidth();

        return (2 * x - width) * multiplier;
    }
    else
    {
        return 0.0f;
    }
}

float Framework::CameraViewMiddleLayer::GetYTrack(int y) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    auto renderer = GetRenderer();

    if (renderer != nullptr)
    {
        const auto height = renderer->GetHeight();

        return (2 * (height - 1 - y) - height) * multiplier;
    }
    else
    {
        return 0.0f;
    }
}
