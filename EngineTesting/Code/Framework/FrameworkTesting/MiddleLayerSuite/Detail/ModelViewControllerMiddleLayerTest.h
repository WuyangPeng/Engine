///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 19:56)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_TEST_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_TEST_H

#include "Framework/MiddleLayer/ModelViewControllerMiddleLayer.h"

namespace Framework
{
    class ModelViewControllerMiddleLayerTest : public ModelViewControllerMiddleLayer
    {
    public:
        using ClassType = ModelViewControllerMiddleLayerTest;
        using ParentType = ModelViewControllerMiddleLayer;

    public:
        ModelViewControllerMiddleLayerTest(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        // 开启protected接口为public，以供测试。
        NODISCARD MiddleLayerSharedPtr GetPublicModelMiddleLayer() noexcept;
        NODISCARD MiddleLayerSharedPtr GetPublicViewMiddleLayer() noexcept;
        NODISCARD MiddleLayerSharedPtr GetPublicControllerMiddleLayer() noexcept;

        NODISCARD ConstMiddleLayerSharedPtr GetConstPublicModelMiddleLayer() const noexcept;
        NODISCARD ConstMiddleLayerSharedPtr GetConstPublicViewMiddleLayer() const noexcept;
        NODISCARD ConstMiddleLayerSharedPtr GetConstPublicControllerMiddleLayer() const noexcept;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_TEST_H
