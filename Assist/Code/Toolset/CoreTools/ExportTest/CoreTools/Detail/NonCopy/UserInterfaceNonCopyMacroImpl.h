///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 14:46)

#ifndef EXPORT_TEST_USER_INTERFACE_NON_COPY_MACRO_IMPL_H
#define EXPORT_TEST_USER_INTERFACE_NON_COPY_MACRO_IMPL_H

#include "UserInterface/UserInterfaceDll.h"

namespace UserInterface
{
    class USER_INTERFACE_HIDDEN_DECLARE UserInterfaceNonCopyMacroImpl final
    {
    public:
        using ClassType = UserInterfaceNonCopyMacroImpl;

    public:
        explicit UserInterfaceNonCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_NON_COPY_MACRO_IMPL_H