///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/05 12:25)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER1_TERM3_DERIVE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER1_TERM3_DERIVE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <deque>
#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            namespace Terms3
            {
                class Widget;

                bool F(MAYBE_UNUSED const Widget& w);  // decltype(w)��const Widget&��decltype(F)��bool (const Widget& w)

                struct Point
                {
                    int x;  // decltype(Point::x)��int
                    int y;  // decltype(Point::y)��int
                };

                class Widget
                {
                };

                template <typename T>
                class Vector  // std::vector�ļ򻯰�
                {
                public:
                    // ...
                    T& operator[](MAYBE_UNUSED std::size_t index) noexcept
                    {
                        static T result{};

                        return result;
                    }
                    // ...
                };

                void ActhenticateUser() noexcept;

                template <typename Container, typename Index>
                auto AuthAndAccess(Container& c, Index i) noexcept -> decltype(c[i])  // ����������ؽ��Ľ�
                {
                    ActhenticateUser();

                    return c[i];
                }

                template <typename Container, typename Index>
                auto AuthAndAccess1(Container& c, Index i) noexcept  // C++14; ������ȷ
                {
                    ActhenticateUser();

                    return c[i];  // ����ֵ�ͱ��Ǹ���c[i]�Ƶ�����
                }

                template <typename Container, typename Index>
                decltype(auto) AuthAndAccess2(Container& c, Index i) noexcept  // C++14; �ܹ�����������ؽ��Ľ�
                {
                    ActhenticateUser();

                    return c[i];
                }

                std::deque<std::string> MakeStringDeque();  // ��������

                template <typename Container, typename Index>
                decltype(auto) AuthAndAccess3(Container&& c, Index i) noexcept  // C++14���հ�
                {
                    ActhenticateUser();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

                    return std::forward<Container>(c)[i];

#include STSTEM_WARNING_POP
                }

                template <typename Container, typename Index>
                auto AuthAndAccess4(Container&& c, Index i) noexcept -> decltype(std::forward<Container>(c)[i])  // C++11���հ�
                {
                    ActhenticateUser();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

                    return std::forward<Container>(c)[i];

#include STSTEM_WARNING_POP
                }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26497)

                inline decltype(auto) F1() noexcept
                {
                    int x = 0;

                    // ...

                    return x;  //  decltype(x) ��int������F1���ص���int
                }

#include STSTEM_WARNING_POP

                /* decltype(auto) F2()
                {
                    int x = 0;

                    // ...

                    return (x);  //  decltype((x)) ��int&������F1���ص���int&
                }*/
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM3_DERIVE_H
