///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/18 21:32)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM29_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM29_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms29
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms29Example final
                {
                public:
                    using ClassType = Terms29Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms29Example() noexcept;

                    void MoveExample() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM29_EXAMPLE_H