/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 09:46)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateChildHeadFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateChildHeadFile::CSVGenerateChildHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvHead, codeMappingAnalysis },
      container{ { SYSTEM_TEXT("SubclassGetFunction"), &ClassType::GetSubclassGetFunctionContent },
                 { SYSTEM_TEXT("GenerateKeyFunction"), &ClassType::GetGenerateKeyFunctionContent },
                 { SYSTEM_TEXT("SubclassCheckingFunction"), &ClassType::GetSubclassCheckingFunctionContent },
                 { SYSTEM_TEXT("SubclassMember"), &ClassType::GetSubclassMemberContent } },
      templateName{ SYSTEM_TEXT("/EntitySubclassH.txt") },

      subclassGetCountArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetCountArrayFunction")) },
      subclassGetValueArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetValueArrayFunction")) },
      subclassGetBeginIterArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetBeginIterArrayFunction")) },
      subclassGetEndIterArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetEndIterArrayFunction")) },
      subclassGetMappingFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetMappingFunction")) },
      subclassGetMappingArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SubclassGetMappingArrayFunction")) }
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
    return GetSuffix() + TextParsing::gHeadFileExtensionName.data();
}

System::String CoreTools::CSVGenerateChildHeadFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    for (const auto& [codeKey, function] : container)
    {
        const auto functionContent = (this->*function)(codeKey);
        boost::algorithm::replace_all(content, GetCodeKey(codeKey), functionContent);
    }

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateChildHeadFile::GenerateKeyParameter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto head = GetCSVHead();
    const auto keyName = head.GetKeyName();

    String content{};

    auto index = 0u;
    for (const auto& element : keyName)
    {
        content += GetKeyParameter(head, element, index == keyName.size() - 1);
        ++index;
    }

    return content;
}

System::String CoreTools::CSVGenerateChildHeadFile::GetKeyParameter(const CSVHead& head, const String& element, bool isEnd)
{
    auto content = CSVTypeConversion::GetActualType(head.GetDataType(element));
    content += TextParsing::gSpace;
    content += element;

    if (!isEnd)
    {
        content += TextParsing::gComma;
        content += TextParsing::gSpace;
    }

    return content;
}

System::String CoreTools::CSVGenerateChildHeadFile::GetSubclassGetFunctionContent(const String& codeKey) const
{
    const auto head = GetCSVHead();

    const auto subclassGetFunction = GetCodeMappingElement(codeKey);

    String content{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto actualType = head.GetActualType(index);
        const auto functionVariableName = head.GetFunctionVariableName(index);
        const auto dataType = head.GetDataType(index);
        const auto valueType = head.GetValueType(index);
        const auto abbreviation = head.GetAbbreviation(index);
        const auto upperVariableName = head.GetUpperVariableName(index);

        content += GetSubclassGetFunctionContent(subclassGetFunction, head, index, functionVariableName, dataType, valueType, abbreviation, upperVariableName);
    }

    return content;
}

System::String CoreTools::CSVGenerateChildHeadFile::GetSubclassGetFunctionContent(const String& subclassGetFunction,
                                                                                  const CSVHead& head,
                                                                                  int index,
                                                                                  const String& functionVariableName,
                                                                                  CSVDataType dataType,
                                                                                  const String& valueType,
                                                                                  const String& abbreviation,
                                                                                  const String& upperVariableName) const
{
    auto content = GetReplaceContent(subclassGetFunction,
                                     { { TextParsing::gElementType, abbreviation },
                                       { TextParsing::gElementName, functionVariableName },
                                       { TextParsing::gElementIsNoexcept, GetElementIsNoexceptReplace(dataType) } });

    content += GetSubclassGetArrayFunctionContent(dataType, valueType, abbreviation, upperVariableName);

    content += GetSubclassGetMappingFunctionContent(head, index, dataType, upperVariableName);

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateChildHeadFile::GetSubclassGetArrayFunctionContent(CSVDataType dataType,
                                                                                       const String& valueType,
                                                                                       const String& abbreviation,
                                                                                       const String& upperVariableName) const
{
    String content{};

    if (CSVDataType::BoolArray <= dataType)
    {
        content += GetReplaceContent(subclassGetCountArrayFunction,
                                     { { TextParsing::gElementType, abbreviation },
                                       { TextParsing::gElementName, upperVariableName } });

        content += GetReplaceContent(subclassGetValueArrayFunction,
                                     { { TextParsing::gElementType, abbreviation },
                                       { TextParsing::gElementName, upperVariableName },
                                       { TextParsing::gSmallElementType, GetSmallElementTypeReplace(valueType) } });

        content += GetReplaceContent(subclassGetBeginIterArrayFunction,
                                     { { TextParsing::gElementType, abbreviation },
                                       { TextParsing::gElementName, upperVariableName } });

        content += GetReplaceContent(subclassGetEndIterArrayFunction,
                                     { { TextParsing::gElementType, abbreviation },
                                       { TextParsing::gElementName, upperVariableName } });
    }

    return content;
}

System::String CoreTools::CSVGenerateChildHeadFile::GetSubclassGetMappingFunctionContent(const CSVHead& head, int index, CSVDataType dataType, const String& upperVariableName) const
{
    String content{};

    if (const auto mapping = head.GetMapping(index);
        !mapping.empty())
    {
        const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

        content += GetReplaceContent(CSVDataType::BoolArray <= dataType ? subclassGetMappingArrayFunction : subclassGetMappingFunction,
                                     { { TextParsing::gMappingType, mappingUpper },
                                       { TextParsing::gElementName, upperVariableName } });
    }

    return content;
}

System::String CoreTools::CSVGenerateChildHeadFile::GetGenerateKeyFunctionContent(const String& codeKey) const
{
    if (GetCSVFormatType() == CSVFormatType::Key)
    {
        auto generateKeyFunction = GetCodeMappingElement(codeKey);

        boost::algorithm::replace_all(generateKeyFunction, SYSTEM_TEXT("$KeyType$"), GetKeyTypeDescribe());
        boost::algorithm::replace_all(generateKeyFunction, SYSTEM_TEXT("$KeyParameter$"), GenerateKeyParameter());
        boost::algorithm::replace_all(generateKeyFunction, SYSTEM_TEXT("$KeyReturn$"), GetKey());

        return generateKeyFunction;
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateChildHeadFile::GetSubclassCheckingFunctionContent(const String& codeKey) const
{
    if (HasScope())
    {
        return GetCodeMappingElement(codeKey);
    }
    else
    {
        return SYSTEM_TEXT("");
    }
}

System::String CoreTools::CSVGenerateChildHeadFile::GetSubclassMemberContent(const String& codeKey) const
{
    const auto head = GetCSVHead();
    const auto subclassMember = GetCodeMappingElement(codeKey);

    String content{};
    for (auto index = 0; index < head.GetCount(); ++index)
    {
        const auto abbreviation = head.GetAbbreviation(index);
        const auto variableName = head.GetVariableName(index);
        const auto annotation = StringConversion::Utf8ConversionStandard(head.GetAnnotation(index));

        content += GetReplaceContent(subclassMember,
                                     { { SYSTEM_TEXT("MemberType"), abbreviation },
                                       { SYSTEM_TEXT("MemberName"), variableName },
                                       { SYSTEM_TEXT("MemberNote"), annotation } });
    }

    return content;
}
