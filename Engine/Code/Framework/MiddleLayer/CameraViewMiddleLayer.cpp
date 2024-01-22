/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:03)

#include "Framework/FrameworkExport.h"

#include "CameraViewMiddleLayer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Framework/WindowCreate/WindowSize.h"

Framework::CameraViewMiddleLayer::CameraViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, multiplier{ 0.0f }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraViewMiddleLayer)

Framework::WindowSize Framework::CameraViewMiddleLayer::GetWindowSize() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (const auto renderer = GetRenderer();
        renderer != nullptr)
    {
        const auto width = renderer->GetWidth();
        const auto height = renderer->GetHeight();

        return WindowSize{ width, height };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("渲染器不存在！"s))
    }
}

bool Framework::CameraViewMiddleLayer::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (ParentType::Resize(windowDisplay, size))
    {
        const auto width = size.GetWindowWidth();
        const auto height = size.GetWindowHeight();

        if (const auto minValue = std::min(width, height);
            0 < minValue)
        {
            multiplier = 1.0f / static_cast<float>(minValue);
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
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (const auto renderer = GetRenderer();
        renderer != nullptr)
    {
        const auto width = renderer->GetWidth();

        return static_cast<float>(2 * x - width) * multiplier;
    }
    else
    {
        return 0.0f;
    }
}

float Framework::CameraViewMiddleLayer::GetYTrack(int y) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (const auto renderer = GetRenderer();
        renderer != nullptr)
    {
        const auto height = renderer->GetHeight();

        return static_cast<float>(2 * (height - 1 - y) - height) * multiplier;
    }
    else
    {
        return 0.0f;
    }
}
