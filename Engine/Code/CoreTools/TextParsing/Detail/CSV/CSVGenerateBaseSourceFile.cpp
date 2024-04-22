/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 09:46)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateBaseSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateBaseSourceFile::CSVGenerateBaseSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvHead, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/EntityBaseCpp.txt") },

      baseGetFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseGetFunctionDefine")) },
      baseStringGetFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseStringGetFunctionDefine")) },
      baseArrayGetFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseArrayGetFunctionDefine")) },
      baseEnumGetFunctionDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseEnumGetFunctionDefine")) },
      baseGetCountArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseGetCountArrayFunctionDefine")) },
      baseGetValueArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseGetValueArrayFunctionDefine")) },
      baseGetBeginIterArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseGetBeginIterArrayFunctionDefine")) },
      baseGetEndIterArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseGetEndIterArrayFunctionDefine")) },
      baseGetMappingFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseGetMappingFunctionDefine")) },
      baseGetMappingArrayFunction{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BaseGetMappingArrayFunctionDefine")) }
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
    return GetSuffix() + TextParsing::gSourceFileExtensionName.data();
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + templateName);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$BaseGetFunctionDefine$"), GetBaseGetFunctionDefineContent());

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetBaseGetFunctionDefineContent() const
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

        content += GetBaseGetFunctionDefineContent(head,
                                                   index,
                                                   functionVariableName,
                                                   dataType,
                                                   actualType,
                                                   valueType,
                                                   abbreviation,
                                                   upperVariableName);
    }

    return content;
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetBaseGetFunctionDefineContent(const CSVHead& head,
                                                                                     int index,
                                                                                     const String& functionVariableName,
                                                                                     CSVDataType dataType,
                                                                                     const String& actualType,
                                                                                     const String& valueType,
                                                                                     const String& abbreviation,
                                                                                     const String& upperVariableName) const
{
    auto content = GetCopyBaseGetFunctionDefine(functionVariableName, dataType, actualType, abbreviation);

    content += GetBaseGetArrayFunctionDefineContent(dataType, valueType, abbreviation, upperVariableName);

    content += GetBaseGetMappingFunctionDefineContent(head, index, dataType, upperVariableName);

    return content;
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetCopyBaseGetFunctionDefine(const String& functionVariableName,
                                                                                  CSVDataType dataType,
                                                                                  const String& actualType,
                                                                                  const String& abbreviation) const
{
    return GetReplaceContent(GetBaseGetFunctionDefine(dataType),
                             { { TextParsing::gElementType, CSVDataType::BoolArray <= dataType ? SYSTEM_TEXT("$Namespace$::$ClassName$Base::") + abbreviation : actualType },
                               { TextParsing::gElementName, functionVariableName },
                               { TextParsing::gElementIsNoexcept, GetElementIsNoexceptReplace(dataType) } });
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetBaseGetFunctionDefine(CSVDataType dataType) const
{
    String content{};

    if (dataType == CSVDataType::String)
    {
        content = baseStringGetFunctionDefine;
    }
    else if (dataType == CSVDataType::Enum)
    {
        content = baseEnumGetFunctionDefine;
    }
    else if (CSVDataType::BoolArray <= dataType)
    {
        content = baseArrayGetFunctionDefine;
    }
    else
    {
        content = baseGetFunctionDefine;

        const auto defaultValue = CSVTypeConversion::GetBaseReturnDescribe(dataType);

        boost::algorithm::replace_all(content, GetCodeKey(TextParsing::gElementDefaultValue.data()), defaultValue);
    }

    return content;
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetBaseGetArrayFunctionDefineContent(CSVDataType dataType,
                                                                                          const String& valueType,
                                                                                          const String& abbreviation,
                                                                                          const String& upperVariableName) const
{
    String content{};

    if (CSVDataType::BoolArray <= dataType)
    {
        content += GetReplaceContent(baseGetCountArrayFunction,
                                     { { TextParsing::gElementName, upperVariableName },
                                       { TextParsing::gElementType, abbreviation } });

        content += GetReplaceContent(baseGetValueArrayFunction,
                                     { { TextParsing::gElementName, upperVariableName },
                                       { TextParsing::gElementType, abbreviation },
                                       { TextParsing::gSmallElementType, valueType } });

        content += GetReplaceContent(baseGetBeginIterArrayFunction,
                                     { { TextParsing::gElementName, upperVariableName },
                                       { TextParsing::gElementType, abbreviation } });

        content += GetReplaceContent(baseGetEndIterArrayFunction,
                                     { { TextParsing::gElementName, upperVariableName },
                                       { TextParsing::gElementType, abbreviation } });
    }

    return content;
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetBaseGetMappingFunctionDefineContent(const CSVHead& head,
                                                                                            int index,
                                                                                            CSVDataType dataType,
                                                                                            const String& upperVariableName) const
{
    String content{};

    if (const auto mapping = head.GetMapping(index);
        !mapping.empty())
    {
        const auto mappingUpper = StringUtility::ToFirstLetterUpper(mapping);

        content += GetReplaceContent((CSVDataType::BoolArray <= dataType) ? baseGetMappingArrayFunction : baseGetMappingFunction,
                                     { { TextParsing::gElementName, upperVariableName },
                                       { TextParsing::gMappingType, mappingUpper } });
    }

    return content;
}
