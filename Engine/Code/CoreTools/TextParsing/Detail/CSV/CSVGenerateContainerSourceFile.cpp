///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:47)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateContainerSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateContainerSourceFile::CSVGenerateContainerSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateContainerSourceFile)

System::String CoreTools::CSVGenerateContainerSourceFile::GetSuffix() const
{
    return String{ TextParsing::gContainer };
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gSourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EntityContainerCpp.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    if (const auto head = GetCSVHead();
        head.GetCSVFormatType() == CSVFormatType::Unique)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetFirstContainerDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$EntityContainerInclude$"), codeMapping.GetElement(SYSTEM_TEXT("SingleEntityContainerInclude")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$CallUnique$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$UniqueFunctionDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$LoadFunctionDefine$"), codeMapping.GetElement(SYSTEM_TEXT("UniqueLoadFunctionDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ShrinkToFitCall$"), codeMapping.GetElement(SYSTEM_TEXT("ShrinkToFitCall")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetSharedPtrDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerByKeyDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetOriginalContainerDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerSizeDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetUniqueDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetUniqueDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsVector$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsMap$"), SYSTEM_TEXT(""));
    }
    else if (head.GetCSVFormatType() == CSVFormatType::Default ||
             head.GetCSVFormatType() == CSVFormatType::Key)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetFirstContainerDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetFirstContainerDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$EntityContainerInclude$"), codeMapping.GetElement(SYSTEM_TEXT("EntityContainerInclude")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$CallUnique$"), codeMapping.GetElement(SYSTEM_TEXT("CallUnique")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$UniqueFunctionDefine$"), codeMapping.GetElement(SYSTEM_TEXT("UniqueFunctionDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$LoadFunctionDefine$"), codeMapping.GetElement(SYSTEM_TEXT("LoadFunctionDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ShrinkToFitCall$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetFirstContainerReturn$"), codeMapping.GetElement(SYSTEM_TEXT("GetFirstContainerReturn")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetSharedPtrDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetSharedPtrDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerByKeyDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetOriginalContainerDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetOriginalContainerDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerSizeDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetContainerSizeDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetUniqueDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsVector$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetSharedPtrDefineReturn$"), codeMapping.GetElement(SYSTEM_TEXT("GetSharedPtrDefineReturn")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsMap$"), SYSTEM_TEXT(""));
    }
    else if (head.GetCSVFormatType() == CSVFormatType::Vector)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetFirstContainerDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$EntityContainerInclude$"), codeMapping.GetElement(SYSTEM_TEXT("EntityContainerInclude")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$CallUnique$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$UniqueFunctionDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$LoadFunctionDefine$"), codeMapping.GetElement(SYSTEM_TEXT("LoadFunctionDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ShrinkToFitCall$"), codeMapping.GetElement(SYSTEM_TEXT("ShrinkToFitCall")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetSharedPtrDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetSharedPtrDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerByKeyDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetContainerByKeyDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetOriginalContainerDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetOriginalContainerDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerSizeDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetContainerSizeDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetUniqueDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsVector$"), SYSTEM_TEXT("First"));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetSharedPtrDefineReturn$"), codeMapping.GetElement(SYSTEM_TEXT("VectorGetSharedPtrDefineReturn")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsMap$"), SYSTEM_TEXT(""));
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetFirstContainerDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetFirstContainerDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$EntityContainerInclude$"), codeMapping.GetElement(SYSTEM_TEXT("EntityContainerInclude")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$CallUnique$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$UniqueFunctionDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$LoadFunctionDefine$"), codeMapping.GetElement(SYSTEM_TEXT("MapLoadFunctionDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ShrinkToFitCall$"), codeMapping.GetElement(SYSTEM_TEXT("ShrinkToFitCall")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetFirstContainerReturn$"), codeMapping.GetElement(SYSTEM_TEXT("MapGetFirstContainerReturn")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetSharedPtrDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetSharedPtrDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerByKeyDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetOriginalContainerDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetOriginalContainerDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerSizeDefine$"), codeMapping.GetElement(SYSTEM_TEXT("GetContainerSizeDefine")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetUniqueDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsVector$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetSharedPtrDefineReturn$"), codeMapping.GetElement(SYSTEM_TEXT("MapGetSharedPtrDefineReturn")));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsMap$"), SYSTEM_TEXT("Mapping"));
    }

    return ReplaceTemplate(content);
}
