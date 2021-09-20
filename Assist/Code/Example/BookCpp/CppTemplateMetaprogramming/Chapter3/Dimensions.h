///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/24 22:07)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_DIMENSIONS_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_DIMENSIONS_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/int.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>

namespace boost
{
    namespace mpl
    {
    }
}

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        typedef int Dimension[7];  // m  l  t  ...
        Dimension const mass = { 1, 0, 0, 0, 0, 0, 0 };
        Dimension const length = { 0, 1, 0, 0, 0, 0, 0 };
        Dimension const time = { 0, 0, 1, 0, 0, 0, 0 };
        // ...

        Dimension const force = { 1, 1, -2, 0, 0, 0, 0 };

        typedef boost::mpl::vector<signed char, short, int, long> SignedTypes;

        namespace mpl = boost::mpl;
        static int constexpr five = mpl::int_<5>::value;

        typedef mpl::vector<mpl::int_<1>, mpl::int_<0>, mpl::int_<0>, mpl::int_<0>, mpl::int_<0>, mpl::int_<0>, mpl::int_<0>> Mass1;

        typedef mpl::vector<mpl::int_<0>, mpl::int_<1>, mpl::int_<0>, mpl::int_<0>, mpl::int_<0>, mpl::int_<0>, mpl::int_<0>> Length1;

        namespace
        {
            typedef mpl::vector_c<int, 1, 0, 0, 0, 0, 0, 0> Mass;
            typedef mpl::vector_c<int, 0, 1, 0, 0, 0, 0, 0> Length;  // or position
            typedef mpl::vector_c<int, 0, 0, 1, 0, 0, 0, 0> Time;
            typedef mpl::vector_c<int, 0, 0, 0, 1, 0, 0, 0> Charge;
            typedef mpl::vector_c<int, 0, 0, 0, 0, 1, 0, 0> Temperature;
            typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 1, 0> Intensity;
            typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 0, 1> Angle;
        }

        // base dimension:        m l  t ...
        typedef mpl::vector_c<int, 0, 1, -1, 0, 0, 0, 0> Velocity;  // l/t
        typedef mpl::vector_c<int, 0, 1, -2, 0, 0, 0, 0> Acceleration;  // l/(t2)
        typedef mpl::vector_c<int, 1, 1, -1, 0, 0, 0, 0> Momentum;  // ml/t
        typedef mpl::vector_c<int, 1, 1, -2, 0, 0, 0, 0> Force;  // ml/(t2)

        typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 0, 0> Scalar;
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_DIMENSIONS_H
