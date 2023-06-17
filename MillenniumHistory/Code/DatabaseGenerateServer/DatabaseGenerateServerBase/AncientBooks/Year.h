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

    public:
        explicit Year(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD System::String GetName() const override;

        NODISCARD int GetSexagenaryCycle() const noexcept override;
        NODISCARD std::shared_ptr<const SexagenaryCycleMappingType> GetSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int64_t GetReignTitle() const noexcept override;
        NODISCARD std::shared_ptr<const ReignTitleMappingType> GetReignTitle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetYear() const noexcept override;

        NODISCARD std::vector<int> GetUnorthodoxReignTitle() const override;
        NODISCARD int GetUnorthodoxReignTitleCount() const override;
        NODISCARD int GetUnorthodoxReignTitle(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetUnorthodoxReignTitleBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetUnorthodoxReignTitleEnd() const noexcept override;

        NODISCARD std::vector<int> GetUnorthodoxYear() const override;
        NODISCARD int GetUnorthodoxYearCount() const override;
        NODISCARD int GetUnorthodoxYear(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetUnorthodoxYearBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetUnorthodoxYearEnd() const noexcept override;

    private:
        int id;  // Id
        System::String name;  // ����
        int sexagenaryCycle;  // ��֧
        int64_t reignTitle;  // ���y��̖
        int year;  // ����
        std::vector<int> unorthodoxReignTitle;  // ����̖
        std::vector<int> unorthodoxYear;  // ����
    };
}

#endif  // ANCIENT_BOOKS_YEAR_H
