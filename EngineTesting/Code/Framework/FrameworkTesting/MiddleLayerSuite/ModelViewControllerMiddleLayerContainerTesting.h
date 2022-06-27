///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 10:23)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLELAYER_CONTAINER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLELAYER_CONTAINER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class ModelViewControllerMiddleLayerContainerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ModelViewControllerMiddleLayerContainerTesting;
        using ParentType = UnitTest;

    public:
        explicit ModelViewControllerMiddleLayerContainerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void MiddleLayerTest();
        void PixelMiddleLayerTest();
        void CameraMiddleLayerTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLELAYER_CONTAINER_TESTING_H