/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 22:31)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateContainerHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVTotalGenerateContainerHeadFile::CSVTotalGenerateContainerHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ nameSpace, csvHeadContainer, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/EngineeringContainerH.txt") },
      containerSharedPtrUsing{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ContainerSharedPtrUsing")) },
      getContainerSharedPtrUsing{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("GetContainerSharedPtrUsing")) },
      containerSharedPtr{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ContainerSharedPtr")) }
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
    auto content = GetTemplateContent(codeDirectory + templateName);

    const auto dataType = GetDataType();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerSharedPtrUsing$"), ContainerSharedPtrUsingContent(dataType));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerSharedPtrUsing$"), GetContainerSharedPtrUsingContent(dataType));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerSharedPtr$"), GetContainerSharedPtrContent(dataType));

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVTotalGenerateContainerHeadFile::ContainerSharedPtrUsingContent(const ContainerType& dataType) const
{
    String content{};

    for (const auto& element : dataType)
    {
        content += ReplaceClassName(containerSharedPtrUsing, element);
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerHeadFile::GetContainerSharedPtrUsingContent(const ContainerType& dataType) const
{
    String content{};

    for (const auto& element : dataType)
    {
        content += ReplaceClassName(getContainerSharedPtrUsing, element);
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerHeadFile::GetContainerSharedPtrContent(const ContainerType& dataType) const
{
    String content{};
    for (const auto& element : dataType)
    {
        content += GetContainerSharedPtrContent(element);
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerHeadFile::GetContainerSharedPtrContent(const String& element) const
{
    auto content = containerSharedPtr;

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassName$"), element);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

    return content + TextParsing::gNewlineCharacter;
}