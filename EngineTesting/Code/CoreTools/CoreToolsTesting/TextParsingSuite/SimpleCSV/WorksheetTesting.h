/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:10)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_WORKSHEET_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_WORKSHEET_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class WorksheetTesting final : public UnitTest
    {
    public:
        using ClassType = WorksheetTesting;
        using ParentType = UnitTest;

    public:
        explicit WorksheetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;
        using Cell = SimpleCSV::Cell;
        using Color = SimpleCSV::Color;
        using CellReference = SimpleCSV::CellReference;
        using Document = SimpleCSV::Document;
        using DocumentSharedPtr = Document::DocumentSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WorksheetCellTest();
        void WorksheetRangeTest();
        void WorksheetRowRangeTest();
        void WorksheetRowTest();
        void WorksheetColumnTest();
        void LastCellTest();
        void SelectedTest();
        void ColorTest();

        void WorksheetCell0Test();
        void WorksheetCell1Test();
        void WorksheetCell2Test(const CellReference& cellReference);
        void WorksheetRange0Test();
        void WorksheetRange1Test();

        NODISCARD static Worksheet GetWorkSheet(const Document& document);

        void WorksheetRowRange0Test();
        void WorksheetRowRange1Test();
        void WorksheetRowRange2Test();

    private:
        std::string docPath;
        DocumentSharedPtr document;
        Worksheet worksheet;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_WORKSHEET_TESTING_H