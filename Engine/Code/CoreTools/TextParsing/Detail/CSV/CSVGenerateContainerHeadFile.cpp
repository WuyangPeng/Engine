/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:55)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateContainerHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateContainerHeadFile::CSVGenerateContainerHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateContainerHeadFile)

System::String CoreTools::CSVGenerateContainerHeadFile::GetSuffix() const
{
    return String{ TextParsing::gContainer };
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gHeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EntityContainerH.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    const auto head = GetCSVHead();

    String containerStdIncludeContent{};

    if (head.GetCSVFormatType() == CSVFormatType::TreeMap)
    {
        containerStdIncludeContent += TextParsing::gMapInclude;
    }

    containerStdIncludeContent += TextParsing::gMemoryInclude;

    if (head.GetCSVFormatType() == CSVFormatType::HashMap)
    {
        containerStdIncludeContent += TextParsing::gUnorderedMapInclude;
    }

    containerStdIncludeContent += TextParsing::gVectorInclude;

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerStdInclude$"), containerStdIncludeContent);

    if (head.GetCSVFormatType() == CSVFormatType::Unique)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerGetFunction$"), codeMapping.GetElement(SYSTEM_TEXT("SingleContainerGetFunction")));
    }
    else if (head.GetCSVFormatType() == CSVFormatType::Vector)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerGetFunction$"), codeMapping.GetElement(SYSTEM_TEXT("VectorContainerGetFunction")));
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerGetFunction$"), codeMapping.GetElement(SYSTEM_TEXT("ContainerGetFunction")));
    }

    if (head.GetCSVFormatType() == CSVFormatType::HashMap)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$MappingContainerUsing$"), codeMapping.GetElement(SYSTEM_TEXT("MappingContainerUsing")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerType$"), SYSTEM_TEXT("MappingContainer"));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerUsing$"), codeMapping.GetElement(SYSTEM_TEXT("ContainerUsing")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$MapName$"), codeMapping.GetElement(SYSTEM_TEXT("unordered_map")));
    }
    else if (head.GetCSVFormatType() == CSVFormatType::TreeMap)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$MappingContainerUsing$"), codeMapping.GetElement(SYSTEM_TEXT("MappingContainerUsing")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerType$"), SYSTEM_TEXT("MappingContainer"));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerUsing$"), codeMapping.GetElement(SYSTEM_TEXT("ContainerUsing")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$MapName$"), codeMapping.GetElement(SYSTEM_TEXT("map")));
    }
    else if (head.GetCSVFormatType() == CSVFormatType::Unique)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$MappingContainerUsing$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerType$"), SYSTEM_TEXT("Const") + GetCSVClassName() + SYSTEM_TEXT("SharedPtr"));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerUsing$"), SYSTEM_TEXT(""));
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$MappingContainerUsing$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerType$"), SYSTEM_TEXT("Container"));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerUsing$"), codeMapping.GetElement(SYSTEM_TEXT("ContainerUsing")));
    }

    if (head.GetCSVFormatType() == CSVFormatType::Default ||
        head.GetCSVFormatType() == CSVFormatType::Key)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$UniqueFunction$"), codeMapping.GetElement(SYSTEM_TEXT("UniqueFunction")));
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$UniqueFunction$"), SYSTEM_TEXT(""));
    }

    if (head.GetCSVFormatType() == CSVFormatType::Vector)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyParameter$"), codeMapping.GetElement(SYSTEM_TEXT("KeyParameter")));
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyParameter$"), SYSTEM_TEXT(""));
    }

    return ReplaceTemplate(content);
}
