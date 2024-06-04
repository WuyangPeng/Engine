/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:02)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_RANGE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_RANGE_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowRangeTesting final : public UnitTest
    {
    public:
        using ClassType = RowRangeTesting;
        using ParentType = UnitTest;

    public:
        explicit RowRangeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;
        using Document = SimpleCSV::Document;
        using Workbook = SimpleCSV::Workbook;
        using DocumentSharedPtr = Document::DocumentSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RowRangeTest();

        NODISCARD Worksheet GetWorkSheet();

    private:
        DocumentSharedPtr document;
        Workbook workbook;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_RANGE_TESTING_H