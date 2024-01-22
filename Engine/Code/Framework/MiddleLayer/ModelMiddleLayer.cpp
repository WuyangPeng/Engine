/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:03)

#include "Framework/FrameworkExport.h"

#include "ModelMiddleLayer.h"
#include "Flags/MiddleLayerPlatformFlags.h"
#include "Detail/ModelMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

namespace Framework
{
    constexpr auto defaultMaxTimer = 30;
}

Framework::ModelMiddleLayer::ModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ defaultMaxTimer }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelMiddleLayer)

bool Framework::ModelMiddleLayer::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Idle(timeDelta))
    {
        impl->MeasureTime();

        return true;
    }
    else
    {
        return false;
    }
}

double Framework::ModelMiddleLayer::GetFrameRate() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetFrameRate();
}

std::string Framework::ModelMiddleLayer::GetFrameRateMessage() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetFrameRateMessage();
}

void Framework::ModelMiddleLayer::ResetTime()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->ResetTime();
}

void Framework::ModelMiddleLayer::MeasureTime()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->MeasureTime();
}

void Framework::ModelMiddleLayer::UpdateFrameCount()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->UpdateFrameCount();
}

bool Framework::ModelMiddleLayer::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Paint();
}

bool Framework::ModelMiddleLayer::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Move(point);
}

bool Framework::ModelMiddleLayer::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::ModelMiddleLayer::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyUp(key, point);
}

bool Framework::ModelMiddleLayer::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyDown(key, point);
}

bool Framework::ModelMiddleLayer::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::ModelMiddleLayer::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::ModelMiddleLayer::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::PassiveMotion(point);
}

bool Framework::ModelMiddleLayer::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::ModelMiddleLayer::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::ModelMiddleLayer::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
