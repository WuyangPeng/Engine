/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 18:18)

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
    constexpr DataTypeDescribe dataTypeDescribe{ CSVDataType::String, SYSTEM_TEXT("string"sv), SYSTEM_TEXT("System::String"sv), SYSTEM_TEXT("GetString"sv), SYSTEM_TEXT("System::String"sv), SYSTEM_TEXT(""sv), SYSTEM_TEXT("String"sv) };

    ASSERT_EQUAL(dataTypeDescribe.GetCsvDataType(), CSVDataType::String);
    ASSERT_EQUAL(dataTypeDescribe.GetDescribe().data(), SYSTEM_TEXT("string"));
    ASSERT_EQUAL(dataTypeDescribe.GetActualType().data(), SYSTEM_TEXT("System::String"));
    ASSERT_EQUAL(dataTypeDescribe.GetFunctionName().data(), SYSTEM_TEXT("GetString"));
    ASSERT_EQUAL(dataTypeDescribe.GetValueType().data(), SYSTEM_TEXT("System::String"));
    ASSERT_EQUAL(dataTypeDescribe.GetBaseReturnDescribe().data(), SYSTEM_TEXT(""));
    ASSERT_EQUAL(dataTypeDescribe.GetAbbreviation().data(), SYSTEM_TEXT("String"));
}