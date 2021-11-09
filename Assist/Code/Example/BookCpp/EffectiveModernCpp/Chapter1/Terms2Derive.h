///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/04 22:18)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER1_TERM2_DERIVE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER1_TERM2_DERIVE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            namespace Terms2
            {
                // template <typename T>
                // void F(ParamType param);

                // F(expr); 以某表达式调用F

                template <typename T>
                void FuncForX0(MAYBE_UNUSED T param) noexcept  // 为推导x的型别而生成的概念性模板
                {
                }

                template <typename T>
                void FuncForX1(MAYBE_UNUSED const T param) noexcept  // 为推导cx的型别而生成的概念性模板
                {
                }

                template <typename T>
                void FuncForX2(MAYBE_UNUSED const T& param) noexcept  // 为推导rx的型别而生成的概念性模板
                {
                }

                void SomeFunc(int, double) noexcept;  // SomeFunc是个函数，型别是void(int, double)

                template <typename T>
                void F(MAYBE_UNUSED T param) noexcept  // 带有形参的模板与x的声明等价的声明式
                {
                }

                template <typename T>
                void F0(MAYBE_UNUSED std::initializer_list<T> initList) noexcept
                {
                }

                /* auto CreateInitList()
                {
                    return { 1, 2, 3 };  // 错误：无法为{ 1, 2, 3 }完成型别推导
                }*/
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM2_DERIVE_H
