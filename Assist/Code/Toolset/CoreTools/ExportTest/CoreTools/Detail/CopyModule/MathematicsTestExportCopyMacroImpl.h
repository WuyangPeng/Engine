///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/17 11:40)

#ifndef EXPORT_TEST_MATHEMATICS_TEST_EXPORT_COPY_MACRO_IMPL_H
#define EXPORT_TEST_MATHEMATICS_TEST_EXPORT_COPY_MACRO_IMPL_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE MathematicsTestExportCopyMacroImpl final
    {
    public:
        using ClassType = MathematicsTestExportCopyMacroImpl;

    public:
        explicit MathematicsTestExportCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_TEST_EXPORT_COPY_MACRO_IMPL_H