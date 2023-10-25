///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:27)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateContainerHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVTotalGenerateContainerHeadFile::CSVTotalGenerateContainerHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ nameSpace, csvHeadContainer, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateContainerHeadFile)

System::String CoreTools::CSVTotalGenerateContainerHeadFile::GetFileSuffix() const
{
    return TextParsing::gContainerHeadFileExtensionName.data();
}

System::String CoreTools::CSVTotalGenerateContainerHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EngineeringContainerH.txt"));

    EnumType dataType{};

    for (const auto& element : GetCSVHeadContainer())
    {
        if (element.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(element.GetCSVClassName());
        }
    }

    const auto codeMapping = GetCodeMappingAnalysis();
    const auto containerSharedPtrUsing = codeMapping.GetElement(SYSTEM_TEXT("ContainerSharedPtrUsing"));

    String containerSharedPtrUsingContent{};
    for (const auto& element : dataType)
    {
        auto copyContainerSharedPtrUsing = containerSharedPtrUsing;

        boost::algorithm::replace_all(copyContainerSharedPtrUsing, SYSTEM_TEXT("$ClassName$"), element);

        containerSharedPtrUsingContent += copyContainerSharedPtrUsing;
        containerSharedPtrUsingContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerSharedPtrUsing$"), containerSharedPtrUsingContent);

    const auto getContainerSharedPtrUsing = codeMapping.GetElement(SYSTEM_TEXT("GetContainerSharedPtrUsing"));

    String getContainerSharedPtrUsingContent{};
    for (const auto& element : dataType)
    {
        auto copyGetContainerSharedPtrUsing = getContainerSharedPtrUsing;

        boost::algorithm::replace_all(copyGetContainerSharedPtrUsing, SYSTEM_TEXT("$ClassName$"), element);

        getContainerSharedPtrUsingContent += copyGetContainerSharedPtrUsing;
        getContainerSharedPtrUsingContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerSharedPtrUsing$"), getContainerSharedPtrUsingContent);

    const auto containerSharedPtr = codeMapping.GetElement(SYSTEM_TEXT("ContainerSharedPtr"));

    String containerSharedPtrContent{};
    for (const auto& element : dataType)
    {
        auto copyContainerSharedPtr = containerSharedPtr;

        boost::algorithm::replace_all(copyContainerSharedPtr, SYSTEM_TEXT("$ClassName$"), element);
        boost::algorithm::replace_all(copyContainerSharedPtr, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

        containerSharedPtrContent += copyContainerSharedPtr;
        containerSharedPtrContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerSharedPtr$"), containerSharedPtrContent);

    return ReplaceTemplate(content);
}
