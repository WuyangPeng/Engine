///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:09)

#ifndef EXPORT_TEST_CORE_TOOLS_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_CORE_TOOLS_COPY_UNSHARED_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

CORE_TOOLS_COPY_UNSHARED_EXPORT_IMPL(CoreToolsCopyUnsharedMacro, CoreToolsCopyUnsharedMacroImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CoreToolsCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(CoreToolsCopyUnsharedMacro);

    public:
        explicit CoreToolsCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_COPY_UNSHARED_MACRO_H