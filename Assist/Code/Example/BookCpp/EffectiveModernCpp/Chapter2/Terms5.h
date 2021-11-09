///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/18 21:45)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER2_TERM5_H
#define EFFECTIVE_MODERN_CPP_CHAPTER2_TERM5_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter2
        {
            namespace Terms5
            {
                // 做我所想，do what I mean 算法应用范围是从b到e的所有元素
                template <typename It>
                void Dwim(It b, It e)
                {
                    while (b != e)
                    {
                        typename std::iterator_traits<It>::value_type currValue = *b;
                        // ...
                    }
                }

                // 意义同前
                template <typename It>
                void Dwim1(It b, It e)
                {
                    while (b != e)
                    {
                        auto currValue = *b;
                        // ...
                    }
                }

                class Widget
                {
                };

                bool operator<(MAYBE_UNUSED const Widget& lhs, MAYBE_UNUSED const Widget& rhs) noexcept;
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER2_TERM5_H
