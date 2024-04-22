/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 11:21)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateContainerSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateContainerSourceFile::CSVGenerateContainerSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/EntityContainerCpp.txt") }
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
    return GetSuffix() + TextParsing::gSourceFileExtensionName.data();
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetFirstContainerDefine$"), GetFirstContainerDefineReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$EntityContainerInclude$"), GetEntityContainerIncludeReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$CallUnique$"), GetCallUniqueReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$UniqueFunctionDefine$"), GetUniqueFunctionDefineReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$LoadFunctionDefine$"), GetLoadFunctionDefineReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ShrinkToFitCall$"), GetShrinkToFitCallReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetFirstContainerReturn$"), GetFirstContainerReturnReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetSharedPtrDefine$"), GetSharedPtrDefineReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerByKeyDefine$"), GetContainerByKeyDefineReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetOriginalContainerDefine$"), GetOriginalContainerDefineReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerSizeDefine$"), GetContainerSizeDefineReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetUniqueDefine$"), GetUniqueDefineReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsVector$"), GetIsVectorReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IsMap$"), GetIsMapReplace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetSharedPtrDefineReturn$"), GetSharedPtrDefineReturnReplace());

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetFirstContainerDefineReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Unique ||
        GetCSVFormatType() == CSVFormatType::Vector)
    {
        return SYSTEM_TEXT("");
    }
    else
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(SYSTEM_TEXT("GetFirstContainerDefine"));
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetEntityContainerIncludeReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("SingleEntityContainerInclude"));
    }
    else
    {
        return codeMapping.GetElement(SYSTEM_TEXT("EntityContainerInclude"));
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetCallUniqueReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Default ||
        GetCSVFormatType() == CSVFormatType::Key)
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(SYSTEM_TEXT("CallUnique"));
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetUniqueFunctionDefineReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Default ||
        GetCSVFormatType() == CSVFormatType::Key)
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(SYSTEM_TEXT("UniqueFunctionDefine"));
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetLoadFunctionDefineReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("UniqueLoadFunctionDefine"));
    }
    else if (GetCSVFormatType() == CSVFormatType::Default ||
             GetCSVFormatType() == CSVFormatType::Key ||
             GetCSVFormatType() == CSVFormatType::Vector)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("LoadFunctionDefine"));
    }
    else
    {
        return codeMapping.GetElement(SYSTEM_TEXT("MapLoadFunctionDefine"));
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetShrinkToFitCallReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Default ||
        GetCSVFormatType() == CSVFormatType::Key)
    {
        return SYSTEM_TEXT("");
    }
    else
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(SYSTEM_TEXT("ShrinkToFitCall"));
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetFirstContainerReturnReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::Unique ||
        GetCSVFormatType() == CSVFormatType::Vector)
    {
        return SYSTEM_TEXT("");
    }
    else if (GetCSVFormatType() == CSVFormatType::Default ||
             GetCSVFormatType() == CSVFormatType::Key)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("GetFirstContainerReturn"));
    }
    else
    {
        return codeMapping.GetElement(SYSTEM_TEXT("MapGetFirstContainerReturn"));
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetSharedPtrDefineReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        return SYSTEM_TEXT("");
    }
    else
    {
        return codeMapping.GetElement(SYSTEM_TEXT("GetSharedPtrDefine"));
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetContainerByKeyDefineReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Vector)
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(SYSTEM_TEXT("GetContainerByKeyDefine"));
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetOriginalContainerDefineReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        return SYSTEM_TEXT("");
    }
    else
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(SYSTEM_TEXT("GetOriginalContainerDefine"));
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetContainerSizeDefineReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        return SYSTEM_TEXT("");
    }
    else
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(SYSTEM_TEXT("GetContainerSizeDefine"));
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetUniqueDefineReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(SYSTEM_TEXT("GetUniqueDefine"));
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetIsVectorReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Vector)
    {
        return SYSTEM_TEXT("First");
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetIsMapReplace() const
{
    if (GetCSVFormatType() == CSVFormatType::Unique ||
        GetCSVFormatType() == CSVFormatType::Default ||
        GetCSVFormatType() == CSVFormatType::Key ||
        GetCSVFormatType() == CSVFormatType::Vector)
    {
        return SYSTEM_TEXT("");
    }
    else
    {
        return SYSTEM_TEXT("Mapping");
    }
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateContainerSourceFile::GetSharedPtrDefineReturnReplace() const
{
    const auto codeMapping = GetCodeMappingAnalysis();

    if (GetCSVFormatType() == CSVFormatType::Unique)
    {
        return SYSTEM_TEXT("");
    }
    else if (GetCSVFormatType() == CSVFormatType::Default ||
             GetCSVFormatType() == CSVFormatType::Key)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("GetSharedPtrDefineReturn"));
    }
    else if (GetCSVFormatType() == CSVFormatType::Vector)
    {
        return codeMapping.GetElement(SYSTEM_TEXT("VectorGetSharedPtrDefineReturn"));
    }
    else
    {
        return codeMapping.GetElement(SYSTEM_TEXT("MapGetSharedPtrDefineReturn"));
    }
}
