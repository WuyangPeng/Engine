/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:50)

#include "CSVHeadTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/CSV/ExcelConversionCSV.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using System::operator++;

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
    ExcelConversionCSV excelConversionCSV{ "Resource/CSVTesting/CSVHeadTesting.xlsx", SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"), false };
}

CoreTools::CSVHeadTesting::FileContent CoreTools::CSVHeadTesting::ReadFile()
{
    FileContent fileContent{};

    const IFileStreamManager streamManager{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv") };

    const auto content = streamManager.GetFileContent(SYSTEM_TEXT("\r\n"));

    auto csvType = CSVType::Format;
    for (const auto& element : content)
    {
        fileContent.emplace_back(element);

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
    CSVHead csvHead{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"), ReadFile() };

    ASSERT_EQUAL(csvHead.GetCSVFormatType(), CSVFormatType::Default);
    ASSERT_EQUAL(csvHead.GetNameSpace(), SYSTEM_TEXT("CSVHead"));
    ASSERT_EQUAL(csvHead.GetCSVClassName(), SYSTEM_TEXT("CSVHeadTesting"));

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
            ASSERT_EQUAL(enumTypeName, SYSTEM_TEXT("CSVDataType"));
            ASSERT_EQUAL(enumTypeName, csvHead.GetActualType(i));
        }
        else
        {
            ASSERT_TRUE(enumTypeName.empty());
            ASSERT_EQUAL(CSVTypeConversion::GetActualType(csvDataType), csvHead.GetActualType(i));
            ASSERT_EQUAL(CSVTypeConversion::GetValueType(csvDataType), csvHead.GetValueType(i));
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

        ASSERT_EQUAL(csvHead.GetDataType(i), csvHead.GetDataType(variableName));

        ASSERT_EQUAL(i, csvHead.GetDataIndex(variableName));
        ASSERT_EQUAL(i, csvHead.GetDataIndex(System::StringView{ variableName }));

        ASSERT_TRUE(csvHead.HasDataField(variableName));
        ASSERT_TRUE(csvHead.HasDataField(System::StringView{ variableName }));

        ASSERT_FALSE(csvHead.GetAbbreviation(i).empty());
    }

    ASSERT_TRUE(csvHead.HasBase());
}
