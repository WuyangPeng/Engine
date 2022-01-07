///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/17 21:04)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM28_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM28_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms28
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms28Example final
                {
                public:
                    using ClassType = Terms28Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms28Example() noexcept;

                    void Widget0Example() const noexcept;
                    void RefExample() const noexcept;
                    void AutoExample() const noexcept;
                    void Widget1Example() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM28_EXAMPLE_H
