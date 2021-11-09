///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/07 14:04)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM17_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM17_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms17
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms17Example final
                {
                public:
                    using ClassType = Terms17Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms17Example() noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM17_EXAMPLE_H
