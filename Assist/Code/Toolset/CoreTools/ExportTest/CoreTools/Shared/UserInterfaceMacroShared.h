///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 15:00)

#ifndef EXPORT_TEST_USER_INTERFACE_MACRO_SHARED_H
#define EXPORT_TEST_USER_INTERFACE_MACRO_SHARED_H

#include "UserInterface/UserInterfaceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

USER_INTERFACE_SHARED_EXPORT_IMPL(UserInterfaceMacroSharedImpl);

namespace UserInterface
{
    class USER_INTERFACE_DEFAULT_DECLARE UserInterfaceMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(UserInterfaceMacroShared);

    public:
        explicit UserInterfaceMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_MACRO_SHARED_H