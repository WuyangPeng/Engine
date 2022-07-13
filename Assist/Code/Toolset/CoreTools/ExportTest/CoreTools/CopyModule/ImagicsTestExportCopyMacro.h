///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:11)

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