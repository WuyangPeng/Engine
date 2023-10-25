/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_MONTH_BASE_H
#define ANCIENT_BOOKS_MONTH_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"


namespace AncientBooks
{
    class MonthBase
    {
    public:
        using ClassType = MonthBase;

        using String = System::String;

    public:
        MonthBase() noexcept = default;
        explicit MonthBase(int key) noexcept;

        virtual ~MonthBase() noexcept = default;
        MonthBase(const MonthBase& rhs) noexcept = default;
        MonthBase& operator=(const MonthBase& rhs) noexcept = default;
        MonthBase(MonthBase&& rhs) noexcept = default;
        MonthBase& operator=(MonthBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual String GetName() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_MONTH_BASE_H
