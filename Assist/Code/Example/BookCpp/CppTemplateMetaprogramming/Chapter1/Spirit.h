///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/31 22:26)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_SPIRIT_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_SPIRIT_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "System/Helper/PragmaWarning/Spirit.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        // 利用LL样式_1，_2和_3
        phoenix::actor<phoenix::argument<0>> const _1 = phoenix::argument<0>();
        phoenix::actor<phoenix::argument<1>> const _2 = phoenix::argument<1>();
        phoenix::actor<phoenix::argument<2>> const _3 = phoenix::argument<2>();

        struct vars : boost::spirit::classic::closure<vars, double>
        {
            member1 val;
        };

        struct calculator : public boost::spirit::classic::grammar<calculator, vars::context_t>
        {
            template <class Tokenizer>
            struct definition
            {
                // 我们所有的规则都有一个附加的int，称为“val”。
                boost::spirit::classic::rule<Tokenizer, vars::context_t>
                    expr, term, factor, group, integer;

                // ...除了最高规则
                boost::spirit::classic::rule<Tokenizer> top;

                definition(calculator const& self)
                {
                    top = expr[self.val = _1];

                    expr =
                        (term[expr.val = _1] >> '+' >> expr[expr.val += _1]) | (term[expr.val = _1] >> '-' >> expr[expr.val -= _1]) | term[expr.val = _1];

                    term =
                        (factor[term.val = _1] >> '*' >> term[term.val *= _1]) | (factor[term.val = _1] >> '/' >> term[term.val /= _1]) | factor[term.val = _1];

                    factor =
                        integer[factor.val = _1] | ('(' >> expr[factor.val = _1] >> ')');

                    integer = boost::spirit::classic::int_p[integer.val = _1];
                }

                // 告诉Spirit开始使用“top”进行解析
                boost::spirit::classic::rule<Tokenizer> const& start() const
                {
                    return top;
                }
            };
        };
    }
}

#endif  //  CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_SPIRIT_H
