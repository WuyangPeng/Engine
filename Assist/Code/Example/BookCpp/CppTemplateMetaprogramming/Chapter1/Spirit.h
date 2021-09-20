///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/31 22:26)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_SPIRIT_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_SPIRIT_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "System/Helper/PragmaWarning/Spirit.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        // ����LL��ʽ_1��_2��_3
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
                // �������еĹ�����һ�����ӵ�int����Ϊ��val����
                boost::spirit::classic::rule<Tokenizer, vars::context_t>
                    expr, term, factor, group, integer;

                // ...������߹���
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

                // ����Spirit��ʼʹ�á�top�����н���
                boost::spirit::classic::rule<Tokenizer> const& start() const
                {
                    return top;
                }
            };
        };
    }
}

#endif  //  CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_SPIRIT_H
