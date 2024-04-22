/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:16)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <ranges>

CoreTools::CSVTotalGenerateHeadFile::CSVTotalGenerateHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ nameSpace, csvHeadContainer, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/CSVEngineering.txt") },
      includeEnum{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeEnum")) },
      includeClass{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeClass")) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateHeadFile)

System::String CoreTools::CSVTotalGenerateHeadFile::GetFileSuffix() const
{
    return TextParsing::gHeadFileExtensionName.data();
}

System::String CoreTools::CSVTotalGenerateHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    const auto enumType = GetEnumType();
    const auto dataType = GetHeadData();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IncludeEnum$"), GetIncludeEnumContent(enumType));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IncludeClass$"), GetIncludeClassContent(dataType));

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVTotalGenerateHeadFile::GetIncludeEnumContent(const ContainerType& enumType) const
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

System::String CoreTools::CSVTotalGenerateHeadFile::GetIncludeEnumContent(const String& element) const
{
    auto content = includeEnum;
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$EnumName$"), element);

    return content + TextParsing::gNewlineCharacter;
}

System::String CoreTools::CSVTotalGenerateHeadFile::GetIncludeClassContent(const HeadDataType& dataType) const
{
    /// 这里根据名字对包含的头文件进行了排序。
    /// 如果要去除key，需要对容器排序以保证逻辑正确。
    String content{};
    for (const auto& csvHead : dataType | std::views::values)
    {
        content += GetIncludeClassContent(csvHead);
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateHeadFile::GetIncludeClassContent(const CSVHead& csvHead) const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    auto content = includeClass;

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IncludeBaseClass$"), csvHead.HasBase() ? codeMapping.GetElement(SYSTEM_TEXT("IncludeBaseClass")) : SYSTEM_TEXT(""));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IncludeChildClass$"), codeMapping.GetElement(SYSTEM_TEXT("IncludeChildClass")));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IncludeContainerClass$"), csvHead.GetCSVFormatType() == CSVFormatType::Unique ? codeMapping.GetElement(SYSTEM_TEXT("IncludeContainerClass")) : codeMapping.GetElement(SYSTEM_TEXT("IncludeContainerDetailClass")));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassName$"), csvHead.GetCSVClassName());

    return content + TextParsing::gNewlineCharacter;
}