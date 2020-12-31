// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

#include "ModelViewControllerMiddleLayer.h"

namespace Framework
{
	// ���Ʋ��������
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

		// ��Ⱦ�м�㴦��
		bool Paint() final;
		bool Move(const WindowPoint& point) final;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

