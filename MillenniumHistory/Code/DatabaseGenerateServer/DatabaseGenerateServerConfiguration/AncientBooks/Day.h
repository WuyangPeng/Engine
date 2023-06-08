/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_DAY_H
#define ANCIENT_BOOKS_DAY_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "DayBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Day final : public DayBase
    {
    public:
        using ClassType = Day;
        using ParentType = DayBase;

    public:
        explicit Day(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD System::String GetName() const override;

    private:
        int id;  // Id
        System::String name;  // ����
    };
}

#endif  // ANCIENT_BOOKS_DAY_H
