//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 11:52)

#ifndef CORE_TOOLS_THREADING_DLL_MUTEX_H
#define CORE_TOOLS_THREADING_DLL_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "Flags/MutexFlags.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(MutexImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DllMutex
    {
    public:
        using DllMutexImpl = MutexImpl;
        NON_COPY_CLASSES_TYPE_DECLARE(DllMutex);

    public:
        // 参数UseCriticalSection只对Windows平台有效，非Windows平台会自动转换成UseDefault。
        explicit DllMutex(MutexCreate mutexCreate = MutexCreate::UseCriticalSection);
        virtual ~DllMutex() noexcept = default;
        DllMutex(const DllMutex&) = delete;
        virtual DllMutex& operator=(const DllMutex&) = delete;
        DllMutex(DllMutex&& rhs) noexcept;
        virtual DllMutex& operator=(DllMutex&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] bool TryEnter();
        void Enter();
        void Leave() noexcept;

        virtual void Initialize();
        virtual void Delete() noexcept;

    private:
        IMPL_TYPE_DECLARE(DllMutex);
    };
}

#endif  // CORE_TOOLS_THREADING_DLL_MUTEX_H
