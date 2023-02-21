///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 11:29)

#include "Framework/FrameworkExport.h"

#include "ObjectMotion.h"
#include "Detail/ObjectMotionImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::ObjectMotion::ObjectMotion(const SpatialSharedPtr& motionObject)
    : impl{ motionObject }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ObjectMotion)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, ObjectMotion, MoveObject, float, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, ObjectMotion, RotateTrackBall, ConstCameraSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetDoRoll, int, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetDoYaw, int, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetDoPitch, int, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetTrackBallDow, bool, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ObjectMotion, GetTrackBallDow, bool);

void Framework::ObjectMotion::SetBeginTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetBeginTrack(xTrack, yTrack);
}

void Framework::ObjectMotion::SetEndTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetEndTrack(xTrack, yTrack);
}

void Framework::ObjectMotion::SetSaveRotate() noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetSaveRotate();
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ObjectMotion, GetMotionObjectLocalTransform, Framework::ObjectMotion::Transform);
