///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/02 21:54)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER6_TERM33_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER6_TERM33_EXAMPLE_H

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
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms33Example final
                {
                public:
                    using ClassType = Terms33Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms33Example() noexcept;

                    void Lambda0Example() const noexcept;
                    void Lambda1Example() const noexcept;
                    void Lambda2Example() const noexcept;
                    void Lambda3Example() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER6_TERM33_EXAMPLE_H
