// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:40)

// 视图层类的声明
#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ViewMiddleLayer.h"
#include "Rendering/SceneGraph/Camera.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE CameraViewMiddleLayer: public ViewMiddleLayer
	{
	public:
		using ClassType = CameraViewMiddleLayer;
		using ParentType = ViewMiddleLayer;
		using ConstCameraSmartPointer = Rendering::ConstCameraSmartPointer;

	public:
		CameraViewMiddleLayer();
		virtual ~CameraViewMiddleLayer();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool Initialize();
		virtual void Terminate();

		virtual bool Resize(WindowDisplayFlags type,const WindowSize& size);

		void SetCamera(const ConstCameraSmartPointer& camera);		
		const WindowSize GetWindowSize() const;

		float GetXTrack(int x) const;
		float GetYTrack(int y) const;

	private:
		float m_Multiplier;
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, CameraViewMiddleLayer);
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H



	