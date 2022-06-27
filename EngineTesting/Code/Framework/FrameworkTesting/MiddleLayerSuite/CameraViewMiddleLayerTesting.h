///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 10:24)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_VIEW_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_VIEW_MIDDLE_LAYER_TESTING_H

#include "CameraMiddleLayerTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

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
        void DoRunUnitTest() final;

        void MainTest();

        void MiddleLayerTest();
        void DrawFrameRateTest();
        void TrackTest() noexcept;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_VIEW_MIDDLE_LAYER_TESTING_H