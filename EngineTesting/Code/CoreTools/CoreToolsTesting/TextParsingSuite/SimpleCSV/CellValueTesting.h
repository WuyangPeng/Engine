///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/08 11:23)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CellValueTesting final : public UnitTest
    {
    public:
        using ClassType = CellValueTesting;
        using ParentType = UnitTest;

    public:
        explicit CellValueTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateDefaultTest();
        void CreateErrorTest();
        void CreateBoolTest();
        void CreateIntTest();
        void CreateDoubleTest();
        void CreateStringTest();
        void ClearTest();
        void CellValueErrorTest();
        void CellValueSetTest();
        void CellValueEqualTest();
        void EqualTest();
        void LessTest();
        void OStreamTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_TESTING_H
