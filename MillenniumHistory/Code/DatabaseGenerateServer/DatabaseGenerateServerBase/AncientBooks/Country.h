/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_COUNTRY_H
#define ANCIENT_BOOKS_COUNTRY_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "CountryBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Country final : public CountryBase
    {
    public:
        using ClassType = Country;
        using ParentType = CountryBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Country(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetImperialCourt() const noexcept override;
        NODISCARD ConstImperialCourtSharedPtr GetImperialCourt(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetCategory() const override;

        NODISCARD int GetBeginYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetBeginYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginMonth() const noexcept override;
        NODISCARD ConstMonthSharedPtr GetBeginMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginSexagenaryCycle() const noexcept override;
        NODISCARD ConstSexagenaryCycleSharedPtr GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBeginDay() const noexcept override;
        NODISCARD ConstDaySharedPtr GetBeginDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetEndYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndMonth() const noexcept override;
        NODISCARD ConstMonthSharedPtr GetEndMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndSexagenaryCycle() const noexcept override;
        NODISCARD ConstSexagenaryCycleSharedPtr GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEndDay() const noexcept override;
        NODISCARD ConstDaySharedPtr GetEndDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD StringContainer GetUnansweredQuestion() const override;
        NODISCARD int GetUnansweredQuestionCount() const override;
        NODISCARD String GetUnansweredQuestion(int index) const override;
        NODISCARD StringContainerConstIter GetUnansweredQuestionBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetUnansweredQuestionEnd() const noexcept override;


    private:
        int id;  // Id
        int imperialCourt;  // 王朝
        String category;  // 名称
        int beginYear;  // 开始年
        int beginMonth;  // 开始月
        int beginSexagenaryCycle;  // 开始干支日
        int beginDay;  // 开始日
        int endYear;  // 结束年
        int endMonth;  // 结束月
        int endSexagenaryCycle;  // 结束干支日
        int endDay;  // 结束日
        StringContainer unansweredQuestion;  // 存疑
    };
}

#endif  // ANCIENT_BOOKS_COUNTRY_H
