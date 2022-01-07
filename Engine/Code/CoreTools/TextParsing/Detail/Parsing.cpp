///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:27)

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
        content += TextParsing::g_Indentation;
    }

    return content;
}

System::String CoreTools::Parsing::GenerateFunctionBeginBrackets(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_FunctionBeginBrackets;

    return content;
}

System::String CoreTools::Parsing::GenerateFunctionEndBrackets(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_FunctionEndBrackets;

    return content;
}

System::String CoreTools::Parsing::GeneratePublic() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_Public;

    return content;
}

System::String CoreTools::Parsing::GenerateUserSelfClassIsValid9(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_UserSelfClassIsValid9;

    return content;
}

System::String CoreTools::Parsing::GenerateUserSelfClassIsValid1(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_UserSelfClassIsValid1;

    return content;
}

System::String CoreTools::Parsing::GenerateUserClassIsValidConst9(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_UserClassIsValidConst9;

    return content;
}

System::String CoreTools::Parsing::GenerateUserClassIsValidConst1(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_UserClassIsValidConst1;

    return content;
}

System::String CoreTools::Parsing::GenerateOpenClassInvariant() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_OpenClassInvariant;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::Parsing::GenerateOpenClassInvariantEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_NewlineCharacter;
    content += TextParsing::g_OpenClassInvariantEndif;

    return content;
}

System::String CoreTools::Parsing::GenerateParentTypeIsValid(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_ParentTypeIsValid;

    return content;
}

System::String CoreTools::Parsing::GenerateReturnTrue(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_ReturnTrue;

    return content;
}

System::String CoreTools::Parsing::GenerateReturnFalse(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_ReturnFalse;

    return content;
}

System::String CoreTools::Parsing::GenerateElse(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_Else;

    return content;
}

System::String CoreTools::Parsing::GenerateClassEndBrackets(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_ClassEndBrackets;

    return content;
}

CoreTools::Parsing::SplitType CoreTools::Parsing::GetSplitComma(const String& column)
{
    SplitType result{};

    boost::algorithm::split(result, column, boost::is_any_of(TextParsing::g_Comma), boost::token_compress_off);

    return result;
}

System::String CoreTools::Parsing::GenerateReturnIterSecond() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ReturnIterSecond;

    return content;
}