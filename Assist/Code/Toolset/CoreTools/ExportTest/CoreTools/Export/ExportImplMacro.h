///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/17 14:43)

#ifndef EXPORT_TEST_EXPORT_IMPL_MACRO_H
#define EXPORT_TEST_EXPORT_IMPL_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(CoreTools, ExportImplMacroImpl, CORE_TOOLS_DEFAULT_DECLARE);
EXPORT_IMPL(ExportImplMacroImpl, CORE_TOOLS, NON_COPY);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExportImplMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ExportImplMacro);

    public:
        explicit ExportImplMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_IMPL_MACRO_H