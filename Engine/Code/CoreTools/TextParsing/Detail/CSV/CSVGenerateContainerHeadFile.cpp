/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 11:21)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateContainerHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateContainerHeadFile::CSVGenerateContainerHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/EntityContainerH.txt") }
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
    return GetSuffix() + TextParsing::gHeadFileExtensionName.data();
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerStdInclude$"), GetContainerStdIncludeContent());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerGetFunction$"), GetContainerGetFunctionReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$MappingContainerUsing$"), GetMappingContainerUsingReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerType$"), GetContainerTypeReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerUsing$"), GetContainerUsingReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$MapName$"), GetMapNameReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$UniqueFunction$"), GetUniqueFunctionReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyParameter$"), GetKeyParameterReplace());

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetContainerStdIncludeContent() const
{
    String content{};

    if (GetCSVFormatType() == CSVFormatType::TreeMap)
    {
        content += TextParsing::gMapInclude;
    }

    content += TextParsing::gMemoryInclude;

    if (GetCSVFormatType() == CSVFormatType::HashMap)
    {
        content += TextParsing::gUnorderedMapInclude;
    }

    content += TextParsing::gVectorInclude;

    return content;
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetContainerGetFunctionReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("SingleContainerGetFunction"));
    }
    else if (GetCSVFormatType() == CSVFormatType::Vector)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("VectorContainerGetFunction"));
    }
    else
    {
        return codeMapping.GetElement(SYSTEM_TEXT("ContainerGetFunction"));
    }
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetMappingContainerUsingReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::HashMap ||
        GetCSVFormatType() == CSVFormatType::TreeMap)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("MappingContainerUsing"));
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetContainerTypeReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::HashMap ||
        GetCSVFormatType() == CSVFormatType::TreeMap)
    {
        return SYSTEM_TEXT("MappingContainer");
    }
    else if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        return SYSTEM_TEXT("Const") + GetCSVClassName() + SYSTEM_TEXT("SharedPtr");
    }
    else
    {
        return SYSTEM_TEXT("Container");
    }
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetContainerUsingReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        return SYSTEM_TEXT("");
    }
    else
    {
        return codeMapping.GetElement(SYSTEM_TEXT("ContainerUsing"));
    }
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetMapNameReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::HashMap)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("unordered_map"));
    }
    else if (GetCSVFormatType() == CSVFormatType::TreeMap)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("map"));
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetUniqueFunctionReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::Default ||
        GetCSVFormatType() == CSVFormatType::Key)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("UniqueFunction"));
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateContainerHeadFile::GetKeyParameterReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Vector)
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(SYSTEM_TEXT("KeyParameter"));
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}
