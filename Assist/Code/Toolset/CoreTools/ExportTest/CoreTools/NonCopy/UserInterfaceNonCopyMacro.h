///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:58)

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