///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/01 18:01)

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
