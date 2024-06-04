/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 16:08)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_ITERATOR_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_ITERATOR_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowDataIteratorTesting final : public UnitTest
    {
    public:
        using ClassType = RowDataIteratorTesting;
        using ParentType = UnitTest;

    public:
        explicit RowDataIteratorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;
        using Document = SimpleCSV::Document;
        using Workbook = SimpleCSV::Workbook;
        using CellValue = SimpleCSV::CellValue;
        using Row = SimpleCSV::Row;
        using RowDataRange = SimpleCSV::RowDataRange;
        using RowDataIterator = SimpleCSV::RowDataIterator;
        using DocumentSharedPtr = Document::DocumentSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RowDataIteratorTest();

        void SuffixIteratorTest();
        NODISCARD Worksheet GetWorkSheet();
        void DoRowDataIteratorTest(int row, const Row& element);
        void GetCellReferenceTest(int row, int column, RowDataRange& rowDataRange, RowDataIterator& iter);
        void DoSuffixIteratorTest(int row, const Row& element);

    private:
        DocumentSharedPtr document;
        Workbook workbook;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_ITERATOR_TESTING_H