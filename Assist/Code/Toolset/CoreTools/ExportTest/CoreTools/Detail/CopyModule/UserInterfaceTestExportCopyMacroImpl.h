///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 11:46)

#ifndef EXPORT_TEST_USER_INTERFACE_TEST_EXPORT_COPY_MACRO_IMPL_H
#define EXPORT_TEST_USER_INTERFACE_TEST_EXPORT_COPY_MACRO_IMPL_H

#include "UserInterface/UserInterfaceDll.h"

namespace UserInterface
{
    class USER_INTERFACE_HIDDEN_DECLARE UserInterfaceTestExportCopyMacroImpl final
    {
    public:
        using ClassType = UserInterfaceTestExportCopyMacroImpl;

    public:
        explicit UserInterfaceTestExportCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_TEST_EXPORT_COPY_MACRO_IMPL_H