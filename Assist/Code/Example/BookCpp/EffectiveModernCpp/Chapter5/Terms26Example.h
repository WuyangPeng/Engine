///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/15 20:28)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM26_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM26_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms26
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms26Example final
                {
                public:
                    using ClassType = Terms26Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms26Example() noexcept;

                    void Log0Example() const;
                    void Log1Example() const;
                    void Log2Example() const;
                    void Person0Example() const;
                    void Person1Example() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM26_EXAMPLE_H