///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/05 11:36)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM14_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM14_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms14
            {
                namespace Example0
                {
                    int F(MAYBE_UNUSED int x) throw();  // F不会发射异常：C++98风格
                }

                namespace Example1
                {
                    int F(MAYBE_UNUSED int x) noexcept;  // F不会发射异常：C++11风格
                }

                // RetType Function(params) noexcept;  // 最优化
                // RetType Function(params) throw();  // 优化不够
                // RetType Function(params);  // 优化不够

                class Widget
                {
                };

                template <class T, size_t N>
                void Swap(T (&a)[N], T (&b)[N]) noexcept(noexcept(swap(*a, *b)))
                {
                    std::swap(*a, *b);
                }

                template <class T1, class T2>
                struct Pair
                {
                    // ...
                    void Swap(Pair& p) noexcept(noexcept(swap(first, p.first)) && noexcept(swap(second, p.second)))
                    {
                        std::swap(first, p.first);
                        std::swap(second, p.second);
                    }

                    T1 first;
                    T2 second;
                };

                void F(MAYBE_UNUSED const std::string& s) noexcept;  // 前置条件：s.length() <= 32

                void Setup();
                void Cleanup();

                void DoWork() noexcept;
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM14_H
