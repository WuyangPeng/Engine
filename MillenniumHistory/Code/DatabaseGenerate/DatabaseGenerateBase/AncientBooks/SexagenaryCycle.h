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

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit SexagenaryCycle(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD String GetHeavenly() const override;

        NODISCARD String GetBranch() const override;

        NODISCARD String GetName() const override;

    private:
        int id;  // Id
        String heavenly;  // ���
        String branch;  // ��֧
        String name;  // ����
    };
}

#endif  // ANCIENT_BOOKS_SEXAGENARY_CYCLE_H
