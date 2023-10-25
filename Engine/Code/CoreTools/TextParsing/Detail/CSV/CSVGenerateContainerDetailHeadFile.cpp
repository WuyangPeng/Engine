///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:49)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateContainerDetailHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateContainerDetailHeadFile::CSVGenerateContainerDetailHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateContainerDetailHeadFile)

System::String CoreTools::CSVGenerateContainerDetailHeadFile::GetSuffix() const
{
    return String{ TextParsing::gContainer };
}

System::String CoreTools::CSVGenerateContainerDetailHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateContainerDetailHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gDetailHeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateContainerDetailHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EntityContainerDetailH.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    if (const auto head = GetCSVHead();
        head.GetCSVFormatType() == CSVFormatType::TreeMap ||
        head.GetCSVFormatType() == CSVFormatType::HashMap)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetEntityFirstDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetEntityMapFirstDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ElementSecond$"), SYSTEM_TEXT("element.second"));
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetEntityFirstDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetEntityFirstDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ElementSecond$"), SYSTEM_TEXT("element"));
    }

    return ReplaceTemplate(content);
}
