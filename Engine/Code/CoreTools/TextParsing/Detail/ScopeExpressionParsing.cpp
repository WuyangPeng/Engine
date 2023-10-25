///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:11)

#include "CoreTools/CoreToolsExport.h"

#include "ScopeExpressionParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ScopeExpressionParsing::ScopeExpressionParsing(const String& scopeExpression, String variableNameExpression)
    : scopeExpression{ scopeExpression }, variableNameExpression{ std::move(variableNameExpression) }
{
    if (scopeExpression.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("范围表达式为空。\n"s))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::ScopeExpressionParsing::IsValid() const noexcept
{
    if (!scopeExpression.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

System::String CoreTools::ScopeExpressionParsing::Parsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto scopeExpressionResult = GetScopeExpressionResult();

    switch (const auto firstChar = scopeExpression.front(); firstChar)
    {
        case TextParsing::gLeftSquareBrackets:
        {
            return GetClosedInterval(scopeExpressionResult);
        }
        case TextParsing::gLeftBrackets:
        {
            return GetOpenInterval(scopeExpressionResult);
        }
        case TextParsing::gRightAngleBracket:
        {
            return GetGreater(scopeExpressionResult);
        }
        case TextParsing::gLeftAngleBracket:
        {
            return GetLess(scopeExpressionResult);
        }
        default:
        {
            return String{};
        }
    }
}

CoreTools::ScopeExpressionParsing::SplitType CoreTools::ScopeExpressionParsing::GetScopeExpressionResult() const
{
    SplitType scopeExpressionResult{};
    split(scopeExpressionResult, scopeExpression, boost::is_any_of(TextParsing::gScopeExpressionSplit), boost::token_compress_on);

    const auto result = std::ranges::remove(scopeExpressionResult, String{});

    scopeExpressionResult.erase(result.begin(), result.end());

    return scopeExpressionResult;
}

System::String CoreTools::ScopeExpressionParsing::GetClosedInterval(const SplitType& scopeExpressionResult) const
{
    return GetInterval(scopeExpressionResult, TextParsing::gLessEqual);
}

System::String CoreTools::ScopeExpressionParsing::GetOpenInterval(const SplitType& scopeExpressionResult) const
{
    return GetInterval(scopeExpressionResult, TextParsing::gLess);
}

System::String CoreTools::ScopeExpressionParsing::GetInterval(const SplitType& scopeExpressionResult, const StringView& compare) const
{
    String result{ TextParsing::gLeftBrackets };

    result += scopeExpressionResult.at(0);
    result += compare;
    result += variableNameExpression;
    result += TextParsing::gExpressionAnd;

    result += GetEndInterval(scopeExpressionResult);

    return result;
}

System::String CoreTools::ScopeExpressionParsing::GetGreater(const SplitType& scopeExpressionResult) const
{
    String result{};

    result += scopeExpressionResult.at(0);

    if (scopeExpression.find(TextParsing::gEqualSign) == 1)
    {
        result += TextParsing::gGreaterEqual;
    }
    else
    {
        result += TextParsing::gGreater;
    }

    result += variableNameExpression;

    return result;
}

System::String CoreTools::ScopeExpressionParsing::GetLess(const SplitType& scopeExpressionResult) const
{
    String result{};

    result += scopeExpressionResult.at(0);

    if (scopeExpression.find(TextParsing::gEqualSign) == 1)
    {
        result += TextParsing::gLessEqual;
    }
    else
    {
        result += TextParsing::gLess;
    }

    result += variableNameExpression;

    return result;
}

System::String CoreTools::ScopeExpressionParsing::GetEndInterval(const SplitType& scopeExpressionResult) const
{
    String result{};

    if (const auto lastChar = scopeExpression.back();
        lastChar == TextParsing::gRightSquareBrackets)
    {
        result += variableNameExpression;
        result += TextParsing::gLessEqual;
        result += scopeExpressionResult.at(1);
        result += TextParsing::gRightBrackets;
    }
    else if (lastChar == TextParsing::gRightBrackets)
    {
        result += variableNameExpression;
        result += TextParsing::gLess;
        result += scopeExpressionResult.at(1);
        result += TextParsing::gRightBrackets;
    }

    return result;
}
