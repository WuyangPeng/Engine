/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:55)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateChildHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateChildHeadFile::CSVGenerateChildHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateChildHeadFile)

System::String CoreTools::CSVGenerateChildHeadFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateChildHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateChildHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gHeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateChildHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EntitySubclassH.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    const auto head = GetCSVHead();

    const auto subclassGetFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetFunction"));
    const auto subclassGetCountArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetCountArrayFunction"));
    const auto subclassGetValueArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetValueArrayFunction"));
    const auto subclassGetBeginIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetBeginIterArrayFunction"));
    const auto subclassGetEndIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetEndIterArrayFunction"));
    const auto subclassGetMappingFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetMappingFunction"));
    const auto subclassGetMappingArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetMappingArrayFunction"));

    String subclassGetFunctionContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto actualType = head.GetActualType(index);
        const auto functionVariableName = head.GetFunctionVariableName(index);
        const auto dataType = head.GetDataType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto upperVariableName = head.GetUpperVariableName(index);

        auto copySubclassGetFunction = subclassGetFunction;

        boost::algorithm::replace_all(copySubclassGetFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
        boost::algorithm::replace_all(copySubclassGetFunction, SYSTEM_TEXT("$ElementName$"), functionVariableName);

        if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
        {
            boost::algorithm::replace_all(copySubclassGetFunction, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(" noexcept"));
        }
        else
        {
            boost::algorithm::replace_all(copySubclassGetFunction, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(""));
        }

        subclassGetFunctionContent += copySubclassGetFunction;
        subclassGetFunctionContent += SYSTEM_TEXT("\n");

        if (CSVDataType::BoolArray <= dataType)
        {
            auto copySubclassGetCountArrayFunction = subclassGetCountArrayFunction;

            boost::algorithm::replace_all(copySubclassGetCountArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copySubclassGetCountArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            subclassGetFunctionContent += copySubclassGetCountArrayFunction;
            subclassGetFunctionContent += SYSTEM_TEXT("\n");

            auto copySubclassGetValueArrayFunction = subclassGetValueArrayFunction;

            boost::algorithm::replace_all(copySubclassGetValueArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copySubclassGetValueArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
            if (valueType == SYSTEM_TEXT("System::String"))
            {
                boost::algorithm::replace_all(copySubclassGetValueArrayFunction, SYSTEM_TEXT("$SmallElementType$"), SYSTEM_TEXT("String"));
            }
            else
            {
                boost::algorithm::replace_all(copySubclassGetValueArrayFunction, SYSTEM_TEXT("$SmallElementType$"), valueType);
            }

            subclassGetFunctionContent += copySubclassGetValueArrayFunction;
            subclassGetFunctionContent += SYSTEM_TEXT("\n");

            auto copySubclassGetBeginIterArrayFunction = subclassGetBeginIterArrayFunction;

            boost::algorithm::replace_all(copySubclassGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copySubclassGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            subclassGetFunctionContent += copySubclassGetBeginIterArrayFunction;
            subclassGetFunctionContent += SYSTEM_TEXT("\n");

            auto copySubclassGetEndIterArrayFunction = subclassGetEndIterArrayFunction;

            boost::algorithm::replace_all(copySubclassGetEndIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copySubclassGetEndIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            subclassGetFunctionContent += copySubclassGetEndIterArrayFunction;
            subclassGetFunctionContent += SYSTEM_TEXT("\n");
        }

        if (const auto mapping = head.GetMapping(index);
            !mapping.empty())
        {
            const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

            if (CSVDataType::BoolArray <= dataType)
            {
                auto copySubclassGetMappingArrayFunction = subclassGetMappingArrayFunction;

                boost::algorithm::replace_all(copySubclassGetMappingArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
                boost::algorithm::replace_all(copySubclassGetMappingArrayFunction, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                subclassGetFunctionContent += copySubclassGetMappingArrayFunction;
                subclassGetFunctionContent += SYSTEM_TEXT("\n");
            }
            else
            {
                auto copySubclassGetMappingFunction = subclassGetMappingFunction;

                boost::algorithm::replace_all(copySubclassGetMappingFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
                boost::algorithm::replace_all(copySubclassGetMappingFunction, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                subclassGetFunctionContent += copySubclassGetMappingFunction;
                subclassGetFunctionContent += SYSTEM_TEXT("\n");
            }
        }

        subclassGetFunctionContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassGetFunction$"), subclassGetFunctionContent);

    if (head.GetCSVFormatType() == CSVFormatType::Key)
    {
        auto generateKeyFunction = codeMapping.GetElement(SYSTEM_TEXT("GenerateKeyFunction"));

        boost::algorithm::replace_all(generateKeyFunction, SYSTEM_TEXT("$KeyType$"), GetKeyTypeDescribe());
        boost::algorithm::replace_all(generateKeyFunction, SYSTEM_TEXT("$KeyParameter$"), GenerateKeyParameter());
        boost::algorithm::replace_all(generateKeyFunction, SYSTEM_TEXT("$KeyReturn$"), head.GetKey());

        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GenerateKeyFunction$"), generateKeyFunction);
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$GenerateKeyFunction$"), SYSTEM_TEXT(""));
    }

    if (head.HasScope())
    {
        auto subclassCheckingFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassCheckingFunction"));

        boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassCheckingFunction$"), subclassCheckingFunction);
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassCheckingFunction$"), SYSTEM_TEXT(""));
    }

    auto subclassMember = codeMapping.GetElement(SYSTEM_TEXT("SubclassMember"));
    String subclassMemberContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto abbreviation = head.GetAbbreviation(index);
        const auto variableName = head.GetVariableName(index);
        const auto annotation = StringConversion::Utf8ConversionStandard(head.GetAnnotation(index));

        auto copySubclassMember = subclassMember;

        boost::algorithm::replace_all(copySubclassMember, SYSTEM_TEXT("$MemberType$"), abbreviation);
        boost::algorithm::replace_all(copySubclassMember, SYSTEM_TEXT("$MemberName$"), variableName);
        boost::algorithm::replace_all(copySubclassMember, SYSTEM_TEXT("$MemberNote$"), annotation);

        subclassMemberContent += copySubclassMember;
        subclassMemberContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassMember$"), subclassMemberContent);

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateChildHeadFile::GenerateKeyParameter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto head = GetCSVHead();
    const auto result = head.GetKeyName();

    String content{};

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(head.GetDataType(value));
        content += TextParsing::gSpace;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += TextParsing::gComma;
            content += TextParsing::gSpace;
        }
    }

    return content;
}