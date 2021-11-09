///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/18 21:51)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM16_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM16_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "Terms16.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms16
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms16Example final
                {
                public:
                    using ClassType = Terms16Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms16Example() noexcept;

                    void PolynomialExample() const;

                    void Thread0(const Example1::Polynomial& p) const;
                    void Thread1(const Example1::Polynomial& p) const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM16_EXAMPLE_H
