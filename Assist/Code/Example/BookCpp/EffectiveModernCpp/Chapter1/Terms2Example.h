///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/04 22:18)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER1_TERM2_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER1_TERM2_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            namespace Terms2
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms2Example final
                {
                public:
                    using ClassType = Terms2Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms2Example() noexcept;

                    void Derivation() const noexcept;
                    void Derivation0() const noexcept;
                    void Derivation1() const noexcept;
                    void Derivation2() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM2_EXAMPLE_H
