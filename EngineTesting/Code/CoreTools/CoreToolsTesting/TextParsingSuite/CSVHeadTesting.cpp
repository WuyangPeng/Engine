///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/26 16:07)

#include "CSVHeadTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/CSV/ExcelConversionCSV.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using System::operator++;
using namespace std::literals;

CoreTools::CSVHeadTesting::CSVHeadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVHeadTesting)

void CoreTools::CSVHeadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CSVHeadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateCSV);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVHeadTest);
}

void CoreTools::CSVHeadTesting::CreateCSV()
{
    ExcelConversionCSV excelConversionCSV{ "Resource/CSVTesting/CSVHeadTesting.xlsx"s, SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s), false };
}

CoreTools::CSVHeadTesting::FileContent CoreTools::CSVHeadTesting::ReadFile()
{
    FileContent fileContent{};

    const IFStreamManager streamManager{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s) };

    const auto content = streamManager.GetFileContent();

    std::vector<String> row{};
    split(row, content, boost::is_any_of(SYSTEM_TEXT("\r\n")), boost::token_compress_on);

    auto csvType = CSVType::Format;
    for (const auto& value : row)
    {
        fileContent.emplace_back(value);

        ++csvType;
        if (CSVType::VariableName < csvType)
        {
            break;
        }
    }

    return fileContent;
}

void CoreTools::CSVHeadTesting::CSVHeadTest()
{
    CSVHead csvHead{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s), ReadFile() };

    ASSERT_ENUM_EQUAL(csvHead.GetCSVFormatType(), CSVFormatType::Default);
    ASSERT_EQUAL(csvHead.GetNameSpace(), SYSTEM_TEXT("CSVHead"s));
    ASSERT_EQUAL(csvHead.GetCSVClassName(), SYSTEM_TEXT("CSVHeadTesting"s));
    ASSERT_EQUAL(csvHead.GetCompleteClassName(), SYSTEM_TEXT("CSVHead::CSVHeadTesting"s));
    ASSERT_TRUE(csvHead.GetKey().empty());
    ASSERT_TRUE(csvHead.GetKeyName().empty());

    ASSERT_TRUE(csvHead.HasArrayDataType());
    ASSERT_TRUE(csvHead.HasVectorArrayDataType());

    for (auto i = 0; i < csvHead.GetCount(); ++i)
    {
        auto mapping = csvHead.GetMapping(i);
        ASSERT_TRUE(mapping.empty());
        ASSERT_FALSE(csvHead.HasMapping());

        auto scope = csvHead.GetScope(i);
        ASSERT_TRUE(scope.empty());
        ASSERT_FALSE(csvHead.HasScope());
        ASSERT_TRUE(csvHead.GetScopeExpression(i).empty());

        auto defaultValue = csvHead.GetDefaultValue(i);
        ASSERT_TRUE(defaultValue.empty());

        auto annotation = csvHead.GetAnnotation(i);
        ASSERT_FALSE(annotation.empty());

        const auto csvDataType = csvHead.GetDataType(i);
        auto enumTypeName = csvHead.GetEnumTypeName(i);

        if (csvDataType == CSVDataType::Enum || csvDataType == CSVDataType::EnumArray)
        {
            ASSERT_EQUAL(enumTypeName, SYSTEM_TEXT("CSVDataType"s));
            ASSERT_EQUAL(enumTypeName, csvHead.GetActualType(i));
            ASSERT_EQUAL(SYSTEM_TEXT("CSVHead::"s) + enumTypeName, csvHead.GetActualTypeByNameSpace(i));
        }
        else
        {
            ASSERT_TRUE(enumTypeName.empty());
            ASSERT_EQUAL(CSVTypeConversion::GetActualType(csvDataType), csvHead.GetActualType(i));
            ASSERT_EQUAL(CSVTypeConversion::GetValueType(csvDataType), csvHead.GetValueType(i));
            ASSERT_EQUAL(CSVTypeConversion::GetActualType(csvDataType), csvHead.GetActualTypeByNameSpace(i));
        }

        auto variableName = csvHead.GetVariableName(i);
        ASSERT_FALSE(variableName.empty());

        auto upperVariableName = csvHead.GetUpperVariableName(i);
        ASSERT_FALSE(upperVariableName.empty());

        auto functionVariableName = csvHead.GetFunctionVariableName(i);
        ASSERT_FALSE(functionVariableName.empty());

        auto functionName = csvHead.GetFunctionName(i);
        ASSERT_FALSE(functionName.empty());

        ASSERT_TRUE(csvHead.HasDataType(csvDataType));

        ASSERT_ENUM_EQUAL(csvHead.GetDataType(i), csvHead.GetDataType(variableName));

        ASSERT_EQUAL(i, csvHead.GetDataIndex(variableName));
        ASSERT_EQUAL(i, csvHead.GetDataIndex(System::StringView{ variableName }));

        ASSERT_TRUE(csvHead.HasDataField(variableName));
        ASSERT_TRUE(csvHead.HasDataField(System::StringView{ variableName }));
    }
}
