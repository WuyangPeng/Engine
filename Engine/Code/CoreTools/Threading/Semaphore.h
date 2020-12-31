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

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(SemaphoreImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Semaphore final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Semaphore);

    public:
        Semaphore(int initialCount, int maximumCount);

        CLASS_INVARIANT_DECLARE;

        void Release(int releaseCount);
        void Wait();

        [[nodiscard]] int GetCurrentCount() const noexcept;
        [[nodiscard]] int GetMaximumCount() const noexcept;

    private:
        IMPL_TYPE_DECLARE(Semaphore);
    };
}

#endif  // CORE_TOOLS_THREADING_SEMAPHORE_H
