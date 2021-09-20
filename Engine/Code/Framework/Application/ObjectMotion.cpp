// Copyright (c) 2010-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "ObjectMotion.h"
#include "Detail/ObjectMotionImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::ObjectMotion ::ObjectMotion(const SpatialSmartPointer& motionObject)
    : impl{ motionObject }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ObjectMotion)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, ObjectMotion, MoveObject, float, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, ObjectMotion, RotateTrackBall, ConstCameraSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetDoRoll, int, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetDoYaw, int, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetDoPitch, int, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetTrackBallDow, bool, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ObjectMotion, GetTrackBallDow, bool);

void Framework::ObjectMotion ::SetBeginTrack(float xTrack, float yTrack) noexcept
{
    ;

    return impl->SetBeginTrack(xTrack, yTrack);
}

void Framework::ObjectMotion ::SetEndTrack(float xTrack, float yTrack) noexcept
{
    ;

    return impl->SetEndTrack(xTrack, yTrack);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ObjectMotion, SetSaveRotate, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ObjectMotion, GetMotionObjectLocalTransform, const Framework::ObjectMotion::Transform);
