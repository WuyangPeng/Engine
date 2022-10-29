///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/17 23:46)

#ifndef EXPORT_TEST_FRAMEWORK_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_FRAMEWORK_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "Framework/FrameworkDll.h"

#include <memory>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE FrameworkPerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = FrameworkPerformanceUnsharedMacroImpl;

    public:
        explicit FrameworkPerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept; 

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_PERFORMANCE_UNSHARED_MACRO_IMPL_H