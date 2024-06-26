/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:59)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_RANGE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_RANGE_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowDataRangeTesting final : public UnitTest
    {
    public:
        using ClassType = RowDataRangeTesting;
        using ParentType = UnitTest;

    public:
        explicit RowDataRangeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;
        using Document = SimpleCSV::Document;
        using Workbook = SimpleCSV::Workbook;
        using DocumentSharedPtr = Document::DocumentSharedPtr;
        using Row = SimpleCSV::Row;
        using RowDataRange = SimpleCSV::RowDataRange;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RowDataRangeTest();
        NODISCARD Worksheet GetWorkSheet();

        void DoRowDataRangeTest(int row, const Row& element);
        void GetCellReferenceTest(int row, int size, RowDataRange& rowDataRange);

    private:
        DocumentSharedPtr document;
        Workbook workbook;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_RANGE_TESTING_H