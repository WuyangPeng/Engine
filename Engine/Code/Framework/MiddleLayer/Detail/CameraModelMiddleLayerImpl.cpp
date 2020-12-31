// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:51)

#include "Framework/FrameworkExport.h"

#include "CameraModelMiddleLayerImpl.h" 
#include "CoreTools/Helper/ExceptionMacro.h"

#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/SceneGraph/Node.h" 
#include "Rendering/SceneGraph/Camera.h"
#include "Framework/Application/CameraMotion.h"
#include "Framework/Application/ObjectMotion.h"

using std::move;
using std::make_shared;
using namespace std::literals;

Framework::CameraModelMiddleLayerImpl
	::CameraModelMiddleLayerImpl() noexcept
	:m_CameraMotion{ }, m_ObjectMotion{ }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::CameraModelMiddleLayerImpl
	::CameraModelMiddleLayerImpl(CameraModelMiddleLayerImpl&& rhs) noexcept
	:m_CameraMotion{ move(rhs.m_CameraMotion) }, m_ObjectMotion{ move(rhs.m_ObjectMotion) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::CameraModelMiddleLayerImpl& Framework::CameraModelMiddleLayerImpl
	::operator=(CameraModelMiddleLayerImpl&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_CameraMotion = move(rhs.m_CameraMotion);
	m_ObjectMotion = move(rhs.m_ObjectMotion);

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, CameraModelMiddleLayerImpl)

void Framework::CameraModelMiddleLayerImpl
	::InitializeCameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_CameraMotion = make_shared<CameraMotion>(translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor);
}

void Framework::CameraModelMiddleLayerImpl
	::InitializeObjectMotion()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	Rendering::SpatialSharedPtr spatial{ std::make_shared<Rendering::Node>() };

	m_ObjectMotion = make_shared<ObjectMotion>(spatial);
}

bool Framework::CameraModelMiddleLayerImpl
	::MoveCamera()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		return m_CameraMotion->MoveCamera();
	}
	else
	{
		return false;
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SlowerCameraTranslation() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SlowerCameraTranslation();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::FasterCameraTranslation() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->FasterCameraTranslation();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SlowerCameraRotation() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SlowerCameraRotation();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::FasterCameraRotation() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->FasterCameraRotation();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveForward(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveForward(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveBackward(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveBackward(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetTurnLeft(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetTurnLeft(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetTurnRight(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetTurnRight(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetLookUp(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetLookUp(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetLookDown(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetLookDown(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveUp(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveUp(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveDown(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveDown(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveRight(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveRight(pressed);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetMoveLeft(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		m_CameraMotion->SetMoveLeft(pressed);
	}
}

bool Framework::CameraModelMiddleLayerImpl
	::MoveObject()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_ObjectMotion != nullptr && m_CameraMotion != nullptr)
	{
		const auto rotationSpeed = m_CameraMotion->GetRotationSpeed();

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

	if (m_ObjectMotion != nullptr && m_CameraMotion != nullptr)
	{
		auto camera = m_CameraMotion->GetCameraPtr();

		m_ObjectMotion->RotateTrackBall(camera);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetTrackBallDow(bool value) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetTrackBallDow(value);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetSaveRotate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetSaveRotate();
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetDoRoll(NumericalValueSymbol doRoll) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetDoRoll(System::EnumCastUnderlying(doRoll));
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetDoYaw(NumericalValueSymbol doYaw) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetDoYaw(System::EnumCastUnderlying(doYaw));
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetDoPitch(NumericalValueSymbol doPitch) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetDoPitch(System::EnumCastUnderlying(doPitch));
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetBeginTrack(float xTrack, float yTrack) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetBeginTrack(xTrack, yTrack);
	}
}

void Framework::CameraModelMiddleLayerImpl
	::SetEndTrack(float xTrack, float yTrack) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_ObjectMotion != nullptr)
	{
		m_ObjectMotion->SetEndTrack(xTrack, yTrack);
	}
}

bool Framework::CameraModelMiddleLayerImpl
	::GetTrackBallDow() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if (m_ObjectMotion != nullptr)
	{
		return m_ObjectMotion->GetTrackBallDow();
	}
	else
	{
		return false;
	}
}

Framework::CameraModelMiddleLayerImpl::CameraSmartPointer Framework::CameraModelMiddleLayerImpl
	::GetCamera()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_CameraMotion != nullptr)
	{
		return m_CameraMotion->GetCameraPtr();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"s));
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
		THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"s));
	}
}

void Framework::CameraModelMiddleLayerImpl
	::Terminate() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_CameraMotion.reset();
	m_ObjectMotion.reset();
}

const Framework::CameraModelMiddleLayerImpl::APoint Framework::CameraModelMiddleLayerImpl
	::GetCameraPosition() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	auto camera = GetCamera();

	return camera->GetPosition();
}

const Framework::CameraModelMiddleLayerImpl::AVector Framework::CameraModelMiddleLayerImpl
	::GetCameraDirectionVector() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	auto camera = GetCamera();

	return camera->GetDirectionVector();
}

const Framework::CameraModelMiddleLayerImpl::AVector Framework::CameraModelMiddleLayerImpl
	::GetCameraUpVector() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	auto camera = GetCamera();

	return camera->GetUpVector();
}

const Framework::CameraModelMiddleLayerImpl::AVector Framework::CameraModelMiddleLayerImpl
	::GetCameraRightVector() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	auto camera = GetCamera();

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
		THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"s));
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
		THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"s));
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
		THROW_EXCEPTION(SYSTEM_TEXT("ObjectMotion 未初始化"s));
	}
}
