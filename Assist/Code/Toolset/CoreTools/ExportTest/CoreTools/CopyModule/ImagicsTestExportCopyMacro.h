///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 16:06)

#ifndef EXPORT_TEST_IMAGICS_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_IMAGICS_TEST_EXPORT_COPY_MACRO_H

#include "Imagics/ImagicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(Imagics, ImagicsTestExportCopyMacroImpl, IMAGICS_DEFAULT_DECLARE);
IMAGICS_COPY_EXPORT(ImagicsTestExportCopyMacro, ImagicsTestExportCopyMacroImpl, COPY_UNSHARED);

namespace Imagics
{
    class IMAGICS_DEFAULT_DECLARE ImagicsTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ImagicsTestExportCopyMacro);

    public:
        explicit ImagicsTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_IMAGICS_TEST_EXPORT_COPY_MACRO_H