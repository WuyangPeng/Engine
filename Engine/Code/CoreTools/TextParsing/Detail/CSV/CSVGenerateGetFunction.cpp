///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:17)

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
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

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
