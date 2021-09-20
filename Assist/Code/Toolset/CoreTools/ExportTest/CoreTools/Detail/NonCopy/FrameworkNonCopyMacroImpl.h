///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 16:43)

#ifndef EXPORT_TEST_FRAMEWORK_NON_COPY_MACRO_IMPL_H
#define EXPORT_TEST_FRAMEWORK_NON_COPY_MACRO_IMPL_H

#include "Framework/FrameworkDll.h"

#include <memory>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE FrameworkNonCopyMacroImpl final
    {
    public:
        using ClassType = FrameworkNonCopyMacroImpl;

    public:
        explicit FrameworkNonCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_NON_COPY_MACRO_IMPL_H