///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/03 13:59)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateMember.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateMember::CSVGenerateMember(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateMember)

System::String CoreTools::CSVGenerateMember::GenerateBaseMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ g_Indentation };

    content += g_Private;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("int key{};\n");

    content += g_ClassEndBrackets;
    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateMember::GenerateChildMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ g_Indentation };
    content += g_Private;

    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        const auto dataType = csvHead.GetDataType(index);
        const auto variableName = csvHead.GetVariableName(index);
        const auto annotation = StringConversion::UTF8ConversionStandard(csvHead.GetAnnotation(index));

        content += g_Indentation;
        content += g_Indentation;
        content += csvHead.GetActualType(index);

        content += g_Space;
        content += variableName;
        content += SYSTEM_TEXT(";  // "s);
        content += annotation;
        content += g_NewlineCharacter;
    }

    content += g_ClassEndBrackets;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateMember::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (csvHead.GetCSVFormatType() == CSVFormatType::Unique)
    {
        return GenerateUniqueContainerMember();
    }

    String content{ g_Indentation };
    content += g_Private;

    content += g_Indentation;
    content += g_Indentation;
    if (csvHead.GetCSVFormatType() == CSVFormatType::TreeMap || csvHead.GetCSVFormatType() == CSVFormatType::HashMap)
    {
        content += SYSTEM_TEXT("MappingContainer ");
    }
    else
    {
        content += SYSTEM_TEXT("Container ");
    }

    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName()) + SYSTEM_TEXT(";\n"s);
    content += g_ClassEndBrackets;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateMember::GenerateUniqueContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ g_Indentation };
    content += g_Private;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("SharedPtr "s);
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += g_SemicolonNewline;

    content += g_ClassEndBrackets;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}