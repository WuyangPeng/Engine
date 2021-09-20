///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:37)

#ifndef EXPORT_TEST_USER_INTERFACE_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_USER_INTERFACE_COPY_UNSHARED_MACRO_IMPL_H

#include "UserInterface/UserInterfaceDll.h"

namespace UserInterface
{
    class USER_INTERFACE_HIDDEN_DECLARE UserInterfaceCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = UserInterfaceCopyUnsharedMacroImpl;

    public:
        explicit UserInterfaceCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_COPY_UNSHARED_MACRO_IMPL_H