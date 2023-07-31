///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:58)

#ifndef EXPORT_TEST_USER_INTERFACE_NON_COPY_MACRO_H
#define EXPORT_TEST_USER_INTERFACE_NON_COPY_MACRO_H

#include "UserInterface/UserInterfaceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

USER_INTERFACE_NON_COPY_EXPORT_IMPL(UserInterfaceNonCopyMacroImpl);

namespace UserInterface
{
    class USER_INTERFACE_DEFAULT_DECLARE UserInterfaceNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(UserInterfaceNonCopyMacro);

    public:
        explicit UserInterfaceNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_NON_COPY_MACRO_H