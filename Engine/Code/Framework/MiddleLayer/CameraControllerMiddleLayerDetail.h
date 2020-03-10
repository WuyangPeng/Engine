// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:29)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_DETAIL_H
 
#include "CameraControllerMiddleLayer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "ControllerMiddleLayerDetail.h"
#include "MiddleLayerInterfaceDetail.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"
#include "Framework/WindowCreate/WindowPoint.h"

template <typename ApplicationTrait>
Framework::CameraControllerMiddleLayer<ApplicationTrait>
	:: CameraControllerMiddleLayer()
 	:ParentType{}
{	
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename ApplicationTrait>
Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::~ CameraControllerMiddleLayer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::Initialize())
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
void Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return ParentType::Terminate();
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::KeyDown( uint8_t key,const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	
	if(ParentType::KeyDown(key,point))
	{			
		CameraModelMiddleLayerSmartPointer cameraModelMiddleLayer = GetCameraModelMiddleLayer();

		if (cameraModelMiddleLayer.IsValidPtr())
		{			 
			ChangeCameraSpeed(key, cameraModelMiddleLayer);			
		} 

		return true;
	}
	else
	{
		return false;
	}		
}

template <typename ApplicationTrait>
void Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::ChangeCameraSpeed( uint8_t key,CameraModelMiddleLayerSmartPointer& cameraModelMiddleLayer)
{
	// 标准键对应用程序。
	if (key == ApplicationTrait::KeyIdentifiers::sm_LowerT)
		cameraModelMiddleLayer->SlowerCameraTranslation();// 摄像机平移变慢。 
	else if (key == ApplicationTrait::KeyIdentifiers::sm_UpperT)
		cameraModelMiddleLayer->FasterCameraTranslation(); // 摄像机平移变快。 
	else if (key == ApplicationTrait::KeyIdentifiers::sm_LowerR)
		cameraModelMiddleLayer->SlowerCameraRotation(); // 摄像机旋转变慢。
	else if (key == ApplicationTrait::KeyIdentifiers::sm_UpperR)
		cameraModelMiddleLayer->FasterCameraRotation();  // 摄像机旋转变快。	
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::KeyUp( uint8_t key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::KeyUp(key,point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::SpecialKeyDown( int key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::SpecialKeyDown(key,point))
	{
		CameraModelMiddleLayerSmartPointer cameraModelMiddleLayer = GetCameraModelMiddleLayer();

		if (cameraModelMiddleLayer.IsValidPtr())
		{
			ChangeCameraSpeedMoveStatus(key, cameraModelMiddleLayer, true);			
		}
		
		return true;		
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait>
void Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::ChangeCameraSpeedMoveStatus(int key,CameraModelMiddleLayerSmartPointer& cameraModelMiddleLayer, bool move)
{
	if (key == ApplicationTrait::KeyIdentifiers::sm_KeyLeftArrow)
		cameraModelMiddleLayer->SetMoveLeft(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyRightArrow)
		cameraModelMiddleLayer->SetMoveRight(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyUpArrow)
		cameraModelMiddleLayer->SetMoveForward(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyDownArrow)
		cameraModelMiddleLayer->SetMoveBackward(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyPageUp)
		cameraModelMiddleLayer->SetMoveUp(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyPageDown)
		cameraModelMiddleLayer->SetMoveDown(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyHome)
		cameraModelMiddleLayer->SetLookUp(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyEnd)
		cameraModelMiddleLayer->SetLookDown(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyInsert)
		cameraModelMiddleLayer->SetTurnLeft(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyDelete)
		cameraModelMiddleLayer->SetTurnRight(move);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyF1)
		cameraModelMiddleLayer->SetDoRoll(move ? Mathematics::NumericalValueSymbol::Positive : Mathematics::NumericalValueSymbol::Zero);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyF2)
		cameraModelMiddleLayer->SetDoRoll(move ? Mathematics::NumericalValueSymbol::Negative : Mathematics::NumericalValueSymbol::Zero);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyF3)
		cameraModelMiddleLayer->SetDoYaw(move ? Mathematics::NumericalValueSymbol::Positive : Mathematics::NumericalValueSymbol::Zero);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyF4)
		cameraModelMiddleLayer->SetDoYaw(move ? Mathematics::NumericalValueSymbol::Negative : Mathematics::NumericalValueSymbol::Zero);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyF5)
		cameraModelMiddleLayer->SetDoPitch(move ? Mathematics::NumericalValueSymbol::Positive : Mathematics::NumericalValueSymbol::Zero);
	else if (key == ApplicationTrait::KeyIdentifiers::sm_KeyF6)
		cameraModelMiddleLayer->SetDoPitch(move ? Mathematics::NumericalValueSymbol::Negative : Mathematics::NumericalValueSymbol::Zero);
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::SpecialKeyUp( int key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::SpecialKeyUp(key,point))
	{
		CameraModelMiddleLayerSmartPointer cameraModelMiddleLayer = GetCameraModelMiddleLayer();

		if (cameraModelMiddleLayer.IsValidPtr())
		{
			ChangeCameraSpeedMoveStatus(key,cameraModelMiddleLayer, false);			
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
	::MouseClick( MouseButtonsTypes button,MouseStateTypes state, const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::MouseClick(button,state,point,virtualKeysTypes))
	{
		CameraModelMiddleLayerSmartPointer cameraModelMiddleLayer = GetCameraModelMiddleLayer();
		CameraViewMiddleLayerSmartPointer cameraViewMiddleLayer = GetCameraViewMiddleLayer();

		if (cameraModelMiddleLayer.IsValidPtr() && cameraViewMiddleLayer.IsValidPtr())
		{
			if (button == MouseButtonsTypesLeftButton)
			{
				if (state == MouseStateTypesMouseDown)
				{
					SetBeginTrack(point, cameraModelMiddleLayer, cameraViewMiddleLayer);
				}
				else
				{
					cameraModelMiddleLayer->SetTrackBallDow(false);
				}
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
void Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::SetBeginTrack(const WindowPoint& point, CameraModelMiddleLayerSmartPointer& cameraModelMiddleLayer,  CameraViewMiddleLayerSmartPointer& cameraViewMiddleLayer)
{
	// 得到起点。
	cameraModelMiddleLayer->SetTrackBallDow(true);
	cameraModelMiddleLayer->SetSaveRotate();

	float xTrack = cameraViewMiddleLayer->GetXTrack(point.GetWindowX());
	float yTrack = cameraViewMiddleLayer->GetYTrack(point.GetWindowY());

	cameraModelMiddleLayer->SetBeginTrack(xTrack, yTrack);
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::Motion( const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::Motion(point,virtualKeysTypes))
	{
		CameraModelMiddleLayerSmartPointer cameraModelMiddleLayer = GetCameraModelMiddleLayer();
		CameraViewMiddleLayerSmartPointer cameraViewMiddleLayer = GetCameraViewMiddleLayer();

		if (cameraModelMiddleLayer.IsValidPtr() && cameraViewMiddleLayer.IsValidPtr())		
		{
			if (virtualKeysTypes.IsLeftMouseDown() && cameraModelMiddleLayer->GetTrackBallDow())
			{
				RotateTrackBall(point, cameraModelMiddleLayer, cameraViewMiddleLayer);
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
void Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::RotateTrackBall( const WindowPoint& point,CameraModelMiddleLayerSmartPointer& cameraModelMiddleLayer,CameraViewMiddleLayerSmartPointer& cameraViewMiddleLayer )
{
	float xTrack = cameraViewMiddleLayer->GetXTrack(point.GetWindowX());
	float yTrack = cameraViewMiddleLayer->GetYTrack(point.GetWindowY());

	cameraModelMiddleLayer->SetEndTrack(xTrack, yTrack);

	// 更新对象的局部旋转
	cameraModelMiddleLayer->RotateTrackBall();
}


template <typename ApplicationTrait>
const Framework::CameraModelMiddleLayerSmartPointer Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::GetCameraModelMiddleLayer()
{
	return MiddleLayerInterface::GetSmartPointer<CameraModelMiddleLayerSmartPointer>(this,&ClassType::GetModelMiddleLayer);
}

template <typename ApplicationTrait>
const Framework::CameraViewMiddleLayerSmartPointer Framework::CameraControllerMiddleLayer<ApplicationTrait>
	::GetCameraViewMiddleLayer()
{
	return MiddleLayerInterface::GetSmartPointer<CameraViewMiddleLayerSmartPointer>(this, &ClassType::GetViewMiddleLayer);
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_DETAIL_H