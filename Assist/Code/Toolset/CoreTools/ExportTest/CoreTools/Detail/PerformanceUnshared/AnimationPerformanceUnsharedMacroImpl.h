///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 16:52)

#ifndef EXPORT_TEST_ANIMATION_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_ANIMATION_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "Animation/AnimationDll.h"

namespace Animation
{
    class ANIMATION_HIDDEN_DECLARE AnimationPerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = AnimationPerformanceUnsharedMacroImpl;

    public:
        explicit AnimationPerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept; 

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_ANIMATION_PERFORMANCE_UNSHARED_MACRO_IMPL_H