///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 14:10)

#ifndef EXPORT_TEST_USER_INTERFACE_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_USER_INTERFACE_COPY_UNSHARED_MACRO_H

#include "UserInterface/UserInterfaceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

USER_INTERFACE_COPY_UNSHARED_EXPORT_IMPL(UserInterfaceCopyUnsharedMacro, UserInterfaceCopyUnsharedMacroImpl);

namespace UserInterface
{
    class USER_INTERFACE_DEFAULT_DECLARE UserInterfaceCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(UserInterfaceCopyUnsharedMacro);

    public:
        explicit UserInterfaceCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_COPY_UNSHARED_MACRO_H