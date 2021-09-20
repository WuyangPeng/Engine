///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:35)

#ifndef EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_IMPL_H

#include "Animation/AnimationDll.h"

namespace Animation
{
    class ANIMATION_HIDDEN_DECLARE AnimationCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = AnimationCopyUnsharedMacroImpl;

    public:
        explicit AnimationCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_IMPL_H