/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:11)

#ifndef CORE_TOOLS_THREADING_THREAD_GUARD_H
#define CORE_TOOLS_THREADING_THREAD_GUARD_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <thread>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ThreadGuardImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ThreadGuard final
    {
    public:
        NON_COPY_TYPE_DECLARE(ThreadGuard);

    public:
        template <typename Function, typename... Args>
        explicit ThreadGuard(Function&& function, Args&&... args);

        CLASS_INVARIANT_DECLARE;

    private:
        explicit ThreadGuard(std::thread thread);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_GUARD_H
