///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/11 12:53)

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
        void DoRunUnitTest() final;
        void MainTest();

        void RowTest();
        void RowCellTest();
        void ContainerTest();
        void OperatorTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_TESTING_H