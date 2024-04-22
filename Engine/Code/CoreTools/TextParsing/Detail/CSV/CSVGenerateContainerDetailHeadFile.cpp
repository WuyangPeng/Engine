/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 10:04)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateContainerDetailHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateContainerDetailHeadFile::CSVGenerateContainerDetailHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvHead, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/EntityContainerDetailH.txt") },

      getEntityMapFirstDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("GetEntityMapFirstDefine")) },
      getEntityFirstDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("GetEntityFirstDefine")) }
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
    return GetSuffix() + TextParsing::gDetailHeadFileExtensionName.data();
}

System::String CoreTools::CSVGenerateContainerDetailHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetEntityFirstDefine$"), IsCSVFormatTypeMap() ? getEntityMapFirstDefine : getEntityFirstDefine);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ElementSecond$"), IsCSVFormatTypeMap() ? SYSTEM_TEXT("element.second") : SYSTEM_TEXT("element"));

    return ReplaceTemplate(content);
}
