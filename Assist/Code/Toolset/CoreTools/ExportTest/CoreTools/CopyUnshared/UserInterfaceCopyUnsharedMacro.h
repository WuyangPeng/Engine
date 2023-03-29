///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 15:30)

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

         NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_COPY_UNSHARED_MACRO_H