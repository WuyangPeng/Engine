///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/04 21:36)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM13_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM13_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms13
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms13Example final
                {
                public:
                    using ClassType = Terms13Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms13Example() noexcept;

                    void FindExample() const;
                    void ConstFindCpp98Example() const;
                    void ConstFindCpp11Example() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM13_EXAMPLE_H
