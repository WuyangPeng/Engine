///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 22:19)

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
        int mCount;
    };
}

#endif  // EXPORT_TEST_ANIMATION_TEST_EXPORT_MACRO_SHARE_IMPL_H