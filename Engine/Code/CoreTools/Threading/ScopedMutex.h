///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 17:31)

#ifndef CORE_TOOLS_THREADING_SCOPED_MUTEX_H
#define CORE_TOOLS_THREADING_SCOPED_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "ThreadingFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ScopedMutex
    {
    public:
        using ClassType = ScopedMutex;
        using MasterType = DllMutex;

    public:
        explicit ScopedMutex(MasterType& mutex);
        ~ScopedMutex() noexcept;
        ScopedMutex(const ScopedMutex& rhs) = delete;
        ScopedMutex operator=(const ScopedMutex& rhs) = delete;
        ScopedMutex(ScopedMutex&& rhs) noexcept = delete;
        ScopedMutex operator=(ScopedMutex&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        MasterType& mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_SCOPED_MUTEX_H
