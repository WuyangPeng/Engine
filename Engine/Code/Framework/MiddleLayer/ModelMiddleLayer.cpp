// Copyright (c) 2010-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.3.0.1 (2020/05/21 14:55)

#include "Framework/FrameworkExport.h"

#include "ModelMiddleLayer.h"
#include "Flags/MiddleLayerPlatformFlags.h"
#include "Detail/ModelMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::move;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Framework
{
    constexpr auto g_DefaultMaxTimer = 30;
}

Framework::ModelMiddleLayer ::ModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }, impl{ g_DefaultMaxTimer }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelMiddleLayer ::ModelMiddleLayer(ModelMiddleLayer&& rhs) noexcept
    : ParentType{ move(rhs) }, impl{ move(rhs.impl) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelMiddleLayer& Framework::ModelMiddleLayer ::operator=(ModelMiddleLayer&& rhs) noexcept
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

bool Framework::ModelMiddleLayer ::Idle(int64_t timeDelta)
{
    ;

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

bool Framework::ModelMiddleLayer ::Paint()
{
    ;

    return ParentType::Paint();
}

bool Framework::ModelMiddleLayer ::Move(const WindowPoint& point)
{
    ;

    return ParentType::Move(point);
}

bool Framework::ModelMiddleLayer ::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    ;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::ModelMiddleLayer ::KeyUp(int key, const WindowPoint& point)
{
    ;

    return ParentType::KeyUp(key, point);
}

bool Framework::ModelMiddleLayer ::KeyDown(int key, const WindowPoint& point)
{
    ;

    return ParentType::KeyDown(key, point);
}

bool Framework::ModelMiddleLayer ::SpecialKeyUp(int key, const WindowPoint& point)
{
    ;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::ModelMiddleLayer ::SpecialKeyDown(int key, const WindowPoint& point)
{
    ;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::ModelMiddleLayer ::PassiveMotion(const WindowPoint& point)
{
    ;

    return ParentType::PassiveMotion(point);
}

bool Framework::ModelMiddleLayer ::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    ;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::ModelMiddleLayer ::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    ;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::ModelMiddleLayer ::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    ;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}

#include STSTEM_WARNING_POP