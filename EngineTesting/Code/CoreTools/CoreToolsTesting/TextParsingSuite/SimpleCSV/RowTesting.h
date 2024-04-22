/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:02)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowTesting final : public UnitTest
    {
    public:
        using ClassType = RowTesting;
        using ParentType = UnitTest;

    public:
        explicit RowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RowTest();
        void RowCellTest();
        void ContainerTest();
        void OperatorTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_TESTING_H