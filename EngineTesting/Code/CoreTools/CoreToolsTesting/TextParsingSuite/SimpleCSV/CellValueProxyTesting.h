/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:35)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_PROXY_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_PROXY_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CellValueProxyTesting final : public UnitTest
    {
    public:
        using ClassType = CellValueProxyTesting;
        using ParentType = UnitTest;

    public:
        explicit CellValueProxyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Worksheet = SimpleCSV::Worksheet;
        using Document = SimpleCSV::Document;
        using DocumentSharedPtr = Document::DocumentSharedPtr;
        using CellValueProxy = SimpleCSV::CellValueProxy;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CellValueProxyTypeTest();
        void CellValueProxySetTest();
        void CellValueTest();
        void CreateEmptyTest();
        void CellValueSetTest();
        void CellValueEqualTest();
        void CellTest();

        NODISCARD Worksheet GetWorkSheet();
        void CellValueProxyType0Test(const Worksheet& worksheet);
        void CellValueProxyType1Test(const Worksheet& worksheet);
        void CellValueProxyType2Test(const Worksheet& worksheet);
        void CellValueProxyType3Test(const Worksheet& worksheet);
        void CellValueProxyType4Test(const Worksheet& worksheet);

        void CellValueProxySet0Test(CellValueProxy& cellValueProxy);
        void CellValueProxySet1Test(CellValueProxy& cellValueProxy);
        void CellValueProxySet2Test(CellValueProxy& cellValueProxy);
        void CellValueProxySet3Test(CellValueProxy& cellValueProxy);
        void CellValueProxySet4Test(CellValueProxy& cellValueProxy);
        void CellValueProxySet5Test(CellValueProxy& cellValueProxy);

        void CellValueSet0Test(CellValueProxy& cellValueProxy);
        void CellValueSet1Test(CellValueProxy& cellValueProxy);
        void CellValueSet2Test(CellValueProxy& cellValueProxy);
        void CellValueSet3Test(CellValueProxy& cellValueProxy);
        void CellValueSet4Test(CellValueProxy& cellValueProxy);
        void CellValueSet5Test(CellValueProxy& cellValueProxy);
        void CellValueSet6Test(CellValueProxy& cellValueProxy);

        void CellValueEqual0Test(CellValueProxy& cellValueProxy);
        void CellValueEqual1Test(CellValueProxy& cellValueProxy);
        void CellValueEqual2Test(CellValueProxy& cellValueProxy);
        void CellValueEqual3Test(CellValueProxy& cellValueProxy);
        void CellValueEqual4Test(CellValueProxy& cellValueProxy);

    private:
        DocumentSharedPtr document;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_PROXY_TESTING_H
