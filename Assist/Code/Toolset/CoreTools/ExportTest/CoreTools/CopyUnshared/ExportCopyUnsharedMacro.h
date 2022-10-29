///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 11:16)

#ifndef EXPORT_TEST_EXPORT_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_EXPORT_COPY_UNSHARED_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

COPY_UNSHARED_EXPORT_IMPL(ExportCopyUnsharedMacro, ExportCopyUnsharedMacroImpl, CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExportCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ExportCopyUnsharedMacro);

    public:
        explicit ExportCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_COPY_UNSHARED_MACRO_H