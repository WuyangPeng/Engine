//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 18:04)

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
        ScopedMutex(const ScopedMutex&) = delete;
        ScopedMutex operator=(const ScopedMutex&) = delete;
        ScopedMutex(ScopedMutex&&) noexcept = delete;
        ScopedMutex operator=(ScopedMutex&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        MasterType& m_Mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_SCOPED_MUTEX_H
