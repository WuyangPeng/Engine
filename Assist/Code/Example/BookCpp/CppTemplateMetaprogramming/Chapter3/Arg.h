///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/05 19:40)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_ARG_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_ARG_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/mpl/apply.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_float.hpp>
#include <vector>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        namespace Boost
        {
            namespace Mpl
            {
                namespace Placeholder
                {
                    template <int N>
                    struct Arg;  // 前置声明

                    struct Void_;

                    template <>
                    struct Arg<1>
                    {
                        template <class A1, class A2 = Void_, class Am = Void_>
                        struct apply
                        {
                            typedef A1 type;  // 返回第一个参数
                        };
                    };

                    typedef Arg<1> _1;

                    template <>
                    struct Arg<2>
                    {
                        template <class A1, class A2 = Void_, class Am = Void_>
                        struct apply
                        {
                            typedef A2 type;  // 返回第二个参数
                        };
                    };

                    typedef Arg<2> _2;

                    // 其他特化版本和typedefs...

                    typedef Arg<-1> _;  // 匿名点位符
                }
            }

            namespace mpl = boost::mpl;
            using namespace mpl::placeholders;

            template <class U>
            struct MakeVector
            {
                typedef std::vector<U> type;
            };

            typedef mpl::apply<MakeVector<_>, T>::type VectorOfT1;
            typedef mpl::apply<std::vector<_>, T>::type VectorOfT2;

            struct AlwaysInt
            {
                typedef int type;
            };

            struct AddPointerF6
            {
                template <class T>
                struct apply : boost::add_pointer<T>
                {
                };
            };

            typedef mpl::vector<int, char*, double&> Seq;
            typedef mpl::transform<Seq, boost::add_pointer<_>> CalcPtrSeq;

            struct SomeSequence
            {
            };

            // 确定满足以下条件的类型x在some_sequence中的位置
            // x可被转换为int
            // 且x不是char类型
            // 且x不是浮点类型
            typedef mpl::find_if<SomeSequence, mpl::and_<boost::is_convertible<_1, int>,
                                                         mpl::not_<boost::is_same<_1, char>>,
                                                         mpl::not_<boost::is_float<_1>>>>::type Iter;
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_ARG_H
