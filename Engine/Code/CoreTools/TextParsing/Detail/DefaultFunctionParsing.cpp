///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:58)

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
    content += TextParsing::g_Brackets;
    content += TextParsing::g_NoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateKeyConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Explicit;
    content += className;
    content += TextParsing::g_Key;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateCSVRowConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Explicit;
    content += className;
    content += TextParsing::g_CSVRow;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateCSVContentConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Explicit;
    content += className;
    content += TextParsing::g_CSVContent;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateDestructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_VirtualDestructor;
    content += className;
    content += TextParsing::g_Brackets;
    content += TextParsing::g_NoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateCopyConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += className;
    content += TextParsing::g_LeftBrackets;
    content += TextParsing::g_Const;
    content += className;
    content += TextParsing::g_RhsCopy;
    content += TextParsing::g_NoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateCopyAssignment() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += className;
    content += TextParsing::g_CopyAssignment;
    content += TextParsing::g_Const;
    content += className;
    content += TextParsing::g_RhsCopy;
    content += TextParsing::g_NoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateMoveConstructor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += className;
    content += TextParsing::g_LeftBrackets;
    content += className;
    content += TextParsing::g_RhsMove;
    content += TextParsing::g_NoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateMoveAssignment() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += className;
    content += TextParsing::g_CopyAssignment;
    content += className;
    content += TextParsing::g_RhsMove;
    content += TextParsing::g_NoexceptDefault;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateClassInvariantDeclare() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ClassInvariantDeclare;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateClassInvariantVirtualDeclare() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ClassInvariantVirtualDeclare;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::DefaultFunctionParsing::GenerateClassInvariantFinalDeclare() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ClassInvariantFinalDeclare;
    content += TextParsing::g_NewlineCharacter;

    return content;
}
