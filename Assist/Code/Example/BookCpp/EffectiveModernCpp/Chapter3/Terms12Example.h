///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/04 16:10)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM12_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM12_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms12
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms12Example final
                {
                public:
                    using ClassType = Terms12Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms12Example() noexcept;

                    void DoWorkExample() const;
                    void Widget0Example() const;
                    void Widget1Example() const;
                    void Widget2Example() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM12_EXAMPLE_H
