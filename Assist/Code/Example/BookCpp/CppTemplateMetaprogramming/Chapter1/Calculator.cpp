///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/31 1:06)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Calculator.h"
#include "Spirit.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#include <iostream>
#include <string>

using namespace std;
using namespace boost::spirit;
using namespace boost::spirit::classic;
using namespace phoenix;

BookTemplate::CppTemplateMetaprogramming::Calculator::Calculator() noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_SELF_CLASS_IS_VALID_9;
}

int BookTemplate::CppTemplateMetaprogramming::Calculator::Main() const
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "\t\tThe Calculator...\n\n";
    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "Type an expression...or [q or Q] to quit\n\n";

    // 我们的语法
    calculator calc;

    string str;
    while (getline(cin, str))
    {
        if (str.at(0) == 'q' || str.at(0) == 'Q')
            break;

        double n = 0;
        const parse_info<> info = parse(str.c_str(), calc[var(n) = _1], space_p);

        // calc[var(n) = arg1] 调用计算器并提取计算结果。 请参阅上面的计算器语法注释。

        if (info.full)
        {
            cout << "-------------------------\n";
            cout << "Parsing succeeded\n";
            cout << "result = " << n << endl;
            cout << "-------------------------\n";
        }
        else
        {
            cout << "-------------------------\n";
            cout << "Parsing failed\n";
            cout << "stopped at: \": " << info.stop << "\"\n";
            cout << "-------------------------\n";
        }
    }

    cout << "Bye... :-) \n\n";

    return 0;
}
