///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:19)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <map>
#include <set>

CoreTools::CSVTotalGenerateImpl::CSVTotalGenerateImpl(String nameSpace, CSVHeadContainer csvHeadContainer, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : nameSpace{ std::move(nameSpace) }, csvHeadContainer{ std::move(csvHeadContainer) }, codeMappingAnalysis{ std::move(codeMappingAnalysis) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVTotalGenerateImpl)

void CoreTools::CSVTotalGenerateImpl::GenerateFile(const String& codeDirectory, const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto fileName = directory + TextParsing::gForwardSlash + nameSpace + GetFileSuffix();

    const auto oldContent = GetOldContent(fileName);
    const auto newContent = GetContent(codeDirectory);

    if (oldContent != newContent)
    {
        const auto result = StringConversion::StandardConversionMultiByte(newContent);

        FileManagerHelper::SaveIntoFile(fileName, true, boost::numeric_cast<int>(result.size()), result.c_str());
    }
}

System::String CoreTools::CSVTotalGenerateImpl::GetOldContent(const String& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    try
    {
        IFStreamManager iFStreamManager{ fileName };

        iFStreamManager.SetSimplifiedChinese();

        return iFStreamManager.GetFileContent();
    }
    catch (const Error&)
    {
        // 文件不存在是正常的。
        return String{};
    }
}

CoreTools::CodeMappingAnalysis CoreTools::CSVTotalGenerateImpl::GetCodeMappingAnalysis() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return codeMappingAnalysis;
}

CoreTools::CSVTotalGenerateImpl::String CoreTools::CSVTotalGenerateImpl::GetNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nameSpace;
}

CoreTools::CSVTotalGenerateImpl::CSVHeadContainer CoreTools::CSVTotalGenerateImpl::GetCSVHeadContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHeadContainer;
}

CoreTools::CSVTotalGenerateImpl::String CoreTools::CSVTotalGenerateImpl::GetTemplateContent(const String& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    IFStreamManager streamManager{ fileName };
    streamManager.SetSimplifiedChinese();

    return streamManager.GetFileContent();
}

CoreTools::CSVTotalGenerateImpl::String CoreTools::CSVTotalGenerateImpl::ReplaceTemplate(const String& content) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto result = content;

    boost::algorithm::replace_all(result, SYSTEM_TEXT("$Copyright$"), codeMappingAnalysis.GetElement(SYSTEM_TEXT("Copyright")));
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$NamespaceUppercaseSeparator$"), CoreTools::StringUtility::ToUpperMacro(GetNameSpace()));
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$NameSpaceName$"), GetNameSpace());

    return result;
}
