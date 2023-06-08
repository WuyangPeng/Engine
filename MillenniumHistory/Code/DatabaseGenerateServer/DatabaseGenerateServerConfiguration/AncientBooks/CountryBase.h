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
        NODISCARD virtual std::shared_ptr<const ImperialCourtMappingType> GetImperialCourt(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetCategory() const;

        NODISCARD virtual int GetBeginYear() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetBeginYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBeginMonth() const noexcept;
        NODISCARD virtual std::shared_ptr<const MonthMappingType> GetBeginMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBeginSexagenaryCycle() const noexcept;
        NODISCARD virtual std::shared_ptr<const SexagenaryCycleMappingType> GetBeginSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBeginDay() const noexcept;
        NODISCARD virtual std::shared_ptr<const DayMappingType> GetBeginDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndYear() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetEndYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndMonth() const noexcept;
        NODISCARD virtual std::shared_ptr<const MonthMappingType> GetEndMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndSexagenaryCycle() const noexcept;
        NODISCARD virtual std::shared_ptr<const SexagenaryCycleMappingType> GetEndSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndDay() const noexcept;
        NODISCARD virtual std::shared_ptr<const DayMappingType> GetEndDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual std::vector<System::String> GetUnansweredQuestion() const;
        NODISCARD virtual int GetUnansweredQuestionCount() const;
        NODISCARD virtual System::String GetUnansweredQuestion(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_COUNTRY_BASE_H
