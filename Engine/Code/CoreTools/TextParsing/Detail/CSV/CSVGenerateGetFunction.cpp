///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 17:38)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateGetFunction.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Detail/BaseGetFunctionParsing.h"
#include "CoreTools/TextParsing/Detail/ChildGetFunctionParsing.h"
#include "CoreTools/TextParsing/Detail/ContainerFunctionParsing.h"
#include "CoreTools/TextParsing/Detail/FinalGetFunctionParsing.h"
#include "CoreTools/TextParsing/Detail/StringCastEnumDefinitionParsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

CoreTools::CSVGenerateGetFunction::CSVGenerateGetFunction(const CSVHead& csvHead, const String& keyTypeDescribe)
    : csvHead{ csvHead }, keyTypeDescribe{ keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateGetFunction)

System::String CoreTools::CSVGenerateGetFunction::GenerateBaseGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const BaseGetFunctionParsing baseGetFunctionParsing{ csvHead, keyTypeDescribe };

    return baseGetFunctionParsing.GenerateGetFunction();
}

System::String CoreTools::CSVGenerateGetFunction::GenerateChildGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const ChildGetFunctionParsing childGetFunctionParsing{ csvHead, keyTypeDescribe };

    return childGetFunctionParsing.GenerateGetFunction();
}

System::String CoreTools::CSVGenerateGetFunction::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const FinalGetFunctionParsing finalGetFunctionParsing{ csvHead, keyTypeDescribe };

    return finalGetFunctionParsing.GenerateGetFunction();
}

System::String CoreTools::CSVGenerateGetFunction::GenerateContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto containerFunctionParsing = ContainerFunctionParsing::Create(csvHead, keyTypeDescribe);

    auto content = containerFunctionParsing->GenerateGetFunction();

    content += containerFunctionParsing->GenerateParsing();

    return content;
}

CoreTools::CSVGenerateGetFunction::String CoreTools::CSVGenerateGetFunction::GenerateStringCastEnumFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + keyTypeDescribe;

    const StringCastEnumDefinitionParsing stringCastEnumDefinitionParsing{ csvHead, className };

    return stringCastEnumDefinitionParsing.GenerateStringCastEnumFunction();
}
