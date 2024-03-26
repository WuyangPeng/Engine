/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:36)

#ifndef EXPORT_TEST_RENDERING_DELAY_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_RENDERING_DELAY_COPY_UNSHARED_MACRO_IMPL_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingDelayCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = RenderingDelayCopyUnsharedMacroImpl;

    public:
        explicit RenderingDelayCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_RENDERING_DELAY_COPY_UNSHARED_MACRO_IMPL_H