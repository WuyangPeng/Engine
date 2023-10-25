///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:44)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateEnumHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/Detail/Parsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateEnumHeadFile::CSVGenerateEnumHeadFile(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvContent.GetCSVHead(), codeMappingAnalysis }, csvContent{ csvContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateEnumHeadFile)

System::String CoreTools::CSVGenerateEnumHeadFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::gEnumFilePrefix };
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gHeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/FlagsH.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    const auto head = GetCSVHead();

    const auto idIndex = head.GetDataIndex(TextParsing::gIdSmall);
    const auto nameIndex = head.GetDataIndex(TextParsing::gEnumName);
    const auto describeIndex = head.GetDataIndex(TextParsing::gEnumDescribe);

    const auto classNameMember = codeMapping.GetElement(SYSTEM_TEXT("ClassNameMember"));

    String classNameMemberContent{};
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        const auto column = csvContent.GetContent(i);

        const auto result = Parsing::GetSplitComma(column);

        const auto& id = result.at(idIndex);

        auto name = result.at(nameIndex);
        trim_if(name, boost::is_any_of(TextParsing::gQuotationMarks));

        auto describe = StringConversion::Utf8ConversionStandard(result.at(describeIndex));
        trim_if(describe, boost::is_any_of(TextParsing::gQuotationMarks));

        auto copyClassNameMember = classNameMember;
        boost::algorithm::replace_all(copyClassNameMember, SYSTEM_TEXT("$EnumName$"), name);
        boost::algorithm::replace_all(copyClassNameMember, SYSTEM_TEXT("$EnumValue$"), id);
        boost::algorithm::replace_all(copyClassNameMember, SYSTEM_TEXT("$EnumNameNote$"), describe);

        classNameMemberContent += copyClassNameMember;
        classNameMemberContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassNameMember$"), classNameMemberContent);

    return ReplaceTemplate(content);
}
