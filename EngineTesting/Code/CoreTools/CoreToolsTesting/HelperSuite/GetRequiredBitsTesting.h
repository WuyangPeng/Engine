///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:20)

#ifndef CORE_TOOLS_HELPER_SUITE_GET_REQUIRED_BITS_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_GET_REQUIRED_BITS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class GetRequiredBitsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetRequiredBitsTesting;
        using ParentType = UnitTest;

    public:
        explicit GetRequiredBitsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void BitsTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_GET_REQUIRED_BITS_TESTING_H