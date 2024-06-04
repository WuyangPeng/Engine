/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.10 (2024/06/01 20:40)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CELL_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CELL_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CellTesting final : public UnitTest
    {
    public:
        using ClassType = CellTesting;
        using ParentType = UnitTest;

    public:
        explicit CellTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;
        using Document = SimpleCSV::Document;
        using DocumentSharedPtr = Document::DocumentSharedPtr;
        using CellValueProxy = SimpleCSV::CellValueProxy;
        using Cell = SimpleCSV::Cell;
        using CellSharedPtr = Cell::CellSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void EqualTest();
        void CreateEmptyTest();
        void FormulaTest();
        void CellReferenceTest();

        void CellValueProxyTest();

        NODISCARD Worksheet GetWorkSheet();

        void Equal0Test(const Worksheet& worksheet, const Cell& cell0);
        void Equal1Test(const Worksheet& worksheet, const Cell& cell0);
        void CellValueProxy0Test(const Worksheet& worksheet);
        void CellValueProxy1Test(const Worksheet& worksheet);

    private:
        DocumentSharedPtr document;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CELL_TESTING_H