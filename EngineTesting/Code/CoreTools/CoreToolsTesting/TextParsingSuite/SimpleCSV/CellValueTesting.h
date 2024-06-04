/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:40)

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
        using CellValue = SimpleCSV::CellValue;
        using ValueType = SimpleCSV::ValueType;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateDefaultTest();
        void CreateErrorTest();
        void CreateBoolTest();
        void CreateInt32Test();
        void CreateInt64Test();
        void CreateDoubleTest();
        void CreateStringTest();
        void ClearTest();
        void CellValueErrorTest();
        void CellValueSetTest();
        void CellValueEqualTest();
        void EqualTest();
        void LessTest();
        void OStreamTest();

        void CreateString0Test();
        void CreateString1Test();

        void CellValueSet0Test(CellValue& cellValue);
        void CellValueSet1Test(CellValue& cellValue);
        void CellValueSet2Test(CellValue& cellValue);
        void CellValueSet3Test(CellValue& cellValue);
        void CellValueSet4Test(CellValue& cellValue);
        void CellValueSet5Test(const CellValue& cellValue);
        void CellValueEqual0Test(CellValue& cellValue);
        void CellValueEqual1Test(CellValue& cellValue);
        void CellValueEqual2Test(CellValue& cellValue);
        void CellValueEqual3Test(CellValue& cellValue);
        void CellValueEqual4Test(CellValue& cellValue);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_TESTING_H
