///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:04)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_VIEW_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_VIEW_MIDDLE_LAYER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class ViewMiddleLayerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ViewMiddleLayerTesting;
        using ParentType = UnitTest;

    public:
        explicit ViewMiddleLayerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void MiddleLayerTest();
        void DrawFrameRateTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_VIEW_MIDDLE_LAYER_TESTING_H