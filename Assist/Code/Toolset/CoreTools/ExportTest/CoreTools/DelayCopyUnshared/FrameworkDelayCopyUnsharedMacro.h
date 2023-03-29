///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 15:29)

#ifndef EXPORT_TEST_FRAMEWORK_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_FRAMEWORK_DELAY_COPY_UNSHARED_MACRO_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

FRAMEWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(FrameworkDelayCopyUnsharedMacro, FrameworkDelayCopyUnsharedMacroImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE FrameworkDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(FrameworkDelayCopyUnsharedMacro);

    public:
        explicit FrameworkDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_DELAY_COPY_UNSHARED_MACRO_H