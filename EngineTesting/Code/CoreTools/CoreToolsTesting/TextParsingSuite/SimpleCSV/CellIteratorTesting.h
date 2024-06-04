/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:18)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CELL_ITERATOR_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CELL_ITERATOR_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CellIteratorTesting final : public UnitTest
    {
    public:
        using ClassType = CellIteratorTesting;
        using ParentType = UnitTest;

    public:
        explicit CellIteratorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;
        using Document = SimpleCSV::Document;
        using DocumentSharedPtr = Document::DocumentSharedPtr;
        using Cell = SimpleCSV::Cell;
        using CellRange = SimpleCSV::CellRange;
        using CellIterator = SimpleCSV::CellIterator;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CellRangeIteratorTest();
        void SuffixIteratorTest();

        NODISCARD Worksheet GetWorkSheet();
        void DoCellRangeIteratorTest(int row,
                                     int column,
                                     int distance,
                                     CellRange& cellRange,
                                     CellIterator& iter);
        void DoSuffixIteratorTest(int distance,
                                  CellRange& cellRange,
                                  const CellIterator& iter);

    private:
        DocumentSharedPtr document;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CELL_ITERATOR_TESTING_H