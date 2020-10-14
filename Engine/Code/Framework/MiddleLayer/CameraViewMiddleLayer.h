// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ViewMiddleLayer.h"
#include "Rendering/SceneGraph/Camera.h"

namespace Framework
{
	// 视图层类的声明
	class FRAMEWORK_DEFAULT_DECLARE CameraViewMiddleLayer : public ViewMiddleLayer
	{
	public:
		using ClassType = CameraViewMiddleLayer;
		using ParentType = ViewMiddleLayer;
		using CameraSmartPointer = Rendering::CameraSharedPtr;

	public:
		explicit CameraViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

		void SetCamera(const CameraSmartPointer& camera);
		const WindowSize GetWindowSize() const;

		float GetXTrack(int x) const;
		float GetYTrack(int y) const;

	private:
		float m_Multiplier;
	};

	using CameraViewMiddleLayerSharedPtr = std::shared_ptr<CameraViewMiddleLayer>;
	using ConstCameraViewMiddleLayerSharedPtr = std::shared_ptr<const CameraViewMiddleLayer>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H



