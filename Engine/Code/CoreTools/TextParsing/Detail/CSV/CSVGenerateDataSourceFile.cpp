/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 14:50)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateDataSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <set>

CoreTools::CSVGenerateDataSourceFile::CSVGenerateDataSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvHead, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/EntityCpp.txt") },

      dataCheckingCall{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataCheckingCall")) },
      dataIsValidStubDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataIsValidStubDefine")) },
      includeUserClassInvariantMacro{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeUserClassInvariantMacro")) },
      exceptionMacroInclude{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ExceptionMacroInclude")) },
      numericCastInclude{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("NumericCastInclude")) },
      includeChildClass{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeChildClass")) },
      includeNamespaceContainer{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeNamespaceContainer")) },
      includeMappingContainer{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeMappingContainer")) },
      beginDataClassMember{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BeginDataClassMember")) },
      dataClassMember{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataClassMember")) },
      endDataClassMember{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("EndDataClassMember")) },
      dataCheckingDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataCheckingDefine")) },
      dataCheckingCondition{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataCheckingCondition")) },
      dataIsValidDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataIsValidDefine")) },
      dataGetFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetFunctionDefine")) },
      dataGetCountArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetCountArrayFunctionDefine")) },
      dataGetValueArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetValueArrayFunctionDefine")) },
      dataGetBeginIterArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetBeginIterArrayFunctionDefine")) },
      dataGetEndIterArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetEndIterArrayFunctionDefine")) },
      dataGetMappingFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetMappingFunctionDefine")) },
      dataGetMappingArrayFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetMappingArrayFunctionDefine")) }
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
    return GetSuffix() + TextParsing::gSourceFileExtensionName.data();
}

System::String CoreTools::CSVGenerateDataSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    const auto codeMapping = GetCodeMappingAnalysis();
    const auto head = GetCSVHead();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataInclude$"), GetDataIncludeContent());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataClassMember$"), GetDataClassMemberContent());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataCheckingCall$"), HasScope() ? dataCheckingCall : SYSTEM_TEXT(""));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataCheckingDefine$"), HasScope() ? GetDataCheckingDefine() : SYSTEM_TEXT(""));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataIsValidDefine$"), HasScope() ? GetDataIsValidDefine() : dataIsValidStubDefine);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DataGetFunctionDefine$"), GetDataGetFunctionDefineContent());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyName$"), GetCSVFormatType() == CSVFormatType::Key ? head.GetKey() : head.GetVariableName(0));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassIsValidLevel$"), HasScope() ? SYSTEM_TEXT("1") : SYSTEM_TEXT("9"));

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataIncludeContent() const
{
    const auto dataIncludeContainer = GetDataIncludeContainer();

    String content{};
    for (const auto& element : dataIncludeContainer)
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

CoreTools::CSVGenerateDataSourceFile::SubclassIncludeContainer CoreTools::CSVGenerateDataSourceFile::GetDataIncludeContainer() const
{
    SubclassIncludeContainer container{ includeChildClass };

    if (HasMapping())
    {
        container.emplace(includeNamespaceContainer);

        const auto result = GetDataIncludeMappingContainer();

        container.insert(result.begin(), result.end());
    }

    return container;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataIncludeMappingContainer(const CSVHead& head, int index) const
{
    if (const auto mapping = head.GetMapping(index);
        !mapping.empty())
    {
        const auto element = StringUtility::ToFirstLetterUpper(mapping);

        auto result = includeMappingContainer;
        boost::algorithm::replace_all(result, GetCodeKey(TextParsing::gMappingType.data()), element);

        return result;
    }

    return SYSTEM_TEXT("");
}

CoreTools::CSVGenerateDataSourceFile::SubclassIncludeContainer CoreTools::CSVGenerateDataSourceFile::GetDataIncludeMappingContainer() const
{
    const auto head = GetCSVHead();

    SubclassIncludeContainer container{};

    for (auto index = 0; index < head.GetCount(); ++index)
    {
        if (const auto result = GetDataIncludeMappingContainer(head, index);
            !result.empty())
        {
            container.emplace(result);
        }
    }

    return container;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataClassMemberContent() const
{
    const auto head = GetCSVHead();

    String content{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        content += GetDataClassMemberContent(head, index);
    }

    return content;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataClassMemberContent(const CSVHead& head, int index) const
{
    const auto functionName = head.GetFunctionName(index);
    const auto actualType = head.GetActualType(index);
    const auto valueType = head.GetValueType(index);
    const auto abbreviation = head.GetAbbreviation(index);
    const auto variableName = head.GetVariableName(index);

    return GetReplaceContent(index == 0 ? beginDataClassMember : ((index == head.GetCount() - 1) ? endDataClassMember : dataClassMember),
                             { { TextParsing::gElementType, functionName },
                               { TextParsing::gElementName, variableName } });
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataCheckingDefine() const
{
    auto result = dataCheckingDefine;

    boost::algorithm::replace_all(result, SYSTEM_TEXT("$DataCheckingCondition$"), GetDataCheckingCondition());

    return result;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataCheckingCondition() const
{
    String content{};

    auto isFirst = true;
    const auto head = GetCSVHead();
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        if (const auto result = GetDataCheckingCondition(head, isFirst, index);
            result.empty())
        {
            content += result;
            isFirst = false;
        }
    }

    return content;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataCheckingCondition(const CSVHead& head, bool isFirst, int index) const
{
    String content{};

    if (const auto scope = head.GetScope(index);
        !scope.empty())
    {
        if (!isFirst)
        {
            content += TextParsing::gNewlineCharacter;
        }

        auto copyCheckingCondition = dataCheckingCondition;

        boost::algorithm::replace_all(copyCheckingCondition, GetCodeKey(TextParsing::gCheckingTypeCondition.data()), head.GetScopeExpression(index));
        boost::algorithm::replace_all(copyCheckingCondition, GetCodeKey(TextParsing::gElementType.data()), head.GetVariableName(index));

        content += copyCheckingCondition;
    }

    return content;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataIsValidDefine() const
{
    auto content = dataIsValidDefine;

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$CheckingIsValidCondition$"), GetCheckingIsValidConditionContent());

    return content;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetCheckingIsValidConditionContent() const
{
    String content{};

    const auto head = GetCSVHead();
    auto isFirst = true;
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        if (const auto result = GetCheckingIsValidConditionContent(head, isFirst, index);
            !result.empty())
        {
            content += result;
            isFirst = false;
        }
    }

    return content;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetCheckingIsValidConditionContent(const CSVHead& head, bool isFirst, int index)
{
    String content{};

    if (const auto scope = head.GetScope(index);
        !scope.empty())
    {
        if (!isFirst)
        {
            content += TextParsing::gNewlineCharacter;
        }

        content += SYSTEM_TEXT("        (");
        content += head.GetScopeExpression(index);
        content += SYSTEM_TEXT(")");
    }

    return content;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataGetFunctionDefineContent() const
{
    String content{};

    const auto head = GetCSVHead();
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto functionVariableName = head.GetFunctionVariableName(index);
        const auto dataType = head.GetDataType(index);
        const auto actualType = head.GetActualType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto upperVariableName = head.GetUpperVariableName(index);
        const auto variableName = head.GetVariableName(index);

        content += GetDataGetFunctionDefineContent(head, index, functionVariableName, dataType, actualType, valueType, abbreviation, upperVariableName, variableName);
    }

    return content;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataGetFunctionDefineContent(const CSVHead& head,
                                                                                     int index,
                                                                                     const String& functionVariableName,
                                                                                     CSVDataType dataType,
                                                                                     const String& actualType,
                                                                                     const String& valueType,
                                                                                     const String& abbreviation,
                                                                                     const String& upperVariableName,
                                                                                     const String& variableName) const
{
    auto content = GetReplaceContent(dataGetFunctionDefine,
                                     { { TextParsing::gElementType, GetElementTypeReplace(dataType, abbreviation, actualType) },
                                       { TextParsing::gElementName, functionVariableName },
                                       { TextParsing::gElementIsNoexcept, GetElementIsNoexceptReplace(dataType) },
                                       { TextParsing::gSmallElementName, variableName } });

    if (CSVDataType::BoolArray <= dataType)
    {
        content += GetDataGetArrayFunctionDefineContent(valueType, abbreviation, upperVariableName, variableName);
    }

    if (const auto mapping = head.GetMapping(index);
        !mapping.empty())
    {
        content += GetDataGetMappingFunctionDefineContent(dataType, upperVariableName, variableName, mapping);
    }

    return content;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataGetArrayFunctionDefineContent(const String& valueType,
                                                                                          const String& abbreviation,
                                                                                          const String& upperVariableName,
                                                                                          const String& variableName) const
{
    auto content = GetReplaceContent(dataGetCountArrayFunctionDefine,
                                     { { TextParsing::gElementType, abbreviation },
                                       { TextParsing::gElementName, upperVariableName },
                                       { TextParsing::gSmallElementName, variableName } });

    content += GetReplaceContent(dataGetValueArrayFunctionDefine,
                                 { { TextParsing::gElementType, abbreviation },
                                   { TextParsing::gElementName, upperVariableName },
                                   { TextParsing::gSmallElementType, valueType },
                                   { TextParsing::gSmallElementName, variableName } });

    content += GetReplaceContent(dataGetBeginIterArrayFunctionDefine,
                                 { { TextParsing::gElementType, abbreviation },
                                   { TextParsing::gElementName, upperVariableName },
                                   { TextParsing::gSmallElementName, variableName } });

    content += GetReplaceContent(dataGetEndIterArrayFunctionDefine,
                                 { { TextParsing::gElementType, abbreviation },
                                   { TextParsing::gElementName, upperVariableName },
                                   { TextParsing::gSmallElementName, variableName } });

    return content;
}

System::String CoreTools::CSVGenerateDataSourceFile::GetDataGetMappingFunctionDefineContent(CSVDataType dataType,
                                                                                            const String& upperVariableName,
                                                                                            const String& variableName,
                                                                                            const String& mapping) const
{
    const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

    return GetReplaceContent(CSVDataType::BoolArray <= dataType ? dataGetMappingArrayFunctionDefine : dataGetMappingFunctionDefine,
                             { { TextParsing::gElementType, mappingUpper },
                               { TextParsing::gElementName, upperVariableName },
                               { TextParsing::gElementIsNoexcept, variableName } });
}