/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 09:37)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateChildSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateChildSourceFile::CSVGenerateChildSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvHead, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/EntitySubclassCpp.txt") },

      subclassCheckingCall{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassCheckingCall")) },
      subclassIsValidStubDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassIsValidStubDefine")) },
      includeUserClassInvariantMacro{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeUserClassInvariantMacro")) },
      exceptionMacroInclude{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ExceptionMacroInclude")) },
      numericCastInclude{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("NumericCastInclude")) },
      includeChildClass{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeChildClass")) },
      includeNamespaceContainer{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeNamespaceContainer")) },
      includeMappingContainer{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeMappingContainer")) },
      subclassClassMember{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassClassMember")) },
      endSubclassClassMember{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("EndSubclassClassMember")) },
      subclassGetFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetFunctionDefine")) },
      subclassGetCountArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetCountArrayFunctionDefine")) },
      subclassGetValueArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetValueArrayFunctionDefine")) },
      subclassGetBeginIterArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetBeginIterArrayFunctionDefine")) },
      subclassGetEndIterArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetEndIterArrayFunctionDefine")) },
      subclassGetMappingFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetMappingFunctionDefine")) },
      subclassGetMappingArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetMappingArrayFunctionDefine")) },
      subclassIsValidDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassIsValidDefine")) },
      subclassCheckingDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassCheckingDefine")) },
      checkingCondition{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("CheckingCondition")) }
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
    return GetSuffix() + TextParsing::gSourceFileExtensionName.data();
}

System::String CoreTools::CSVGenerateChildSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    const auto head = GetCSVHead();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassInclude$"), GetSubclassIncludeContent());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassClassMember$"), GetSubclassClassMemberContent());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassCheckingCall$"), HasScope() ? subclassCheckingCall : SYSTEM_TEXT(""));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassCheckingDefine$"), HasScope() ? GetSubclassCheckingDefine() : SYSTEM_TEXT(""));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassIsValidDefine$"), HasScope() ? GetSubclassIsValidDefine() : subclassIsValidStubDefine);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SubclassGetFunctionDefine$"), GetSubclassGetFunctionDefineContent());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyName$"), head.GetCSVFormatType() == CSVFormatType::Key ? head.GetKey() : head.GetVariableName(0));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassIsValidLevel$"), HasScope() ? SYSTEM_TEXT("1") : SYSTEM_TEXT("9"));

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateChildSourceFile::GetSubclassIncludeContent() const
{
    const auto subclassIncludeContainer = GetSubclassIncludeContainer();

    String content{};

    for (const auto& element : subclassIncludeContainer)
    {
        content += element;
    }

    if (HasArrayDataType())
    {
        content += numericCastInclude;
    }

    content += includeUserClassInvariantMacro;

    if (HasScope())
    {
        content += exceptionMacroInclude;
    }

    return content;
}

CoreTools::CSVGenerateChildSourceFile::SubclassIncludeContainer CoreTools::CSVGenerateChildSourceFile::GetSubclassIncludeMappingContainer() const
{
    SubclassIncludeContainer container{};

    const auto head = GetCSVHead();

    for (auto index = 0; index < head.GetCount(); ++index)
    {
        if (const auto result = GetSubclassIncludeContainer(head, index);
            !result.empty())
        {
            container.emplace(result);
        }
    }

    return container;
}

CoreTools::CSVGenerateChildSourceFile::SubclassIncludeContainer CoreTools::CSVGenerateChildSourceFile::GetSubclassIncludeContainer() const
{
    SubclassIncludeContainer container{ includeChildClass };

    if (HasMapping())
    {
        container.emplace(includeNamespaceContainer);

        const auto result = GetSubclassIncludeMappingContainer();

        container.insert(result.begin(), result.end());
    }

    return container;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetSubclassIncludeContainer(const CSVHead& head, int index) const
{
    if (const auto mapping = head.GetMapping(index);
        !mapping.empty())
    {
        const auto element = StringUtility::ToFirstLetterUpper(mapping);
        auto result = includeMappingContainer;
        boost::algorithm::replace_all(result, GetCodeKey(TextParsing::gMappingType.data()), element);

        return result;
    }
    else
    {
        return String{};
    }
}

System::String CoreTools::CSVGenerateChildSourceFile::GetSubclassClassMemberContent() const
{
    const auto head = GetCSVHead();

    String content{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto functionName = head.GetFunctionName(index);
        const auto variableName = head.GetVariableName(index);

        content += GetReplaceContent(index == head.GetCount() - 1 ? endSubclassClassMember : subclassClassMember,
                                     { { TextParsing::gElementType, functionName },
                                       { TextParsing::gElementName, variableName } });
    }

    return content;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetSubclassGetFunctionDefineContent() const
{
    const auto head = GetCSVHead();

    String content{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto functionVariableName = head.GetFunctionVariableName(index);
        const auto dataType = head.GetDataType(index);
        const auto actualType = head.GetActualType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto upperVariableName = head.GetUpperVariableName(index);
        const auto variableName = head.GetVariableName(index);

        content += GetSubclassGetFunctionDefineContent(head, index, functionVariableName, dataType, actualType, valueType, abbreviation, upperVariableName, variableName);
    }

    return content;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetSubclassGetFunctionDefineContent(const CSVHead& head,
                                                                                          int index,
                                                                                          const String& functionVariableName,
                                                                                          CSVDataType dataType,
                                                                                          const String& actualType,
                                                                                          const String& valueType,
                                                                                          const String& abbreviation,
                                                                                          const String& upperVariableName,
                                                                                          const String& variableName) const
{
    String content = GetReplaceContent(subclassGetFunctionDefine,
                                       { { TextParsing::gElementType, GetElementTypeReplace(dataType, abbreviation, actualType) },
                                         { TextParsing::gElementName, functionVariableName },
                                         { TextParsing::gElementIsNoexcept, GetElementIsNoexceptReplace(dataType) },
                                         { TextParsing::gSmallElementName, variableName } });

    if (CSVDataType::BoolArray <= dataType)
    {
        content += GetSubclassGetArrayFunctionDefineContent(valueType, abbreviation, upperVariableName, variableName);
    }

    if (const auto mapping = head.GetMapping(index);
        !mapping.empty())
    {
        content += GetSubclassGetMappingFunctionDefineContent(dataType, upperVariableName, variableName, mapping);
    }

    return content;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetSubclassGetArrayFunctionDefineContent(const String& valueType,
                                                                                               const String& abbreviation,
                                                                                               const String& upperVariableName,
                                                                                               const String& variableName) const
{
    auto content = GetReplaceContent(subclassGetCountArrayFunctionDefine,
                                     { { TextParsing::gElementType, abbreviation },
                                       { TextParsing::gElementName, upperVariableName },
                                       { TextParsing::gSmallElementName, variableName } });

    content += GetReplaceContent(subclassGetValueArrayFunctionDefine,
                                 { { TextParsing::gElementType, abbreviation },
                                   { TextParsing::gElementName, upperVariableName },
                                   { TextParsing::gSmallElementType, valueType },
                                   { TextParsing::gSmallElementName, variableName } });

    content += GetReplaceContent(subclassGetBeginIterArrayFunctionDefine,
                                 { { TextParsing::gElementType, abbreviation },
                                   { TextParsing::gElementName, upperVariableName },
                                   { TextParsing::gSmallElementName, variableName } });

    content += GetReplaceContent(subclassGetEndIterArrayFunctionDefine,
                                 { { TextParsing::gElementType, abbreviation },
                                   { TextParsing::gElementName, upperVariableName },
                                   { TextParsing::gSmallElementName, variableName } });

    return content;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetSubclassGetMappingFunctionDefineContent(CSVDataType dataType,
                                                                                                 const String& upperVariableName,
                                                                                                 const String& variableName,
                                                                                                 const String& mapping) const
{
    const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

    return GetReplaceContent(CSVDataType::BoolArray <= dataType ? subclassGetMappingArrayFunctionDefine : subclassGetMappingFunctionDefine,
                             { { TextParsing::gElementName, upperVariableName },
                               { TextParsing::gMappingType, mappingUpper },
                               { TextParsing::gSmallElementName, variableName } });
}

System::String CoreTools::CSVGenerateChildSourceFile::GetSubclassIsValidDefine() const
{
    auto content = subclassIsValidDefine;

    const auto checkingIsValidConditionContent = GetCheckingIsValidConditionContent();
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$CheckingIsValidCondition$"), checkingIsValidConditionContent);

    return content;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetCheckingIsValidConditionContent() const
{
    String content{};

    const auto head = GetCSVHead();
    bool isFirst = true;
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        if (const auto result = GetCheckingIsValidConditionContent(isFirst, head, index);
            !result.empty())
        {
            content += result;
            isFirst = false;
        }
    }

    return content;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetCheckingIsValidConditionContent(bool isFirst, const CSVHead& head, int index)
{
    String content{};

    if (const auto scope = head.GetScope(index);
        !scope.empty())
    {
        if (!isFirst)
        {
            content += TextParsing::gNewlineCharacter;
        }

        content += SYSTEM_TEXT("        ");
        content += TextParsing::gLeftBrackets;
        content += head.GetScopeExpression(index);
        content += TextParsing::gRightBrackets;
    }

    return content;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetSubclassCheckingDefine() const
{
    auto content = subclassCheckingDefine;

    const auto checkingConditionContent = GetCheckingConditionContent();
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$CheckingCondition$"), checkingConditionContent);

    return content;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetCheckingConditionContent(bool isFirst, const CSVHead& head, int index) const
{
    String content{};

    if (const auto scope = head.GetScope(index);
        !scope.empty())
    {
        if (!isFirst)
        {
            content += TextParsing::gNewlineCharacter;
        }

        auto copyCheckingCondition = checkingCondition;

        boost::algorithm::replace_all(copyCheckingCondition, GetCodeKey(TextParsing::gCheckingTypeCondition.data()), head.GetScopeExpression(index));
        boost::algorithm::replace_all(copyCheckingCondition, GetCodeKey(TextParsing::gElementType.data()), head.GetVariableName(index));

        content += copyCheckingCondition;
    }

    return content;
}

System::String CoreTools::CSVGenerateChildSourceFile::GetCheckingConditionContent() const
{
    String content{};

    auto isFirst = true;
    const auto head = GetCSVHead();
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        if (const auto result = GetCheckingConditionContent(isFirst, head, index);
            !result.empty())
        {
            content += result;
            isFirst = false;
        }
    }

    return content;
}
