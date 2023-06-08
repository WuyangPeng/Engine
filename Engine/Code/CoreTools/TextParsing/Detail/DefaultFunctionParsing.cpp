///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:53)

#include "CoreTools/CoreToolsExport.h"

#include "DefaultFunctionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::DefaultFunctionParsing::DefaultFunctionParsing(int indentationCount, const String& className, const String& keyTypeDescribe)
    : ParentType{ indentationCount }, className{ className }, keyTypeDescribe{ keyTypeDescribe }
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
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gLeftBrackets;
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) noexcept");
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateCSVRowConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gExplicit;
    content += TextParsing::gSpace;
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
    content += TextParsing::gSpace;
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
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
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
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
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
