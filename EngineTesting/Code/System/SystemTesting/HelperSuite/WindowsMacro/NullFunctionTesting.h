///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/16 19:43)

#ifndef SYSTEM_TESTING_HELPER_SUITE_NULL_FUNCTION_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_NULL_FUNCTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class NullFunctionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = NullFunctionTesting;
        using ParentType = UnitTest;

    public:
        explicit NullFunctionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void NullFunctionTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_NULL_FUNCTION_TESTING_H
