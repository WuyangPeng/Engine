/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_YEAR_H
#define ANCIENT_BOOKS_YEAR_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "YearBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Year final : public YearBase
    {
    public:
        using ClassType = Year;
        using ParentType = YearBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Year(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD String GetName() const override;

        NODISCARD int GetSexagenaryCycle() const noexcept override;
        NODISCARD ConstSexagenaryCycleSharedPtr GetSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int64_t GetReignTitle() const noexcept override;
        NODISCARD ConstReignTitleSharedPtr GetReignTitle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetYear() const noexcept override;

        NODISCARD Int64Container GetUnorthodoxReignTitle() const override;
        NODISCARD int GetUnorthodoxReignTitleCount() const override;
        NODISCARD int64_t GetUnorthodoxReignTitle(int index) const override;
        NODISCARD Int64ContainerConstIter GetUnorthodoxReignTitleBegin() const noexcept override;
        NODISCARD Int64ContainerConstIter GetUnorthodoxReignTitleEnd() const noexcept override;
        NODISCARD ReignTitleContainer GetUnorthodoxReignTitle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD IntContainer GetUnorthodoxYear() const override;
        NODISCARD int GetUnorthodoxYearCount() const override;
        NODISCARD int GetUnorthodoxYear(int index) const override;
        NODISCARD IntContainerConstIter GetUnorthodoxYearBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetUnorthodoxYearEnd() const noexcept override;
        NODISCARD YearContainer GetUnorthodoxYear(const AncientBooksContainer& csvContainer) const override;


    private:
        int id;  // Id
        String name;  // ����
        int sexagenaryCycle;  // ��֧
        int64_t reignTitle;  // ���y��̖
        int year;  // ����
        Int64Container unorthodoxReignTitle;  // ����̖
        IntContainer unorthodoxYear;  // ����
    };
}

#endif  // ANCIENT_BOOKS_YEAR_H
