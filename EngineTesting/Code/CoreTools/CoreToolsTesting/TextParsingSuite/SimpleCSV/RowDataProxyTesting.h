/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 14:59)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_PROXY_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_PROXY_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataProxy.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowDataProxyTesting final : public UnitTest
    {
    public:
        using ClassType = RowDataProxyTesting;
        using ParentType = UnitTest;

    public:
        explicit RowDataProxyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;
        using Document = SimpleCSV::Document;
        using Workbook = SimpleCSV::Workbook;
        using CellValue = SimpleCSV::CellValue;
        using DocumentSharedPtr = Document::DocumentSharedPtr;
        using Row = SimpleCSV::Row;
        using RowDataProxy = SimpleCSV::RowDataProxy;
        using CellValueContainer = RowDataProxy::CellValueContainer;
        using BoolContainer = RowDataProxy::BoolContainer;
        using CellValueDeque = std::deque<CellValue>;
        using CellValueList = std::list<CellValue>;
        using StringList = std::list<std::string>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RowDataProxyTest();
        void CellValueContainerTest();
        void BoolContainerTest();
        void DeleteCellValuesTest();
        void PrependCellValueTest();
        void ClearTest();
        void DequeTest();
        void ListTest();
        void StringListTest();

        NODISCARD Worksheet GetWorkSheet();
        void DoRowDataProxyTest(Row& row);
        void CellValueContainerOperatorTest(RowDataProxy& rowDataProxy);
        void BoolContainerOperatorTest(RowDataProxy& rowDataProxy);
        void DoDeleteCellValuesTest(RowDataProxy& rowDataProxy);
        void DoPrependCellValueTest(RowDataProxy& rowDataProxy);
        void DoDequeTest(RowDataProxy& rowDataProxy);
        void DoListTest(RowDataProxy& rowDataProxy);

    private:
        DocumentSharedPtr document;
        Workbook workbook;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_PROXY_TESTING_H