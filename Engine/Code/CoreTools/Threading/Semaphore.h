//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 18:05)

#ifndef CORE_TOOLS_THREADING_SEMAPHORE_H
#define CORE_TOOLS_THREADING_SEMAPHORE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
 

CORE_TOOLS_NON_COPY_EXPORT_IMPL(SemaphoreImpl);


namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Semaphore final 
    {
    public:
        NON_COPY_TYPE_DECLARE(Semaphore);

    public:
        Semaphore(int initialCount, int maximumCount);
        ~Semaphore() noexcept = default;
        Semaphore(const Semaphore& rhs) noexcept = delete;
        Semaphore& operator=(const Semaphore& rhs) noexcept = delete;
        Semaphore(Semaphore&& rhs) noexcept = delete;
        Semaphore& operator=(Semaphore&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Release(int releaseCount);
        void Wait();

        [[nodiscard]] int GetCurrentCount() const noexcept;
        [[nodiscard]] int GetMaximumCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_SEMAPHORE_H
