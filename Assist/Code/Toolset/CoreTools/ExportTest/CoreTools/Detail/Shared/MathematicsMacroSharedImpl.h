///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 17:02)

#ifndef EXPORT_TEST_MATHEMATICS_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_MATHEMATICS_MACRO_SHARED_IMPL_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE MathematicsMacroSharedImpl final
    {
    public:
        using ClassType = MathematicsMacroSharedImpl;

    public:
        explicit MathematicsMacroSharedImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_MACRO_SHARED_IMPL_H