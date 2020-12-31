// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:41)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_DETAIL_H

#include "CameraControllerMiddleLayer.h"
#include "MiddleLayerInterface.h"
#include "ControllerMiddleLayerDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename ApplicationTrait>
Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::CameraControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform },
	 m_ChangeCameraSpeed{ { KeyIdentifiers::sm_LowerT,&CameraModelMiddleLayer::SlowerCameraTranslation },// 摄像机平移变慢。 
						  { KeyIdentifiers::sm_UpperT,&CameraModelMiddleLayer::FasterCameraTranslation },// 摄像机平移变快。 
						  { KeyIdentifiers::sm_LowerR,&CameraModelMiddleLayer::SlowerCameraRotation },// 摄像机旋转变慢。 
						  { KeyIdentifiers::sm_UpperR,&CameraModelMiddleLayer::FasterCameraRotation } },// 摄像机旋转变快。 
	 m_ChangeCameraMotion{ { KeyIdentifiers::sm_KeyF1,{ &CameraModelMiddleLayer::SetDoRoll,Mathematics::NumericalValueSymbol::Positive } },
						   { KeyIdentifiers::sm_KeyF2,{ &CameraModelMiddleLayer::SetDoRoll,Mathematics::NumericalValueSymbol::Negative } },
						   { KeyIdentifiers::sm_KeyF3,{ &CameraModelMiddleLayer::SetDoYaw,Mathematics::NumericalValueSymbol::Positive } },
						   { KeyIdentifiers::sm_KeyF4,{ &CameraModelMiddleLayer::SetDoYaw,Mathematics::NumericalValueSymbol::Negative } },
						   { KeyIdentifiers::sm_KeyF5,{ &CameraModelMiddleLayer::SetDoPitch,Mathematics::NumericalValueSymbol::Positive } },
						   { KeyIdentifiers::sm_KeyF6,{ &CameraModelMiddleLayer::SetDoPitch,Mathematics::NumericalValueSymbol::Negative } } },
	 m_ChangeObjectMotion{ { KeyIdentifiers::sm_KeyLeftArrow,&CameraModelMiddleLayer::SetMoveLeft },
						   { KeyIdentifiers::sm_KeyRightArrow,&CameraModelMiddleLayer::SetMoveRight },
						   { KeyIdentifiers::sm_KeyUpArrow,&CameraModelMiddleLayer::SetMoveForward },
						   { KeyIdentifiers::sm_KeyDownArrow,&CameraModelMiddleLayer::SetMoveBackward },
						   { KeyIdentifiers::sm_KeyPageUp,&CameraModelMiddleLayer::SetMoveUp },
						   { KeyIdentifiers::sm_KeyPageDown,&CameraModelMiddleLayer::SetMoveDown },
						   { KeyIdentifiers::sm_KeyHome,&CameraModelMiddleLayer::SetLookUp },
						   { KeyIdentifiers::sm_KeyEnd,&CameraModelMiddleLayer::SetLookDown },
						   { KeyIdentifiers::sm_KeyInsert,&CameraModelMiddleLayer::SetTurnLeft },
						   { KeyIdentifiers::sm_KeyDelete,&CameraModelMiddleLayer::SetTurnRight } }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::KeyDown(int key, const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::KeyDown(key, point))
	{
		const auto iter = m_ChangeCameraSpeed.find(key);

		if (iter != m_ChangeCameraSpeed.cend())
		{
			auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();

			// 标准键对应用程序。
			((*cameraModelMiddleLayer).*(iter->second))();
		}

		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::SpecialKeyDown(key, point))
	{
		SpecialKey(key, true);

		return true;
	}
	else
	{
		return false;
	}
}

// private
template <typename ApplicationTrait>
void Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::SpecialKey(int key, bool pressed)
{
	if (KeyIdentifiers::sm_KeyF1 <= key && key <= KeyIdentifiers::sm_KeyF12)
	{
		CameraSpecialKey(key, pressed);
	}
	else
	{
		ObjectSpecialKey(key, pressed);
	}
}

// private
template <typename ApplicationTrait>
void Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::CameraSpecialKey(int key, bool pressed)
{
	const auto iter = m_ChangeCameraMotion.find(key);

	if (iter != m_ChangeCameraMotion.cend())
	{
		auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();

		((*cameraModelMiddleLayer).*(iter->second.first))(pressed ? iter->second.second : Mathematics::NumericalValueSymbol::Zero);
	}
}

// private
template <typename ApplicationTrait>
void Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::ObjectSpecialKey(int key, bool pressed)
{
	const auto iter = m_ChangeObjectMotion.find(key);

	if (iter != m_ChangeObjectMotion.cend())
	{
		auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();

		((*cameraModelMiddleLayer).*(iter->second))(pressed);
	}
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::SpecialKeyUp(key, point))
	{
		SpecialKey(key, false);

		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::MouseClick(button, state, point, virtualKeys))
	{
		if (button == MouseButtonsTypes::LeftButton)
		{
			auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();

			if (state == MouseStateTypes::MouseDown)
			{
				auto cameraViewMiddleLayer = GetCameraViewMiddleLayer();

				cameraModelMiddleLayer->SetBeginTrack(point, *cameraViewMiddleLayer);
			}
			else
			{
				cameraModelMiddleLayer->SetTrackBallDow(false);
			}
		}

		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::Motion(point, virtualKeys))
	{
		auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();

		if (virtualKeys.IsLeftMouseDown() && cameraModelMiddleLayer->GetTrackBallDow())
		{
			auto cameraViewMiddleLayer = GetCameraViewMiddleLayer();

			cameraModelMiddleLayer->RotateTrackBall(point, *cameraViewMiddleLayer);
		}

		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait>
const Framework::CameraModelMiddleLayerSharedPtr Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::GetCameraModelMiddleLayer()
{
	return boost::polymorphic_pointer_cast<CameraModelMiddleLayer>(this->GetModelMiddleLayer());
}

template <typename ApplicationTrait>
const Framework::CameraViewMiddleLayerSharedPtr Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::GetCameraViewMiddleLayer()
{
	return boost::polymorphic_pointer_cast<CameraViewMiddleLayer>(this->GetViewMiddleLayer());
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_DETAIL_H