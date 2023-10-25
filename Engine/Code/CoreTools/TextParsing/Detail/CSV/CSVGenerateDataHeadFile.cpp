///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:46)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateDataHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateDataHeadFile::CSVGenerateDataHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateDataHeadFile)

System::String CoreTools::CSVGenerateDataHeadFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateDataHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateDataHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gHeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateDataHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EntityH.txt"));

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

    if (head.HasArrayDataType())
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

    const auto dataGetFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetFunction"));
    const auto dataGetCountArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetCountArrayFunction"));
    const auto dataGetValueArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetValueArrayFunction"));
    const auto dataGetBeginIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetBeginIterArrayFunction"));
    const auto dataGetEndIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetEndIterArrayFunction"));
    const auto dataGetMappingFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetMappingFunction"));
    const auto dataGetMappingArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetMappingArrayFunction"));

    String dataGetFunctionContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto actualType = head.GetActualType(index);
        const auto functionVariableName = head.GetFunctionVariableName(index);
        const auto dataType = head.GetDataType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto upperVariableName = head.GetUpperVariableName(index);

        auto copyDataGetFunction = dataGetFunction;

        boost::algorithm::replace_all(copyDataGetFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
        boost::algorithm::replace_all(copyDataGetFunction, SYSTEM_TEXT("$ElementName$"), functionVariableName);

        if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
        {
            boost::algorithm::replace_all(copyDataGetFunction, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(" noexcept"));
        }
        else
        {
            boost::algorithm::replace_all(copyDataGetFunction, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(""));
        }

        dataGetFunctionContent += copyDataGetFunction;
        dataGetFunctionContent += SYSTEM_TEXT("\n");

        if (CSVDataType::BoolArray <= dataType)
        {
            auto copyDataGetCountArrayFunction = dataGetCountArrayFunction;

            boost::algorithm::replace_all(copyDataGetCountArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyDataGetCountArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            dataGetFunctionContent += copyDataGetCountArrayFunction;
            dataGetFunctionContent += SYSTEM_TEXT("\n");

            auto copyDataGetValueArrayFunction = dataGetValueArrayFunction;

            boost::algorithm::replace_all(copyDataGetValueArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyDataGetValueArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
            if (valueType == SYSTEM_TEXT("System::String"))
            {
                boost::algorithm::replace_all(copyDataGetValueArrayFunction, SYSTEM_TEXT("$SmallElementType$"), SYSTEM_TEXT("String"));
            }
            else
            {
                boost::algorithm::replace_all(copyDataGetValueArrayFunction, SYSTEM_TEXT("$SmallElementType$"), valueType);
            }

            dataGetFunctionContent += copyDataGetValueArrayFunction;
            dataGetFunctionContent += SYSTEM_TEXT("\n");

            auto copyDataGetBeginIterArrayFunction = dataGetBeginIterArrayFunction;

            boost::algorithm::replace_all(copyDataGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyDataGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            dataGetFunctionContent += copyDataGetBeginIterArrayFunction;
            dataGetFunctionContent += SYSTEM_TEXT("\n");

            auto copyDataGetEndIterArrayFunction = dataGetEndIterArrayFunction;

            boost::algorithm::replace_all(copyDataGetEndIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyDataGetEndIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            dataGetFunctionContent += copyDataGetEndIterArrayFunction;
            dataGetFunctionContent += SYSTEM_TEXT("\n");
        }

        if (const auto mapping = head.GetMapping(index);
            !mapping.empty())
        {
            const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

            if (CSVDataType::BoolArray <= dataType)
            {
                auto copyDataGetMappingArrayFunction = dataGetMappingArrayFunction;

                boost::algorithm::replace_all(copyDataGetMappingArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
                boost::algorithm::replace_all(copyDataGetMappingArrayFunction, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                dataGetFunctionContent += copyDataGetMappingArrayFunction;
                dataGetFunctionContent += SYSTEM_TEXT("\n");
            }
            else
            {
                auto copyDataGetMappingFunction = dataGetMappingFunction;

                boost::algorithm::replace_all(copyDataGetMappingFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
                boost::algorithm::replace_all(copyDataGetMappingFunction, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                dataGetFunctionContent += copyDataGetMappingFunction;
                dataGetFunctionContent += SYSTEM_TEXT("\n");
            }
        }

        dataGetFunctionContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataGetFunction$"), dataGetFunctionContent);

    if (head.HasScope())
    {
        auto dataCheckingFunction = codeMapping.GetElement(SYSTEM_TEXT("DataCheckingFunction"));

        boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataCheckingFunction$"), dataCheckingFunction);
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataCheckingFunction$"), SYSTEM_TEXT(""));
    }

    auto dataMember = codeMapping.GetElement(SYSTEM_TEXT("DataMember"));
    String dataMemberContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto abbreviation = head.GetAbbreviation(index);
        const auto variableName = head.GetVariableName(index);
        const auto annotation = StringConversion::Utf8ConversionStandard(head.GetAnnotation(index));

        auto copyDataMember = dataMember;

        boost::algorithm::replace_all(copyDataMember, SYSTEM_TEXT("$MemberType$"), abbreviation);
        boost::algorithm::replace_all(copyDataMember, SYSTEM_TEXT("$MemberName$"), variableName);
        boost::algorithm::replace_all(copyDataMember, SYSTEM_TEXT("$MemberNote$"), annotation);

        dataMemberContent += copyDataMember;
        dataMemberContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataMember$"), dataMemberContent);

    return ReplaceTemplate(content);
}
