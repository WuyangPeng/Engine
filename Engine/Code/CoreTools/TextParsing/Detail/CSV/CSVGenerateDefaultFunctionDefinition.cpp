///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:16)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateDefaultFunctionDefinition.h"
#include "CSVGenerateHelper.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Detail/CSVRowDefaultFunctionDefinitionParsing.h"
#include "CoreTools/TextParsing/Detail/CheckingFunctionDefinitionParsing.h"
#include "CoreTools/TextParsing/Detail/ContainerDefaultFunctionDefinitionParsing.h"
#include "CoreTools/TextParsing/Detail/KeyDefaultFunctionDefinitionParsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateDefaultFunctionDefinition::CSVGenerateDefaultFunctionDefinition(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateDefaultFunctionDefinition)

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateBaseDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    KeyDefaultFunctionDefinitionParsing defaultFunctionDefinitionParsing{ csvHead, className };

    auto content = defaultFunctionDefinitionParsing.GenerateKeyConstructorDefinition();

    content += defaultFunctionDefinitionParsing.GenerateClassInvariantStubDefine();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateChildDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    CSVRowDefaultFunctionDefinitionParsing defaultFunctionDefinitionParsing{ csvHead, className };

    auto content = defaultFunctionDefinitionParsing.GenerateCSVRowChildConstructorDefinition();

    if (csvHead.HasScope())
    {
        CheckingFunctionDefinitionParsing checkingFunctionDefinitionParsing{ csvHead, className };

        content += checkingFunctionDefinitionParsing.GenerateCheckingFunctionDefinition();
        content += checkingFunctionDefinitionParsing.GenerateIsValidFunctionDefinition();
    }
    else
    {
        content += defaultFunctionDefinitionParsing.GenerateClassInvariantStubDefine();
    }

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    CSVRowDefaultFunctionDefinitionParsing defaultFunctionDefinitionParsing{ csvHead, className };

    auto content = defaultFunctionDefinitionParsing.GenerateCSVRowConstructorDefinition();

    if (csvHead.HasScope())
    {
        CheckingFunctionDefinitionParsing checkingFunctionDefinitionParsing{ csvHead, className };

        content += checkingFunctionDefinitionParsing.GenerateCheckingFunctionDefinition();
        content += checkingFunctionDefinitionParsing.GenerateIsValidFunctionDefinition();
    }
    else
    {
        content += defaultFunctionDefinitionParsing.GenerateClassInvariantStubDefine();
    }

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateContainerDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;
    const auto containerDefaultFunctionDefinitionParsing = ContainerDefaultFunctionDefinitionParsing::Create(csvHead, className);

    auto content = containerDefaultFunctionDefinitionParsing->GenerateContainerDefaultFunctionDefinition();

    content += containerDefaultFunctionDefinitionParsing->GenerateContainerParsingFunctionDefinition();
    content += containerDefaultFunctionDefinitionParsing->GenerateClassInvariantStubDefine();
    content += TextParsing::g_NewlineCharacter;

    return content;
}
