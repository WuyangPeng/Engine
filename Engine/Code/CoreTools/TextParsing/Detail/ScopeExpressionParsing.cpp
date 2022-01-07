///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:28)

#include "CoreTools/CoreToolsExport.h"

#include "ScopeExpressionParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ScopeExpressionParsing::ScopeExpressionParsing(const String& scopeExpression, const String& variableNameExpression)
    : scopeExpression{ scopeExpression }, variableNameExpression{ variableNameExpression }
{
    if (scopeExpression.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("范围表达式为空。\n"s));
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

    const auto firstChar = scopeExpression.front();

    switch (firstChar)
    {
        case TextParsing::g_LeftSquareBrackets:
        {
            return GetClosedInterval(scopeExpressionResult);
        }
        break;
        case TextParsing::g_LeftBrackets:
        {
            return GetOpenInterval(scopeExpressionResult);
        }
        break;
        case TextParsing::g_RightAngleBracket:
        {
            return GetGreater(scopeExpressionResult);
        }
        break;
        case TextParsing::g_LeftAngleBracket:
        {
            return GetLess(scopeExpressionResult);
        }
        break;
        default:
        {
            return String{};
        }
        break;
    }
}

CoreTools::ScopeExpressionParsing::SplitType CoreTools::ScopeExpressionParsing::GetScopeExpressionResult() const
{
    SplitType scopeExpressionResult{};
    boost::algorithm::split(scopeExpressionResult, scopeExpression, boost::is_any_of(TextParsing::g_ScopeExpressionSplit), boost::token_compress_on);

    scopeExpressionResult.erase(std::remove(scopeExpressionResult.begin(), scopeExpressionResult.end(), String{}),
                                scopeExpressionResult.end());

    return scopeExpressionResult;
}

System::String CoreTools::ScopeExpressionParsing::GetClosedInterval(const SplitType& scopeExpressionResult) const
{
    return GetInterval(scopeExpressionResult, TextParsing::g_LessEqual);
}

System::String CoreTools::ScopeExpressionParsing::GetOpenInterval(const SplitType& scopeExpressionResult) const
{
    return GetInterval(scopeExpressionResult, TextParsing::g_Less);
}

System::String CoreTools::ScopeExpressionParsing::GetInterval(const SplitType& scopeExpressionResult, const StringView& compare) const
{
    String result{ TextParsing::g_LeftBrackets };

    result += scopeExpressionResult.at(0);
    result += compare;
    result += variableNameExpression;
    result += TextParsing::g_ExpressionAnd;

    result += GetEndInterval(scopeExpressionResult);

    return result;
}

System::String CoreTools::ScopeExpressionParsing::GetGreater(const SplitType& scopeExpressionResult) const
{
    String result{};

    const auto nextChar = scopeExpression.at(1);

    result += scopeExpressionResult.at(0);

    if (nextChar == TextParsing::g_equalSignChar)
    {
        result += TextParsing::g_GreaterEqual;
    }
    else
    {
        result += TextParsing::g_Greater;
    }

    result += variableNameExpression;

    return result;
}

System::String CoreTools::ScopeExpressionParsing::GetLess(const SplitType& scopeExpressionResult) const
{
    String result{};

    const auto nextChar = scopeExpression.at(1);

    result += scopeExpressionResult.at(0);

    if (nextChar == TextParsing::g_equalSignChar)
    {
        result += TextParsing::g_LessEqual;
    }
    else
    {
        result += TextParsing::g_Less;
    }

    result += variableNameExpression;

    return result;
}

System::String CoreTools::ScopeExpressionParsing::GetEndInterval(const SplitType& scopeExpressionResult) const
{
    String result{};

    const auto lastChar = scopeExpression.back();
    if (lastChar == TextParsing::g_RightSquareBrackets)
    {
        result += variableNameExpression;
        result += TextParsing::g_LessEqual;
        result += scopeExpressionResult.at(1);
        result += TextParsing::g_RightBrackets;
    }
    else if (lastChar == TextParsing::g_RightBrackets)
    {
        result += variableNameExpression;
        result += TextParsing::g_Less;
        result += scopeExpressionResult.at(1);
        result += TextParsing::g_RightBrackets;
    }

    return result;
}
