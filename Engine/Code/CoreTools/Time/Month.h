///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/16 21:51)

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
