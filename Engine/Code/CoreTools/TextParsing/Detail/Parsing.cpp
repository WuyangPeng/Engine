///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:50)

#include "CoreTools/CoreToolsExport.h"

#include "Parsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::Parsing::Parsing(int indentationCount) noexcept
    : indentationCount{ indentationCount }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Parsing)

System::String CoreTools::Parsing::GenerateIndentation(int addIndentationCount) const
{
    String content{};

    for (auto i = 0; i < indentationCount + addIndentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    return content;
}

System::String CoreTools::Parsing::GenerateFunctionBeginBrackets(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gFunctionBeginBrackets;

    return content;
}

System::String CoreTools::Parsing::GenerateFunctionEndBrackets(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gFunctionEndBrackets;

    return content;
}

System::String CoreTools::Parsing::GeneratePublic() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gPublic;

    return content;
}

System::String CoreTools::Parsing::GenerateUserSelfClassIsValid9(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gUserSelfClassIsValid9;

    return content;
}

System::String CoreTools::Parsing::GenerateUserSelfClassIsValid1(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gUserSelfClassIsValid1;

    return content;
}

System::String CoreTools::Parsing::GenerateUserClassIsValidConst9(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gUserClassIsValidConst9;

    return content;
}

System::String CoreTools::Parsing::GenerateUserClassIsValidConst1(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gUserClassIsValidConst1;

    return content;
}

System::String CoreTools::Parsing::GenerateOpenClassInvariant() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gOpenClassInvariant;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::Parsing::GenerateOpenClassInvariantEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gOpenClassInvariantEndif;

    return content;
}

System::String CoreTools::Parsing::GenerateParentTypeIsValid(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gParentTypeIsValid;

    return content;
}

System::String CoreTools::Parsing::GenerateReturnTrue(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gReturnTrue;

    return content;
}

System::String CoreTools::Parsing::GenerateReturnFalse(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gReturnFalse;

    return content;
}

System::String CoreTools::Parsing::GenerateElse(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gElse;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::Parsing::GenerateClassEndBrackets(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gClassEndBrackets;

    return content;
}

CoreTools::Parsing::SplitType CoreTools::Parsing::GetSplitComma(const String& column)
{
    SplitType result{};

    split(result, column, boost::is_any_of(TextParsing::gComma), boost::token_compress_off);

    return result;
}

System::String CoreTools::Parsing::GenerateReturnIterSecond() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gReturnIterSecond;

    return content;
}