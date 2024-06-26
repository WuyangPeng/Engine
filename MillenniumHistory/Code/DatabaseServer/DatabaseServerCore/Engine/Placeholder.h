/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef DATABASE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define DATABASE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "DatabaseServer/DatabaseServerCore/DatabaseServerCoreDll.h"

#include "DatabaseServer/DatabaseServerCore/Helper/ExportMacro.h"

namespace DatabaseServerCore
{
    class DATABASE_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // DATABASE_SERVER_CORE_ENGINE_PLACEHOLDER_H