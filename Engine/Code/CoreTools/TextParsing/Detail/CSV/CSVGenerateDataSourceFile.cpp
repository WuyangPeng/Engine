///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:45)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateDataSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <set>

CoreTools::CSVGenerateDataSourceFile::CSVGenerateDataSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateDataSourceFile)

System::String CoreTools::CSVGenerateDataSourceFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateDataSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateDataSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gSourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EntityCpp.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    std::set<String> dataIncludeContainer{};

    auto includeChildClass = codeMapping.GetElement(SYSTEM_TEXT("IncludeChildClass"));
    boost::algorithm::replace_all(includeChildClass, SYSTEM_TEXT("$ClassName$"), GetCSVClassName());
    dataIncludeContainer.emplace(includeChildClass);

    const auto head = GetCSVHead();

    if (head.HasMapping())
    {
        auto includeNamespaceContainer = codeMapping.GetElement(SYSTEM_TEXT("IncludeNamespaceContainer"));
        boost::algorithm::replace_all(includeNamespaceContainer, SYSTEM_TEXT("$Namespace$"), GetNameSpace());
        dataIncludeContainer.emplace(includeNamespaceContainer);

        const auto count = head.GetCount();
        for (auto index = 0; index < count; ++index)
        {
            if (const auto mapping = head.GetMapping(index);
                !mapping.empty())
            {
                const auto element = StringUtility::ToFirstLetterUpper(mapping);
                auto includeMappingContainer = codeMapping.GetElement(SYSTEM_TEXT("IncludeMappingContainer"));
                boost::algorithm::replace_all(includeMappingContainer, SYSTEM_TEXT("$MappingType$"), element);

                dataIncludeContainer.emplace(includeMappingContainer);
            }
        }
    }

    String dataIncludeContent{};
    for (const auto& element : dataIncludeContainer)
    {
        dataIncludeContent += element;
    }

    if (head.HasArrayDataType())
    {
        dataIncludeContent += SYSTEM_TEXT("#include \"System/Helper/PragmaWarning/NumericCast.h\"\n");
    }

    dataIncludeContent += codeMapping.GetElement(SYSTEM_TEXT("IncludeUserClassInvariantMacro"));

    if (head.HasScope())
    {
        dataIncludeContent += SYSTEM_TEXT("#include \"CoreTools/Helper/ExceptionMacro.h\"\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataInclude$"), dataIncludeContent);

    const auto beginDataClassMember = codeMapping.GetElement(SYSTEM_TEXT("BeginDataClassMember"));
    const auto dataClassMember = codeMapping.GetElement(SYSTEM_TEXT("DataClassMember"));
    const auto endDataClassMember = codeMapping.GetElement(SYSTEM_TEXT("EndDataClassMember"));

    String dataClassMemberContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto functionName = head.GetFunctionName(index);
        const auto actualType = head.GetActualType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto variableName = head.GetVariableName(index);

        auto copyDataClassMember = dataClassMember;
        if (index == head.GetCount() - 1)
        {
            copyDataClassMember = endDataClassMember;
        }
        else if (index == 0)
        {
            copyDataClassMember = beginDataClassMember;
        }

        boost::algorithm::replace_all(copyDataClassMember, SYSTEM_TEXT("$ElementType$"), functionName);
        boost::algorithm::replace_all(copyDataClassMember, SYSTEM_TEXT("$ElementName$"), variableName);

        dataClassMemberContent += copyDataClassMember;
        dataClassMemberContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataClassMember$"), dataClassMemberContent);

    if (head.HasScope())
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataCheckingCall$"), codeMapping.GetElement(SYSTEM_TEXT("DataCheckingCall")));

        auto dataCheckingDefine = codeMapping.GetElement(SYSTEM_TEXT("DataCheckingDefine"));

        const auto checkingCondition = codeMapping.GetElement(SYSTEM_TEXT("DataCheckingCondition"));

        String checkingConditionContent{};
        auto first = true;
        for (auto index = 0; index < head.GetCount(); ++index)
        {
            if (const auto scope = head.GetScope(index);
                !scope.empty())
            {
                if (!first)
                {
                    checkingConditionContent += SYSTEM_TEXT("\n");
                    first = false;
                }

                auto copyCheckingCondition = checkingCondition;

                boost::algorithm::replace_all(copyCheckingCondition, SYSTEM_TEXT("$CheckingTypeCondition$"), head.GetScopeExpression(index));
                boost::algorithm::replace_all(copyCheckingCondition, SYSTEM_TEXT("$ElementType$"), head.GetVariableName(index));

                checkingConditionContent += copyCheckingCondition;
            }
        }

        boost::algorithm::replace_all(dataCheckingDefine, SYSTEM_TEXT("$DataCheckingCondition$"), checkingConditionContent);

        boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataCheckingDefine$"), dataCheckingDefine);

        auto dataIsValidDefine = codeMapping.GetElement(SYSTEM_TEXT("DataIsValidDefine"));

        String checkingIsValidConditionContent{};
        first = true;
        for (auto index = 0; index < head.GetCount(); ++index)
        {
            if (const auto scope = head.GetScope(index);
                !scope.empty())
            {
                if (!first)
                {
                    checkingIsValidConditionContent += SYSTEM_TEXT("\n");
                    first = false;
                }

                checkingIsValidConditionContent += SYSTEM_TEXT("        (") + head.GetScopeExpression(index) + SYSTEM_TEXT(")");
            }
        }

        boost::algorithm::replace_all(dataIsValidDefine, SYSTEM_TEXT("$CheckingIsValidCondition$"), checkingIsValidConditionContent);
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataIsValidDefine$"), dataIsValidDefine);
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataCheckingCall$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataCheckingDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataIsValidDefine$"), codeMapping.GetElement(SYSTEM_TEXT("DataIsValidStubDefine")));
    }

    const auto dataGetFunctionDefine = codeMapping.GetElement(SYSTEM_TEXT("DataGetFunctionDefine"));
    const auto dataGetCountArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetCountArrayFunctionDefine"));
    const auto dataGetValueArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetValueArrayFunctionDefine"));
    const auto dataGetBeginIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetBeginIterArrayFunctionDefine"));
    const auto dataGetEndIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetEndIterArrayFunctionDefine"));
    const auto dataGetMappingFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetMappingFunctionDefine"));
    const auto dataGetMappingArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("DataGetMappingArrayFunctionDefine"));

    String dataGetFunctionDefineContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto functionVariableName = head.GetFunctionVariableName(index);
        const auto dataType = head.GetDataType(index);
        const auto actualType = head.GetActualType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto upperVariableName = head.GetUpperVariableName(index);
        const auto variableName = head.GetVariableName(index);

        auto copyDataGetFunctionDefine = dataGetFunctionDefine;

        if (CSVDataType::BoolArray <= dataType)
        {
            boost::algorithm::replace_all(copyDataGetFunctionDefine, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("$Namespace$::$ClassName$::") + abbreviation);
        }
        else if (dataType == CSVDataType::Enum)
        {
            boost::algorithm::replace_all(copyDataGetFunctionDefine, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("$Namespace$::") + abbreviation);
        }
        else
        {
            boost::algorithm::replace_all(copyDataGetFunctionDefine, SYSTEM_TEXT("$ElementType$"), actualType);
        }

        boost::algorithm::replace_all(copyDataGetFunctionDefine, SYSTEM_TEXT("$ElementName$"), functionVariableName);

        if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
        {
            boost::algorithm::replace_all(copyDataGetFunctionDefine, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(" noexcept"));
        }
        else
        {
            boost::algorithm::replace_all(copyDataGetFunctionDefine, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(""));
        }

        boost::algorithm::replace_all(copyDataGetFunctionDefine, SYSTEM_TEXT("$SmallElementName$"), variableName);

        dataGetFunctionDefineContent += copyDataGetFunctionDefine;
        dataGetFunctionDefineContent += SYSTEM_TEXT("\n");

        if (CSVDataType::BoolArray <= dataType)
        {
            auto copyDataGetCountArrayFunction = dataGetCountArrayFunction;

            boost::algorithm::replace_all(copyDataGetCountArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyDataGetCountArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
            boost::algorithm::replace_all(copyDataGetCountArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

            dataGetFunctionDefineContent += copyDataGetCountArrayFunction;
            dataGetFunctionDefineContent += SYSTEM_TEXT("\n");

            auto copyDataGetValueArrayFunction = dataGetValueArrayFunction;

            boost::algorithm::replace_all(copyDataGetValueArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyDataGetValueArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            boost::algorithm::replace_all(copyDataGetValueArrayFunction, SYSTEM_TEXT("$SmallElementType$"), valueType);
            boost::algorithm::replace_all(copyDataGetValueArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

            dataGetFunctionDefineContent += copyDataGetValueArrayFunction;
            dataGetFunctionDefineContent += SYSTEM_TEXT("\n");

            auto copyDataGetBeginIterArrayFunction = dataGetBeginIterArrayFunction;

            boost::algorithm::replace_all(copyDataGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyDataGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
            boost::algorithm::replace_all(copyDataGetBeginIterArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

            dataGetFunctionDefineContent += copyDataGetBeginIterArrayFunction;
            dataGetFunctionDefineContent += SYSTEM_TEXT("\n");

            auto copyDataGetEndIterArrayFunction = dataGetEndIterArrayFunction;

            boost::algorithm::replace_all(copyDataGetEndIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copyDataGetEndIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            boost::algorithm::replace_all(copyDataGetEndIterArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

            dataGetFunctionDefineContent += copyDataGetEndIterArrayFunction;
            dataGetFunctionDefineContent += SYSTEM_TEXT("\n");
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

                boost::algorithm::replace_all(copyDataGetMappingArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

                dataGetFunctionDefineContent += copyDataGetMappingArrayFunction;
                dataGetFunctionDefineContent += SYSTEM_TEXT("\n");
            }
            else
            {
                auto copyDataGetMappingFunction = dataGetMappingFunction;

                boost::algorithm::replace_all(copyDataGetMappingFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
                boost::algorithm::replace_all(copyDataGetMappingFunction, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                boost::algorithm::replace_all(copyDataGetMappingFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

                dataGetFunctionDefineContent += copyDataGetMappingFunction;
                dataGetFunctionDefineContent += SYSTEM_TEXT("\n");
            }
        }
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataGetFunctionDefine$"), dataGetFunctionDefineContent);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Namespace$"), GetNameSpace());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassName$"), GetCSVClassName());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(GetCSVClassName()));

    if (head.GetCSVFormatType() == CSVFormatType::Key)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyName$"), head.GetKey());
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyName$"), head.GetVariableName(0));
    }

    if (head.HasScope())
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassIsValidLevel$"), SYSTEM_TEXT("1"));
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassIsValidLevel$"), SYSTEM_TEXT("9"));
    }

    return ReplaceTemplate(content);
}
