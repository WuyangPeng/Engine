/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 14:36)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_ITERATOR_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_ITERATOR_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowIteratorTesting final : public UnitTest
    {
    public:
        using ClassType = RowIteratorTesting;
        using ParentType = UnitTest;

    public:
        explicit RowIteratorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;
        using Document = SimpleCSV::Document;
        using Workbook = SimpleCSV::Workbook;
        using DocumentSharedPtr = Document::DocumentSharedPtr;
        using RowRange = SimpleCSV::RowRange;
        using RowIterator = SimpleCSV::RowIterator;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RowIteratorTest();
        void SuffixIteratorTest();

        NODISCARD Worksheet GetWorkSheet();

        void DoRowIteratorTest(RowRange& rows, RowIterator& iter);
        void DoSuffixIteratorTest(RowRange& rows, RowIterator& iter);

    private:
        DocumentSharedPtr document;
        Workbook workbook;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_ITERATOR_TESTING_H