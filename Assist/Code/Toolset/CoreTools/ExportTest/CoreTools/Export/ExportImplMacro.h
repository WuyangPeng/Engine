///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:52)

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