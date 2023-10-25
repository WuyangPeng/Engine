///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:40)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateImpl::CSVGenerateImpl(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : csvHead{ csvHead }, codeMappingAnalysis{ codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateImpl)

void CoreTools::CSVGenerateImpl::GenerateFile(const String& codeDirectory, const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvClassName = GetCSVClassName();
    const auto fileName = directory + GetFilePrefix() + csvClassName + GetFileSuffix();

    const auto oldContent = GetOldContent(fileName);
    const auto newContent = GetContent(codeDirectory);

    if (oldContent != newContent)
    {
        const auto result = StringConversion::StandardConversionMultiByte(newContent);

        FileManagerHelper::SaveIntoFile(fileName, true, boost::numeric_cast<int>(result.size()), result.c_str());
    }
}

System::String CoreTools::CSVGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(csvHead.GetNameSpace() + GetCSVClassName() + GetFileSuffix());

    String content{ TextParsing::gIfndef };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gDefine;
    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gNamespace };

    content += TextParsing::gSpace;
    content += csvHead.GetNameSpace();
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gFunctionBeginBrackets;

    return content;
}

System::String CoreTools::CSVGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(csvHead.GetNameSpace() + GetCSVClassName() + GetFileSuffix());

    String content{ TextParsing::gEndif };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateImpl::GetKeyTypeDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (csvHead.GetCSVFormatType() != CSVFormatType::Key)
    {
        if (csvHead.GetDataType(0) == CSVDataType::Int64)
        {
            return CSVTypeConversion::GetActualType(CSVDataType::Int64);
        }
    }
    else
    {
        for (const auto result = csvHead.GetKeyName(); const auto& value : result)
        {
            if (csvHead.GetDataType(value) == CSVDataType::Int64)
            {
                return CSVTypeConversion::GetActualType(CSVDataType::Int64);
            }
        }
    }

    return CSVTypeConversion::GetActualType(CSVDataType::Int);
}

CoreTools::CodeMappingAnalysis CoreTools::CSVGenerateImpl::GetCodeMappingAnalysis() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return codeMappingAnalysis;
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.GetNameSpace();
}

const CoreTools::CSVGenerateImpl::HeadContentContainer& CoreTools::CSVGenerateImpl::GetHeadContentContainer()
{
    static const HeadContentContainer headContentContainer{ { { CSVDataType::IntVector2, CSVDataType::IntVector2Array }, SYSTEM_TEXT("IntVector2") },
                                                            { { CSVDataType::IntVector3, CSVDataType::IntVector3Array }, SYSTEM_TEXT("IntVector3") },
                                                            { { CSVDataType::IntVector4, CSVDataType::IntVector4Array }, SYSTEM_TEXT("IntVector4") },
                                                            { { CSVDataType::Vector2, CSVDataType::Vector2Array }, SYSTEM_TEXT("Vector2") },
                                                            { { CSVDataType::Vector3, CSVDataType::Vector3Array }, SYSTEM_TEXT("Vector3") },
                                                            { { CSVDataType::Vector4, CSVDataType::Vector4Array }, SYSTEM_TEXT("Vector4") } };

    return headContentContainer;
}

System::String CoreTools::CSVGenerateImpl::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.GetCSVClassName();
}

System::String CoreTools::CSVGenerateImpl::GetOldContent(const String& fileName)
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

CoreTools::CSVFormatType CoreTools::CSVGenerateImpl::GetCSVFormatType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.GetCSVFormatType();
}

CoreTools::CSVHead CoreTools::CSVGenerateImpl::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead;
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetTemplateContent(const String& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    IFStreamManager streamManager{ fileName };
    streamManager.SetSimplifiedChinese();

    return streamManager.GetFileContent();
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::ReplaceTemplate(const String& content) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto result = content;

    boost::algorithm::replace_all(result, SYSTEM_TEXT("$Copyright$"), codeMappingAnalysis.GetElement(SYSTEM_TEXT("Copyright")));
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$NamespaceUppercaseSeparator$"), CoreTools::StringUtility::ToUpperMacro(GetNameSpace()));
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$NameSpaceName$"), GetNameSpace());
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$Namespace$"), GetNameSpace());
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$ClassNameUppercase$"), CoreTools::StringUtility::ToUpperMacro(GetCSVClassName()));
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$ClassName$"), GetCSVClassName());
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$KeyType$"), GetKeyTypeDescribe());
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$ClassNameLetter$"), StringUtility::ToFirstLetterLower(GetCSVClassName()));
    boost::algorithm::replace_all(result, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(GetCSVClassName()));

    return result;
}
