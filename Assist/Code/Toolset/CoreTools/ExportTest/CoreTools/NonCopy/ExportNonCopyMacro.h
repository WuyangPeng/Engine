///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 17:14)

#ifndef EXPORT_TEST_EXPORT_NON_COPY_MACRO_H
#define EXPORT_TEST_EXPORT_NON_COPY_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

NON_COPY_EXPORT_IMPL(ExportNonCopyMacroImpl, CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExportNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ExportNonCopyMacro);

    public:
        explicit ExportNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_NON_COPY_MACRO_H