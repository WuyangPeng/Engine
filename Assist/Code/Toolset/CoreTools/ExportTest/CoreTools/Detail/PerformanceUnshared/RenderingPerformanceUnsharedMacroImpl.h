///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/17 23:48)

#ifndef EXPORT_TEST_RENDERING_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_RENDERING_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingPerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = RenderingPerformanceUnsharedMacroImpl;

    public:
        explicit RenderingPerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept; 

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_RENDERING_PERFORMANCE_UNSHARED_MACRO_IMPL_H