// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.1 (2020/05/27 14:08)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_TEST_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_TEST_H

#include "Framework/MiddleLayer/ModelViewControllerMiddleLayer.h"  

namespace Framework
{
	class ModelViewControllerMiddleLayerTest : public  ModelViewControllerMiddleLayer
	{
	public:
		using ClassType = ModelViewControllerMiddleLayerTest;
		using ParentType = ModelViewControllerMiddleLayer;

	public:
		explicit ModelViewControllerMiddleLayerTest(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_OVERRIDE_DECLARE;		 

	public:
		// ����protected�ӿ�Ϊpublic���Թ����ԡ�
		const MiddleLayerSharedPtr GetPublicModelMiddleLayer() noexcept;
		const MiddleLayerSharedPtr GetPublicViewMiddleLayer() noexcept;
		const MiddleLayerSharedPtr GetPublicControllerMiddleLayer() noexcept;

		const ConstMiddleLayerSharedPtr GetConstPublicModelMiddleLayer() const noexcept;
		const ConstMiddleLayerSharedPtr GetConstPublicViewMiddleLayer() const noexcept;
		const ConstMiddleLayerSharedPtr GetConstPublicControllerMiddleLayer() const noexcept;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_TEST_H

