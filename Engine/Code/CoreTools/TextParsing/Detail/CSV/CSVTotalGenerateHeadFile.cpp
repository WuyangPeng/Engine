/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:58)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVTotalGenerateHeadFile::CSVTotalGenerateHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ nameSpace, csvHeadContainer, codeMappingAnalysis }
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
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/CSVEngineering.txt"));

    EnumType enumType{};
    DataType dataType{};

    for (const auto& element : GetCSVHeadContainer())
    {
        if (element.GetCSVFormatType() == CSVFormatType::Enum)
        {
            enumType.emplace(element.GetCSVClassName());
        }
        else
        {
            dataType.emplace(element.GetCSVClassName(), element);
        }
    }

    const auto codeMapping = GetCodeMappingAnalysis();
    const auto includeEnumDeclaration = codeMapping.GetElement(SYSTEM_TEXT("IncludeEnum"));

    String includeEnumContent{};
    for (const auto& element : enumType)
    {
        auto copyIncludeEnumDeclaration = includeEnumDeclaration;
        boost::algorithm::replace_all(copyIncludeEnumDeclaration, SYSTEM_TEXT("$EnumName$"), element);

        includeEnumContent += copyIncludeEnumDeclaration;
        includeEnumContent += SYSTEM_TEXT("\n");
    }

    if (!enumType.empty())
    {
        includeEnumContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IncludeEnum$"), includeEnumContent);

    const auto includeClassDeclaration = codeMapping.GetElement(SYSTEM_TEXT("IncludeClass"));

    String includeClassContent{};
    for (const auto& element : dataType)
    {
        auto copyIncludeClassDeclaration = includeClassDeclaration;

        if (element.second.GetCSVFormatType() == CSVFormatType::Default ||
            element.second.GetCSVFormatType() == CSVFormatType::Vector ||
            element.second.GetCSVFormatType() == CSVFormatType::Key)
        {
            boost::algorithm::replace_all(copyIncludeClassDeclaration, SYSTEM_TEXT("$IncludeBaseClass$"), codeMapping.GetElement(SYSTEM_TEXT("IncludeBaseClass")));
        }
        else
        {
            boost::algorithm::replace_all(copyIncludeClassDeclaration, SYSTEM_TEXT("$IncludeBaseClass$"), SYSTEM_TEXT(""));
        }

        boost::algorithm::replace_all(copyIncludeClassDeclaration, SYSTEM_TEXT("$IncludeChildClass$"), codeMapping.GetElement(SYSTEM_TEXT("IncludeChildClass")));

        if (element.second.GetCSVFormatType() == CSVFormatType::Unique)
        {
            boost::algorithm::replace_all(copyIncludeClassDeclaration, SYSTEM_TEXT("$IncludeContainerClass$"), codeMapping.GetElement(SYSTEM_TEXT("IncludeContainerClass")));
        }
        else
        {
            boost::algorithm::replace_all(copyIncludeClassDeclaration, SYSTEM_TEXT("$IncludeContainerClass$"), codeMapping.GetElement(SYSTEM_TEXT("IncludeContainerDetailClass")));
        }

        boost::algorithm::replace_all(copyIncludeClassDeclaration, SYSTEM_TEXT("$ClassName$"), element.second.GetCSVClassName());

        includeClassContent += copyIncludeClassDeclaration;
        includeClassContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IncludeClass$"), includeClassContent);

    return ReplaceTemplate(content);
}
