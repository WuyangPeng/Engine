/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:55)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateBaseSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateBaseSourceFile::CSVGenerateBaseSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateBaseSourceFile)

System::String CoreTools::CSVGenerateBaseSourceFile::GetSuffix() const
{
    return String{ TextParsing::gBase };
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gSourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EntityBaseCpp.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    const auto head = GetCSVHead();

    const auto baseGetFunctionDefine = codeMapping.GetElement(SYSTEM_TEXT("BaseGetFunctionDefine"));
    const auto baseStringGetFunctionDefine = codeMapping.GetElement(SYSTEM_TEXT("BaseStringGetFunctionDefine"));
    const auto baseArrayGetFunctionDefine = codeMapping.GetElement(SYSTEM_TEXT("BaseArrayGetFunctionDefine"));
    const auto baseEnumGetFunctionDefine = codeMapping.GetElement(SYSTEM_TEXT("BaseEnumGetFunctionDefine"));
    const auto baseGetCountArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetCountArrayFunctionDefine"));
    const auto baseGetValueArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetValueArrayFunctionDefine"));
    const auto baseGetBeginIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetBeginIterArrayFunctionDefine"));
    const auto baseGetEndIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetEndIterArrayFunctionDefine"));
    const auto baseGetMappingFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetMappingFunctionDefine"));
    const auto baseGetMappingArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetMappingArrayFunctionDefine"));

    String baseGetFunctionDefineContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto functionVariableName = head.GetFunctionVariableName(index);
        const auto dataType = head.GetDataType(index);
        const auto actualType = head.GetActualType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto upperVariableName = head.GetUpperVariableName(index);

        auto copyBaseGetFunctionDefine = baseGetFunctionDefine;

        if (dataType == CSVDataType::String)
        {
            copyBaseGetFunctionDefine = baseStringGetFunctionDefine;
        }
        else if (dataType == CSVDataType::Enum)
        {
            copyBaseGetFunctionDefine = baseEnumGetFunctionDefine;
        }
        else if (CSVDataType::BoolArray <= dataType)
        {
            copyBaseGetFunctionDefine = baseArrayGetFunctionDefine;
        }
        else
        {
            const auto defaultValue = CSVTypeConversion::GetBaseReturnDescribe(dataType);

            boost::algorithm::replace_all(copyBaseGetFunctionDefine, SYSTEM_TEXT("$ElementDefaultValue$"), defaultValue);
        }

        if (CSVDataType::BoolArray <= dataType)
        {
            boost::algorithm::replace_all(copyBaseGetFunctionDefine, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("$Namespace$::$ClassName$Base::") + abbreviation);
        }
        else
        {
            boost::algorithm::replace_all(copyBaseGetFunctionDefine, SYSTEM_TEXT("$ElementType$"), actualType);
        }

        boost::algorithm::replace_all(copyBaseGetFunctionDefine, SYSTEM_TEXT("$ElementName$"), functionVariableName);

        if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
        {
            boost::algorithm::replace_all(copyBaseGetFunctionDefine, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(" noexcept"));
        }
        else
        {
            boost::algorithm::replace_all(copyBaseGetFunctionDefine, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(""));
        }

        baseGetFunctionDefineContent += copyBaseGetFunctionDefine;
        baseGetFunctionDefineContent += SYSTEM_TEXT("\n");

        if (CSVDataType::BoolArray <= dataType)
        {
            auto copyBaseGetCountArrayFunction = baseGetCountArrayFunction;

            boost::algorithm::replace_all(copyBaseGetCountArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyBaseGetCountArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            baseGetFunctionDefineContent += copyBaseGetCountArrayFunction;
            baseGetFunctionDefineContent += SYSTEM_TEXT("\n");

            auto copyBaseGetValueArrayFunction = baseGetValueArrayFunction;

            boost::algorithm::replace_all(copyBaseGetValueArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyBaseGetValueArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            boost::algorithm::replace_all(copyBaseGetValueArrayFunction, SYSTEM_TEXT("$SmallElementType$"), valueType);

            baseGetFunctionDefineContent += copyBaseGetValueArrayFunction;
            baseGetFunctionDefineContent += SYSTEM_TEXT("\n");

            auto copyBaseGetBeginIterArrayFunction = baseGetBeginIterArrayFunction;

            boost::algorithm::replace_all(copyBaseGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyBaseGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            baseGetFunctionDefineContent += copyBaseGetBeginIterArrayFunction;
            baseGetFunctionDefineContent += SYSTEM_TEXT("\n");

            auto copyBaseGetEndIterArrayFunction = baseGetEndIterArrayFunction;

            boost::algorithm::replace_all(copyBaseGetEndIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyBaseGetEndIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            baseGetFunctionDefineContent += copyBaseGetEndIterArrayFunction;
            baseGetFunctionDefineContent += SYSTEM_TEXT("\n");
        }

        if (const auto mapping = head.GetMapping(index);
            !mapping.empty())
        {
            const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

            if (CSVDataType::BoolArray <= dataType)
            {
                auto copyBaseGetMappingArrayFunction = baseGetMappingArrayFunction;

                boost::algorithm::replace_all(copyBaseGetMappingArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
                boost::algorithm::replace_all(copyBaseGetMappingArrayFunction, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                baseGetFunctionDefineContent += copyBaseGetMappingArrayFunction;
                baseGetFunctionDefineContent += SYSTEM_TEXT("\n");
            }
            else
            {
                auto copyBaseGetMappingFunction = baseGetMappingFunction;

                boost::algorithm::replace_all(copyBaseGetMappingFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
                boost::algorithm::replace_all(copyBaseGetMappingFunction, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                baseGetFunctionDefineContent += copyBaseGetMappingFunction;
                baseGetFunctionDefineContent += SYSTEM_TEXT("\n");
            }
        }
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$BaseGetFunctionDefine$"), baseGetFunctionDefineContent);

    return ReplaceTemplate(content);
}
