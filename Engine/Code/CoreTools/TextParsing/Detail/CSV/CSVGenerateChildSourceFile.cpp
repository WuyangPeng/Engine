/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:55)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateChildSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <set>

CoreTools::CSVGenerateChildSourceFile::CSVGenerateChildSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateChildSourceFile)

System::String CoreTools::CSVGenerateChildSourceFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateChildSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateChildSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gSourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EntitySubclassCpp.txt"));

    const auto codeMapping = GetCodeMappingAnalysis();

    std::set<String> subclassIncludeContainer{};

    auto includeChildClass = codeMapping.GetElement(SYSTEM_TEXT("IncludeChildClass"));
    boost::algorithm::replace_all(includeChildClass, SYSTEM_TEXT("$ClassName$"), GetCSVClassName());
    subclassIncludeContainer.emplace(includeChildClass);

    const auto head = GetCSVHead();

    if (head.HasMapping())
    {
        auto includeNamespaceContainer = codeMapping.GetElement(SYSTEM_TEXT("IncludeNamespaceContainer"));
        boost::algorithm::replace_all(includeNamespaceContainer, SYSTEM_TEXT("$Namespace$"), GetNameSpace());
        subclassIncludeContainer.emplace(includeNamespaceContainer);

        const auto count = head.GetCount();
        for (auto index = 0; index < count; ++index)
        {
            if (const auto mapping = head.GetMapping(index);
                !mapping.empty())
            {
                const auto element = StringUtility::ToFirstLetterUpper(mapping);
                auto includeMappingContainer = codeMapping.GetElement(SYSTEM_TEXT("IncludeMappingContainer"));
                boost::algorithm::replace_all(includeMappingContainer, SYSTEM_TEXT("$MappingType$"), element);

                subclassIncludeContainer.emplace(includeMappingContainer);
            }
        }
    }

    String subclassIncludeContent{};
    for (const auto& element : subclassIncludeContainer)
    {
        subclassIncludeContent += element;
    }

    if (head.HasArrayDataType())
    {
        subclassIncludeContent += SYSTEM_TEXT("#include \"System/Helper/PragmaWarning/NumericCast.h\"\n");
    }

    subclassIncludeContent += codeMapping.GetElement(SYSTEM_TEXT("IncludeUserClassInvariantMacro"));

    if (head.HasScope())
    {
        subclassIncludeContent += SYSTEM_TEXT("#include \"CoreTools/Helper/ExceptionMacro.h\"\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassInclude$"), subclassIncludeContent);

    const auto subclassClassMember = codeMapping.GetElement(SYSTEM_TEXT("SubclassClassMember"));
    const auto endSubclassClassMember = codeMapping.GetElement(SYSTEM_TEXT("EndSubclassClassMember"));

    String subclassClassMemberContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto functionName = head.GetFunctionName(index);
        const auto actualType = head.GetActualType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto variableName = head.GetVariableName(index);

        auto copySubclassClassMember = subclassClassMember;
        if (index == head.GetCount() - 1)
        {
            copySubclassClassMember = endSubclassClassMember;
        }

        boost::algorithm::replace_all(copySubclassClassMember, SYSTEM_TEXT("$ElementType$"), functionName);
        boost::algorithm::replace_all(copySubclassClassMember, SYSTEM_TEXT("$ElementName$"), variableName);

        subclassClassMemberContent += copySubclassClassMember;
        subclassClassMemberContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassClassMember$"), subclassClassMemberContent);

    if (head.HasScope())
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassCheckingCall$"), codeMapping.GetElement(SYSTEM_TEXT("SubclassCheckingCall")));

        auto subclassCheckingDefine = codeMapping.GetElement(SYSTEM_TEXT("SubclassCheckingDefine"));

        const auto checkingCondition = codeMapping.GetElement(SYSTEM_TEXT("CheckingCondition"));

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

        boost::algorithm::replace_all(subclassCheckingDefine, SYSTEM_TEXT("$CheckingCondition$"), checkingConditionContent);

        boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassCheckingDefine$"), subclassCheckingDefine);

        auto subclassIsValidDefine = codeMapping.GetElement(SYSTEM_TEXT("SubclassIsValidDefine"));

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

        boost::algorithm::replace_all(subclassIsValidDefine, SYSTEM_TEXT("$CheckingIsValidCondition$"), checkingIsValidConditionContent);
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassIsValidDefine$"), subclassIsValidDefine);
    }
    else
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassCheckingCall$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassCheckingDefine$"), SYSTEM_TEXT(""));
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassIsValidDefine$"), codeMapping.GetElement(SYSTEM_TEXT("SubclassIsValidStubDefine")));
    }

    const auto subclassGetFunctionDefine = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetFunctionDefine"));
    const auto subclassGetCountArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetCountArrayFunctionDefine"));
    const auto subclassGetValueArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetValueArrayFunctionDefine"));
    const auto subclassGetBeginIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetBeginIterArrayFunctionDefine"));
    const auto subclassGetEndIterArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetEndIterArrayFunctionDefine"));
    const auto subclassGetMappingFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetMappingFunctionDefine"));
    const auto subclassGetMappingArrayFunction = codeMapping.GetElement(SYSTEM_TEXT("SubclassGetMappingArrayFunctionDefine"));

    String subclassGetFunctionDefineContent{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto functionVariableName = head.GetFunctionVariableName(index);
        const auto dataType = head.GetDataType(index);
        const auto actualType = head.GetActualType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto upperVariableName = head.GetUpperVariableName(index);
        const auto variableName = head.GetVariableName(index);

        auto copySubclassGetFunctionDefine = subclassGetFunctionDefine;

        if (CSVDataType::BoolArray <= dataType)
        {
            boost::algorithm::replace_all(copySubclassGetFunctionDefine, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("$Namespace$::$ClassName$::") + abbreviation);
        }
        else if (dataType == CSVDataType::Enum)
        {
            boost::algorithm::replace_all(copySubclassGetFunctionDefine, SYSTEM_TEXT("$ElementType$"), SYSTEM_TEXT("$Namespace$::") + abbreviation);
        }
        else
        {
            boost::algorithm::replace_all(copySubclassGetFunctionDefine, SYSTEM_TEXT("$ElementType$"), actualType);
        }

        boost::algorithm::replace_all(copySubclassGetFunctionDefine, SYSTEM_TEXT("$ElementName$"), functionVariableName);

        if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
        {
            boost::algorithm::replace_all(copySubclassGetFunctionDefine, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(" noexcept"));
        }
        else
        {
            boost::algorithm::replace_all(copySubclassGetFunctionDefine, SYSTEM_TEXT("$ElementIsNoexcept$"), SYSTEM_TEXT(""));
        }

        boost::algorithm::replace_all(copySubclassGetFunctionDefine, SYSTEM_TEXT("$SmallElementName$"), variableName);

        subclassGetFunctionDefineContent += copySubclassGetFunctionDefine;
        subclassGetFunctionDefineContent += SYSTEM_TEXT("\n");

        if (CSVDataType::BoolArray <= dataType)
        {
            auto copySubclassGetCountArrayFunction = subclassGetCountArrayFunction;

            boost::algorithm::replace_all(copySubclassGetCountArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copySubclassGetCountArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
            boost::algorithm::replace_all(copySubclassGetCountArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

            subclassGetFunctionDefineContent += copySubclassGetCountArrayFunction;
            subclassGetFunctionDefineContent += SYSTEM_TEXT("\n");

            auto copySubclassGetValueArrayFunction = subclassGetValueArrayFunction;

            boost::algorithm::replace_all(copySubclassGetValueArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copySubclassGetValueArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            boost::algorithm::replace_all(copySubclassGetValueArrayFunction, SYSTEM_TEXT("$SmallElementType$"), valueType);
            boost::algorithm::replace_all(copySubclassGetValueArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

            subclassGetFunctionDefineContent += copySubclassGetValueArrayFunction;
            subclassGetFunctionDefineContent += SYSTEM_TEXT("\n");

            auto copySubclassGetBeginIterArrayFunction = subclassGetBeginIterArrayFunction;

            boost::algorithm::replace_all(copySubclassGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copySubclassGetBeginIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);
            boost::algorithm::replace_all(copySubclassGetBeginIterArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

            subclassGetFunctionDefineContent += copySubclassGetBeginIterArrayFunction;
            subclassGetFunctionDefineContent += SYSTEM_TEXT("\n");

            auto copySubclassGetEndIterArrayFunction = subclassGetEndIterArrayFunction;

            boost::algorithm::replace_all(copySubclassGetEndIterArrayFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
            boost::algorithm::replace_all(copySubclassGetEndIterArrayFunction, SYSTEM_TEXT("$ElementType$"), abbreviation);

            boost::algorithm::replace_all(copySubclassGetEndIterArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

            subclassGetFunctionDefineContent += copySubclassGetEndIterArrayFunction;
            subclassGetFunctionDefineContent += SYSTEM_TEXT("\n");
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

                boost::algorithm::replace_all(copySubclassGetMappingArrayFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

                subclassGetFunctionDefineContent += copySubclassGetMappingArrayFunction;
                subclassGetFunctionDefineContent += SYSTEM_TEXT("\n");
            }
            else
            {
                auto copySubclassGetMappingFunction = subclassGetMappingFunction;

                boost::algorithm::replace_all(copySubclassGetMappingFunction, SYSTEM_TEXT("$ElementName$"), upperVariableName);
                boost::algorithm::replace_all(copySubclassGetMappingFunction, SYSTEM_TEXT("$MappingType$"), mappingUpper);

                boost::algorithm::replace_all(copySubclassGetMappingFunction, SYSTEM_TEXT("$SmallElementName$"), variableName);

                subclassGetFunctionDefineContent += copySubclassGetMappingFunction;
                subclassGetFunctionDefineContent += SYSTEM_TEXT("\n");
            }
        }
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassGetFunctionDefine$"), subclassGetFunctionDefineContent);

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
