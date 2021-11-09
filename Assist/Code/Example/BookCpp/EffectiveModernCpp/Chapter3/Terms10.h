///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/09/30 20:37)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM10_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM10_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms10
            {
                // 函数，返回x的质因数
                std::vector<std::size_t> PrimeFactors(std::size_t x);

                namespace Example0
                {
                    // enum Color;  // 错误
                }

                namespace Example1
                {
                    enum class Color;  // 没问题
                }

                namespace Example2
                {
                    enum Color
                    {
                        black,
                        white,
                        red
                    };

                    enum Status
                    {
                        good = 0,
                        failed = 1,
                        incomplete = 100,
                        corrupt = 200,
                        indeterminate = 0xFFFFFFFF
                    };
                }

                namespace Example3
                {
                    enum Status
                    {
                        good = 0,
                        failed = 1,
                        incomplete = 100,
                        corrupt = 200,
                        audited = 500,
                        indeterminate = 0xFFFFFFFF
                    };
                }

                namespace Example4
                {
                    enum class Status;  // 前置声明

                    void ContinueProcessing(MAYBE_UNUSED Status s) noexcept;  // 取用前置声明的枚举型别
                }

                namespace Example5
                {
                    enum class Status;  // 底层型别是int
                }

                namespace Example6
                {
                    enum class Status : std::uint32_t;  // Status的底层型别是std::uint32_t（该型别在<cstdint>中包含）
                }

                namespace Example7
                {
                    enum Color : std::uint8_t;  // 不限范围的枚举型别的前置声明，底层型别是std::uint8_t

                    enum Status : std::uint32_t
                    {
                        good = 0,
                        failed = 1,
                        incomplete = 100,
                        corrupt = 200,
                        audited = 500,
                        indeterminate = 0xFFFFFFFF
                    };
                }

                namespace Example0
                {
                    template <typename E>
                    constexpr typename std::underlying_type<E>::type ToUType(E enumerator) noexcept
                    {
                        return static_cast<typename std::underlying_type<E>::type>(enumerator);
                    }
                }

                namespace Example1
                {
                    template <typename E>
                    constexpr std::underlying_type_t<E> ToUType(E enumerator) noexcept  // C++14
                    {
                        return static_cast<std::underlying_type_t<E>>(enumerator);
                    }
                }

                namespace Example2
                {
                    template <typename E>
                    constexpr auto ToUType(E enumerator) noexcept  // C++14
                    {
                        return static_cast<std::underlying_type_t<E>>(enumerator);
                    }
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM10_H
