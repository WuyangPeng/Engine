///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:25)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateFwdHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVTotalGenerateFwdHeadFile::CSVTotalGenerateFwdHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ nameSpace, csvHeadContainer, codeMappingAnalysis }
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
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/CSVEngineeringFwd.txt"));

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

    const auto includeEnumDeclaration = codeMapping.GetElement(SYSTEM_TEXT("EnumDeclaration"));

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

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$EnumDeclaration$"), includeEnumContent);

    const auto classDeclaration = codeMapping.GetElement(SYSTEM_TEXT("ClassDeclaration"));

    String includeClassContent{};
    for (const auto& element : dataType)
    {
        auto copyClassDeclaration = classDeclaration;

        if (element.second.GetCSVFormatType() == CSVFormatType::Default ||
            element.second.GetCSVFormatType() == CSVFormatType::Vector ||
            element.second.GetCSVFormatType() == CSVFormatType::Key)
        {
            boost::algorithm::replace_all(copyClassDeclaration, SYSTEM_TEXT("$BaseClassDeclaration$"), codeMapping.GetElement(SYSTEM_TEXT("BaseClassDeclaration")));
            boost::algorithm::replace_all(copyClassDeclaration, SYSTEM_TEXT("$MappingTypeUsing$"), codeMapping.GetElement(SYSTEM_TEXT("MappingTypeBaseUsing")));
        }
        else
        {
            boost::algorithm::replace_all(copyClassDeclaration, SYSTEM_TEXT("$BaseClassDeclaration$"), SYSTEM_TEXT(""));
            boost::algorithm::replace_all(copyClassDeclaration, SYSTEM_TEXT("$MappingTypeUsing$"), codeMapping.GetElement(SYSTEM_TEXT("MappingTypeUsing")));
        }

        boost::algorithm::replace_all(copyClassDeclaration, SYSTEM_TEXT("$ChildClassDeclaration$"), codeMapping.GetElement(SYSTEM_TEXT("ChildClassDeclaration")));
        boost::algorithm::replace_all(copyClassDeclaration, SYSTEM_TEXT("$ContainerClassDeclaration$"), codeMapping.GetElement(SYSTEM_TEXT("ContainerClassDeclaration")));

        boost::algorithm::replace_all(copyClassDeclaration, SYSTEM_TEXT("$ClassName$"), element.second.GetCSVClassName());

        includeClassContent += copyClassDeclaration;
        includeClassContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassDeclaration$"), includeClassContent);

    return ReplaceTemplate(content);
}
