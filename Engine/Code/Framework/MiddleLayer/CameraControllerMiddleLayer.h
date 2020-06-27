// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:47)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_H

#include "ControllerMiddleLayer.h"
#include "CameraModelMiddleLayer.h"
#include "CameraViewMiddleLayer.h"

#include <map>

namespace Framework
{
	template <typename ApplicationTrait>
	class CameraControllerMiddleLayer : public ControllerMiddleLayer<ApplicationTrait>
	{
	public:
		using ClassType = CameraControllerMiddleLayer<ApplicationTrait>;
		using ParentType = ControllerMiddleLayer<ApplicationTrait>;

	public:
		explicit CameraControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		bool KeyDown(int key, const WindowPoint& point) override;
		bool SpecialKeyDown(int key, const WindowPoint& point) override;
		bool SpecialKeyUp(int key, const WindowPoint& point) override;
		bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
		bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;

	private:	
		const CameraModelMiddleLayerSharedPtr GetCameraModelMiddleLayer();
		const CameraViewMiddleLayerSharedPtr GetCameraViewMiddleLayer();

		void SpecialKey(int key, bool pressed);
		void CameraSpecialKey(int key, bool pressed);
		void ObjectSpecialKey(int key, bool pressed);

	private:
		using KeyIdentifiers = typename ApplicationTrait::KeyIdentifiers;
		using ChangeCameraSpeedFunction = void (CameraModelMiddleLayer::*)();
		using ChangeCameraSpeedProcess = std::map<int, ChangeCameraSpeedFunction>;
		using ChangeCameraMotionFunction = void (CameraModelMiddleLayer::*)(Mathematics::NumericalValueSymbol);
		using ChangeCameraMotionProcess = std::map<int,std::pair<ChangeCameraMotionFunction,Mathematics::NumericalValueSymbol>>;
		using ChangeObjectMotionFunction = void (CameraModelMiddleLayer::*)(bool);
		using ChangeObjectMotionProcess = std::map<int, ChangeObjectMotionFunction>;

	private:
		ChangeCameraSpeedProcess m_ChangeCameraSpeed;
		ChangeCameraMotionProcess m_ChangeCameraMotion;
		ChangeObjectMotionProcess m_ChangeObjectMotion;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_H

