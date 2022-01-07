///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:58)

#include "CoreTools/CoreToolsExport.h"

#include "CSV/CSVGenerateHelper.h"
#include "EnumDescribeParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::EnumDescribeParsing::EnumDescribeParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className, int nameIndex, int describeIndex)
    : ParentType{ csvHead, csvContent, className, nameIndex }, describeIndex{ describeIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EnumDescribeParsing)

System::String CoreTools::EnumDescribeParsing::GenerateHeader() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    String content{ TextParsing::g_SystemString };

    content += TextParsing::g_Space;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_GetEnumDescribe;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_TypeEnd;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::EnumDescribeParsing::GenerateDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto typeDescribe = GenerateIndentation(1);

    typeDescribe += TextParsing::g_StaticMapBegin;
    typeDescribe += csvHead.GetCSVClassName();
    typeDescribe += TextParsing::g_Comma;
    typeDescribe += TextParsing::g_Space;
    typeDescribe += TextParsing::g_SystemString;
    typeDescribe += TextParsing::g_TypeDescribe;

    return typeDescribe;
}

System::String CoreTools::EnumDescribeParsing::GenerateColumn(const String& space) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvContent = GetCSVContent();

    String content{};

    const auto size = csvContent.GetCount();
    for (auto index = 0; index < size; ++index)
    {
        const auto column = csvContent.GetContent(index);

        const auto csvPoistionType = GetPoistionType(index, size);

        content += GetEnumDescribeColumn(column, space, csvPoistionType);
    }

    return content;
}

System::String CoreTools::EnumDescribeParsing::GenerateFindFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetFindFunctionDefinition(TextParsing::g_Type);
}

System::String CoreTools::EnumDescribeParsing::GetEnumDescribeColumn(const String& column, const String& space, CSVPoistionType csvPoistionType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto result = Parsing::GetSplitComma(column);

    auto name = result.at(GetNameIndex());
    boost::algorithm::trim_if(name, boost::is_any_of(TextParsing::g_QuotationMarks));

    auto describe = StringConversion::UTF8ConversionStandard(result.at(describeIndex));
    boost::algorithm::trim_if(describe, boost::is_any_of(TextParsing::g_QuotationMarks));

    return GetColumn(GetEnumDescribeColumn(name, describe), space, csvPoistionType);
}

System::String CoreTools::EnumDescribeParsing::GetEnumDescribeColumn(const String& name, const String& describe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    String content{ TextParsing::g_LeftBigParantheses };

    content += TextParsing::g_Space;

    content += csvHead.GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += name;
    content += TextParsing::g_SystemTextValue;
    content += describe;
    content += TextParsing::g_SystemTextInitEnd;

    return content;
}