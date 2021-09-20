///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/05 19:40)

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
                    struct Arg;  // ǰ������

                    struct Void_;

                    template <>
                    struct Arg<1>
                    {
                        template <class A1, class A2 = Void_, class Am = Void_>
                        struct apply
                        {
                            typedef A1 type;  // ���ص�һ������
                        };
                    };

                    typedef Arg<1> _1;

                    template <>
                    struct Arg<2>
                    {
                        template <class A1, class A2 = Void_, class Am = Void_>
                        struct apply
                        {
                            typedef A2 type;  // ���صڶ�������
                        };
                    };

                    typedef Arg<2> _2;

                    // �����ػ��汾��typedefs...

                    typedef Arg<-1> _;  // ������λ��
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

            // ȷ��������������������x��some_sequence�е�λ��
            // x�ɱ�ת��Ϊint
            // ��x����char����
            // ��x���Ǹ�������
            typedef mpl::find_if<SomeSequence, mpl::and_<boost::is_convertible<_1, int>,
                                                         mpl::not_<boost::is_same<_1, char>>,
                                                         mpl::not_<boost::is_float<_1>>>>::type Iter;
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_ARG_H
