///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.0 (2021/07/17 11:39)

#ifndef SYSTEM_EXAMPLE_PLACEHOLDER_H
#define SYSTEM_EXAMPLE_PLACEHOLDER_H

#include "Example/System/SystemExample/SystemExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace SystemExample
{
    class SYSTEM_EXAMPLE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SYSTEM_EXAMPLE_PLACEHOLDER_H
