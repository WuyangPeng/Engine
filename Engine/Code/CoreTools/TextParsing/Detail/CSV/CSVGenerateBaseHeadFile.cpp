///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:52)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateBaseHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateBaseHeadFile::CSVGenerateBaseHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateBaseHeadFile)

System::String CoreTools::CSVGenerateBaseHeadFile::GetSuffix() const
{
    return String{ TextParsing::gBase };
}

System::String CoreTools::CSVGenerateBaseHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateBaseHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gHeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateBaseHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EntityBaseH.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    const auto head = GetCSVHead();

    const auto dataInclude = codeMapping.GetElement(SYSTEM_TEXT("DataInclude"));

    String dataIncludeContent{};
    for (const auto& headContentContainer = GetHeadContentContainer();
         const auto& element : headContentContainer)
    {
        if (head.HasDataType(element.first.first) || head.HasDataType(element.first.second))
        {
            auto copyDataInclude = dataInclude;

            boost::algorithm::replace_all(copyDataInclude, SYSTEM_TEXT("$VectorName$"), element.second);

            dataIncludeContent += copyDataInclude;
            dataIncludeContent += SYSTEM_TEXT("\n");
        }
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataInclude$"), dataIncludeContent);

    const auto stdInclude = codeMapping.GetElement(SYSTEM_TEXT("StdInclude"));

    String stdIncludeContent{};
    if (head.HasDataType(CSVDataType::BoolArray))
    {
        auto copyStdInclude = stdInclude;

        boost::algorithm::replace_all(copyStdInclude, SYSTEM_TEXT("$StdName$"), SYSTEM_TEXT("deque"));

        stdIncludeContent += copyStdInclude;
        stdIncludeContent += SYSTEM_TEXT("\n");
    }

    if (head.HasMapping())
    {
        auto copyStdInclude = stdInclude;

        boost::algorithm::replace_all(copyStdInclude, SYSTEM_TEXT("$StdName$"), SYSTEM_TEXT("memory"));

        stdIncludeContent += copyStdInclude;
        stdIncludeContent += SYSTEM_TEXT("\n");
    }

    if (head.HasVectorArrayDataType())
    {
        auto copyStdInclude = stdInclude;

        boost::algorithm::replace_all(copyStdInclude, SYSTEM_TEXT("$StdName$"), SYSTEM_TEXT("vector"));

        stdIncludeContent += copyStdInclude;
        stdIncludeContent += SYSTEM_TEXT("\n");
    }

    if (head.HasArrayDataType() || head.HasMapping())
    {
        stdIncludeContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$StdInclude$"), stdIncludeContent);

    String baseClassUsingContent{};
    auto isOtherUsing = false;
    if (head.HasDataType(CSVDataType::String))
    {
        isOtherUsing = true;

        const auto baseClassUsing = codeMapping.GetElement(SYSTEM_TEXT("BaseClassStringUsing"));

        baseClassUsingContent += baseClassUsing;
        baseClassUsingContent += SYSTEM_TEXT("\n");
    }

    if (head.HasDataType(CSVDataType::StringArray))
    {
        isOtherUsing = true;

        auto baseClassContainerUsing = codeMapping.GetElement(SYSTEM_TEXT("BaseClassContainerUsing"));

        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("String"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$SmallElementType$"), SYSTEM_TEXT("String"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$StdType$"), SYSTEM_TEXT("vector"));

        baseClassUsingContent += baseClassContainerUsing;
        baseClassUsingContent += SYSTEM_TEXT("\n");
    }

    if (head.HasDataType(CSVDataType::IntArray))
    {
        isOtherUsing = true;

        auto baseClassContainerUsing = codeMapping.GetElement(SYSTEM_TEXT("BaseClassContainerUsing"));

        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("Int"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$SmallElementType$"), SYSTEM_TEXT("int"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$StdType$"), SYSTEM_TEXT("vector"));

        baseClassUsingContent += baseClassContainerUsing;
        baseClassUsingContent += SYSTEM_TEXT("\n");
    }

    if (head.HasDataType(CSVDataType::Int64Array))
    {
        isOtherUsing = true;

        auto baseClassContainerUsing = codeMapping.GetElement(SYSTEM_TEXT("BaseClassContainerUsing"));

        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("Int64"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$SmallElementType$"), SYSTEM_TEXT("int64_t"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$StdType$"), SYSTEM_TEXT("vector"));

        baseClassUsingContent += baseClassContainerUsing;
        baseClassUsingContent += SYSTEM_TEXT("\n");
    }

    if (head.HasDataType(CSVDataType::BoolArray))
    {
        isOtherUsing = true;

        auto baseClassContainerUsing = codeMapping.GetElement(SYSTEM_TEXT("BaseClassContainerUsing"));

        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("Bool"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$SmallElementType$"), SYSTEM_TEXT("bool"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$StdType$"), SYSTEM_TEXT("deque"));

        baseClassUsingContent += baseClassContainerUsing;
        baseClassUsingContent += SYSTEM_TEXT("\n");
    }

    if (head.HasDataType(CSVDataType::CharArray))
    {
        isOtherUsing = true;

        auto baseClassCharUsing = codeMapping.GetElement(SYSTEM_TEXT("BaseClassCharUsing"));

        baseClassUsingContent += baseClassCharUsing;
        baseClassUsingContent += SYSTEM_TEXT("\n");

        auto baseClassContainerUsing = codeMapping.GetElement(SYSTEM_TEXT("BaseClassContainerUsing"));

        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("Char"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$SmallElementType$"), SYSTEM_TEXT("Char"));
        boost::algorithm::replace_all(baseClassContainerUsing, SYSTEM_TEXT("$StdType$"), SYSTEM_TEXT("vector"));

        baseClassUsingContent += baseClassContainerUsing;
        baseClassUsingContent += SYSTEM_TEXT("\n");
    }

    if (head.HasMapping())
    {
        for (auto i = 0; i < head.GetCount(); ++i)
        {
            if (const auto mapping = head.GetMapping(i);
                !mapping.empty())
            {
                const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

                auto baseClassMappingUsing = codeMapping.GetElement(SYSTEM_TEXT("BaseClassMappingUsing"));

                boost::algorithm::replace_all(baseClassMappingUsing, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                baseClassUsingContent += baseClassMappingUsing;
                baseClassUsingContent += SYSTEM_TEXT("\n");

                if (CSVDataType::BoolArray <= head.GetDataType(i))
                {
                    auto baseClassMappingContainerUsing = codeMapping.GetElement(SYSTEM_TEXT("BaseClassMappingContainerUsing"));

                    boost::algorithm::replace_all(baseClassMappingContainerUsing, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                    baseClassUsingContent += baseClassMappingContainerUsing;
                    baseClassUsingContent += SYSTEM_TEXT("\n");
                }
            }
        }
    }

    if (isOtherUsing)
    {
        baseClassUsingContent += TextParsing::gNewlineCharacter;
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$BaseClassUsing$"), baseClassUsingContent);

    const auto baseGetFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetFunction"));
    const auto baseGetCountArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetCountArrayFunction"));
    const auto baseGetValueArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetValueArrayFunction"));
    const auto baseGetBeginIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetBeginIterArrayFunction"));
    const auto baseGetEndIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetEndIterArrayFunction"));
    const auto baseGetMappingFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetMappingFunction"));
    const auto baseGetMappingArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("BaseGetMappingArrayFunction"));

    String baseGetFunctionContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto functionVariableName = head.GetFunctionVariableName(index);
        const auto dataType = head.GetDataType(index);
        const auto actualType = head.GetActualType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto upperVariableName = head.GetUpperVariableName(index);

        auto copyBaseGetFunction = baseGetFunction;

        boost::algorithm::replace_all(copyBaseGetFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
        boost::algorithm::replace_all(copyBaseGetFunction, SYSTEM_TEXT("$ElementName$"), functionVariableName);

        if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
        {
            boost::algorithm::replace_all(copyBaseGetFunction, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(" noexcept"));
        }
        else
        {
            boost::algorithm::replace_all(copyBaseGetFunction, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(""));
        }

        baseGetFunctionContent += copyBaseGetFunction;
        baseGetFunctionContent += SYSTEM_TEXT("\n");

        if (CSVDataType::BoolArray <= dataType)
        {
            auto copyBaseGetCountArrayFunction = baseGetCountArrayFunction;

            boost::algorithm::replace_all(copyBaseGetCountArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyBaseGetCountArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            baseGetFunctionContent += copyBaseGetCountArrayFunction;
            baseGetFunctionContent += SYSTEM_TEXT("\n");

            auto copyBaseGetValueArrayFunction = baseGetValueArrayFunction;

            boost::algorithm::replace_all(copyBaseGetValueArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyBaseGetValueArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
            if (valueType == SYSTEM_TEXT("System::String"))
            {
                boost::algorithm::replace_all(copyBaseGetValueArrayFunction, SYSTEM_TEXT("$SmallElementType$"), SYSTEM_TEXT("String"));
            }
            else
            {
                boost::algorithm::replace_all(copyBaseGetValueArrayFunction, SYSTEM_TEXT("$SmallElementType$"), valueType);
            }

            baseGetFunctionContent += copyBaseGetValueArrayFunction;
            baseGetFunctionContent += SYSTEM_TEXT("\n");

            auto copyBaseGetBeginIterArrayFunction = baseGetBeginIterArrayFunction;

            boost::algorithm::replace_all(copyBaseGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyBaseGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            baseGetFunctionContent += copyBaseGetBeginIterArrayFunction;
            baseGetFunctionContent += SYSTEM_TEXT("\n");

            auto copyBaseGetEndIterArrayFunction = baseGetEndIterArrayFunction;

            boost::algorithm::replace_all(copyBaseGetEndIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyBaseGetEndIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            baseGetFunctionContent += copyBaseGetEndIterArrayFunction;
            baseGetFunctionContent += SYSTEM_TEXT("\n");
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

                baseGetFunctionContent += copyBaseGetMappingArrayFunction;
                baseGetFunctionContent += SYSTEM_TEXT("\n");
            }
            else
            {
                auto copyBaseGetMappingFunction = baseGetMappingFunction;

                boost::algorithm::replace_all(copyBaseGetMappingFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
                boost::algorithm::replace_all(copyBaseGetMappingFunction, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                baseGetFunctionContent += copyBaseGetMappingFunction;
                baseGetFunctionContent += SYSTEM_TEXT("\n");
            }
        }

        baseGetFunctionContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$BaseGetFunction$"), baseGetFunctionContent);

    return ReplaceTemplate(content);
}
