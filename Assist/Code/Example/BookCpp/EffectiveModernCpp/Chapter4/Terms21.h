///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/22 20:42)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM21_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM21_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <memory>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms21
            {
                template <typename T, typename... Ts>
                std::unique_ptr<T> MakeUnique(Ts&&... params)
                {
                    return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
                }

                class Widget
                {
                };

                void ProcessWidget(MAYBE_UNUSED std::shared_ptr<Widget> spw, MAYBE_UNUSED int priority) noexcept;

                int ComputePriority() noexcept;

                class ReallyBigType
                {
                    // ...
                };

                void CusDel(Widget* ptr) noexcept;  // 自定义析构器
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM21_H
