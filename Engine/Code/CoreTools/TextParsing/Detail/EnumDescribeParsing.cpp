///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:53)

#include "CoreTools/CoreToolsExport.h"

#include "CSV/CSVGenerateHelper.h"
#include "EnumDescribeParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

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

    String content{ TextParsing::gSystemString };

    content += TextParsing::gSpace;
    content += csvHead.GetNameSpace();
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGetEnumDescribe;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gTypeEnd;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::EnumDescribeParsing::GenerateDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto typeDescribe = GenerateIndentation(1);

    typeDescribe += TextParsing::gStaticMapBegin;
    typeDescribe += csvHead.GetCSVClassName();
    typeDescribe += TextParsing::gComma;
    typeDescribe += TextParsing::gSpace;
    typeDescribe += TextParsing::gSystemString;
    typeDescribe += TextParsing::gTypeDescribe;

    return typeDescribe;
}

System::String CoreTools::EnumDescribeParsing::GenerateColumn(const String& space) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto content = GetCSVContent();

    String result{};

    const auto size = content.GetCount();
    for (auto index = 0; index < size; ++index)
    {
        const auto column = content.GetContent(index);

        const auto csvPositionType = GetPositionType(index, size);

        result += GetEnumDescribeColumn(column, space, csvPositionType);
    }

    return result;
}

System::String CoreTools::EnumDescribeParsing::GenerateFindFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetFindFunctionDefinition(TextParsing::gType);
}

System::String CoreTools::EnumDescribeParsing::GetEnumDescribeColumn(const String& column, const String& space, CSVPositionType csvPositionType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto result = Parsing::GetSplitComma(column);

    auto name = result.at(GetNameIndex());
    trim_if(name, boost::is_any_of(TextParsing::gQuotationMarks));

    auto describe = StringConversion::Utf8ConversionStandard(result.at(describeIndex));
    trim_if(describe, boost::is_any_of(TextParsing::gQuotationMarks));

    return GetColumn(GetEnumDescribeColumn(name, describe), space, csvPositionType);
}

System::String CoreTools::EnumDescribeParsing::GetEnumDescribeColumn(const String& name, const String& describe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    String content{ TextParsing::gLeftBrace };

    content += TextParsing::gSpace;

    content += csvHead.GetCSVClassName();
    content += TextParsing::gDoubleColon;
    content += name;
    content += TextParsing::gSystemTextValue;
    content += describe;
    content += TextParsing::gSystemTextInitEnd;

    return content;
}