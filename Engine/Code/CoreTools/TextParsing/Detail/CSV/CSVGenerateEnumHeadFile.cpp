/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 17:26)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateEnumHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/Detail/Parsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateEnumHeadFile::CSVGenerateEnumHeadFile(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvContent.GetCSVHead(), codeMappingAnalysis },
      csvContent{ csvContent },
      templateName{ SYSTEM_TEXT("/FlagsH.txt") },
      classNameMember{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ClassNameMember")) }
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
    return GetSuffix() + TextParsing::gHeadFileExtensionName.data();
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassNameMember$"), GetClassNameMemberContent());

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetClassNameMemberContent() const
{
    const auto head = GetCSVHead();

    const auto idIndex = head.GetDataIndex(TextParsing::gIdSmall);
    const auto nameIndex = head.GetDataIndex(TextParsing::gEnumName);
    const auto describeIndex = head.GetDataIndex(TextParsing::gEnumDescribe);

    String content{};

    for (auto index = 0; index < csvContent.GetCount(); ++index)
    {
        content += GetClassNameMemberContent(idIndex, nameIndex, describeIndex, index);
    }

    return content;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetClassNameMemberContent(const int idIndex, const int nameIndex, const int describeIndex, int index) const
{
    String content{};

    const auto column = csvContent.GetContent(index);
    const auto result = Parsing::GetSplitComma(column);
    const auto& id = result.at(idIndex);

    auto name = result.at(nameIndex);
    trim_if(name, boost::is_any_of(TextParsing::gQuotationMarks));

    auto describe = StringConversion::Utf8ConversionStandard(result.at(describeIndex));
    trim_if(describe, boost::is_any_of(TextParsing::gQuotationMarks));

    content += GetReplaceContent(classNameMember,
                                 { { SYSTEM_TEXT("EnumName"), name },
                                   { SYSTEM_TEXT("EnumValue"), id },
                                   { SYSTEM_TEXT("EnumNameNote"), describe } });

    return content;
}
