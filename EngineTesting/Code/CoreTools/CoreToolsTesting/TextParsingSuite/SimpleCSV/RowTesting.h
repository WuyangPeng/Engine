/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 13:37)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowTesting final : public UnitTest
    {
    public:
        using ClassType = RowTesting;
        using ParentType = UnitTest;

    public:
        explicit RowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Document = SimpleCSV::Document;
        using DocumentSharedPtr = Document::DocumentSharedPtr;
        using Worksheet = SimpleCSV::Worksheet;
        using Row = SimpleCSV::Row;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RowTest();
        void RowCellTest();
        void ContainerTest();
        void OperatorTest();

        NODISCARD Worksheet GetWorkSheet() const;
        void DoRowTest(Row& row);
        void DoRowCellTest(const Row& row);
        void DoContainerTest(const Row& row);
        void DoOperatorTest(const Row& row);

    private:
        DocumentSharedPtr document;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_TESTING_H