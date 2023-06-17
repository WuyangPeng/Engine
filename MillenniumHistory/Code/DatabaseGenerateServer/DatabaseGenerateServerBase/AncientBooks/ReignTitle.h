/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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
        System::String name;  // 名称
        std::vector<int> emperor;  // 皇帝
        int serial;  // 序號
        int beginYear;  // 开始年
        int beginMonth;  // 开始月
        int beginSexagenaryCycle;  // 开始干支日
        int beginDay;  // 开始日
        int endYear;  // 结束年
        int endMonth;  // 结束月
        int endSexagenaryCycle;  // 结束干支日
        int endDay;  // 结束日
    };
}

#endif  // ANCIENT_BOOKS_REIGN_TITLE_H
