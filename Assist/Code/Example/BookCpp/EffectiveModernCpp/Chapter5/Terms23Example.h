///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/11/03 22:39)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM23_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM23_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms23
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms23Example final
                {
                public:
                    using ClassType = Terms23Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms23Example() noexcept;

                    void LogExample() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM23_EXAMPLE_H