///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:06)

#include "CoreTools/CoreToolsExport.h"

#include "ClassNameParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ClassNameParsing::ClassNameParsing(int indentationCount, String className) noexcept
    : ParentType{ indentationCount }, className{ std::move(className) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ClassNameParsing)

System::String CoreTools::ClassNameParsing::GenerateParentClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gClass;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateClassType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gClassType;
    content += className;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateChildClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gClass;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gFinalInherit;
    content += className;
    content += TextParsing::gBase;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateParentType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gParentType;
    content += className;
    content += TextParsing::gBase;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gClass;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gSpace;
    content += TextParsing::gFinal;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ClassNameParsing::GenerateEnumClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gEnumClass;
    content += className;
    content += TextParsing::gNewlineCharacter;

    return content;
}
