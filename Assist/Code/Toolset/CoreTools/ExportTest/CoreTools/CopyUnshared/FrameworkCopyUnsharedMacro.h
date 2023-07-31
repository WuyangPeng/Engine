///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:54)

#ifndef EXPORT_TEST_FRAMEWORK_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_FRAMEWORK_COPY_UNSHARED_MACRO_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

FRAMEWORK_COPY_UNSHARED_EXPORT_IMPL(FrameworkCopyUnsharedMacro, FrameworkCopyUnsharedMacroImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE FrameworkCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(FrameworkCopyUnsharedMacro);

    public:
        explicit FrameworkCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_COPY_UNSHARED_MACRO_H