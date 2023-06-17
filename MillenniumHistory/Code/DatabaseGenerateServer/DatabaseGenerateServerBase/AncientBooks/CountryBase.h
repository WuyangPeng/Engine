/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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
        NODISCARD virtual std::shared_ptr<const ImperialCourtMappingType> GetImperialCourt(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetCategory() const;

        NODISCARD virtual int GetBeginYear() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetBeginYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBeginMonth() const noexcept;
        NODISCARD virtual std::shared_ptr<const MonthMappingType> GetBeginMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBeginSexagenaryCycle() const noexcept;
        NODISCARD virtual std::shared_ptr<const SexagenaryCycleMappingType> GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBeginDay() const noexcept;
        NODISCARD virtual std::shared_ptr<const DayMappingType> GetBeginDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndYear() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetEndYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndMonth() const noexcept;
        NODISCARD virtual std::shared_ptr<const MonthMappingType> GetEndMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndSexagenaryCycle() const noexcept;
        NODISCARD virtual std::shared_ptr<const SexagenaryCycleMappingType> GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEndDay() const noexcept;
        NODISCARD virtual std::shared_ptr<const DayMappingType> GetEndDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual std::vector<System::String> GetUnansweredQuestion() const;
        NODISCARD virtual int GetUnansweredQuestionCount() const;
        NODISCARD virtual System::String GetUnansweredQuestion(int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_COUNTRY_BASE_H
