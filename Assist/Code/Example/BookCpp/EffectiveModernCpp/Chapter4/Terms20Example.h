///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/10 21:10)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM20_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM20_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms20
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms20Example final
                {
                public:
                    using ClassType = Terms20Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms20Example() noexcept;

                    void WeakPtrExample() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM18_EXAMPLE_H
