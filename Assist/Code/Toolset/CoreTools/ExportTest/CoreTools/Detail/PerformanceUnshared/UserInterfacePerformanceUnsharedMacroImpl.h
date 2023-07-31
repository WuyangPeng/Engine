///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 15:35)

#ifndef EXPORT_TEST_USER_INTERFACE_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_USER_INTERFACE_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "UserInterface/UserInterfaceDll.h"

namespace UserInterface
{
    class USER_INTERFACE_HIDDEN_DECLARE UserInterfacePerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = UserInterfacePerformanceUnsharedMacroImpl;

    public:
        explicit UserInterfacePerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept; 

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_USER_INTERFACE_PERFORMANCE_UNSHARED_MACRO_IMPL_H