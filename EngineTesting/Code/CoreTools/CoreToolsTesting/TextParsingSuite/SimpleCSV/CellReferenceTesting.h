/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:25)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CELL_REFERENCE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CELL_REFERENCE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace CoreTools
{
    class CellReferenceTesting final : public UnitTest
    {
    public:
        using ClassType = CellReferenceTesting;
        using ParentType = UnitTest;

    public:
        explicit CellReferenceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using CellReference = SimpleCSV::CellReference;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CellAddressTest();

        NODISCARD bool RowTest();
        void OneLetterColumnTest();

        NODISCARD bool TwoLetterRowTest();
        NODISCARD bool ThreeLetterRowTest();
        void OperatorTest();
        void GetColumnTest();

        void SetRowTest(CellReference& cellReference);
        void DoOneLetterColumnTest(int column);
        void GetAddressTest(int row, const CellReference& cellReference0);
        void DoOneLetterColumn0Test(int row, int column, const std::string& address, const CellReference& cellReference);
        void DoOneLetterColumn1Test(int row, const CellReference& cellReference0);
        void DoOneLetterColumn2Test(int column, const CellReference& cellReference0);

        void TwoLetterRow0Test(int row,
                               int column0,
                               int column1,
                               const std::string& address,
                               const CellReference& cellReference);
        void TwoLetterRow1Test(int row, const CellReference& cellReference0);
        void TwoLetterRow2Test(const CellReference& cellReference0);

        void ThreeLetterRow0Test(int row,
                                 int column0,
                                 int column1,
                                 int column2,
                                 const std::string& address,
                                 const CellReference& cellReference);
        void ThreeLetterRow1Test(int row, const CellReference& cellReference0);
        void ThreeLetterRow2Test(const CellReference& cellReference0);

    private:
        static constexpr auto alphabetSize = 26;

    private:
        std::default_random_engine randomEngine;
        std::uniform_int_distribution<> rowRandomDistribution;
        std::uniform_int_distribution<> alphabetRandomDistribution;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CELL_REFERENCE_TESTING_H
