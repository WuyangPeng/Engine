/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/03 10:28)

#include "CellReferenceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Constants.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CellReferenceTesting::CellReferenceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      randomEngine{ GetEngineRandomSeed() },
      rowRandomDistribution{ 1, SimpleCSV::gMaxRows },
      alphabetRandomDistribution{ 1, alphabetSize }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CellReferenceTesting)

void CoreTools::CellReferenceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CellReferenceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CellAddressTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OneLetterColumnTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(TwoLetterRowTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ThreeLetterRowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetColumnTest);
}

void CoreTools::CellReferenceTesting::CellAddressTest()
{
    const CellReference cellReference{ "A1" };

    ASSERT_EQUAL(cellReference.GetColumn(), 1);
    ASSERT_EQUAL(cellReference.GetRow(), 1);
    ASSERT_EQUAL(cellReference.GetAddress(), "A1");
}

bool CoreTools::CellReferenceTesting::RowTest()
{
    const auto row = rowRandomDistribution(randomEngine);
    CellReference cellReference{ row, 500 };

    ASSERT_EQUAL(cellReference.GetColumn(), 500);
    ASSERT_EQUAL(cellReference.GetRow(), row);

    ASSERT_NOT_THROW_EXCEPTION_2(GetAddressTest, row, cellReference);

    ASSERT_NOT_THROW_EXCEPTION_1(SetRowTest, cellReference);

    return true;
}

void CoreTools::CellReferenceTesting::SetRowTest(CellReference& cellReference)
{
    const auto row = rowRandomDistribution(randomEngine);
    cellReference.SetRow(row);
    ASSERT_EQUAL(cellReference.GetRow(), row);
}

void CoreTools::CellReferenceTesting::GetAddressTest(int row, const CellReference& cellReference0)
{
    ASSERT_EQUAL(cellReference0.GetAddress(), "SF" + std::to_string(row));

    const CellReference cellReference1{ cellReference0.GetAddress() };
    ASSERT_EQUAL(cellReference0, cellReference1);
}

void CoreTools::CellReferenceTesting::OneLetterColumnTest()
{
    for (auto column = 1; column <= alphabetSize; ++column)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoOneLetterColumnTest, column);
    }
}

void CoreTools::CellReferenceTesting::DoOneLetterColumnTest(int column)
{
    constexpr auto row = 100;
    const std::string address{ boost::numeric_cast<char>(column + 'A' - 1) };
    const CellReference cellReference{ row, address };

    DoOneLetterColumn0Test(row, column, address, cellReference);

    ASSERT_NOT_THROW_EXCEPTION_2(DoOneLetterColumn1Test, row, cellReference);

    ASSERT_NOT_THROW_EXCEPTION_2(DoOneLetterColumn2Test, column, cellReference);
}

void CoreTools::CellReferenceTesting::DoOneLetterColumn0Test(int row, int column, const std::string& address, const CellReference& cellReference)
{
    ASSERT_EQUAL(cellReference.GetColumn(), column);
    ASSERT_EQUAL(cellReference.GetRow(), row);

    ASSERT_EQUAL(cellReference.GetAddress(), address + std::to_string(row));
}

void CoreTools::CellReferenceTesting::DoOneLetterColumn1Test(const int row, const CellReference& cellReference0)
{
    const CellReference cellReference1{ row, cellReference0.GetColumn() };
    ASSERT_EQUAL(cellReference0, cellReference1);
}

void CoreTools::CellReferenceTesting::DoOneLetterColumn2Test(int column, const CellReference& cellReference0)
{
    CellReference cellReference1{ cellReference0.GetAddress() };
    ASSERT_EQUAL(cellReference0, cellReference1);

    cellReference1.SetColumn(column + 1);
    ASSERT_EQUAL(cellReference1.GetColumn(), column + 1);
}

bool CoreTools::CellReferenceTesting::TwoLetterRowTest()
{
    constexpr auto row = 105;
    const auto column0 = alphabetRandomDistribution(randomEngine);
    const auto column1 = alphabetRandomDistribution(randomEngine);
    const auto address = std::string{ boost::numeric_cast<char>(column0 + 'A' - 1) } + std::string{ boost::numeric_cast<char>(column1 + 'A' - 1) };
    const CellReference cellReference{ row, address };

    TwoLetterRow0Test(row, column0, column1, address, cellReference);

    ASSERT_NOT_THROW_EXCEPTION_2(TwoLetterRow1Test, row, cellReference);

    ASSERT_NOT_THROW_EXCEPTION_1(TwoLetterRow2Test, cellReference);

    return true;
}

void CoreTools::CellReferenceTesting::TwoLetterRow0Test(int row,
                                                        int column0,
                                                        int column1,
                                                        const std::string& address,
                                                        const CellReference& cellReference)
{
    ASSERT_EQUAL(cellReference.GetColumn(), column0 * alphabetSize + column1);
    ASSERT_EQUAL(cellReference.GetRow(), row);

    ASSERT_EQUAL(cellReference.GetAddress(), address + std::to_string(row));
}

void CoreTools::CellReferenceTesting::TwoLetterRow1Test(int row, const CellReference& cellReference0)
{
    const CellReference cellReference1{ row, cellReference0.GetColumn() };
    ASSERT_EQUAL(cellReference0, cellReference1);
}

void CoreTools::CellReferenceTesting::TwoLetterRow2Test(const CellReference& cellReference0)
{
    CellReference cellReference1{ cellReference0.GetAddress() };
    ASSERT_EQUAL(cellReference0, cellReference1);

    cellReference1.SetRowAndColumn(cellReference0.GetRow() + 1, cellReference0.GetColumn() + 1);
    ASSERT_EQUAL(cellReference1.GetColumn(), cellReference0.GetColumn() + 1);
    ASSERT_EQUAL(cellReference1.GetRow(), cellReference0.GetRow() + 1);
}

bool CoreTools::CellReferenceTesting::ThreeLetterRowTest()
{
    constexpr auto row = 1051;
    const auto column0 = alphabetRandomDistribution(randomEngine);
    const auto column1 = alphabetRandomDistribution(randomEngine);
    const auto column2 = alphabetRandomDistribution(randomEngine);
    const auto address = std::string{ boost::numeric_cast<char>(column0 + 'A' - 1) } + std::string{ boost::numeric_cast<char>(column1 + 'A' - 1) } + std::string{ boost::numeric_cast<char>(column2 + 'A' - 1) };
    const CellReference cellReference{ row, address };

    ThreeLetterRow0Test(row, column0, column1, column2, address, cellReference);

    ASSERT_NOT_THROW_EXCEPTION_2(ThreeLetterRow1Test, row, cellReference);

    ASSERT_NOT_THROW_EXCEPTION_1(ThreeLetterRow2Test, cellReference);

    return true;
}

void CoreTools::CellReferenceTesting::ThreeLetterRow0Test(int row,
                                                          int column0,
                                                          int column1,
                                                          int column2,
                                                          const std::string& address,
                                                          const CellReference& cellReference)
{
    ASSERT_EQUAL(cellReference.GetColumn(), column0 * alphabetSize * alphabetSize + column1 * alphabetSize + column2);
    ASSERT_EQUAL(cellReference.GetRow(), row);

    ASSERT_EQUAL(cellReference.GetAddress(), address + std::to_string(row));
}

void CoreTools::CellReferenceTesting::ThreeLetterRow1Test(const int row, const CellReference& cellReference0)
{
    const CellReference cellReference1{ row, cellReference0.GetColumn() };
    ASSERT_EQUAL(cellReference0, cellReference1);
}

void CoreTools::CellReferenceTesting::ThreeLetterRow2Test(const CellReference& cellReference0)
{
    CellReference cellReference1{ cellReference0.GetAddress() };
    ASSERT_EQUAL(cellReference0, cellReference1);

    cellReference1.SetAddress("A1");
    ASSERT_EQUAL(cellReference1.GetColumn(), 1);
    ASSERT_EQUAL(cellReference1.GetRow(), 1);
    ASSERT_EQUAL(cellReference1.GetAddress(), "A1");

    cellReference1.SetAddress(cellReference0.GetAddress());
    ASSERT_EQUAL(cellReference0, cellReference1);
}

void CoreTools::CellReferenceTesting::OperatorTest()
{
    const CellReference cellReference0{ "A1" };
    const CellReference cellReference1{ "A2" };

    ASSERT_FALSE(cellReference0 < cellReference0);
    ASSERT_FALSE(cellReference1 < cellReference1);
    ASSERT_TRUE(cellReference0 <= cellReference0);
    ASSERT_TRUE(cellReference1 <= cellReference1);
    ASSERT_FALSE(cellReference0 > cellReference0);
    ASSERT_FALSE(cellReference1 > cellReference1);
    ASSERT_TRUE(cellReference0 >= cellReference0);
    ASSERT_TRUE(cellReference1 >= cellReference1);
    ASSERT_TRUE(cellReference0 == cellReference0);
    ASSERT_TRUE(cellReference1 == cellReference1);
    ASSERT_FALSE(cellReference0 != cellReference0);
    ASSERT_FALSE(cellReference1 != cellReference1);

    ASSERT_TRUE(cellReference0 < cellReference1);
    ASSERT_TRUE(cellReference0 <= cellReference1);
    ASSERT_FALSE(cellReference0 > cellReference1);
    ASSERT_FALSE(cellReference0 >= cellReference1);

    ASSERT_FALSE(cellReference0 == cellReference1);
    ASSERT_TRUE(cellReference0 != cellReference1);
}

void CoreTools::CellReferenceTesting::GetColumnTest()
{
    ASSERT_EQUAL(CellReference::GetColumn("A1"), 1);
}
