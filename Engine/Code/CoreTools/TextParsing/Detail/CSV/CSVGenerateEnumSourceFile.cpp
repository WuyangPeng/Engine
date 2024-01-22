/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:56)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateEnumSourceFile.h"
#include "CSVGenerateHelper.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/Detail/Parsing.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateEnumSourceFile::CSVGenerateEnumSourceFile(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvContent.GetCSVHead(), codeMappingAnalysis }, csvContent{ csvContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
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
    auto result = GetSuffix();

    result += TextParsing::gSourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/FlagsCpp.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    auto typeDescribe = codeMapping.GetElement(SYSTEM_TEXT("TypeDescribe"));
    boost::algorithm::replace_all(typeDescribe, SYSTEM_TEXT("$ClassName$"), GetCSVClassName());
    String space(typeDescribe.size(), SYSTEM_TEXT(' '));

    const auto head = GetCSVHead();

    const auto idIndex = head.GetDataIndex(TextParsing::gIdSmall);
    const auto nameIndex = head.GetDataIndex(TextParsing::gEnumName);
    const auto describeIndex = head.GetDataIndex(TextParsing::gEnumDescribe);

    const auto size = csvContent.GetCount();

    const auto classMemberType = codeMapping.GetElement(SYSTEM_TEXT("ClassMemberType"));

    String classMemberTypeContent{};
    for (auto i = 0; i < size; ++i)
    {
        const auto column = csvContent.GetContent(i);

        const auto result = Parsing::GetSplitComma(column);

        const auto& id = result.at(idIndex);

        auto name = result.at(nameIndex);
        trim_if(name, boost::is_any_of(TextParsing::gQuotationMarks));

        auto describe = StringConversion::Utf8ConversionStandard(result.at(describeIndex));
        trim_if(describe, boost::is_any_of(TextParsing::gQuotationMarks));

        auto copyClassMemberType = classMemberType;
        if (i == size - 1)
        {
            copyClassMemberType = space + codeMapping.GetElement(SYSTEM_TEXT("EndClassMemberType"));
        }
        else if (i != 0)
        {
            copyClassMemberType = space + copyClassMemberType;
        }

        boost::algorithm::replace_all(copyClassMemberType, SYSTEM_TEXT("$EnumName$"), name);
        boost::algorithm::replace_all(copyClassMemberType, SYSTEM_TEXT("$EnumValue$"), id);
        boost::algorithm::replace_all(copyClassMemberType, SYSTEM_TEXT("$EnumNameNote$"), describe);

        classMemberTypeContent += copyClassMemberType;
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassMemberType$"), classMemberTypeContent);

    const auto classMemberName = codeMapping.GetElement(SYSTEM_TEXT("ClassMemberName"));

    String classMemberNameContent{};
    for (auto i = 0; i < size; ++i)
    {
        const auto column = csvContent.GetContent(i);

        const auto result = Parsing::GetSplitComma(column);

        const auto& id = result.at(idIndex);

        auto name = result.at(nameIndex);
        trim_if(name, boost::is_any_of(TextParsing::gQuotationMarks));

        auto describe = StringConversion::Utf8ConversionStandard(result.at(describeIndex));
        trim_if(describe, boost::is_any_of(TextParsing::gQuotationMarks));

        auto copyClassMemberName = classMemberName;
        if (i == size - 1)
        {
            copyClassMemberName = space + codeMapping.GetElement(SYSTEM_TEXT("EndClassMemberName"));
        }
        else if (i != 0)
        {
            copyClassMemberName = space + copyClassMemberName;
        }

        boost::algorithm::replace_all(copyClassMemberName, SYSTEM_TEXT("$EnumName$"), name);
        boost::algorithm::replace_all(copyClassMemberName, SYSTEM_TEXT("$EnumValue$"), id);
        boost::algorithm::replace_all(copyClassMemberName, SYSTEM_TEXT("$EnumNameNote$"), describe);

        classMemberNameContent += copyClassMemberName;
        classMemberNameContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassMemberName$"), classMemberNameContent);

    const auto classMemberNote = codeMapping.GetElement(SYSTEM_TEXT("ClassMemberNote"));

    String classMemberNoteContent{};
    for (auto i = 0; i < size; ++i)
    {
        const auto column = csvContent.GetContent(i);

        const auto result = Parsing::GetSplitComma(column);

        const auto& id = result.at(idIndex);

        auto name = result.at(nameIndex);
        trim_if(name, boost::is_any_of(TextParsing::gQuotationMarks));

        auto describe = StringConversion::Utf8ConversionStandard(result.at(describeIndex));
        trim_if(describe, boost::is_any_of(TextParsing::gQuotationMarks));

        auto copyClassMemberNote = classMemberNote;
        if (i == size - 1)
        {
            copyClassMemberNote = space + codeMapping.GetElement(SYSTEM_TEXT("EndClassMemberNote"));
        }
        else if (i != 0)
        {
            copyClassMemberNote = space + copyClassMemberNote;
        }

        boost::algorithm::replace_all(copyClassMemberNote, SYSTEM_TEXT("$EnumName$"), name);
        boost::algorithm::replace_all(copyClassMemberNote, SYSTEM_TEXT("$EnumValue$"), id);
        boost::algorithm::replace_all(copyClassMemberNote, SYSTEM_TEXT("$EnumNameNote$"), describe);

        classMemberNoteContent += copyClassMemberNote;
        classMemberNoteContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassMemberNote$"), classMemberNoteContent);

    return ReplaceTemplate(content);
}
