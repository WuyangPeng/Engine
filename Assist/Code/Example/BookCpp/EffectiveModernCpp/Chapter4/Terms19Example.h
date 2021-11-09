///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 21:10)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM19_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM19_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms19
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms19Example final
                {
                public:
                    using ClassType = Terms19Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms19Example() noexcept;

                    void SharedPtr0Example() const;
                    void SharedPtr1Example() const;
                    void ErrorSharedPtrExample() const;
                    void SharedPtr2Example() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM18_EXAMPLE_H
