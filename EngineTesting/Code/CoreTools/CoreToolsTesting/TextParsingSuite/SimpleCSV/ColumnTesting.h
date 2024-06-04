/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 16:46)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_COLUMN_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_COLUMN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ColumnTesting final : public UnitTest
    {
    public:
        using ClassType = ColumnTesting;
        using ParentType = UnitTest;

    public:
        explicit ColumnTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ColumnTest();

        void DoColumnTest(const Worksheet& worksheet);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COLUMN_TESTING_H