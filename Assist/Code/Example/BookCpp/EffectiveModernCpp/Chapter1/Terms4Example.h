///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/05 12:25)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER1_TERM4_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER1_TERM4_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            namespace Terms4
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms4Example final
                {
                public:
                    using ClassType = Terms4Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms4Example() noexcept;

                    void Derivation() const;
                    void TypeIndex() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM4_EXAMPLE_H
