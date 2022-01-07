///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/29 21:30)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER6_TERM31_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER6_TERM31_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter6
        {
            namespace Terms31
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms31Example final
                {
                public:
                    using ClassType = Terms31Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms31Example() noexcept;

                    void AddDivisorFilterExample() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER6_TERM31_EXAMPLE_H
