/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_REIGN_TITLE_H
#define ANCIENT_BOOKS_REIGN_TITLE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "ReignTitleBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class ReignTitle final : public ReignTitleBase
    {
    public:
        using ClassType = ReignTitle;
        using ParentType = ReignTitleBase;

    public:
        explicit ReignTitle(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int64_t GetKey() const noexcept override;

        NODISCARD int64_t GetId() const noexcept override;

        NODISCARD System::String GetName() const override;

        NODISCARD std::vector<int> GetEmperor() const override;
        NODISCARD int GetEmperorCount() const override;
        NODISCARD int GetEmperor(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetEmperorBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetEmperorEnd() const noexcept override;

        NODISCARD int GetSerial() const noexcept override;

        NODISCARD int GetBeginYear() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetBeginYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginMonth() const noexcept override;
        NODISCARD std::shared_ptr<const MonthMappingType> GetBeginMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginSexagenaryCycle() const noexcept override;
        NODISCARD std::shared_ptr<const SexagenaryCycleMappingType> GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginDay() const noexcept override;
        NODISCARD std::shared_ptr<const DayMappingType> GetBeginDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndYear() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetEndYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndMonth() const noexcept override;
        NODISCARD std::shared_ptr<const MonthMappingType> GetEndMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndSexagenaryCycle() const noexcept override;
        NODISCARD std::shared_ptr<const SexagenaryCycleMappingType> GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndDay() const noexcept override;
        NODISCARD std::shared_ptr<const DayMappingType> GetEndDay(const AncientBooksContainer& csvContainer) const override;

    private:
        int64_t id;  // Id
        System::String name;  // ����
        std::vector<int> emperor;  // �ʵ�
        int serial;  // ��̖
        int beginYear;  // ��ʼ��
        int beginMonth;  // ��ʼ��
        int beginSexagenaryCycle;  // ��ʼ��֧��
        int beginDay;  // ��ʼ��
        int endYear;  // ������
        int endMonth;  // ������
        int endSexagenaryCycle;  // ������֧��
        int endDay;  // ������
    };
}

#endif  // ANCIENT_BOOKS_REIGN_TITLE_H
