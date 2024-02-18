/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/25 09:57)

#ifndef CORE_TOOLS_TIME_TIMER_H
#define CORE_TOOLS_TIME_TIMER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_COPY_UNSHARED_EXPORT_IMPL(Timer, TimerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Timer final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Timer);

    public:
        // ����߷ֱ��ʼ�ʱ����64λ����
        NODISCARD static Timer Create();

    private:
        explicit Timer(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        // ��ȡ����ڳ�ʼʱ��ĵ�ǰʱ�䡣
        NODISCARD int64_t GetNanoseconds() const noexcept;
        NODISCARD int64_t GetMicroseconds() const noexcept;
        NODISCARD int64_t GetMilliseconds() const noexcept;
        NODISCARD double GetSeconds() const noexcept;

        // ����ʹ��ǰʱ��Ϊ��ʼʱ�䡣
        void Reset() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TIME_TIMER_H