///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:52)

#ifndef EXPORT_TEST_EXPORT_COPY_IMPL_MACRO_H
#define EXPORT_TEST_EXPORT_COPY_IMPL_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(CoreTools, ExportCopyImplMacroImpl, CORE_TOOLS_DEFAULT_DECLARE);
EXPORT_COPY_IMPL(ExportCopyImplMacro, ExportCopyImplMacroImpl, CORE_TOOLS, COPY_UNSHARED);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExportCopyImplMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ExportCopyImplMacro);

    public:
        explicit ExportCopyImplMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_COPY_IMPL_MACRO_H