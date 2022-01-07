///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:35)

#ifndef CORE_TOOLS_TEXT_PARSING_SCOPE_EXPRESSION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_SCOPE_EXPRESSION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ScopeExpressionParsing final
    {
    public:
        using ClassType = ScopeExpressionParsing;
        using String = System::String;
        using StringView = System::StringView;

    public:
        ScopeExpressionParsing(const String& scopeExpression, const String& variableNameExpression);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String Parsing() const;

    private:
        using SplitType = std::vector<String>;

    private:
        NODISCARD SplitType GetScopeExpressionResult() const;

        NODISCARD String GetClosedInterval(const SplitType& scopeExpressionResult) const;
        NODISCARD String GetOpenInterval(const SplitType& scopeExpressionResult) const;
        NODISCARD String GetGreater(const SplitType& scopeExpressionResult) const;
        NODISCARD String GetLess(const SplitType& scopeExpressionResult) const;

        NODISCARD String GetEndInterval(const SplitType& scopeExpressionResult) const;
        NODISCARD String GetInterval(const SplitType& scopeExpressionResult, const StringView& compare) const;

    private:
        String scopeExpression;
        String variableNameExpression;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SCOPE_EXPRESSION_PARSING_H