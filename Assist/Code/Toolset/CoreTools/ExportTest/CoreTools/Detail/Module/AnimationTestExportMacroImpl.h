///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 16:41)

#ifndef EXPORT_TEST_ANIMATION_TEST_EXPORT_MACRO_SHARE_IMPL_H
#define EXPORT_TEST_ANIMATION_TEST_EXPORT_MACRO_SHARE_IMPL_H

#include "Animation/AnimationDll.h"

namespace Animation
{
    class ANIMATION_HIDDEN_DECLARE AnimationTestExportMacroImpl final
    {
    public:
        using ClassType = AnimationTestExportMacroImpl;

    public:
        explicit AnimationTestExportMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_ANIMATION_TEST_EXPORT_MACRO_SHARE_IMPL_H