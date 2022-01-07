///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/13 10:53)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            class Widget;

            // 形参总是左值，即使其型别是右值引用。
            void F(Widget&& w);
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_EXAMPLE_H
