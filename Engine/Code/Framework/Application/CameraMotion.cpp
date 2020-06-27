// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "CameraMotion.h"
#include "Detail/CameraMotionImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::CameraMotion
	::CameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor)
	:m_Impl{ make_shared<ImplType>(translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, CameraMotion)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion, GetCameraPtr, const Framework::CameraMotion::CameraSmartPointer);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion, MoveCamera, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraMotion, SlowerCameraTranslation, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraMotion, FasterCameraTranslation, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraMotion, SlowerCameraRotation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraMotion, FasterCameraRotation, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetMoveForward, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetMoveBackward, bool, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetTurnLeft, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetTurnRight, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetLookUp, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetLookDown, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetMoveUp, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetMoveDown, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetMoveRight, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraMotion, SetMoveLeft, bool, void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraMotion, GetRotationSpeed, float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraMotion, GetTranslationSpeed, float);