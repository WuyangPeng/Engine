///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 21:08)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER1_TERM1_DERIVE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER1_TERM1_DERIVE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            namespace Terms1
            {
                // template <typename T>
                // void F(ParamType param);

                // F(expr); 以某表达式调用F
                // 从expr来推导T和ParamType的型别。

                template <typename T>
                void F(MAYBE_UNUSED const T& param) noexcept  // ParamType是const T&
                {
                }

                template <typename T>
                void F0(MAYBE_UNUSED T& param) noexcept  // param是个引用
                {
                }

                template <typename T>
                void F1(MAYBE_UNUSED const T& param) noexcept  // param现在是const引用了
                {
                }

                template <typename T>
                void F2(MAYBE_UNUSED T* param) noexcept  // param现在是个指针了
                {
                }

                template <typename T>
                void F3(MAYBE_UNUSED T&& param) noexcept  // param现在是个万能引用了
                {
                }

                template <typename T>
                void F4(MAYBE_UNUSED T param) noexcept  // param现在是按值传递
                {
                }

                template <typename T>
                void F5(MAYBE_UNUSED T param) noexcept  // param仍按值传递
                {
                }

                template <typename T>
                void F6(MAYBE_UNUSED T param) noexcept  // 持有按值形参的模板
                {
                }

                void MyFunc(MAYBE_UNUSED int param[]) noexcept;
                void MyFunc(MAYBE_UNUSED int* param) noexcept;

                template <typename T>
                void F7(MAYBE_UNUSED T& param) noexcept  // 按引用方式传递形参的模板
                {
                }

                /// 以编译期常量形式返回数组尺寸
                /// （该数组形参未起名字，因为我们只关心其含有的元素个数）
                template <typename T, std::size_t N>
                constexpr std::size_t ArraySize(T (&)[N]) noexcept
                {
                    return N;
                }

                void SomeFunc(int, double) noexcept;  // SomeFunc是个函数，其型别为void(int, double)

                template <typename T>
                void F8(MAYBE_UNUSED T param) noexcept  // param按值传递
                {
                }

                template <typename T>
                void F9(MAYBE_UNUSED T& param) noexcept  // param按引用传递
                {
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM1_DERIVE_H
