///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:19)

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
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_TESTING_H