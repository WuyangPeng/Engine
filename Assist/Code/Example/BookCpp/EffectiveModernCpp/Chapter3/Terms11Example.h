///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/04 15:03)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM11_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM11_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms11
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms11Example final
                {
                public:
                    using ClassType = Terms11Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms11Example() noexcept;

                    void IsLucky0Example() const noexcept;
                    void IsLucky1Example() const noexcept;
                    void WidgetExample() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM11_EXAMPLE_H
