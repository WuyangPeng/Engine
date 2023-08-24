///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/12 15:22)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_VIEW_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_VIEW_MIDDLE_LAYER_TESTING_H

#include "CameraMiddleLayerTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class CameraViewMiddleLayerTesting final : public CameraMiddleLayerTesting
    {
    public:
        using ClassType = CameraViewMiddleLayerTesting;
        using ParentType = CameraMiddleLayerTesting;

    public:
        explicit CameraViewMiddleLayerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void MiddleLayerTest();
        void DrawFrameRateTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_VIEW_MIDDLE_LAYER_TESTING_H