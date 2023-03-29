///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 10:09)

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