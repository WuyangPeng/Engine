/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:16)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateFwdHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <ranges>

CoreTools::CSVTotalGenerateFwdHeadFile::CSVTotalGenerateFwdHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ nameSpace, csvHeadContainer, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/CSVEngineeringFwd.txt") },
      enumDeclaration{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("EnumDeclaration")) },
      classDeclaration{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ClassDeclaration")) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateFwdHeadFile)

System::String CoreTools::CSVTotalGenerateFwdHeadFile::GetFileSuffix() const
{
    return TextParsing::gFwdHeadFileExtensionName.data();
}

System::String CoreTools::CSVTotalGenerateFwdHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    const auto enumType = GetEnumType();
    const auto dataType = GetHeadData();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$EnumDeclaration$"), GetIncludeEnumContent(enumType));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassDeclaration$"), GetIncludeClassContent(dataType));

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVTotalGenerateFwdHeadFile::GetIncludeEnumContent(const ContainerType& enumType) const
{
    String content{};

    for (const auto& element : enumType)
    {
        content += GetIncludeEnumContent(element);
    }

    if (!enumType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateFwdHeadFile::GetIncludeEnumContent(const String& element) const
{
    auto content = enumDeclaration;
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$EnumName$"), element);

    return content + TextParsing::gNewlineCharacter;
}

System::String CoreTools::CSVTotalGenerateFwdHeadFile::GetIncludeClassContent(const HeadDataType& dataType) const
{
    /// 这里根据名字对声明进行了排序。
    /// 如果要去除key，需要对容器排序以保证逻辑正确。
    String content{};
    for (const auto& csvHead : dataType | std::views::values)
    {
        content += GetIncludeClassContent(csvHead);
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateFwdHeadFile::GetIncludeClassContent(const CSVHead& csvHead) const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    auto content = classDeclaration;

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$BaseClassDeclaration$"), csvHead.HasBase() ? codeMapping.GetElement(SYSTEM_TEXT("BaseClassDeclaration")) : SYSTEM_TEXT(""));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$MappingTypeUsing$"), csvHead.HasBase() ? codeMapping.GetElement(SYSTEM_TEXT("MappingTypeBaseUsing")) : codeMapping.GetElement(SYSTEM_TEXT("MappingTypeUsing")));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ChildClassDeclaration$"), codeMapping.GetElement(SYSTEM_TEXT("ChildClassDeclaration")));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerClassDeclaration$"), codeMapping.GetElement(SYSTEM_TEXT("ContainerClassDeclaration")));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassName$"), csvHead.GetCSVClassName());

    return content + TextParsing::gNewlineCharacter;
}