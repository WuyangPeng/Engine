///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 11:30)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_TUPLE_LESS_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_TUPLE_LESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TupleLessTesting final : public UnitTest
    {
    public:
        using ClassType = TupleLessTesting;
        using ParentType = UnitTest;

    public:
        explicit TupleLessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;

        void TupleLessTest();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_TUPLE_LESS_TESTING_H