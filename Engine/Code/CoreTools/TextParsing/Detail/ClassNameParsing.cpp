///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:54)

#include "CoreTools/CoreToolsExport.h"

#include "ClassNameParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ClassNameParsing::ClassNameParsing(int indentationCount, const String& className)
    : ParentType{ indentationCount }, className{ className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ClassNameParsing)

System::String CoreTools::ClassNameParsing::GenerateParentClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_Class;
    content += className;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateClassType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ClassType;
    content += className;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateChildClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_Class;
    content += className;
    content += TextParsing::g_FinalInherit;
    content += className;
    content += TextParsing::g_Base;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateParentType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ParentType;
    content += className;
    content += TextParsing::g_Base;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_Class;
    content += className;
    content += TextParsing::g_Final;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateEnumClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_EnumClass;
    content += className;
    content += TextParsing::g_NewlineCharacter;

    return content;
}
