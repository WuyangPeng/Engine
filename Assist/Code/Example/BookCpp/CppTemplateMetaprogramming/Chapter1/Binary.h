///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/31 1:05)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_BINARY2_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_BINARY2_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/static_assert.hpp>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        template <unsigned long N>
        struct Binary2
        {
            static unsigned const value = (Binary2<N / 10>::value << 1) |  // ǰ����ϸ�λ
                                          (N % 10);  // �����λ
        };

        template <>  // �ػ�
        struct Binary2<0>  // ��ֹ�ݹ�
        {
            static unsigned const value = 0;
        };

        constexpr unsigned const one = Binary2<1>::value;
        constexpr unsigned const three = Binary2<11>::value;
        constexpr unsigned const five = Binary2<101>::value;
        constexpr unsigned const seven = Binary2<111>::value;
        constexpr unsigned const nine = Binary2<1001>::value;

        BOOST_STATIC_ASSERT(one == 1);
        BOOST_STATIC_ASSERT(three == 3);
        BOOST_STATIC_ASSERT(five == 5);
        BOOST_STATIC_ASSERT(seven == 7);
        BOOST_STATIC_ASSERT(nine == 9);

        unsigned BinaryFunction1(unsigned long N);

        constexpr unsigned BinaryFunction2(unsigned long N) noexcept
        {
            unsigned result = 0;
            for (unsigned bit = 0x1; N; N /= 10, bit <<= 1)
            {
                if (N % 10)
                    result += bit;
            }
            return result;
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER1_BINARY2_H
