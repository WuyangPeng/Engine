// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:06)

#include "Framework/FrameworkExport.h"
 
#include "CameraModelMiddleLayer.h"
#include "Detail/CameraModelMiddleLayerImpl.h"
#include "CameraViewMiddleLayer.h" 
#include "MiddleLayerInterfaceDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "System/Time/Using/DeltaTimeUsing.h"

Framework::CameraModelMiddleLayer
	::CameraModelMiddleLayer()
	:ParentType{}, m_Impl(new ImplType), m_TimeDelta(System::g_Microseconds)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::CameraModelMiddleLayer
	::~CameraModelMiddleLayer()	
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework,CameraModelMiddleLayer)

bool Framework::CameraModelMiddleLayer
	::Initialize()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if(ParentType::Initialize())
	{
		const float speed = 0.01f;
		const float speedFactor = 2.0f;

		InitializeCameraMotion(speed, speed, speedFactor, speedFactor);
		
		InitializeObjectMotion();	

		CameraViewMiddleLayerSmartPointer cameraViewMiddleLayer = GetSmartPointer<CameraViewMiddleLayerSmartPointer>(this, &ClassType::GetViewMiddleLayer);

		Rendering::ConstCameraSmartPointer camera = m_Impl->GetCamera();

		if (cameraViewMiddleLayer.IsValidPtr() && camera.IsValidPtr())
		{
			cameraViewMiddleLayer->SetCamera(camera);
		}			
	
		return true;
	}
	else
	{
		return false;
	}
}

void Framework::CameraModelMiddleLayer
	::Terminate()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	CameraViewMiddleLayerSmartPointer cameraViewMiddleLayer = GetSmartPointer<CameraViewMiddleLayerSmartPointer>(this, &ClassType::GetViewMiddleLayer);

	if (cameraViewMiddleLayer.IsValidPtr())
	{
		cameraViewMiddleLayer->SetCamera(Rendering::ConstCameraSmartPointer());
	}		

	m_Impl->Terminate();
}

bool Framework::CameraModelMiddleLayer
	::Idle(int64_t timeDelta)
{
	if (ParentType::Idle(timeDelta))
	{
		m_TimeDelta -= timeDelta;
		if (m_TimeDelta <= 0)
		{
			MoveCamera();
			MoveObject();

			m_TimeDelta += System::g_Microseconds;
		}

		return true;
	}
	else
	{
		return false;
	}
	
}

void Framework::CameraModelMiddleLayer
	::InitializeCameraMotion( float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->InitializeCameraMotion(translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor);
}

void Framework::CameraModelMiddleLayer
	::InitializeObjectMotion()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->InitializeObjectMotion();
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, MoveCamera, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, SlowerCameraTranslation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, FasterCameraTranslation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, SlowerCameraRotation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, FasterCameraRotation, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetMoveForward, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetMoveBackward, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetTurnLeft, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetTurnRight, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetLookUp, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetLookDown, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetMoveUp, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetMoveDown, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetMoveRight, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetMoveLeft, bool, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, MoveObject, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, RotateTrackBall, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetTrackBallDow, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, SetSaveRotate, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetDoRoll, Mathematics::NumericalValueSymbol, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetDoYaw, Mathematics::NumericalValueSymbol, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, CameraModelMiddleLayer, SetDoPitch, Mathematics::NumericalValueSymbol, void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetTrackBallDow, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraPosition, const Framework::CameraModelMiddleLayer::APoint);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraDirectionVector, const Framework::CameraModelMiddleLayer::AVector);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraUpVector, const Framework::CameraModelMiddleLayer::AVector);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraRightVector, const Framework::CameraModelMiddleLayer::AVector);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetRotationSpeed, float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetTranslationSpeed, float); 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetMotionObjectLocalTransform, const Framework::CameraModelMiddleLayer::Transform);

void Framework::CameraModelMiddleLayer
	::SetBeginTrack(float xTrack, float yTrack)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetBeginTrack(xTrack, yTrack);
}
 
void Framework::CameraModelMiddleLayer
	::SetEndTrack(float xTrack, float yTrack)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetEndTrack(xTrack, yTrack);
}


 
 

 