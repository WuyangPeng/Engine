///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/24 20:35)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM22_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM22_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms22
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms22Example final
                {
                public:
                    using ClassType = Terms22Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms22Example() noexcept;

                    void Widget0Example() const noexcept;
                    void Widget1Example() const;
                    void Widget2Example() const;
                    void SharedPtrExample() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM22_EXAMPLE_H
