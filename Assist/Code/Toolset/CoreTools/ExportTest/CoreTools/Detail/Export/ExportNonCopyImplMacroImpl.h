///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 16:45)

#ifndef EXPORT_TEST_EXPORT_NON_COPY_IMPL_MACRO_IMPL_H
#define EXPORT_TEST_EXPORT_NON_COPY_IMPL_MACRO_IMPL_H

#include "CoreTools/Helper/UserMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

namespace ExportTest
{
    class EXPORT_TEST_HIDDEN_DECLARE ExportNonCopyImplMacroImpl final
    {
    public:
        using ClassType = ExportNonCopyImplMacroImpl;

    public:
        explicit ExportNonCopyImplMacroImpl() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // EXPORT_TEST_EXPORT_NON_COPY_IMPL_MACRO_IMPL_H