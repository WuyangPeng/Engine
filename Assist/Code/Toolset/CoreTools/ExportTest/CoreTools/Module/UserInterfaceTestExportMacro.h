///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 16:56)

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