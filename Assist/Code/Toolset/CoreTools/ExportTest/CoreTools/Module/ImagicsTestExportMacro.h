///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:55)

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