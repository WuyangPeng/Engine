/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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
