///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 17:31)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateDefaultFunction.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/DefaultFunctionParsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::CSVGenerateDefaultFunction::CSVGenerateDefaultFunction(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateDefaultFunction)

System::String CoreTools::CSVGenerateDefaultFunction::GenerateBaseDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    constexpr auto indentationCount = 1;
    const DefaultFunctionParsing defaultFunctionParsing{ indentationCount, className };

    auto content = defaultFunctionParsing.GeneratePublic();

    content += defaultFunctionParsing.GenerateDefaultConstructor();
    content += defaultFunctionParsing.GenerateKeyConstructor();

    content += TextParsing::gNewlineCharacter;

    content += defaultFunctionParsing.GenerateDestructor();
    content += defaultFunctionParsing.GenerateCopyConstructor();
    content += defaultFunctionParsing.GenerateCopyAssignment();
    content += defaultFunctionParsing.GenerateMoveConstructor();
    content += defaultFunctionParsing.GenerateMoveAssignment();

    content += TextParsing::gNewlineCharacter;

    content += defaultFunctionParsing.GenerateClassInvariantVirtualDeclare();

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunction::GenerateChildDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    constexpr auto indentationCount = 1;
    const DefaultFunctionParsing defaultFunctionParsing{ indentationCount, className };

    auto content = defaultFunctionParsing.GeneratePublic();

    content += defaultFunctionParsing.GenerateCSVRowConstructor();
    content += TextParsing::gNewlineCharacter;

    content += defaultFunctionParsing.GenerateClassInvariantFinalDeclare();

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunction::GenerateDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    constexpr auto indentationCount = 1;
    const DefaultFunctionParsing defaultFunctionParsing{ indentationCount, className };

    auto content = defaultFunctionParsing.GeneratePublic();

    content += defaultFunctionParsing.GenerateCSVRowConstructor();
    content += TextParsing::gNewlineCharacter;

    content += defaultFunctionParsing.GenerateClassInvariantDeclare();

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunction::GenerateContainerDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    constexpr auto indentationCount = 1;
    const DefaultFunctionParsing defaultFunctionParsing{ indentationCount, className };

    auto content = defaultFunctionParsing.GeneratePublic();

    content += defaultFunctionParsing.GenerateCSVContentConstructor();
    content += TextParsing::gNewlineCharacter;

    content += defaultFunctionParsing.GenerateClassInvariantDeclare();

    return content;
}

