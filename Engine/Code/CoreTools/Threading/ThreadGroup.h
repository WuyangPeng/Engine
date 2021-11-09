///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/02 11:27)

#ifndef CORE_TOOLS_THREADING_THREAD_GROUP_H
#define CORE_TOOLS_THREADING_THREAD_GROUP_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <thread>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ThreadGroupImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ThreadGroup final
    {
    public:
        NON_COPY_TYPE_DECLARE(ThreadGroup);

    public:
        explicit ThreadGroup(MAYBE_UNUSED DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        template <typename Function, typename... Args>
        void AddThread(Function&& function, Args&&... args);

    private:
        void AddThread(std::thread thread);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_GROUP_H
