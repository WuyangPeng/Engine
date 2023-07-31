///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:48)

#ifndef USER_INTERFACE_EXAMPLE_PLACEHOLDER_H
#define USER_INTERFACE_EXAMPLE_PLACEHOLDER_H

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace UserInterfaceExample
{
    class USER_INTERFACE_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // USER_INTERFACE_EXAMPLE_PLACEHOLDER_H
