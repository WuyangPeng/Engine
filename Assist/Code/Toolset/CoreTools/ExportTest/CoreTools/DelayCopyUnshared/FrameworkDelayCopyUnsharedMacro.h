///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 16:24)

#ifndef EXPORT_TEST_FRAMEWORK_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_FRAMEWORK_DELAY_COPY_UNSHARED_MACRO_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

FRAMEWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(FrameworkDelayCopyUnsharedMacro, FrameworkDelayCopyUnsharedMacroImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE FrameworkDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(FrameworkDelayCopyUnsharedMacro);

    public:
        explicit FrameworkDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_DELAY_COPY_UNSHARED_MACRO_H