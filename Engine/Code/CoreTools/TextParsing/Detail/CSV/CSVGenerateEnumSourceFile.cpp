/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 17:34)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateEnumSourceFile.h"
#include "CSVGenerateHelper.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/Detail/Parsing.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateEnumSourceFile::CSVGenerateEnumSourceFile(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvContent.GetCSVHead(), codeMappingAnalysis },
      csvContent{ csvContent },
      templateName{ SYSTEM_TEXT("/FlagsCpp.txt") },

      space{ GetSpace(csvContent.GetCSVHead(), codeMappingAnalysis) },
      classMemberType{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ClassMemberType")) },
      endClassMemberType{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("EndClassMemberType")) },
      classMemberName{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ClassMemberName")) },
      endClassMemberName{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("EndClassMemberName")) },
      classMemberNote{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ClassMemberNote")) },
      endClassMemberNote{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("EndClassMemberNote")) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetSpace(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis)
{
    auto typeDescribe = codeMappingAnalysis.GetElement(SYSTEM_TEXT("TypeDescribe"));
    boost::algorithm::replace_all(typeDescribe, SYSTEM_TEXT("$ClassName$"), csvHead.GetCSVClassName());
    String space(typeDescribe.size(), SYSTEM_TEXT(' '));

    return space;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateEnumSourceFile)

System::String CoreTools::CSVGenerateEnumSourceFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::gEnumFilePrefix };
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetFileSuffix() const
{
    return GetSuffix() + TextParsing::gSourceFileExtensionName.data();
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    const auto head = GetCSVHead();
    const auto idIndex = head.GetDataIndex(TextParsing::gIdSmall);
    const auto nameIndex = head.GetDataIndex(TextParsing::gEnumName);
    const auto describeIndex = head.GetDataIndex(TextParsing::gEnumDescribe);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassMemberType$"), GetClassMemberTypeContent(idIndex, nameIndex, describeIndex));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassMemberName$"), GetClassMemberNameContent(idIndex, nameIndex, describeIndex));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassMemberNote$"), GetClassMemberNoteContent(idIndex, nameIndex, describeIndex));

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetClassMemberTypeContent(int idIndex, int nameIndex, int describeIndex) const
{
    String content{};
    for (auto index = 0; index < csvContent.GetCount(); ++index)
    {
        content += GetClassMemberTypeContent(idIndex, nameIndex, describeIndex, index, classMemberType, endClassMemberType);
    }

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetClassMemberNameContent(int idIndex, int nameIndex, int describeIndex) const
{
    String content{};
    for (auto index = 0; index < csvContent.GetCount(); ++index)
    {
        content += GetClassMemberTypeContent(idIndex, nameIndex, describeIndex, index, classMemberName, endClassMemberName);
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetClassMemberNoteContent(int idIndex, int nameIndex, int describeIndex) const
{
    String content{};
    for (auto index = 0; index < csvContent.GetCount(); ++index)
    {
        content += GetClassMemberTypeContent(idIndex, nameIndex, describeIndex, index, classMemberNote, endClassMemberNote);
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetClassMemberTypeContent(int idIndex, int nameIndex, int describeIndex, int index, const String& original, const String& end) const
{
    const auto column = csvContent.GetContent(index);
    const auto result = Parsing::GetSplitComma(column);
    const auto& id = result.at(idIndex);

    auto name = result.at(nameIndex);
    trim_if(name, boost::is_any_of(TextParsing::gQuotationMarks));

    auto describe = StringConversion::Utf8ConversionStandard(result.at(describeIndex));
    trim_if(describe, boost::is_any_of(TextParsing::gQuotationMarks));

    auto content = (index == csvContent.GetCount() - 1) ? space + end : (index != 0 ? space + original : original);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$EnumName$"), name);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$EnumValue$"), id);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$EnumNameNote$"), describe);

    return content;
}