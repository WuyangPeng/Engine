///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 17:38)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateGetFunctionDefinition.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Detail/BaseGetFunctionDefinitionParsing.h"
#include "CoreTools/TextParsing/Detail/ChildGetFunctionDefinitionParsing.h"
#include "CoreTools/TextParsing/Detail/ContainerGetFunctionDefinitionParsing.h"
#include "CoreTools/TextParsing/Detail/ContainerGetFunctionDetailDefinitionParsing.h"
#include "CoreTools/TextParsing/Detail/StringCastEnumDefinitionParsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

CoreTools::CSVGenerateGetFunctionDefinition::CSVGenerateGetFunctionDefinition(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateGetFunctionDefinition)

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateBaseGetFunctionDefinition(const String& keyTypeDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    const BaseGetFunctionDefinitionParsing baseGetFunctionDefinitionParsing{ csvHead, className, keyTypeDescribe };

    return baseGetFunctionDefinitionParsing.GenerateGetFunctionDefinition();
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateGetFunctionDefinition(const String& keyTypeDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    const ChildGetFunctionDefinitionParsing childGetFunctionDefinitionParsing{ csvHead, className, keyTypeDescribe };

    return childGetFunctionDefinitionParsing.GenerateGetFunctionDefinition();
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateContainerFunctionDefinition(const String& keyTypeDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    const auto containerGetFunctionDefinitionParsing = ContainerGetFunctionDefinitionParsing::Create(csvHead, className, keyTypeDescribe);

    return containerGetFunctionDefinitionParsing->GenerateGetFunctionDefinition();
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateContainerDetailDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    const auto containerGetFunctionDetailDefinitionParsing = ContainerGetFunctionDetailDefinitionParsing::Create(csvHead, className);

    return containerGetFunctionDetailDefinitionParsing->GenerateGetFunctionDefinition();
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateStringCastEnumDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    const StringCastEnumDefinitionParsing stringCastEnumDefinitionParsing{ csvHead, className };

    return stringCastEnumDefinitionParsing.GenerateStringCastEnumDefinition();
}
