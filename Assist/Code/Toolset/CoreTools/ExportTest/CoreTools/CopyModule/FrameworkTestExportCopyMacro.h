///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 16:06)

#ifndef EXPORT_TEST_FRAMEWORK_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_FRAMEWORK_TEST_EXPORT_COPY_MACRO_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

EXPORT_SHARED_PTR(Framework, FrameworkTestExportCopyMacroImpl, FRAMEWORK_DEFAULT_DECLARE);
FRAMEWORK_COPY_EXPORT(FrameworkTestExportCopyMacro, FrameworkTestExportCopyMacroImpl, DELAY_COPY_UNSHARED);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE FrameworkTestExportCopyMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(FrameworkTestExportCopyMacro);

    public:
        explicit FrameworkTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_TEST_EXPORT_COPY_MACRO_H