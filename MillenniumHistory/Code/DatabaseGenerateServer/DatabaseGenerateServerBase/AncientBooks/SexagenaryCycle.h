/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_SEXAGENARY_CYCLE_H
#define ANCIENT_BOOKS_SEXAGENARY_CYCLE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "SexagenaryCycleBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class SexagenaryCycle final : public SexagenaryCycleBase
    {
    public:
        using ClassType = SexagenaryCycle;
        using ParentType = SexagenaryCycleBase;

    public:
        explicit SexagenaryCycle(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD System::String GetHeavenly() const override;

        NODISCARD System::String GetBranch() const override;

        NODISCARD System::String GetName() const override;

    private:
        int id;  // Id
        System::String heavenly;  // ���
        System::String branch;  // ��֧
        System::String name;  // ����
    };
}

#endif  // ANCIENT_BOOKS_SEXAGENARY_CYCLE_H
