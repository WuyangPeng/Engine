/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:55)

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
