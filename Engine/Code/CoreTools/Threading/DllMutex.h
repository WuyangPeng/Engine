///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:38)

#ifndef CORE_TOOLS_THREADING_DLL_MUTEX_H
#define CORE_TOOLS_THREADING_DLL_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "Flags/MutexFlags.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(MutexImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DllMutex
    {
    public:
        using DllMutexImpl = MutexImpl;
        NON_COPY_TYPE_DECLARE(DllMutex);

    public:
        // 参数UseCriticalSection只对Windows平台有效，非Windows平台会自动转换成UseDefault。
        explicit DllMutex(MutexCreate mutexCreate);
        virtual ~DllMutex() noexcept = default;
        DllMutex(const DllMutex& rhs) = delete;
        DllMutex& operator=(const DllMutex& rhs) = delete;
        DllMutex(DllMutex&& rhs) noexcept;
        DllMutex& operator=(DllMutex&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD bool TryEnter();
        void Enter();
        void Leave() noexcept;

        virtual void Initialize();
        virtual void Delete() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_DLL_MUTEX_H
