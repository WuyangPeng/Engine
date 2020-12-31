// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

#include "ModelViewControllerMiddleLayer.h"

namespace Framework
{
	// 控制层类的声明
	template <typename ApplicationTrait>
	class ControllerMiddleLayer : public ModelViewControllerMiddleLayer
	{
	public:
		using ClassType = ControllerMiddleLayer<ApplicationTrait>;
		using ParentType = ModelViewControllerMiddleLayer;

	public:
		explicit ControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		bool KeyDown(int key, const WindowPoint& point) override;

		// 渲染中间层处理
		bool Paint() final;
		bool Move(const WindowPoint& point) final;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

