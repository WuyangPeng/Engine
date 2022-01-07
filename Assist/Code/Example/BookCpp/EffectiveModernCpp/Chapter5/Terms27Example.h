///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/16 20:44)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM27_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM27_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms27
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms27Example final
                {
                public:
                    using ClassType = Terms27Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms27Example() noexcept;

                    void Person0Example() const;
                    void Person1Example() const noexcept;
                    void Person2Example() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM27_EXAMPLE_H
