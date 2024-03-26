/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:27)

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

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_COPY_UNSHARED_MACRO_H