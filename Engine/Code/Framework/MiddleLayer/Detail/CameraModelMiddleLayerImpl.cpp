// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:04)

#include "Framework/FrameworkExport.h"
 
#include "CameraModelMiddleLayerImpl.h" 
#include "Rendering/SceneGraph/Node.h" 
#include "Rendering/SceneGraph/Camera.h"
#include "Framework/Application/CameraMotion.h"
#include "Framework/Application/ObjectMotion.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::CameraModelMiddleLayerImpl
	::CameraModelMiddleLayerImpl()
	:m_CameraMotion(),m_ObjectMotion()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::CameraModelMiddleLayerImpl
	::~CameraModelMiddleLayerImpl()	
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, CameraModelMiddleLayerImpl) 

void Framework::CameraModelMiddleLayerImpl
	::InitializeCameraMotion( float translationSpeed,  float rotationSpeed,float translationSpeedFactor,float rotationSpeedFactor )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_CameraMotion.reset(new CameraMotion(translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor));
}

void Framework::CameraModelMiddleLayerImpl
	::InitializeObjectMotion()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	Rendering::SpatialSmartPointer spatial(NEW0 Rendering::Node);
	m_ObjectMotion.reset(new ObjectMotion(spatial));
}

bool Framework::CameraModelMiddleLayerImpl
	::MoveCamera()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		return m_CameraMotion->MoveCamera();
	}
	else
	{
		return false;
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SlowerCameraTranslation ()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SlowerCameraTranslation();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::FasterCameraTranslation ()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->FasterCameraTranslation();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SlowerCameraRotation ()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SlowerCameraRotation();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::FasterCameraRotation ()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->FasterCameraRotation();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveForward(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveForward(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveBackward(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveBackward(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetTurnLeft(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetTurnLeft(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetTurnRight(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetTurnRight(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetLookUp(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetLookUp(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetLookDown(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetLookDown(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveUp(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveUp(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveDown(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveDown(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveRight(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveRight(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveLeft(bool pressed)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveLeft(pressed);
	}
}

bool Framework::CameraModelMiddleLayerImpl
	::MoveObject()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_ObjectMotion != nullptr && m_CameraMotion != nullptr)
	{
		float rotationSpeed = m_CameraMotion->GetRotationSpeed();

		return m_ObjectMotion->MoveObject(rotationSpeed);	
	}
	else
	{
		return false;
	}
}

void Framework::CameraModelMiddleLayerImpl
	::RotateTrackBall()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_ObjectMotion != nullptr && m_CameraMotion != nullptr)
	{
		Rendering::ConstCameraSmartPointer camera = m_CameraMotion->GetCameraPtr();

		m_ObjectMotion->RotateTrackBall(camera);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetTrackBallDow( bool value )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetTrackBallDow(value);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetSaveRotate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetSaveRotate();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetDoRoll( Mathematics::NumericalValueSymbol doRoll )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetDoRoll(System::EnumCastUnderlying(doRoll));		
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetDoYaw( Mathematics::NumericalValueSymbol doYaw )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetDoYaw(System::EnumCastUnderlying(doYaw));
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetDoPitch( Mathematics::NumericalValueSymbol doPitch )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetDoPitch(System::EnumCastUnderlying(doPitch));
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetBeginTrack( float xTrack,float yTrack )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetBeginTrack(xTrack,yTrack);
	}		
}

void Framework::CameraModelMiddleLayerImpl
	::SetEndTrack( float xTrack,float yTrack )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetEndTrack(xTrack,yTrack);
	}
}

bool Framework::CameraModelMiddleLayerImpl
	::GetTrackBallDow() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if(m_ObjectMotion != nullptr)
	{
		return m_ObjectMotion->GetTrackBallDow();
	}
	else
	{
		return false;
	}
}

Framework::CameraModelMiddleLayerImpl::ConstCameraSmartPointer Framework::CameraModelMiddleLayerImpl
	::GetCamera() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if (m_CameraMotion != nullptr)
	{
		return m_CameraMotion->GetCameraPtr();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"));
	}	
}

void Framework::CameraModelMiddleLayerImpl
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_CameraMotion.reset();
	m_ObjectMotion.reset();
}

const Framework::CameraModelMiddleLayerImpl::APoint Framework::CameraModelMiddleLayerImpl
	::GetCameraPosition() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	ConstCameraSmartPointer camera = GetCamera();
	 
	return camera->GetPosition();	 
}

const Framework::CameraModelMiddleLayerImpl::AVector Framework::CameraModelMiddleLayerImpl
	::GetCameraDirectionVector() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	ConstCameraSmartPointer camera = GetCamera();

	return camera->GetDirectionVector();
}

const Framework::CameraModelMiddleLayerImpl::AVector Framework::CameraModelMiddleLayerImpl
	::GetCameraUpVector() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	ConstCameraSmartPointer camera = GetCamera();

	return camera->GetUpVector();
}

const Framework::CameraModelMiddleLayerImpl::AVector Framework::CameraModelMiddleLayerImpl
	::GetCameraRightVector() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	ConstCameraSmartPointer camera = GetCamera();

	return camera->GetRightVector();
}

float Framework::CameraModelMiddleLayerImpl
	::GetRotationSpeed() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if (m_CameraMotion != nullptr)
	{
		return m_CameraMotion->GetRotationSpeed();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"));
	}
}

float Framework::CameraModelMiddleLayerImpl
	::GetTranslationSpeed() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if (m_CameraMotion != nullptr)
	{
		return m_CameraMotion->GetTranslationSpeed();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"));
	}
}

const Framework::CameraModelMiddleLayerImpl::Transform Framework::CameraModelMiddleLayerImpl
	::GetMotionObjectLocalTransform() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if (m_ObjectMotion != nullptr)
	{
		return m_ObjectMotion->GetMotionObjectLocalTransform();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("ObjectMotion 未初始化"));
	}
}
