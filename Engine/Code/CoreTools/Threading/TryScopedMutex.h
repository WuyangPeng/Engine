///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 1:22)

#ifndef CORE_TOOLS_THREADING_TRY_SCOPED_MUTEX_H
#define CORE_TOOLS_THREADING_TRY_SCOPED_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "ThreadingFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE TryScopedMutex final
    {
    public:
        using ClassType = TryScopedMutex;
        using MasterType = DllMutex;

    public:
        explicit TryScopedMutex(MasterType& mutex);
        ~TryScopedMutex() noexcept;

        TryScopedMutex(const TryScopedMutex& rhs) = delete;
        TryScopedMutex& operator=(const TryScopedMutex& rhs) = delete;
        TryScopedMutex(TryScopedMutex&& rhs) noexcept = delete;
        TryScopedMutex& operator=(TryScopedMutex&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsSuccess() const noexcept;

    private:
        MasterType& mutex;
        bool isSuccess;
    };
}

#endif  // CORE_TOOLS_THREADING_SCOPED_MUTEX_H
