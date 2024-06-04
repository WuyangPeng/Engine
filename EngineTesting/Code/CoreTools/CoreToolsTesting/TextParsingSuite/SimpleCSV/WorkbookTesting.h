/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 11:32)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_WORKBOOK_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_WORKBOOK_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Workbook.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class WorkbookTesting final : public UnitTest
    {
    public:
        using ClassType = WorkbookTesting;
        using ParentType = UnitTest;

    public:
        explicit WorkbookTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Workbook = SimpleCSV::Workbook;
        using SheetNamesType = SimpleCSV::Workbook::SheetNamesType;
        using Document = SimpleCSV::Document;
        using DocumentSharedPtr = Document::DocumentSharedPtr;
        using Worksheet = SimpleCSV::Worksheet;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetWorksheetTest();
        void WorksheetIndexTest();
        void TypeTest();
        void SheetNamesTest();
        void ExistsTest();
        void SharedStringTest();
        void SetSheetNameTest();
        void SheetIdTest();

        void GetWorksheetSizeTest(const SheetNamesType& worksheetNames);
        void AddWorksheetTest(size_t size);
        void DeleteSheet0Test(size_t size);
        void CloneSheetTest(size_t size);
        void DeleteSheet1Test(size_t size);

        void WorksheetIndex0Test(const Worksheet& worksheet0);
        void WorksheetIndex1Test(const Worksheet& worksheet0);
        void WorksheetIndex2Test(const Worksheet& worksheet0);
        void WorksheetIndex3Test(const Worksheet& worksheet0);
        void WorksheetIndex4Test(const Worksheet& worksheet0);
        void WorksheetIndex5Test(const Worksheet& worksheet0);
        void WorksheetIndex6Test(const Worksheet& worksheet0);
        void WorksheetIndex7Test(const Worksheet& worksheet0);
        void DoTypeTest(int index);

    private:
        DocumentSharedPtr document;
        Workbook workbook;
        std::string sheet1Name;
        std::string sheet3Name;
        std::string sheet4Name;
        std::string sheet5Name;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_WORKBOOK_TESTING_H