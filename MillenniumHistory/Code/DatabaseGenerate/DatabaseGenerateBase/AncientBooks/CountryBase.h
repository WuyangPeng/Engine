/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_COUNTRY_BASE_H
#define ANCIENT_BOOKS_COUNTRY_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class CountryBase
    {
    public:
        using ClassType = CountryBase;

        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;
        using ConstImperialCourtSharedPtr = std::shared_ptr<const ImperialCourtMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstMonthSharedPtr = std::shared_ptr<const MonthMappingType>;
        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using ConstDaySharedPtr = std::shared_ptr<const DayMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstMonthSharedPtr = std::shared_ptr<const MonthMappingType>;
        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using ConstDaySharedPtr = std::shared_ptr<const DayMappingType>;

    public:
        CountryBase() noexcept = default;
        explicit CountryBase(int key) noexcept;

        virtual ~CountryBase() noexcept = default;
        CountryBase(const CountryBase& rhs) noexcept = default;
        CountryBase& operator=(const CountryBase& rhs) noexcept = default;
        CountryBase(CountryBase&& rhs) noexcept = default;
        CountryBase& operator=(CountryBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetImperialCourt() const noexcept;
        NODISCARD virtual ConstImperialCourtSharedPtr GetImperialCourt(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual String GetCategory() const;

        NODISCARD virtual int GetBeginYear() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetBeginYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBeginMonth() const noexcept;
        NODISCARD virtual ConstMonthSharedPtr GetBeginMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBeginSexagenaryCycle() const noexcept;
        NODISCARD virtual ConstSexagenaryCycleSharedPtr GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBeginDay() const noexcept;
        NODISCARD virtual ConstDaySharedPtr GetBeginDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndYear() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetEndYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndMonth() const noexcept;
        NODISCARD virtual ConstMonthSharedPtr GetEndMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndSexagenaryCycle() const noexcept;
        NODISCARD virtual ConstSexagenaryCycleSharedPtr GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndDay() const noexcept;
        NODISCARD virtual ConstDaySharedPtr GetEndDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual StringContainer GetUnansweredQuestion() const;
        NODISCARD virtual int GetUnansweredQuestionCount() const;
        NODISCARD virtual String GetUnansweredQuestion(int index) const;
        NODISCARD virtual StringContainerConstIter GetUnansweredQuestionBegin() const;
        NODISCARD virtual StringContainerConstIter GetUnansweredQuestionEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_COUNTRY_BASE_H
