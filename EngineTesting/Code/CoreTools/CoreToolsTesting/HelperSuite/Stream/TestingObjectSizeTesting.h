///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/16 21:12)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TestingObjectSizeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = TestingObjectSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit TestingObjectSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SaveStreamTest();
        void LoadStreamTest();
        void LinkStreamTest();
        void GetStreamingSizeTest();

    private:
        static constexpr auto bufferSize = 256;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_TESTING_H