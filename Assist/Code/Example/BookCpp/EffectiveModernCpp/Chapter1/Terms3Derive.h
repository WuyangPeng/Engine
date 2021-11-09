///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/05 12:25)

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

                bool F(MAYBE_UNUSED const Widget& w);  // decltype(w)是const Widget&，decltype(F)是bool (const Widget& w)

                struct Point
                {
                    int x;  // decltype(Point::x)是int
                    int y;  // decltype(Point::y)是int
                };

                class Widget
                {
                };

                template <typename T>
                class Vector  // std::vector的简化版
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
                auto AuthAndAccess(Container& c, Index i) noexcept -> decltype(c[i])  // 能运作，但亟须改进
                {
                    ActhenticateUser();

                    return c[i];
                }

                template <typename Container, typename Index>
                auto AuthAndAccess1(Container& c, Index i) noexcept  // C++14; 不甚正确
                {
                    ActhenticateUser();

                    return c[i];  // 返回值型别是根据c[i]推导出来
                }

                template <typename Container, typename Index>
                decltype(auto) AuthAndAccess2(Container& c, Index i) noexcept  // C++14; 能够动作，但仍亟须改进
                {
                    ActhenticateUser();

                    return c[i];
                }

                std::deque<std::string> MakeStringDeque();  // 工厂函数

                template <typename Container, typename Index>
                decltype(auto) AuthAndAccess3(Container&& c, Index i) noexcept  // C++14最终版
                {
                    ActhenticateUser();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

                    return std::forward<Container>(c)[i];

#include STSTEM_WARNING_POP
                }

                template <typename Container, typename Index>
                auto AuthAndAccess4(Container&& c, Index i) noexcept -> decltype(std::forward<Container>(c)[i])  // C++11最终版
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

                    return x;  //  decltype(x) 是int，所以F1返回的是int
                }

#include STSTEM_WARNING_POP

                /* decltype(auto) F2()
                {
                    int x = 0;

                    // ...

                    return (x);  //  decltype((x)) 是int&，所以F1返回的是int&
                }*/
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM3_DERIVE_H
