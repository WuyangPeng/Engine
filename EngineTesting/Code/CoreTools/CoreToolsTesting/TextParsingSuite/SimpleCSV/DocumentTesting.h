/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:49)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_DOCUMENT_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_DOCUMENT_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DocumentTesting final : public UnitTest
    {
    public:
        using ClassType = DocumentTesting;
        using ParentType = UnitTest;

    public:
        explicit DocumentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Workbook = SimpleCSV::Workbook;
        using Worksheet = SimpleCSV::Worksheet;
        using Document = SimpleCSV::Document;
        using DocumentSharedPtr = SimpleCSV::Document::DocumentSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WorkbookTest();
        void CreateTest();
        void RemoveFile();
        void PropertyTest();

        void ExecuteCommandTest();
        void ExecuteQueryTest();

        NODISCARD static DocumentSharedPtr GetDocument();

        void CommandSetSheetNameTest(Document& document, Workbook& workbook, const std::string& worksheetName);
        void CommandSetSheetIndexTest(Document& document, Workbook& workbook);
        void CommandAddWorksheetTest(Document& document, Workbook& workbook);
        void CommandCloneSheetTest(Document& document, Workbook& workbook);
        void CommandDeleteSheetTest(Document& document, Workbook& workbook);

        void QuerySheetNameTest(const Document& document);
        void QuerySheetVisibilityTest(const Document& document);
        void QuerySheetTypeTest(const Document& document);
        void QuerySheetIdTest(const Document& document);
        void QuerySheetRelationshipIdTest(const Document& document);
        void QuerySheetRelationshipTargetTest(const Document& document);
        void QuerySharedStringsTest(const Document& document);
        void QueryXmlDataTest(const Document& document);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_DOCUMENT_TESTING_H