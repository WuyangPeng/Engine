// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:54)

#include "Framework/FrameworkExport.h"

#include "CameraModelMiddleLayer.h"
#include "CameraViewMiddleLayer.h" 
#include "MiddleLayerInterface.h"
#include "Detail/CameraModelMiddleLayerImpl.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
 
#include "Framework/WindowCreate/WindowPoint.h"

using std::move;
using std::make_shared;
 #include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
Framework::CameraModelMiddleLayer
	::CameraModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>() }, m_TimeDelta{ System::g_Microseconds }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
Framework::CameraModelMiddleLayer
	::CameraModelMiddleLayer(CameraModelMiddleLayer&& rhs) noexcept
	:ParentType{ move(rhs) }, m_Impl{ move(rhs.m_Impl) }, m_TimeDelta{ rhs.m_TimeDelta }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
Framework::CameraModelMiddleLayer& Framework::CameraModelMiddleLayer
	::operator=(CameraModelMiddleLayer&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(move(rhs));

	m_Impl = move(rhs.m_Impl);
	m_TimeDelta = rhs.m_TimeDelta;

	return *this;
}
 
CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework, CameraModelMiddleLayer)

bool Framework::CameraModelMiddleLayer
	::Initialize()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize())
	{
		constexpr auto speed = 0.01f;
		constexpr auto speedFactor = 2.0f;

		InitializeCameraMotion(speed, speed, speedFactor, speedFactor);

		InitializeObjectMotion();

		auto cameraViewMiddleLayer = boost::polymorphic_pointer_cast<CameraViewMiddleLayer>(GetViewMiddleLayer());

		auto camera = m_Impl->GetCamera();
	
		cameraViewMiddleLayer->SetCamera(camera);		

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

	auto cameraViewMiddleLayer = boost::polymorphic_pointer_cast<CameraViewMiddleLayer>(GetViewMiddleLayer());

	cameraViewMiddleLayer->SetCamera(Rendering::CameraSharedPtr{});

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
	::InitializeCameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->InitializeCameraMotion(translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor);
}

void Framework::CameraModelMiddleLayer
	::InitializeObjectMotion()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->InitializeObjectMotion();
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, MoveCamera, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, SlowerCameraTranslation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, FasterCameraTranslation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, SlowerCameraRotation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, FasterCameraRotation, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveForward, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveBackward, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetTurnLeft, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetTurnRight, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetLookUp, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetLookDown, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveUp, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveDown, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveRight, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveLeft, bool, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, MoveObject, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, RotateTrackBall, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetTrackBallDow, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, SetSaveRotate, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetDoRoll, NumericalValueSymbol, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetDoYaw, NumericalValueSymbol, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetDoPitch, NumericalValueSymbol, void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, GetTrackBallDow, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraPosition, const Framework::CameraModelMiddleLayer::APoint);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraDirectionVector, const Framework::CameraModelMiddleLayer::AVector);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraUpVector, const Framework::CameraModelMiddleLayer::AVector);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraRightVector, const Framework::CameraModelMiddleLayer::AVector);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetRotationSpeed, float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetTranslationSpeed, float);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetMotionObjectLocalTransform, const Framework::CameraModelMiddleLayer::Transform);

void Framework::CameraModelMiddleLayer
	::SetBeginTrack(float xTrack, float yTrack) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetBeginTrack(xTrack, yTrack);
}

void Framework::CameraModelMiddleLayer
	::SetEndTrack(float xTrack, float yTrack) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetEndTrack(xTrack, yTrack);
}

void Framework::CameraModelMiddleLayer
	::RotateTrackBall(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	const auto xTrack = cameraViewMiddleLayer.GetXTrack(point.GetWindowX());
	const auto yTrack = cameraViewMiddleLayer.GetYTrack(point.GetWindowY());

	SetEndTrack(xTrack, yTrack);

	// 更新对象的局部旋转
	RotateTrackBall();
}

void Framework::CameraModelMiddleLayer
	::SetBeginTrack(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	// 得到起点。
	SetTrackBallDow(true);
	SetSaveRotate();

	const auto xTrack = cameraViewMiddleLayer.GetXTrack(point.GetWindowX());
	const auto yTrack = cameraViewMiddleLayer.GetYTrack(point.GetWindowY());

	SetBeginTrack(xTrack, yTrack);
}



#include STSTEM_WARNING_POP