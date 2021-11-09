///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/05 14:26)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM15_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM15_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms15
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms15Example final
                {
                public:
                    using ClassType = Terms15Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms15Example() noexcept;

                    void ConstexprExample() const noexcept;
                    void ConstExample() const noexcept;
                    void Pow0Example() const noexcept;
                    void Pow1Example() const;
                    void Point0Example() const noexcept;
                    void Point1Example() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM15_EXAMPLE_H
