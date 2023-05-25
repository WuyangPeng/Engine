///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.9 (2023/05/25 11:29)

#ifndef DATABASE_EXAMPLE_PLACEHOLDER_H
#define DATABASE_EXAMPLE_PLACEHOLDER_H

#include "Example/Database/DatabaseExample/DatabaseExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace DatabaseExample
{
    class DATABASE_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // DATABASE_EXAMPLE_PLACEHOLDER_H
