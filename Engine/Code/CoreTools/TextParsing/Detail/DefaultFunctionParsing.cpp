///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 09:43)

#include "CoreTools/CoreToolsExport.h"

#include "DefaultFunctionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::DefaultFunctionParsing::DefaultFunctionParsing(int indentationCount, const String& className)
    : ParentType{ indentationCount }, className{ className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultFunctionParsing)

System::String CoreTools::DefaultFunctionParsing::GenerateDefaultConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += className;
    content += TextParsing::gBrackets;
    content += TextParsing::gNoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateKeyConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gExplicit;
    content += className;
    content += TextParsing::gKey;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateCSVRowConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gExplicit;
    content += className;
    content += TextParsing::gCSVRow;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateCSVContentConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gExplicit;
    content += className;
    content += TextParsing::gCSVContent;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateDestructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gVirtualDestructor;
    content += className;
    content += TextParsing::gBrackets;
    content += TextParsing::gNoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateCopyConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += className;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConst;
    content += className;
    content += TextParsing::gRhsCopy;
    content += TextParsing::gNoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateCopyAssignment() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += className;
    content += TextParsing::gCopyAssignment;
    content += TextParsing::gConst;
    content += className;
    content += TextParsing::gRhsCopy;
    content += TextParsing::gNoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateMoveConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += className;
    content += TextParsing::gLeftBrackets;
    content += className;
    content += TextParsing::gRhsMove;
    content += TextParsing::gNoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateMoveAssignment() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += className;
    content += TextParsing::gCopyAssignment;
    content += className;
    content += TextParsing::gRhsMove;
    content += TextParsing::gNoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateClassInvariantDeclare() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gClassInvariantDeclare;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateClassInvariantVirtualDeclare() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gClassInvariantVirtualDeclare;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateClassInvariantFinalDeclare() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gClassInvariantFinalDeclare;
    content += TextParsing::gNewlineCharacter;

    return content;
}
