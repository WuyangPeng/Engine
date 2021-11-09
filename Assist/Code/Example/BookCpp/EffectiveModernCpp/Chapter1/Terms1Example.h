///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 21:11)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER1_TERM1_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER1_TERM1_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            namespace Terms1
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms1Example final
                {
                public:
                    using ClassType = Terms1Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms1Example() noexcept;

                    void Derivation() const noexcept;
                    void Derivation0() const noexcept;
                    void Derivation1() const noexcept;
                    void Derivation2() const noexcept;
                    void Derivation3() const noexcept;
                    void Derivation4() const noexcept;
                    void Derivation5() const noexcept;
                    void ArrayDegeneratePointer() const noexcept;
                    void Derivation7() const noexcept;
                    void ArraySizeTest() const noexcept;
                    void Derivation8() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM1_EXAMPLE_H
