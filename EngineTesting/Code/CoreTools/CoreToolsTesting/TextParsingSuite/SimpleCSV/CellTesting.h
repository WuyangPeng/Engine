///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/09 14:21)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CELL_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CELL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CellTesting final : public UnitTest
    {
    public:
        using ClassType = CellTesting;
        using ParentType = UnitTest;

    public:
        explicit CellTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void EqualTest();
        void CreateEmptyTest();
        void FormulaTest();
        void CellReferenceTest();
        void CellValueProxyTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CELL_TESTING_H