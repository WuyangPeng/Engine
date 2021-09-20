///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 15:23)

#ifndef EXPORT_TEST_EXPORT_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_EXPORT_DELAY_COPY_UNSHARED_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

DELAY_COPY_UNSHARED_EXPORT_IMPL(ExportDelayCopyUnsharedMacro, ExportDelayCopyUnsharedMacroImpl, CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExportDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ExportDelayCopyUnsharedMacro);

    public:
        explicit ExportDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_DELAY_COPY_UNSHARED_MACRO_H