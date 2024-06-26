/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:27)

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