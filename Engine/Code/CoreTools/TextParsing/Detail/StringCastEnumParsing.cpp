///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:29)

#include "CoreTools/CoreToolsExport.h"

#include "CSV/CSVGenerateHelper.h"
#include "StringCastEnumParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::StringCastEnumParsing::StringCastEnumParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className, int nameIndex)
    : ParentType{ csvHead, csvContent, className, nameIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StringCastEnumParsing)

System::String CoreTools::StringCastEnumParsing::GenerateHeader() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = csvHead.GetCompleteClassName();

    content += TextParsing::g_Space;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_StringCast;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_Describe;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::StringCastEnumParsing::GenerateDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto typeDescribe = GenerateIndentation(1);

    typeDescribe += TextParsing::g_StringKeyMap;
    typeDescribe += csvHead.GetCSVClassName();
    typeDescribe += TextParsing::g_TypeDescribe;

    return typeDescribe;
}

System::String CoreTools::StringCastEnumParsing::GenerateColumn(const String& space) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    const auto csvContent = GetCSVContent();

    const auto size = csvContent.GetCount();
    for (auto index = 0; index < size; ++index)
    {
        const auto column = csvContent.GetContent(index);

        const auto csvPoistionType = GetPoistionType(index, size);

        content += GetStringCastEnumColumn(column, space, csvPoistionType);
    }

    return content;
}

System::String CoreTools::StringCastEnumParsing::GetStringCastEnumColumn(const String& column, const String& space, CSVPoistionType csvPoistionType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto result = Parsing::GetSplitComma(column);

    auto name = result.at(GetNameIndex());
    boost::algorithm::trim_if(name, boost::is_any_of(TextParsing::g_QuotationMarks));

    return GetColumn(GetStringCastEnumColumn(name), space, csvPoistionType);
}

System::String CoreTools::StringCastEnumParsing::GetStringCastEnumColumn(const String& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    String content{ TextParsing::g_InitSystemTextBegin };

    content += name;
    content += TextParsing::g_InitSystemTextEnd;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += name;
    content += TextParsing::g_Space;
    content += TextParsing::g_RightBigParantheses;

    return content;
}

System::String CoreTools::StringCastEnumParsing::GenerateFindFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetFindFunctionDefinition(TextParsing::g_EnumDescribe);
}
