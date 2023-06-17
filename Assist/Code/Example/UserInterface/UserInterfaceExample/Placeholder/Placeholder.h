///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/12 20:00)

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
