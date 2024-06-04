/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/31 11:39)

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
    : ParentType{ stream },
      directory{ SYSTEM_TEXT("Resource/CSVTesting/") },
      nameSpace{ SYSTEM_TEXT("CSVHead") },
      csvClassName{ SYSTEM_TEXT("CSVHeadTesting") },
      fileName{ directory + SYSTEM_TEXT("/") + nameSpace + SYSTEM_TEXT("/") + csvClassName + SYSTEM_TEXT(".csv") }
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
    ExcelConversionCSV excelConversionCSV{ "Resource/CSVTesting/CSVHeadTesting.xlsx", fileName, false };
}

CoreTools::CSVHeadTesting::FileContent CoreTools::CSVHeadTesting::ReadFile()
{
    const IFileStreamManager streamManager{ fileName };

    const auto content = streamManager.GetFileContent(SYSTEM_TEXT("\r\n"));

    return ReadFile(content);
}

CoreTools::CSVHeadTesting::FileContent CoreTools::CSVHeadTesting::ReadFile(const FileContent& content)
{
    FileContent fileContent{};

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
    CSVHead csvHead{ fileName, ReadFile() };

    ASSERT_NOT_THROW_EXCEPTION_1(CSVHeadBaseTest, csvHead);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVHeadKeyTest, csvHead);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVHeadArrayDataTypeTest, csvHead);

    for (auto i = 0; i < csvHead.GetCount(); ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementTest, csvHead, i);
    }

    ASSERT_NOT_THROW_EXCEPTION_1(HasBaseTest, csvHead);
}

void CoreTools::CSVHeadTesting::CSVHeadBaseTest(const CSVHead& csvHead)
{
    ASSERT_EQUAL(csvHead.GetCSVFormatType(), CSVFormatType::Default);
    ASSERT_EQUAL(csvHead.GetNameSpace(), nameSpace);
    ASSERT_EQUAL(csvHead.GetCSVClassName(), csvClassName);
}

void CoreTools::CSVHeadTesting::CSVHeadKeyTest(const CSVHead& csvHead)
{
    ASSERT_TRUE(csvHead.GetKey().empty());
    ASSERT_TRUE(csvHead.GetKeyName().empty());
}

void CoreTools::CSVHeadTesting::CSVHeadArrayDataTypeTest(const CSVHead& csvHead)
{
    ASSERT_TRUE(csvHead.HasArrayDataType());
    ASSERT_TRUE(csvHead.HasVectorArrayDataType());
}

void CoreTools::CSVHeadTesting::HasBaseTest(const CSVHead& csvHead)
{
    ASSERT_TRUE(csvHead.HasBase());
}

void CoreTools::CSVHeadTesting::CSVHeadElementTest(const CSVHead& csvHead, int index)
{
    ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementMappingTest, csvHead, index);
    ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementScopeTest, csvHead, index);
    ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementDefaultValueTest, csvHead, index);
    ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementAnnotationTest, csvHead, index);
    ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementActualTypeTest, csvHead, index);
    ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementVariableNameTest, csvHead, index);
    ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementGetFunctionNameTest, csvHead, index);
    ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementDataTest, csvHead, index);
    ASSERT_NOT_THROW_EXCEPTION_2(CSVHeadElementAbbreviationTest, csvHead, index);
}

void CoreTools::CSVHeadTesting::CSVHeadElementMappingTest(const CSVHead& csvHead, int index)
{
    const auto mapping = csvHead.GetMapping(index);
    ASSERT_TRUE(mapping.empty());
    ASSERT_FALSE(csvHead.HasMapping());
}

void CoreTools::CSVHeadTesting::CSVHeadElementScopeTest(const CSVHead& csvHead, int index)
{
    const auto scope = csvHead.GetScope(index);
    ASSERT_TRUE(scope.empty());
    ASSERT_FALSE(csvHead.HasScope());
    ASSERT_TRUE(csvHead.GetScopeExpression(index).empty());
}

void CoreTools::CSVHeadTesting::CSVHeadElementDefaultValueTest(const CSVHead& csvHead, int index)
{
    const auto defaultValue = csvHead.GetDefaultValue(index);
    ASSERT_TRUE(defaultValue.empty());
}

void CoreTools::CSVHeadTesting::CSVHeadElementAnnotationTest(const CSVHead& csvHead, int index)
{
    const auto annotation = csvHead.GetAnnotation(index);
    ASSERT_FALSE(annotation.empty());
}

void CoreTools::CSVHeadTesting::CSVHeadElementActualTypeTest(const CSVHead& csvHead, int index)
{
    const auto csvDataType = csvHead.GetDataType(index);
    ASSERT_TRUE(csvHead.HasDataType(csvDataType));

    const auto enumTypeName = csvHead.GetEnumTypeName(index);

    if (csvDataType == CSVDataType::Enum || csvDataType == CSVDataType::EnumArray)
    {
        ASSERT_EQUAL(enumTypeName, SYSTEM_TEXT("CSVDataType"));
        ASSERT_EQUAL(enumTypeName, csvHead.GetActualType(index));
    }
    else
    {
        ASSERT_TRUE(enumTypeName.empty());
        ASSERT_EQUAL(CSVTypeConversion::GetActualType(csvDataType), csvHead.GetActualType(index));
        ASSERT_EQUAL(CSVTypeConversion::GetValueType(csvDataType), csvHead.GetValueType(index));
    }
}

void CoreTools::CSVHeadTesting::CSVHeadElementVariableNameTest(const CSVHead& csvHead, int index)
{
    const auto variableName = csvHead.GetVariableName(index);
    ASSERT_FALSE(variableName.empty());

    const auto upperVariableName = csvHead.GetUpperVariableName(index);
    ASSERT_FALSE(upperVariableName.empty());

    const auto functionVariableName = csvHead.GetFunctionVariableName(index);
    ASSERT_FALSE(functionVariableName.empty());
}

void CoreTools::CSVHeadTesting::CSVHeadElementGetFunctionNameTest(const CSVHead& csvHead, int index)
{
    const auto functionName = csvHead.GetFunctionName(index);
    ASSERT_FALSE(functionName.empty());
}

void CoreTools::CSVHeadTesting::CSVHeadElementDataTest(const CSVHead& csvHead, int index)
{
    const auto variableName = csvHead.GetVariableName(index);

    ASSERT_EQUAL(csvHead.GetDataType(index), csvHead.GetDataType(variableName));

    ASSERT_EQUAL(index, csvHead.GetDataIndex(variableName));
    ASSERT_EQUAL(index, csvHead.GetDataIndex(System::StringView{ variableName }));

    ASSERT_TRUE(csvHead.HasDataField(variableName));
    ASSERT_TRUE(csvHead.HasDataField(System::StringView{ variableName }));
}

void CoreTools::CSVHeadTesting::CSVHeadElementAbbreviationTest(const CSVHead& csvHead, int index)
{
    ASSERT_FALSE(csvHead.GetAbbreviation(index).empty());
}