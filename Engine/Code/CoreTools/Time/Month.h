/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:28)

#ifndef CORE_TOOLS_TIME_MONTH_H
#define CORE_TOOLS_TIME_MONTH_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Month final
    {
    public:
        using ClassType = Month;

    public:
        explicit Month(int month) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetMonth() const noexcept;

        NODISCARD static Month Jan() noexcept;
        NODISCARD static Month Feb() noexcept;
        NODISCARD static Month Mar() noexcept;
        NODISCARD static Month Apr() noexcept;
        NODISCARD static Month May() noexcept;
        NODISCARD static Month Jun() noexcept;
        NODISCARD static Month Jul() noexcept;
        NODISCARD static Month Aug() noexcept;
        NODISCARD static Month Sep() noexcept;
        NODISCARD static Month Oct() noexcept;
        NODISCARD static Month Nov() noexcept;
        NODISCARD static Month Dec() noexcept;

    private:
        int month;
    };
}

#endif  // CORE_TOOLS_TIME_MONTH_H
