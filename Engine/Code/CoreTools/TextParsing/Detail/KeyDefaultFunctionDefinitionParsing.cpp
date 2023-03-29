///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 10:09)

#include "CoreTools/CoreToolsExport.h"

#include "KeyDefaultFunctionDefinitionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::KeyDefaultFunctionDefinitionParsing::KeyDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ csvHead, className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, KeyDefaultFunctionDefinitionParsing)

System::String CoreTools::KeyDefaultFunctionDefinitionParsing::GenerateKeyConstructorDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateConstructor(TextParsing::gKey);

    content += GenerateKeyMember();
    content += GenerateFunctionBeginBrackets();
    content += GenerateUserSelfClassIsValid9(1);
    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::KeyDefaultFunctionDefinitionParsing::GenerateKeyMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gKeyMember;

    return content;
}