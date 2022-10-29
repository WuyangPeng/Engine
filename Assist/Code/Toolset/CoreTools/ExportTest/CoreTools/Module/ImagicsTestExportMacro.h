///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/18 0:01)

#ifndef EXPORT_TEST_IMAGICS_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_IMAGICS_TEST_EXPORT_MACRO_H

#include "Imagics/ImagicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(Imagics, ImagicsTestExportMacroImpl, IMAGICS_DEFAULT_DECLARE);
IMAGICS_EXPORT(ImagicsTestExportMacroImpl, NON_COPY);
IMAGICS_EXPORT_UNIQUE_PTR(ImagicsTestExportMacro);

namespace Imagics
{
    class IMAGICS_DEFAULT_DECLARE ImagicsTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ImagicsTestExportMacro);

    public:
        explicit ImagicsTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_IMAGICS_TEST_EXPORT_MACRO_H