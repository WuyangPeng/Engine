// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:21)

#include "Framework/FrameworkExport.h"

#include "CameraMotion.h"
#include "Detail/CameraMotionImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::CameraMotion
	::CameraMotion(float translationSpeed, float rotationSpeed,float translationSpeedFactor, float rotationSpeedFactor)
	:m_Impl(new ImplType(translationSpeed, rotationSpeed,translationSpeedFactor, rotationSpeedFactor)) 
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,CameraMotion)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion,GetCameraPtr,const Framework::CameraMotion::ConstCameraSmartPointer);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion, MoveCamera, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion,SlowerCameraTranslation, void); 

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion,FasterCameraTranslation, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion,SlowerCameraRotation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion,FasterCameraRotation, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetMoveForward, bool ,void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetMoveBackward, bool ,void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetTurnLeft, bool ,void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetTurnRight, bool ,void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetLookUp, bool ,void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetLookDown, bool ,void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetMoveUp, bool ,void); 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetMoveDown, bool ,void); 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetMoveRight, bool ,void); 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraMotion,SetMoveLeft, bool ,void); 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion,GetRotationSpeed, float);  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraMotion,GetTranslationSpeed,float);  