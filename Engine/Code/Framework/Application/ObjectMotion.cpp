// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "ObjectMotion.h"
#include "Detail/ObjectMotionImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::ObjectMotion
	::ObjectMotion(const SpatialSmartPointer& motionObject)
	:m_Impl{ make_shared< ImplType>(motionObject) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, ObjectMotion)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, ObjectMotion, MoveObject, float, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, ObjectMotion, RotateTrackBall, ConstCameraSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetDoRoll, int, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetDoYaw, int, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetDoPitch, int, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, ObjectMotion, SetTrackBallDow, bool, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ObjectMotion, GetTrackBallDow, bool);

void Framework::ObjectMotion
	::SetBeginTrack(float xTrack, float yTrack) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetBeginTrack(xTrack, yTrack);
}

void Framework::ObjectMotion
	::SetEndTrack(float xTrack, float yTrack) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetEndTrack(xTrack, yTrack);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ObjectMotion, SetSaveRotate, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ObjectMotion, GetMotionObjectLocalTransform, const Framework::ObjectMotion::Transform);



