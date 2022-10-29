///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 11:14)

#ifndef EXPORT_TEST_USER_INTERFACE_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_USER_INTERFACE_TEST_EXPORT_COPY_MACRO_H

#include "UserInterface/UserInterfaceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(UserInterface, UserInterfaceTestExportCopyMacroImpl, USER_INTERFACE_DEFAULT_DECLARE);
USER_INTERFACE_COPY_EXPORT(UserInterfaceTestExportCopyMacro, UserInterfaceTestExportCopyMacroImpl, COPY_UNSHARED);

namespace UserInterface
{
    class USER_INTERFACE_DEFAULT_DECLARE UserInterfaceTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(UserInterfaceTestExportCopyMacro);

    public:
        explicit UserInterfaceTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_TEST_EXPORT_COPY_MACRO_H