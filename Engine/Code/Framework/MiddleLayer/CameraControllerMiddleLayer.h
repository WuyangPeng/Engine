// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:39)

// 控制层类的声明
#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_H

#include "ControllerMiddleLayer.h"
#include "CameraModelMiddleLayer.h"
#include "CameraViewMiddleLayer.h"

namespace Framework
{
	template <typename ApplicationTrait>
	class CameraControllerMiddleLayer : public ControllerMiddleLayer<ApplicationTrait>
	{
	public:
		using ClassType = CameraControllerMiddleLayer<ApplicationTrait>;
		using ParentType = ControllerMiddleLayer<ApplicationTrait>;

	public:
		CameraControllerMiddleLayer();
		virtual ~CameraControllerMiddleLayer();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool Initialize();
		virtual void Terminate();	

		virtual bool KeyDown(uint8_t key,const WindowPoint& point);
		virtual bool KeyUp(uint8_t key, const WindowPoint& point);
		virtual bool SpecialKeyDown (int key, const WindowPoint& point);
		virtual bool SpecialKeyUp(int key, const WindowPoint& point);
		virtual bool MouseClick(MouseButtonsTypes button,MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes);

	private:
		void ChangeCameraSpeed(uint8_t key, CameraModelMiddleLayerSmartPointer& cameraModelMiddleLayer);
		void ChangeCameraSpeedMoveStatus(int key, CameraModelMiddleLayerSmartPointer& cameraModelMiddleLayer, bool move);
		void RotateTrackBall(const WindowPoint& point, CameraModelMiddleLayerSmartPointer& cameraModelMiddleLayer,
			                 CameraViewMiddleLayerSmartPointer& cameraViewMiddleLayer);
		void SetBeginTrack(const WindowPoint& point, CameraModelMiddleLayerSmartPointer& cameraModelMiddleLayer,
			               CameraViewMiddleLayerSmartPointer& cameraViewMiddleLayer);

		const CameraModelMiddleLayerSmartPointer GetCameraModelMiddleLayer();
		const CameraViewMiddleLayerSmartPointer GetCameraViewMiddleLayer();
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_H

