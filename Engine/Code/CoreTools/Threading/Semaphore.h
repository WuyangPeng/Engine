/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:03)

#ifndef CORE_TOOLS_THREADING_SEMAPHORE_H
#define CORE_TOOLS_THREADING_SEMAPHORE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

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

        NODISCARD int GetCurrentCount() const noexcept;
        NODISCARD int GetMaximumCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_SEMAPHORE_H
