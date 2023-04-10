///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:38)

#ifndef CORE_TOOLS_THREADING_MUTEX_H
#define CORE_TOOLS_THREADING_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "DllMutex.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Mutex final : public DllMutex
    {
    public:
        using ClassType = Mutex;
        using ParentType = DllMutex;

    public:
        explicit Mutex(MutexCreate mutexCreate);
        ~Mutex() noexcept;
        Mutex(const Mutex&) = delete;
        Mutex& operator=(const Mutex&) = delete;
        Mutex(Mutex&& rhs) noexcept;
        Mutex& operator=(Mutex&& rhs) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept override;
        void Delete() noexcept override;
    };
}

#endif  // CORE_TOOLS_THREADING_MUTEX_H
