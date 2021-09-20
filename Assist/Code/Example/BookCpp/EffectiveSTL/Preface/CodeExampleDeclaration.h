///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:46)

#ifndef EFFECTIVE_STL_PREFACE_CODE_EXAMPLE_DECLARATION_H
#define EFFECTIVE_STL_PREFACE_CODE_EXAMPLE_DECLARATION_H

#include "Example/BookCpp/EffectiveSTL/EffectiveSTLDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveSTL
    {
        template <typename C>
        [[nodiscard]] bool LastGreaterThanFirst(const C& container) noexcept
        {
            if (container.empty())
                return false;

            const typename C::const_iterator begin(container.begin());
            typename C::const_iterator end(container.end());
            return *--end > *begin;
        }

        class Rational
        {
        };

        [[nodiscard]] bool operator==([[maybe_unused]] const Rational& lhs, [[maybe_unused]] const Rational& rhs) noexcept
        {
            return false;
        }
    }
}

#endif  // EFFECTIVE_STL_PREFACE_CODE_EXAMPLE_DECLARATION_H
