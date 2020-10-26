//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 18:07)

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

        TryScopedMutex(const TryScopedMutex&) = delete;
        TryScopedMutex& operator=(const TryScopedMutex&) = delete;
        TryScopedMutex(TryScopedMutex&&) noexcept = delete;
        TryScopedMutex& operator=(TryScopedMutex&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsSuccess() const noexcept;

    private:
        MasterType& m_Mutex;
        bool m_IsSuccess;
    };
}

#endif  // CORE_TOOLS_THREADING_SCOPED_MUTEX_H
