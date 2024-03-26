/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:56)

#ifndef EXPORT_TEST_FRAMEWORK_MACRO_SHARED_H
#define EXPORT_TEST_FRAMEWORK_MACRO_SHARED_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

FRAMEWORK_SHARED_EXPORT_IMPL(FrameworkMacroSharedImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE FrameworkMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(FrameworkMacroShared);

    public:
        explicit FrameworkMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_MACRO_SHARED_H