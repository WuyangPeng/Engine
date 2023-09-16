///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:28)

#ifndef SYSTEM_TESTING_HELPER_SUITE_FIXED_SIZE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_FIXED_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FixedSizeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FixedSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit FixedSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void IntegerSizeTest();
        void IntegerMinCriticalTest();
        void IntegerMaxCriticalTest();
        void Integer64Test() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_FIXED_SIZE_TESTING_H
