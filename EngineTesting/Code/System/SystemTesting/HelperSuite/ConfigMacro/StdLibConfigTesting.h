///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 0:34)

#ifndef SYSTEM_TESTING_HELPER_SUITE_STD_LIB_CONFIG_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_STD_LIB_CONFIG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class StdLibConfigTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StdLibConfigTesting;
        using ParentType = UnitTest;

    public:
        explicit StdLibConfigTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StdLibTest();
        void DinkumwareTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_STD_LIB_CONFIG_TESTING_H
