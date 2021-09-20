///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/08 23:04)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "IterSwap.h"
#include "Iterator.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#include <deque>
#include <vector>

using std::deque;
using std::vector;

BookTemplate::CppTemplateMetaprogramming::Iterator::Iterator() noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_SELF_CLASS_IS_VALID_9;
}

void BookTemplate::CppTemplateMetaprogramming::Iterator::IterSwap1Main() const
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    vector<int> lhs{ 1, 2 };
    vector<int> rhs{ 2, 1 };

    IterSwap1(lhs.begin(), rhs.begin());
}

void BookTemplate::CppTemplateMetaprogramming::Iterator::IterSwap2Main() const
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    vector<int> lhs{ 1, 2 };
    vector<int> rhs{ 2, 1 };

    IterSwap2(lhs.begin(), rhs.begin());
}

void BookTemplate::CppTemplateMetaprogramming::Iterator::IterSwap4Main() const
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    vector<int> lhs{ 1, 2 };
    vector<int> rhs{ 2, 1 };

    IterSwap4(lhs.begin(), rhs.begin());
}

void BookTemplate::CppTemplateMetaprogramming::Iterator::FooMain() const noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    int i1 = 1;
    int i2 = 2;
    Foo(&i1, &i2);
}

void BookTemplate::CppTemplateMetaprogramming::Iterator::IterSwap5Main() const
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    vector<int> lhs{ 1, 2 };
    vector<int> rhs{ 2, 1 };

    IterSwap5(lhs.begin(), rhs.begin());
}

void BookTemplate::CppTemplateMetaprogramming::Iterator::IterSwap6Main() const
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    vector<int> value0{ 1, 2 };
    deque<int> value1{ 2, 1 };
    vector<int> value2{ 1, 2 };

    IterSwap6(value0.begin(), value1.begin());
    IterSwap6(value0.begin(), value2.begin());
}

void BookTemplate::CppTemplateMetaprogramming::Iterator::NonstdMain() const
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    vector<int> value0{ 1, 2 };
    deque<int> value1{ 2, 1 };
    vector<int> value2{ 1, 2 };

    Nonstd::IterSwap(value0.begin(), value1.begin());
    Nonstd::IterSwap(value0.begin(), value2.begin());
}
