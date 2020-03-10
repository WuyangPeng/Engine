// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 11:24)

#include "Framework/FrameworkExport.h"

#include "ObjectMotion.h"
#include "Detail/ObjectMotionImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "Rendering/DataTypes/Transform.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"

Framework::ObjectMotion
	::ObjectMotion(const SpatialSmartPointer& motionObject)
	:m_Impl(new ImplType(motionObject))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,ObjectMotion)
#endif // OPEN_CLASS_INVARIANT

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, ObjectMotion,MoveObject, float,bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, ObjectMotion,RotateTrackBall,ConstCameraSmartPointer,void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, ObjectMotion,SetDoRoll, int,void); 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, ObjectMotion,SetDoYaw, int,void); 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, ObjectMotion,SetDoPitch,int,void); 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, ObjectMotion,SetTrackBallDow,bool,void);  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ObjectMotion,GetTrackBallDow, bool); 

void Framework::ObjectMotion
	::SetBeginTrack(float xTrack,float yTrack)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	
	return m_Impl->SetBeginTrack(xTrack,yTrack);
}

void Framework::ObjectMotion
	::SetEndTrack(float xTrack,float yTrack)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	
	return m_Impl->SetEndTrack(xTrack,yTrack);
}


IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ObjectMotion,SetSaveRotate,void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ObjectMotion, GetMotionObjectLocalTransform, const Framework::ObjectMotion::Transform);

 

