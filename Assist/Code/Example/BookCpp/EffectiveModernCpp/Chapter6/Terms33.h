///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/02 21:54)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER6_TERM33_H
#define EFFECTIVE_MODERN_CPP_CHAPTER6_TERM33_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter6
        {
            namespace Terms33
            {
                void Func(MAYBE_UNUSED int x) noexcept;
                int Normalize(MAYBE_UNUSED int x) noexcept;

                class SomeCompilerGeneratedClassName
                {
                public:
                    // auto型别的返回值
                    template <typename T>
                    auto operator()(T x) const
                    {
                        return Func(Normalize(x));
                    }

                    // ...
                    // 闭包的其他功能
                };

                // 在命名空间std中
                template <typename T>
                T&& Forward(std::remove_reference_t<T>& param) noexcept
                { 
                    return static_cast<T&&>(param);
                }

                class Widget
                {
                };

                // T取值Widget时，std::forward的实例化结果
                inline Widget&& Forward(Widget& param) noexcept
                {
                    return static_cast<Widget&&>(param);
                }

                // T取值Widget时，std::forward的实例化结果（在引用折叠发生之前）
                /*
                Widget&& && Forward(Widget& param)
                {
                    return static_cast<Widget&& &&>(param);
                }
                */
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER6_TERM33_H
