/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 13:41)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateDataHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateDataHeadFile::CSVGenerateDataHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvHead, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/EntityH.txt") },
      container{ { SYSTEM_TEXT("DataInclude"), &ClassType::GetDataIncludeContent },
                 { SYSTEM_TEXT("StdInclude"), &ClassType::GetStdIncludeContent },
                 { SYSTEM_TEXT("BaseClassUsing"), &ClassType::GetBaseClassUsingContent },
                 { SYSTEM_TEXT("DataGetFunction"), &ClassType::GetDataGetFunctionContent },
                 { SYSTEM_TEXT("DataCheckingFunction"), &ClassType::GetDataCheckingFunctionContent },
                 { SYSTEM_TEXT("DataMember"), &ClassType::GetDataMemberContent } },
      stdIncludeContainer{ GetStdIncludeContainer(csvHead) },
      baseClassUsingContainer{ GetBaseClassUsingContainer(csvHead) },

      dataGetFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetFunction")) },
      dataGetCountArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetCountArrayFunction")) },
      dataGetValueArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetValueArrayFunction")) },
      dataGetBeginIterArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetBeginIterArrayFunction")) },
      dataGetEndIterArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetEndIterArrayFunction")) },
      dataGetMappingFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetMappingFunction")) },
      dataGetMappingArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("DataGetMappingArrayFunction")) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CSVGenerateDataHeadFile::StdIncludeContainer CoreTools::CSVGenerateDataHeadFile::GetStdIncludeContainer(const CSVHead& csvHead)
{
    StdIncludeContainer result{};

    if (csvHead.HasDataType(CSVDataType::BoolArray))
    {
        result.emplace_back(TextParsing::gDeque);
    }

    if (csvHead.HasMapping())
    {
        result.emplace_back(TextParsing::gMemory);
    }

    if (csvHead.HasVectorArrayDataType())
    {
        result.emplace_back(TextParsing::gVector);
    }

    return result;
}

CoreTools::CSVGenerateDataHeadFile::BaseClassUsingContainer CoreTools::CSVGenerateDataHeadFile::GetBaseClassUsingContainer(const CSVHead& csvHead)
{
    BaseClassUsingContainer result{};

    if (csvHead.HasDataType(CSVDataType::Char))
    {
        result.emplace_back(SYSTEM_TEXT("BaseClassCharUsing"), ReplaceType{});
    }

    if (csvHead.HasDataType(CSVDataType::String))
    {
        result.emplace_back(SYSTEM_TEXT("BaseClassStringUsing"), ReplaceType{});
    }

    if (csvHead.HasDataType(CSVDataType::StringArray))
    {
        result.emplace_back(SYSTEM_TEXT("BaseClassContainerUsing"),
                            ReplaceType{ { TextParsing::gElementType, SYSTEM_TEXT("String") },
                                         { TextParsing::gSmallElementType, SYSTEM_TEXT("String") },
                                         { TextParsing::gStdType, TextParsing::gVector } });
    }

    if (csvHead.HasDataType(CSVDataType::IntArray))
    {
        result.emplace_back(SYSTEM_TEXT("BaseClassContainerUsing"),
                            ReplaceType{ { TextParsing::gElementType, SYSTEM_TEXT("Int") },
                                         { TextParsing::gSmallElementType, SYSTEM_TEXT("int") },
                                         { TextParsing::gStdType, TextParsing::gVector } });
    }

    if (csvHead.HasDataType(CSVDataType::Int64Array))
    {
        result.emplace_back(SYSTEM_TEXT("BaseClassContainerUsing"),
                            ReplaceType{ { TextParsing::gElementType, SYSTEM_TEXT("Int64") },
                                         { TextParsing::gSmallElementType, SYSTEM_TEXT("int64_t") },
                                         { TextParsing::gStdType, TextParsing::gVector } });
    }

    if (csvHead.HasDataType(CSVDataType::BoolArray))
    {
        result.emplace_back(SYSTEM_TEXT("BaseClassContainerUsing"),
                            ReplaceType{ { TextParsing::gElementType, SYSTEM_TEXT("Bool") },
                                         { TextParsing::gSmallElementType, SYSTEM_TEXT("bool") },
                                         { TextParsing::gStdType, TextParsing::gDeque } });
    }

    if (csvHead.HasDataType(CSVDataType::CharArray))
    {
        if (!csvHead.HasDataType(CSVDataType::Char))
        {
            result.emplace_back(SYSTEM_TEXT("BaseClassCharUsing"), ReplaceType{});
        }

        result.emplace_back(SYSTEM_TEXT("BaseClassContainerUsing"),
                            ReplaceType{ { TextParsing::gElementType, SYSTEM_TEXT("Char") },
                                         { TextParsing::gSmallElementType, SYSTEM_TEXT("Char") },
                                         { TextParsing::gStdType, TextParsing::gVector } });
    }

    return result;
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
    return GetSuffix() + TextParsing::gHeadFileExtensionName.data();
}

System::String CoreTools::CSVGenerateDataHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    for (const auto& [codeKey, function] : container)
    {
        const auto functionContent = (this->*function)(codeKey);
        boost::algorithm::replace_all(content, GetCodeKey(codeKey), functionContent);
    }

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateDataHeadFile::GetStdIncludeContent(const String& codeKey) const
{
    String content{};

    const auto stdInclude = GetCodeMappingElement(codeKey);

    for (const auto& element : stdIncludeContainer)
    {
        content += GetReplaceContent(stdInclude, TextParsing::gStdName, element);
    }

    if (!stdIncludeContainer.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateDataHeadFile::GetBaseClassUsingContent(const String& codeKey) const
{
    System::UnusedFunction(codeKey);

    String content{};

    for (const auto& [key, replace] : baseClassUsingContainer)
    {
        content += GetReplaceContent(GetCodeMappingElement(key), replace);
    }

    if (HasMapping())
    {
        content += GetBaseClassUsingHasMappingContent();
    }

    if (HasDataType(CSVDataType::String) ||
        HasDataType(CSVDataType::StringArray) ||
        HasDataType(CSVDataType::IntArray) ||
        HasDataType(CSVDataType::Int64Array) ||
        HasDataType(CSVDataType::BoolArray) ||
        HasDataType(CSVDataType::CharArray))
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateDataHeadFile::GetDataGetFunctionContent(const String& codeKey) const
{
    System::UnusedFunction(codeKey);

    const auto head = GetCSVHead();

    String content{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        content += GetDataGetFunctionContent(head, index);
    }

    return content;
}

System::String CoreTools::CSVGenerateDataHeadFile::GetDataGetFunctionContent(const CSVHead& head, int index) const
{
    const auto actualType = head.GetActualType(index);
    const auto functionVariableName = head.GetFunctionVariableName(index);
    const auto dataType = head.GetDataType(index);
    const auto valueType = head.GetValueType(index);
    const auto abbreviation = head.GetAbbreviation(index);
    const auto upperVariableName = head.GetUpperVariableName(index);

    auto content = GetReplaceContent(dataGetFunction,
                                     { { TextParsing::gElementType, abbreviation },
                                       { TextParsing::gElementName, functionVariableName },
                                       { TextParsing::gElementIsNoexcept, GetElementIsNoexceptReplace(dataType) } });

    if (CSVDataType::BoolArray <= dataType)
    {
        content += GetDataGetArrayFunctionContent(valueType, abbreviation, upperVariableName);
    }

    if (const auto mapping = head.GetMapping(index);
        !mapping.empty())
    {
        content += GetDataGetFunctionHasMappingContent(dataType, upperVariableName, mapping);
    }

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDataHeadFile::GetDataGetArrayFunctionContent(const String& valueType,
                                                                                  const String& abbreviation,
                                                                                  const String& upperVariableName) const
{
    auto content = GetReplaceContent(dataGetCountArrayFunction,
                                     { { TextParsing::gElementName, upperVariableName },
                                       { TextParsing::gElementType, abbreviation } });

    content += GetReplaceContent(dataGetValueArrayFunction,
                                 { { TextParsing::gElementName, upperVariableName },
                                   { TextParsing::gElementType, abbreviation },
                                   { TextParsing::gSmallElementType, GetSmallElementTypeReplace(valueType) } });

    content += GetReplaceContent(dataGetBeginIterArrayFunction,
                                 { { TextParsing::gElementName, upperVariableName },
                                   { TextParsing::gElementType, abbreviation } });

    content += GetReplaceContent(dataGetEndIterArrayFunction,
                                 { { TextParsing::gElementName, upperVariableName },
                                   { TextParsing::gElementType, abbreviation } });

    return content;
}

System::String CoreTools::CSVGenerateDataHeadFile::GetDataGetFunctionHasMappingContent(CSVDataType dataType,
                                                                                       const String& upperVariableName,
                                                                                       const String& mapping) const
{
    const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

    return GetReplaceContent(CSVDataType::BoolArray <= dataType ? dataGetMappingArrayFunction : dataGetMappingFunction,
                             { { TextParsing::gElementName, upperVariableName },
                               { TextParsing::gMappingType, mappingUpper } });
}

System::String CoreTools::CSVGenerateDataHeadFile::GetDataCheckingFunctionContent(const String& codeKey) const
{
    if (HasScope())
    {
        const auto codeMapping = GetCodeMappingAnalysis();

        return codeMapping.GetElement(codeKey);
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateDataHeadFile::GetDataMemberContent(const String& codeKey) const
{
    const auto codeMapping = GetCodeMappingAnalysis();
    const auto dataMember = codeMapping.GetElement(codeKey);
    const auto head = GetCSVHead();

    String content{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        content += GetDataMemberContent(head, dataMember, index);
    }

    return content;
}

System::String CoreTools::CSVGenerateDataHeadFile::GetDataMemberContent(const CSVHead& head,
                                                                        const String& dataMember,
                                                                        int index)
{
    const auto abbreviation = head.GetAbbreviation(index);
    const auto variableName = head.GetVariableName(index);
    const auto annotation = StringConversion::Utf8ConversionStandard(head.GetAnnotation(index));

    return GetReplaceContent(dataMember,
                             { { SYSTEM_TEXT("MemberType"), abbreviation },
                               { SYSTEM_TEXT("MemberName"), variableName },
                               { SYSTEM_TEXT("MemberNote"), annotation } });
}