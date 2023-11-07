///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:11)

#include "CellReferenceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Constants.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CellReferenceTesting::CellReferenceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      randomEngine{ GetEngineRandomSeed() }
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
}

void CoreTools::CellReferenceTesting::CellAddressTest()
{
    const SimpleCSV::CellReference cellReference{ "A1"s };

    ASSERT_EQUAL(cellReference.GetColumn(), 1);
    ASSERT_EQUAL(cellReference.GetRow(), 1);
    ASSERT_EQUAL(cellReference.GetAddress(), "A1"s);
}

bool CoreTools::CellReferenceTesting::RowTest()
{
    std::uniform_int_distribution<> randomDistribution{ 1, SimpleCSV::gMaxRows };
    auto row = randomDistribution(randomEngine);
    SimpleCSV::CellReference cellReference0{ row, 500 };

    ASSERT_EQUAL(cellReference0.GetColumn(), 500);
    ASSERT_EQUAL(cellReference0.GetRow(), row);

    ASSERT_EQUAL(cellReference0.GetAddress(), "SF" + std::to_string(row));

    const SimpleCSV::CellReference cellReference1{ cellReference0.GetAddress() };
    ASSERT_EQUAL(cellReference0, cellReference1);

    row = randomDistribution(randomEngine);
    cellReference0.SetRow(row);
    ASSERT_EQUAL(cellReference0.GetRow(), row);

    return true;
}

void CoreTools::CellReferenceTesting::OneLetterColumnTest()
{
    for (auto column = 1; column <= alphabetSize; ++column)
    {
        const std::string address{ boost::numeric_cast<char>(column + 'A' - 1) };
        SimpleCSV::CellReference cellReference0{ 100, address };

        ASSERT_EQUAL(cellReference0.GetColumn(), column);
        ASSERT_EQUAL(cellReference0.GetRow(), 100);

        ASSERT_EQUAL(cellReference0.GetAddress(), address + "100");

        SimpleCSV::CellReference cellReference1{ 100, cellReference0.GetColumn() };
        ASSERT_EQUAL(cellReference0, cellReference1);

        SimpleCSV::CellReference cellReference2{ cellReference0.GetAddress() };
        ASSERT_EQUAL(cellReference0, cellReference2);

        cellReference2.SetColumn(column + 1);
        ASSERT_EQUAL(cellReference2.GetColumn(), column + 1);
    }
}

bool CoreTools::CellReferenceTesting::TwoLetterRowTest()
{
    std::uniform_int_distribution<> randomDistribution{ 1, alphabetSize };
    const auto column0 = randomDistribution(randomEngine);
    const auto column1 = randomDistribution(randomEngine);
    const auto address = std::string{ boost::numeric_cast<char>(column0 + 'A' - 1) } + std::string{ boost::numeric_cast<char>(column1 + 'A' - 1) };
    const SimpleCSV::CellReference cellReference0{ 105, address };

    ASSERT_EQUAL(cellReference0.GetColumn(), column0 * alphabetSize + column1);
    ASSERT_EQUAL(cellReference0.GetRow(), 105);

    ASSERT_EQUAL(cellReference0.GetAddress(), address + "105");

    const SimpleCSV::CellReference cellReference1{ 105, cellReference0.GetColumn() };
    ASSERT_EQUAL(cellReference0, cellReference1);

    SimpleCSV::CellReference cellReference2{ cellReference0.GetAddress() };
    ASSERT_EQUAL(cellReference0, cellReference2);

    cellReference2.SetRowAndColumn(cellReference0.GetRow() + 1, cellReference0.GetColumn() + 1);
    ASSERT_EQUAL(cellReference2.GetColumn(), cellReference0.GetColumn() + 1);
    ASSERT_EQUAL(cellReference2.GetRow(), cellReference0.GetRow() + 1);

    return true;
}

bool CoreTools::CellReferenceTesting::ThreeLetterRowTest()
{
    std::uniform_int_distribution<> randomDistribution{ 1, alphabetSize };
    const auto column0 = randomDistribution(randomEngine);
    const auto column1 = randomDistribution(randomEngine);
    const auto column2 = randomDistribution(randomEngine);
    const auto address = std::string{ boost::numeric_cast<char>(column0 + 'A' - 1) } + std::string{ boost::numeric_cast<char>(column1 + 'A' - 1) } + std::string{ boost::numeric_cast<char>(column2 + 'A' - 1) };
    const SimpleCSV::CellReference cellReference0{ 1051, address };

    ASSERT_EQUAL(cellReference0.GetColumn(), column0 * alphabetSize * alphabetSize + column1 * alphabetSize + column2);
    ASSERT_EQUAL(cellReference0.GetRow(), 1051);

    ASSERT_EQUAL(cellReference0.GetAddress(), address + "1051");

    const SimpleCSV::CellReference cellReference1{ 1051, cellReference0.GetColumn() };
    ASSERT_EQUAL(cellReference0, cellReference1);

    SimpleCSV::CellReference cellReference2{ cellReference0.GetAddress() };
    ASSERT_EQUAL(cellReference0, cellReference2);

    cellReference2.SetAddress("A1");
    ASSERT_EQUAL(cellReference2.GetColumn(), 1);
    ASSERT_EQUAL(cellReference2.GetRow(), 1);
    ASSERT_EQUAL(cellReference2.GetAddress(), "A1"s);

    cellReference2.SetAddress(cellReference0.GetAddress());
    ASSERT_EQUAL(cellReference0, cellReference2);

    return true;
}

void CoreTools::CellReferenceTesting::OperatorTest()
{
    const SimpleCSV::CellReference cellReference0{ "A1"s };
    const SimpleCSV::CellReference cellReference1{ "A2"s };

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
