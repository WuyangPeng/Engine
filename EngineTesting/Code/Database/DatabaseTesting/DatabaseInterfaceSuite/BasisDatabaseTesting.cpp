///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/25 15:23)

#include "BasisDatabaseTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;

Database::BasisDatabaseTesting::BasisDatabaseTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, BasisDatabaseTesting)

void Database::BasisDatabaseTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::BasisDatabaseTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullTest);
    ASSERT_THROW_EXCEPTION_0(NullExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_THROW_EXCEPTION_0(StringExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Int32Test);
    ASSERT_THROW_EXCEPTION_0(Int32ExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Int64Test);
    ASSERT_THROW_EXCEPTION_0(Int64ExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTest);
    ASSERT_THROW_EXCEPTION_0(DoubleExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoolTest);
    ASSERT_THROW_EXCEPTION_0(BoolExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ByteArrayTest);
    ASSERT_THROW_EXCEPTION_0(ByteArrayExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ObjectTest);
    ASSERT_THROW_EXCEPTION_0(ObjectExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ObjectArrayTest);
    ASSERT_THROW_EXCEPTION_0(ObjectArrayExceptionTest);
}

void Database::BasisDatabaseTesting::NullTest()
{
    const auto fieldName = "Null";
    const BasisDatabase basisDatabase{ fieldName };

    ASSERT_EQUAL(basisDatabase.GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetDataType(), DataType::Null);
    ASSERT_EQUAL_NULL_PTR(basisDatabase.GetValue<DataType::Null>());
    ASSERT_EQUAL_NULL_PTR(std::any_cast<decltype(nullptr)>(basisDatabase.GetAnyValue()));

    ASSERT_TRUE(basisDatabase.GetString().empty());
    ASSERT_TRUE(basisDatabase.GetQuotationMarkString().empty());
    ASSERT_TRUE(basisDatabase.GetSqlFieldString().empty());
}

void Database::BasisDatabaseTesting::NullExceptionTest()
{
    const auto fieldName = "Null";
    const BasisDatabase basisDatabase{ fieldName };

    MAYBE_UNUSED const auto result = basisDatabase.GetValue<DataType::Int32>();
}

void Database::BasisDatabaseTesting::StringTest()
{
    const auto fieldName = "String";
    const auto value = "Value"s;
    const BasisDatabase basisDatabase{ fieldName, value };

    ASSERT_EQUAL(basisDatabase.GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetDataType(), DataType::String);
    ASSERT_EQUAL(basisDatabase.GetValue<DataType::String>(), value);
    ASSERT_EQUAL(std::any_cast<std::string>(basisDatabase.GetAnyValue()), value);

    ASSERT_EQUAL(basisDatabase.GetString(), value);
    ASSERT_EQUAL(basisDatabase.GetSqlFieldString(), "`Value`");
    ASSERT_EQUAL(basisDatabase.GetQuotationMarkString(), "\"Value\"");
}

void Database::BasisDatabaseTesting::StringExceptionTest()
{
    const auto fieldName = "String";
    const auto value = "Value"s;
    const BasisDatabase basisDatabase{ fieldName, value };

    MAYBE_UNUSED const auto result = basisDatabase.GetValue<DataType::Int32>();
}

void Database::BasisDatabaseTesting::Int32Test()
{
    const auto fieldName = "Int32";
    constexpr auto value = 12;
    const BasisDatabase basisDatabase{ fieldName, value };

    ASSERT_EQUAL(basisDatabase.GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetDataType(), DataType::Int32);
    ASSERT_EQUAL(basisDatabase.GetValue<DataType::Int32>(), value);
    ASSERT_EQUAL(std::any_cast<int32_t>(basisDatabase.GetAnyValue()), value);

    ASSERT_EQUAL(basisDatabase.GetString(), "12");
    ASSERT_EQUAL(basisDatabase.GetSqlFieldString(), "12");
    ASSERT_EQUAL(basisDatabase.GetQuotationMarkString(), "12");
}

void Database::BasisDatabaseTesting::Int32ExceptionTest()
{
    const auto fieldName = "Int32";
    constexpr auto value = 12;
    const BasisDatabase basisDatabase{ fieldName, value };

    MAYBE_UNUSED const auto result = basisDatabase.GetValue<DataType::Int64>();
}

void Database::BasisDatabaseTesting::Int64Test()
{
    const auto fieldName = "Int64";
    constexpr auto value = 12LL;
    const BasisDatabase basisDatabase{ fieldName, value };

    ASSERT_EQUAL(basisDatabase.GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetDataType(), DataType::Int64);
    ASSERT_EQUAL(basisDatabase.GetValue<DataType::Int64>(), value);
    ASSERT_EQUAL(std::any_cast<int64_t>(basisDatabase.GetAnyValue()), value);

    ASSERT_EQUAL(basisDatabase.GetString(), "12");
    ASSERT_EQUAL(basisDatabase.GetSqlFieldString(), "12");
    ASSERT_EQUAL(basisDatabase.GetQuotationMarkString(), "12");
}

void Database::BasisDatabaseTesting::Int64ExceptionTest()
{
    const auto fieldName = "Int64";
    constexpr auto value = 12LL;
    const BasisDatabase basisDatabase{ fieldName, value };

    MAYBE_UNUSED const auto result = basisDatabase.GetValue<DataType::Int32>();
}

void Database::BasisDatabaseTesting::DoubleTest()
{
    const auto fieldName = "Double";
    constexpr auto value = 12.1;
    const BasisDatabase basisDatabase{ fieldName, value };

    ASSERT_EQUAL(basisDatabase.GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetDataType(), DataType::Double);
    ASSERT_APPROXIMATE(basisDatabase.GetValue<DataType::Double>(), value, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(std::any_cast<double>(basisDatabase.GetAnyValue()), value, Mathematics::MathD::GetZeroTolerance());

    ASSERT_UNEQUAL(basisDatabase.GetString().find("12.1"), std::string::npos);
    ASSERT_UNEQUAL(basisDatabase.GetSqlFieldString().find("12.1"), std::string::npos);
    ASSERT_UNEQUAL(basisDatabase.GetQuotationMarkString().find("12.1"), std::string::npos);
}

void Database::BasisDatabaseTesting::DoubleExceptionTest()
{
    const auto fieldName = "Double";
    constexpr auto value = 12.1;
    const BasisDatabase basisDatabase{ fieldName, value };

    MAYBE_UNUSED const auto result = basisDatabase.GetValue<DataType::Int32>();
}

void Database::BasisDatabaseTesting::BoolTest()
{
    const auto fieldName = "Bool";
    const BasisDatabase basisDatabase{ fieldName, true };

    ASSERT_EQUAL(basisDatabase.GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetDataType(), DataType::Bool);
    ASSERT_TRUE(basisDatabase.GetValue<DataType::Bool>());
    ASSERT_TRUE(std::any_cast<bool>(basisDatabase.GetAnyValue()));

    ASSERT_EQUAL(basisDatabase.GetString(), "true");
    ASSERT_EQUAL(basisDatabase.GetQuotationMarkString(), "true");
    ASSERT_EQUAL(basisDatabase.GetSqlFieldString(), "true");
}

void Database::BasisDatabaseTesting::BoolExceptionTest()
{
    const auto fieldName = "Bool";
    const BasisDatabase basisDatabase{ fieldName, true };

    MAYBE_UNUSED const auto result = basisDatabase.GetValue<DataType::Int32>();
}

void Database::BasisDatabaseTesting::ByteArrayTest()
{
    const auto fieldName = "ByteArray";
    const std::vector<uint8_t> value{ 1, 2, 3, 4 };
    const BasisDatabase basisDatabase{ fieldName, value };

    ASSERT_EQUAL(basisDatabase.GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetDataType(), DataType::ByteArray);
    ASSERT_EQUAL(basisDatabase.GetValue<DataType::ByteArray>(), value);
    ASSERT_EQUAL(std::any_cast<std::vector<uint8_t>>(basisDatabase.GetAnyValue()), value);

    ASSERT_TRUE(basisDatabase.GetString().empty());
    ASSERT_TRUE(basisDatabase.GetQuotationMarkString().empty());
    ASSERT_TRUE(basisDatabase.GetSqlFieldString().empty());
}

void Database::BasisDatabaseTesting::ByteArrayExceptionTest()
{
    const auto fieldName = "ByteArray";
    const std::vector<uint8_t> value{ 1, 2, 3, 4 };
    const BasisDatabase basisDatabase{ fieldName, value };

    MAYBE_UNUSED const auto result = basisDatabase.GetValue<DataType::Int32>();
}

void Database::BasisDatabaseTesting::ObjectTest()
{
    const auto fieldName = "Object";
    const auto value = std::make_shared<BasisDatabase>(fieldName, 1);
    const BasisDatabase basisDatabase{ fieldName, value };

    ASSERT_EQUAL(basisDatabase.GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetDataType(), DataType::Object);
    ASSERT_EQUAL(basisDatabase.GetValue<DataType::Object>()->GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetValue<DataType::Object>()->GetDataType(), DataType::Int32);
    ASSERT_EQUAL(basisDatabase.GetValue<DataType::Object>()->GetValue<DataType::Int32>(), 1);
    const auto result = std::any_cast<std::shared_ptr<BasisDatabase>>(basisDatabase.GetAnyValue());
    ASSERT_UNEQUAL_NULL_PTR(result);

    ASSERT_TRUE(basisDatabase.GetString().empty());
    ASSERT_TRUE(basisDatabase.GetQuotationMarkString().empty());
    ASSERT_TRUE(basisDatabase.GetSqlFieldString().empty());
}

void Database::BasisDatabaseTesting::ObjectExceptionTest()
{
    const auto fieldName = "Object";
    const auto value = std::make_shared<BasisDatabase>(fieldName, 1);
    const BasisDatabase basisDatabase{ fieldName, value };

    MAYBE_UNUSED const auto result = basisDatabase.GetValue<DataType::Int32>();
}

void Database::BasisDatabaseTesting::ObjectArrayTest()
{
    const auto fieldName = "Object";
    const auto value = std::make_shared<BasisDatabase>(fieldName, 1);
    const std::vector container{ value, value, value };
    const BasisDatabase basisDatabase{ fieldName, container };

    ASSERT_EQUAL(basisDatabase.GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetDataType(), DataType::ObjectArray);

    ASSERT_EQUAL(basisDatabase.GetValue<DataType::ObjectArray>().size(), 3u);

    ASSERT_EQUAL(basisDatabase.GetValue<DataType::ObjectArray>().at(0)->GetFieldName(), fieldName);
    ASSERT_EQUAL(basisDatabase.GetValue<DataType::ObjectArray>().at(1)->GetDataType(), DataType::Int32);
    ASSERT_EQUAL(basisDatabase.GetValue<DataType::ObjectArray>().at(2)->GetValue<DataType::Int32>(), 1);

    const auto result = std::any_cast<std::vector<std::shared_ptr<BasisDatabase>>>(basisDatabase.GetAnyValue());
    ASSERT_EQUAL(result.size(), 3u);

    ASSERT_TRUE(basisDatabase.GetString().empty());
    ASSERT_TRUE(basisDatabase.GetQuotationMarkString().empty());
    ASSERT_TRUE(basisDatabase.GetSqlFieldString().empty());
}

void Database::BasisDatabaseTesting::ObjectArrayExceptionTest()
{
    const auto fieldName = "Object";
    const auto value = std::make_shared<BasisDatabase>(fieldName, 1);
    const std::vector container{ value, value, value };
    const BasisDatabase basisDatabase{ fieldName, container };

    MAYBE_UNUSED const auto result = basisDatabase.GetValue<DataType::Int32>();
}
