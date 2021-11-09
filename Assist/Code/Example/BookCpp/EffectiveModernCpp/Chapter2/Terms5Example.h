///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/18 21:51)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER2_TERM5_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER2_TERM5_EXAMPLE_H

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
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms5Example final
                {
                public:
                    using ClassType = Terms5Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms5Example() noexcept;

                    void AutoExample() const noexcept;
                    void LambadExample() const noexcept;
                    void FunctionExample() const;
                    void TypeExample() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER2_TERM5_EXAMPLE_H
