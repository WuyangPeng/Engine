///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 16:42)

#ifndef EXPORT_TEST_MATHEMATICS_TEST_EXPORT_MACRO_IMPL_H
#define EXPORT_TEST_MATHEMATICS_TEST_EXPORT_MACRO_IMPL_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE MathematicsTestExportMacroImpl final
    {
    public:
        using ClassType = MathematicsTestExportMacroImpl;

    public:
        explicit MathematicsTestExportMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_TEST_EXPORT_MACRO_IMPL_H