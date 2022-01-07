///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/15 17:03)

#include "DataTypeDescribeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/DataTypeDescribe.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::DataTypeDescribeTesting::DataTypeDescribeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DataTypeDescribeTesting)

void CoreTools::DataTypeDescribeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DataTypeDescribeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DataTypeDescribeTest);
}

void CoreTools::DataTypeDescribeTesting::DataTypeDescribeTest()
{
    constexpr DataTypeDescribe dataTypeDescribe{ CSVDataType::String, SYSTEM_TEXT("string"sv), SYSTEM_TEXT("System::String"sv), SYSTEM_TEXT("GetString"sv), SYSTEM_TEXT("System::String"sv), SYSTEM_TEXT(""sv) };

    ASSERT_ENUM_EQUAL(dataTypeDescribe.GetCsvDataType(), CSVDataType::String);
    ASSERT_EQUAL(dataTypeDescribe.GetDescribe().data(), SYSTEM_TEXT("string"));
    ASSERT_EQUAL(dataTypeDescribe.GetActualType().data(), SYSTEM_TEXT("System::String"));
    ASSERT_EQUAL(dataTypeDescribe.GetFunctionName().data(), SYSTEM_TEXT("GetString"));
    ASSERT_EQUAL(dataTypeDescribe.GetValueType().data(), SYSTEM_TEXT("System::String"));
    ASSERT_EQUAL(dataTypeDescribe.GetBaseReturnDescribe().data(), SYSTEM_TEXT(""));
}
