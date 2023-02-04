///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 17:55)

#ifndef SYSTEM_WINDOWS_SUITE_ENGINEERING_SUFFIX_TESTING_H
#define SYSTEM_WINDOWS_SUITE_ENGINEERING_SUFFIX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EngineeringSuffixTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EngineeringSuffixTesting;
        using ParentType = UnitTest;

    public:
        explicit EngineeringSuffixTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SuffixTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_ENGINEERING_SUFFIX_TESTING_H