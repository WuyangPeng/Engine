/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:07)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_SIMPLE_CSV_EXCEPTION_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_SIMPLE_CSV_EXCEPTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SimpleCSVExceptionTesting final : public UnitTest
    {
    public:
        using ClassType = SimpleCSVExceptionTesting;
        using ParentType = UnitTest;

    public:
        explicit SimpleCSVExceptionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThrowSimpleCSVExceptionTest();
        void ThrowSimpleCSVLastErrorExceptionTest();
        void ThrowSimpleCSVExceptionMultiByteTest();
        void ThrowSimpleCSVLastErrorExceptionMultiByteTest();
        void SimpleCSVExceptionTest();
        void SimpleCSVLastErrorExceptionTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_SIMPLE_CSV_EXCEPTION_TESTING_H
