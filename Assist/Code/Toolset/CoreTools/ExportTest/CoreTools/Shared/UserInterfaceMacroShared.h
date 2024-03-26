/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:56)

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