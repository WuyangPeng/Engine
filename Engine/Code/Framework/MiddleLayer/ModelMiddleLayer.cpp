///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 13:48)

#include "Framework/FrameworkExport.h"

#include "ModelMiddleLayer.h"
#include "Flags/MiddleLayerPlatformFlags.h"
#include "Detail/ModelMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::move;
using std::string;

namespace Framework
{
    constexpr auto defaultMaxTimer = 30;
}

Framework::ModelMiddleLayer::ModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ defaultMaxTimer }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelMiddleLayer::ModelMiddleLayer(ModelMiddleLayer&& rhs) noexcept
    : ParentType{ move(rhs) }, impl{ move(rhs.impl) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelMiddleLayer& Framework::ModelMiddleLayer::operator=(ModelMiddleLayer&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(move(rhs));

    impl = move(rhs.impl);

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelMiddleLayer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, GetFrameRate, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, GetFrameRateMessage, string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, ResetTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, MeasureTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, UpdateFrameCount, void)

bool Framework::ModelMiddleLayer::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

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

bool Framework::ModelMiddleLayer::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Paint();
}

bool Framework::ModelMiddleLayer::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Move(point);
}

bool Framework::ModelMiddleLayer::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::ModelMiddleLayer::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyUp(key, point);
}

bool Framework::ModelMiddleLayer::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyDown(key, point);
}

bool Framework::ModelMiddleLayer::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::ModelMiddleLayer::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::ModelMiddleLayer::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::PassiveMotion(point);
}

bool Framework::ModelMiddleLayer::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::ModelMiddleLayer::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::ModelMiddleLayer::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
