///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/20 21:47)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM30_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM30_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <memory>
#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms30
            {
                namespace Example0
                {
                    void F(MAYBE_UNUSED int v) noexcept;

                    template <typename T>
                    void Fwd(T&& param)  // 接受任意实参
                    {
                        F(std::forward<T>(param));  // 转发该实参到F
                    }
                }

                namespace Example1
                {
                    void F(MAYBE_UNUSED int v) noexcept;

                    template <typename... Ts>
                    void Fwd(Ts&&... param)  // 接受任意实参
                    {
                        F(std::forward<Ts>(param)...);  // 转发该实参到F
                    }
                }

                // F(expression);  // 如果本语句执行了某操作。
                // Fwd(expression);  // 而本语句执行了不同的操作，则称Fwd完美转发expression到F失败。

                namespace Example2
                {
                    void F(MAYBE_UNUSED const std::vector<int>& v) noexcept;

                    template <typename... Ts>
                    void Fwd(Ts&&... param)
                    {
                        F(std::forward<Ts>(param)...);
                    }
                }

                namespace Example3
                {
                    class Widget
                    {
                    public:
                        static const std::size_t MinVals = 28;  // 给出了MinVals的声明
                    };

                    // ...

                    // 未给出MinVals的声明

                    void F(MAYBE_UNUSED std::size_t val) noexcept;

                    template <typename... Ts>
                    void Fwd(Ts&&... param) noexcept
                    {
                        F(std::forward<Ts>(param)...);
                    }
                }

                namespace Example4
                {
                    void F(MAYBE_UNUSED int (*pf)(int)) noexcept;  // PF是“processing function”的简称
                }

                namespace Example5
                {
                    void F(MAYBE_UNUSED int pf(int)) noexcept;  // 声明与上面含义相同的F

                    template <typename... Ts>
                    void Fwd(Ts&&... param) noexcept
                    {
                        F(std::forward<Ts>(param)...);
                    }

                    int ProcessVal(MAYBE_UNUSED int value) noexcept;
                    int ProcessVal(MAYBE_UNUSED int value, MAYBE_UNUSED int priority) noexcept;

                    template <typename T>
                    T WorkOnVal(T param) noexcept
                    {
                        return param;
                    }
                }

                namespace Example6
                {
                    struct IPv4Header
                    {
                        std::uint32_t version : 4,
                            IHL : 4,
                            DSCP : 6,
                            ECN : 2,
                            totalLength : 16;
                    };

                    void F(MAYBE_UNUSED std::size_t sz) noexcept;  // 待调用的函数

                    template <typename... Ts>
                    void Fwd(Ts&&... param) noexcept
                    {
                        F(std::forward<Ts>(param)...);
                    }
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM30_H
