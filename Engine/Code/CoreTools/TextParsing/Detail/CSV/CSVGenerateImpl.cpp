/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 18:12)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/FileManager/OFileStreamManager.h"
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
        for (const auto result = csvHead.GetKeyName();
             const auto& element : result)
        {
            if (csvHead.GetDataType(element) == CSVDataType::Int64)
            {
                return CSVTypeConversion::GetActualType(CSVDataType::Int64);
            }
        }
    }

    return CSVTypeConversion::GetActualType(CSVDataType::Int);
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.GetKey();
}

CoreTools::CodeMappingAnalysis CoreTools::CSVGenerateImpl::GetCodeMappingAnalysis() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return codeMappingAnalysis;
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetCodeMappingElement(const String& codeKey) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return codeMappingAnalysis.GetElement(codeKey);
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
        IFileStreamManager iFStreamManager{ fileName };

        iFStreamManager.SetSimplifiedChinese();

        return iFStreamManager.GetFileContent();
    }
    catch (const Error&)
    {
        /// 文件不存在是正常的。
        return String{};
    }
}

CoreTools::CSVFormatType CoreTools::CSVGenerateImpl::GetCSVFormatType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.GetCSVFormatType();
}

bool CoreTools::CSVGenerateImpl::IsCSVFormatTypeMap() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.GetCSVFormatType() == CSVFormatType::TreeMap || csvHead.GetCSVFormatType() == CSVFormatType::HashMap;
}

bool CoreTools::CSVGenerateImpl::HasDataType(CSVDataType csvDataType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.HasDataType(csvDataType);
}

bool CoreTools::CSVGenerateImpl::HasMapping() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.HasMapping();
}

bool CoreTools::CSVGenerateImpl::HasVectorArrayDataType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.HasVectorArrayDataType();
}

bool CoreTools::CSVGenerateImpl::HasArrayDataType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.HasArrayDataType();
}

bool CoreTools::CSVGenerateImpl::HasScope() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.HasScope();
}

CoreTools::CSVHead CoreTools::CSVGenerateImpl::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead;
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetTemplateContent(const String& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    IFileStreamManager streamManager{ fileName };
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

System::String CoreTools::CSVGenerateImpl::GetCodeKey(const String& codeKey)
{
    return SYSTEM_TEXT("$") + codeKey + SYSTEM_TEXT("$");
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetReplaceContent(const String& data, StringView codeKey, StringView name)
{
    auto copyData = data;

    boost::algorithm::replace_all(copyData, GetCodeKey(codeKey.data()), name);

    return copyData + TextParsing::gNewlineCharacter;
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetReplaceContent(const String& data, const ReplaceType& replace)
{
    auto copyData = data;

    for (const auto& element : replace)
    {
        boost::algorithm::replace_all(copyData, GetCodeKey(element.first.data()), element.second);
    }

    return copyData + TextParsing::gNewlineCharacter;
}

System::String CoreTools::CSVGenerateImpl::GetElementIsNoexceptReplace(CSVDataType csvDataType)
{
    if (CSVDataType::Bool <= csvDataType && csvDataType <= CSVDataType::IntVector4)
    {
        return SYSTEM_TEXT(" noexcept");
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetSmallElementTypeReplace(const String& valueType)
{
    if (valueType == SYSTEM_TEXT("System::String"))
    {
        return SYSTEM_TEXT("String");
    }
    else
    {
        return valueType;
    }
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetElementTypeReplace(CSVDataType csvDataType, const String& abbreviation, const String& actualType)
{
    if (CSVDataType::BoolArray <= csvDataType)
    {
        return SYSTEM_TEXT("$Namespace$::$ClassName$::") + abbreviation;
    }
    else if (csvDataType == CSVDataType::Enum)
    {
        return SYSTEM_TEXT("$Namespace$::") + abbreviation;
    }
    else
    {
        return actualType;
    }
}

System::String CoreTools::CSVGenerateImpl::GetDataIncludeContent(const String& codeKey) const
{
    const auto dataInclude = GetCodeMappingElement(codeKey);

    String content{};

    for (const auto& element : GetHeadContentContainer())
    {
        content += GetDataIncludeContent(dataInclude, element.first.first, element.first.second, element.second);
    }

    return content;
}

System::String CoreTools::CSVGenerateImpl::GetDataIncludeContent(const String& dataInclude, CSVDataType first, CSVDataType second, StringView vectorName) const
{
    if (HasDataType(first) || HasDataType(second))
    {
        return GetReplaceContent(dataInclude, TextParsing::gVectorName, vectorName);
    }

    return String{};
}

System::String CoreTools::CSVGenerateImpl::GetBaseClassUsingHasMappingContent() const
{
    String content{};

    for (auto index = 0; index < csvHead.GetCount(); ++index)
    {
        content += GetBaseClassUsingHasMappingContent(index);
    }

    return content;
}

CoreTools::CSVGenerateImpl::String CoreTools::CSVGenerateImpl::GetBaseClassUsingHasMappingContent(int index) const
{
    String content{};

    if (const auto mapping = csvHead.GetMapping(index);
        !mapping.empty())
    {
        const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

        content += GetReplaceContent(GetCodeMappingElement(SYSTEM_TEXT("BaseClassMappingUsing")), TextParsing::gMappingType, mappingUpper);

        if (CSVDataType::BoolArray <= csvHead.GetDataType(index))
        {
            content += GetReplaceContent(GetCodeMappingElement(SYSTEM_TEXT("BaseClassMappingContainerUsing")), TextParsing::gMappingType, mappingUpper);
        }
    }

    return content;
}