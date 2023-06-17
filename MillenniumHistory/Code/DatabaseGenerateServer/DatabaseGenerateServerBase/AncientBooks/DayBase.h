/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_DAY_BASE_H
#define ANCIENT_BOOKS_DAY_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class DayBase
    {
    public:
        using ClassType = DayBase;

    public:
        DayBase() noexcept = default;
        explicit DayBase(int key) noexcept;

        virtual ~DayBase() noexcept = default;
        DayBase(const DayBase& rhs) noexcept = default;
        DayBase& operator=(const DayBase& rhs) noexcept = default;
        DayBase(DayBase&& rhs) noexcept = default;
        DayBase& operator=(DayBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual System::String GetName() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_DAY_BASE_H
