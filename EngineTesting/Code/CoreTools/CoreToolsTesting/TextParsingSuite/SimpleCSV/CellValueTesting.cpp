/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 18:00)

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
    ASSERT_NOT_THROW_EXCEPTION_0(CreateInt32Test);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateInt64Test);
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
    const auto cellValue = CellValue::CreateDefault();

    ASSERT_EQUAL(cellValue.GetType(), ValueType::Empty);
    ASSERT_EQUAL(cellValue.GetString(), ""s);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "empty"s);
}

void CoreTools::CellValueTesting::CreateErrorTest()
{
    const auto cellValue = CellValue::CreateError();

    ASSERT_EQUAL(cellValue.GetType(), ValueType::Error);
    ASSERT_EQUAL(cellValue.GetString(), ""s);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "error"s);
}

void CoreTools::CellValueTesting::CreateBoolTest()
{
    const CellValue cellValue{ true };

    ASSERT_EQUAL(cellValue.GetType(), ValueType::Boolean);
    ASSERT_EQUAL(cellValue.GetBool(), true);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "boolean"s);
}

void CoreTools::CellValueTesting::CreateInt32Test()
{
    const CellValue cellValue{ 11 };

    ASSERT_EQUAL(cellValue.GetType(), ValueType::Integer);
    ASSERT_EQUAL(cellValue.GetIntegral(), 11);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "integer"s);
}

void CoreTools::CellValueTesting::CreateInt64Test()
{
    const CellValue cellValue{ 11LL };

    ASSERT_EQUAL(cellValue.GetType(), ValueType::Integer);
    ASSERT_EQUAL(cellValue.GetIntegral(), 11);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "integer"s);
}

void CoreTools::CellValueTesting::CreateDoubleTest()
{
    const CellValue cellValue{ 1.2 };

    ASSERT_EQUAL(cellValue.GetType(), ValueType::Float);
    ASSERT_APPROXIMATE(cellValue.GetDouble(), 1.2, Mathematics::MathD::epsilon);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "float"s);
}

void CoreTools::CellValueTesting::CreateStringTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateString0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateString1Test);
}

void CoreTools::CellValueTesting::CreateString0Test()
{
    const CellValue cellValue0{ "cellValue0" };

    ASSERT_EQUAL(cellValue0.GetType(), ValueType::String);
    ASSERT_EQUAL(cellValue0.GetString(), "cellValue0"s);
    ASSERT_EQUAL(cellValue0.GetTypeAsString(), "string"s);
}

void CoreTools::CellValueTesting::CreateString1Test()
{
    const CellValue cellValue1{ "cellValue1"s };

    ASSERT_EQUAL(cellValue1.GetType(), ValueType::String);
    ASSERT_EQUAL(cellValue1.GetString(), "cellValue1"s);
    ASSERT_EQUAL(cellValue1.GetTypeAsString(), "string"s);
}

void CoreTools::CellValueTesting::ClearTest()
{
    CellValue cellValue{ true };

    cellValue.Clear();
    ASSERT_EQUAL(cellValue.GetType(), ValueType::Empty);
    ASSERT_EQUAL(cellValue.GetString(), ""s);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "empty"s);
}

void CoreTools::CellValueTesting::CellValueErrorTest()
{
    CellValue cellValue{ true };

    cellValue.SetError();
    ASSERT_EQUAL(cellValue.GetType(), ValueType::Error);
    ASSERT_EQUAL(cellValue.GetString(), ""s);
    ASSERT_EQUAL(cellValue.GetTypeAsString(), "error"s);
}

void CoreTools::CellValueTesting::CellValueSetTest()
{
    auto cellValue = CellValue::CreateDefault();

    ASSERT_EQUAL(cellValue.GetType(), ValueType::Empty);
    ASSERT_EQUAL(cellValue.Get<std::string>(), ""s);

    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet0Test, cellValue);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet1Test, cellValue);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet2Test, cellValue);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet3Test, cellValue);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet4Test, cellValue);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet5Test, cellValue);
}

void CoreTools::CellValueTesting::CellValueSet0Test(CellValue& cellValue)
{
    cellValue.Set(5);
    ASSERT_EQUAL(cellValue.GetType(), ValueType::Integer);
    ASSERT_EQUAL(cellValue.Get<int>(), 5);
}

void CoreTools::CellValueTesting::CellValueSet1Test(CellValue& cellValue)
{
    cellValue.Set(5.9);
    ASSERT_EQUAL(cellValue.GetType(), ValueType::Float);
    ASSERT_APPROXIMATE(cellValue.Get<double>(), 5.9, Mathematics::MathD::epsilon);
}

void CoreTools::CellValueTesting::CellValueSet2Test(CellValue& cellValue)
{
    cellValue.Set(true);
    ASSERT_EQUAL(cellValue.GetType(), ValueType::Boolean);
    ASSERT_EQUAL(cellValue.Get<bool>(), true);
}

void CoreTools::CellValueTesting::CellValueSet3Test(CellValue& cellValue)
{
    cellValue.Set("cellValue0");
    ASSERT_EQUAL(cellValue.GetType(), ValueType::String);
    ASSERT_EQUAL(cellValue.Get<std::string>(), "cellValue0"s);
}

void CoreTools::CellValueTesting::CellValueSet4Test(CellValue& cellValue)
{
    cellValue.Set("cellValue1"s);
    ASSERT_EQUAL(cellValue.GetType(), ValueType::String);
    ASSERT_EQUAL(cellValue.Get<std::string>(), "cellValue1"s);
}

void CoreTools::CellValueTesting::CellValueSet5Test(const CellValue& cellValue)
{
    auto cellValue1 = CellValue::CreateDefault();
    cellValue1.Set(cellValue);
    ASSERT_EQUAL(cellValue1.GetType(), ValueType::String);
    ASSERT_EQUAL(cellValue1.Get<std::string>(), "cellValue1"s);
}

void CoreTools::CellValueTesting::CellValueEqualTest()
{
    auto cellValue = CellValue::CreateDefault();

    ASSERT_EQUAL(cellValue.GetType(), ValueType::Empty);
    ASSERT_EQUAL(static_cast<std::string>(cellValue), ""s);

    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual0Test, cellValue);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual1Test, cellValue);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual2Test, cellValue);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual3Test, cellValue);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual4Test, cellValue);
}

void CoreTools::CellValueTesting::CellValueEqual0Test(CellValue& cellValue)
{
    cellValue = 5;
    ASSERT_EQUAL(cellValue.GetType(), ValueType::Integer);
    ASSERT_EQUAL(static_cast<int>(cellValue), 5);
}

void CoreTools::CellValueTesting::CellValueEqual1Test(CellValue& cellValue)
{
    cellValue = 5.9;
    ASSERT_EQUAL(cellValue.GetType(), ValueType::Float);
    ASSERT_APPROXIMATE(static_cast<double>(cellValue), 5.9, Mathematics::MathD::epsilon);
}

void CoreTools::CellValueTesting::CellValueEqual2Test(CellValue& cellValue)
{
    cellValue = true;
    ASSERT_EQUAL(cellValue.GetType(), ValueType::Boolean);
    ASSERT_EQUAL(static_cast<bool>(cellValue), true);
}

void CoreTools::CellValueTesting::CellValueEqual3Test(CellValue& cellValue)
{
    cellValue = "cellValue0";
    ASSERT_EQUAL(cellValue.GetType(), ValueType::String);
    ASSERT_EQUAL(static_cast<std::string>(cellValue), "cellValue0"s);
}

void CoreTools::CellValueTesting::CellValueEqual4Test(CellValue& cellValue)
{
    cellValue = "cellValue1"s;
    ASSERT_EQUAL(cellValue.GetType(), ValueType::String);
    ASSERT_EQUAL(static_cast<std::string>(cellValue), "cellValue1"s);
}

void CoreTools::CellValueTesting::EqualTest()
{
    const CellValue cellValue0{ 11 };
    const CellValue cellValue1{ "22" };

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
    const CellValue cellValue0{ 11 };
    const CellValue cellValue1{ "22" };

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
    const CellValue cellValue{ "22" };
    std::stringstream ss{};

    ss << cellValue;

    ASSERT_UNEQUAL(ss.str().find("22"), std::string::npos);
}
