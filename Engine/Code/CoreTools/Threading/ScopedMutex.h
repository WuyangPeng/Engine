/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:03)

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
