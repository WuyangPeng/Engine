/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:40)

#include "CellValueTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;

CoreTools::CellValueTesting::CellValueTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CellValueTesting)

void CoreTools::CellValueTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CellValueTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateDefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateBoolTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateIntTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateDoubleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClearTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueSetTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueEqualTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EqualTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OStreamTest);
}

void CoreTools::CellValueTesting::CreateDefaultTest()
{
    const auto cellValue = SimpleCSV::CellValue::CreateDefault();

    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Empty);
    ASSERT_EQUAL(cellValue.GetString(), ""s);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "empty"s);
}

void CoreTools::CellValueTesting::CreateErrorTest()
{
    const auto cellValue = SimpleCSV::CellValue::CreateError();

    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Error);
    ASSERT_EQUAL(cellValue.GetString(), ""s);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "error"s);
}

void CoreTools::CellValueTesting::CreateBoolTest()
{
    const SimpleCSV::CellValue cellValue{ true };

    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Boolean);
    ASSERT_EQUAL(cellValue.GetBool(), true);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "boolean"s);
}

void CoreTools::CellValueTesting::CreateIntTest()
{
    const SimpleCSV::CellValue cellValue0{ 11 };

    ASSERT_EQUAL(cellValue0.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValue0.GetIntegral(), 11);
    ASSERT_EQUAL(cellValue0.GetTypeAsString(), "integer"s);

    const SimpleCSV::CellValue cellValue1{ 11LL };

    ASSERT_EQUAL(cellValue1.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValue1.GetIntegral(), 11);
    ASSERT_EQUAL(cellValue1.GetTypeAsString(), "integer"s);
}

void CoreTools::CellValueTesting::CreateDoubleTest()
{
    const SimpleCSV::CellValue cellValue{ 1.2 };

    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_APPROXIMATE(cellValue.GetDouble(), 1.2, Mathematics::MathD::epsilon);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "float"s);
}

void CoreTools::CellValueTesting::CreateStringTest()
{
    const SimpleCSV::CellValue cellValue0{ "cellValue0" };

    ASSERT_EQUAL(cellValue0.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValue0.GetString(), "cellValue0"s);
    ASSERT_EQUAL(cellValue0.GetTypeAsString(), "string"s);

    const SimpleCSV::CellValue cellValue1{ "cellValue1"s };

    ASSERT_EQUAL(cellValue1.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValue1.GetString(), "cellValue1"s);
    ASSERT_EQUAL(cellValue1.GetTypeAsString(), "string"s);
}

void CoreTools::CellValueTesting::ClearTest()
{
    SimpleCSV::CellValue cellValue{ true };

    cellValue.Clear();
    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Empty);
    ASSERT_EQUAL(cellValue.GetString(), ""s);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "empty"s);
}

void CoreTools::CellValueTesting::CellValueErrorTest()
{
    SimpleCSV::CellValue cellValue{ true };

    cellValue.SetError();
    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Error);
    ASSERT_EQUAL(cellValue.GetString(), ""s);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "error"s);
}

void CoreTools::CellValueTesting::CellValueSetTest()
{
    auto cellValue0 = SimpleCSV::CellValue::CreateDefault();

    ASSERT_EQUAL(cellValue0.GetType(), SimpleCSV::ValueType::Empty);
    ASSERT_EQUAL(cellValue0.Get<std::string>(), ""s);

    cellValue0.Set(5);
    ASSERT_EQUAL(cellValue0.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValue0.Get<int>(), 5);

    cellValue0.Set(5.9);
    ASSERT_EQUAL(cellValue0.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_APPROXIMATE(cellValue0.Get<double>(), 5.9, Mathematics::MathD::epsilon);

    cellValue0.Set(true);
    ASSERT_EQUAL(cellValue0.GetType(), SimpleCSV::ValueType::Boolean);
    ASSERT_EQUAL(cellValue0.Get<bool>(), true);

    cellValue0.Set("cellValue0");
    ASSERT_EQUAL(cellValue0.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValue0.Get<std::string>(), "cellValue0"s);

    cellValue0.Set("cellValue1"s);
    ASSERT_EQUAL(cellValue0.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValue0.Get<std::string>(), "cellValue1"s);

    auto cellValue1 = SimpleCSV::CellValue::CreateDefault();
    cellValue1.Set(cellValue0);
    ASSERT_EQUAL(cellValue1.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValue1.Get<std::string>(), "cellValue1"s);
}

void CoreTools::CellValueTesting::CellValueEqualTest()
{
    auto cellValue = SimpleCSV::CellValue::CreateDefault();

    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Empty);
    ASSERT_EQUAL(static_cast<std::string>(cellValue), ""s);

    cellValue = 5;
    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(static_cast<int>(cellValue), 5);

    cellValue = 5.9;
    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_APPROXIMATE(static_cast<double>(cellValue), 5.9, Mathematics::MathD::epsilon);

    cellValue = true;
    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::Boolean);
    ASSERT_EQUAL(static_cast<bool>(cellValue), true);

    cellValue = "cellValue0";
    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(static_cast<std::string>(cellValue), "cellValue0"s);

    cellValue = "cellValue1"s;
    ASSERT_EQUAL(cellValue.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(static_cast<std::string>(cellValue), "cellValue1"s);
}

void CoreTools::CellValueTesting::EqualTest()
{
    const SimpleCSV::CellValue cellValue0{ 11 };
    const SimpleCSV::CellValue cellValue1{ "22" };

    ASSERT_TRUE(cellValue0 == cellValue0);
    ASSERT_TRUE(cellValue1 == cellValue1);
    ASSERT_TRUE(cellValue1 != cellValue0);

    ASSERT_FALSE(cellValue0 != cellValue0);
    ASSERT_FALSE(cellValue1 != cellValue1);
    ASSERT_FALSE(cellValue1 == cellValue0);

    ASSERT_TRUE(cellValue0.IsEqual(cellValue0));
}

void CoreTools::CellValueTesting::LessTest()
{
    const SimpleCSV::CellValue cellValue0{ 11 };
    const SimpleCSV::CellValue cellValue1{ "22" };

    if (cellValue0 < cellValue1)
    {
        ASSERT_TRUE(cellValue0 < cellValue1);
        ASSERT_TRUE(cellValue0 <= cellValue0);
        ASSERT_TRUE(cellValue0 <= cellValue1);
        ASSERT_TRUE(cellValue1 <= cellValue1);

        ASSERT_FALSE(cellValue0 > cellValue1);
        ASSERT_FALSE(cellValue0 >= cellValue1);

        ASSERT_TRUE(cellValue0.IsLess(cellValue1));
    }
    else
    {
        ASSERT_TRUE(cellValue1 < cellValue0);
        ASSERT_TRUE(cellValue0 <= cellValue0);
        ASSERT_TRUE(cellValue1 <= cellValue0);
        ASSERT_TRUE(cellValue1 <= cellValue1);

        ASSERT_FALSE(cellValue1 > cellValue0);
        ASSERT_FALSE(cellValue1 >= cellValue0);

        ASSERT_FALSE(cellValue0.IsLess(cellValue1));
    }
}

void CoreTools::CellValueTesting::OStreamTest()
{
    const SimpleCSV::CellValue cellValue{ "22" };
    std::stringstream ss{};

    ss << cellValue;

    ASSERT_UNEQUAL(ss.str().find("22"), std::string::npos);
}
