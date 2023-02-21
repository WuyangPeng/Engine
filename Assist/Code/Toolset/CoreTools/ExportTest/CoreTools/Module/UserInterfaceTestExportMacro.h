///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 17:13)

#ifndef EXPORT_TEST_USER_INTERFACE_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_USER_INTERFACE_TEST_EXPORT_MACRO_H

#include "UserInterface/UserInterfaceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(UserInterface, UserInterfaceTestExportMacroImpl, USER_INTERFACE_DEFAULT_DECLARE);
USER_INTERFACE_EXPORT(UserInterfaceTestExportMacroImpl, NON_COPY);
USER_INTERFACE_EXPORT_UNIQUE_PTR(UserInterfaceTestExportMacro);

namespace UserInterface
{
    class USER_INTERFACE_DEFAULT_DECLARE UserInterfaceTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(UserInterfaceTestExportMacro);

    public:
        explicit UserInterfaceTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_TEST_EXPORT_MACRO_H