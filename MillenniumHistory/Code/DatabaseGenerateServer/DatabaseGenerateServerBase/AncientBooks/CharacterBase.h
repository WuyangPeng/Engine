/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_CHARACTER_BASE_H
#define ANCIENT_BOOKS_CHARACTER_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class CharacterBase
    {
    public:
        using ClassType = CharacterBase;

        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;
        using IntContainer = std::vector<int>;
        using IntContainerConstIter = IntContainer::const_iterator;
        using ConstCountrySharedPtr = std::shared_ptr<const CountryMappingType>;
        using ConstIdentitySharedPtr = std::shared_ptr<const IdentityMappingType>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using CharacterContainer = std::vector<ConstCharacterSharedPtr>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using CharacterContainer = std::vector<ConstCharacterSharedPtr>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstMonthSharedPtr = std::shared_ptr<const MonthMappingType>;
        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using ConstDaySharedPtr = std::shared_ptr<const DayMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstMonthSharedPtr = std::shared_ptr<const MonthMappingType>;
        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using ConstDaySharedPtr = std::shared_ptr<const DayMappingType>;

    public:
        CharacterBase() noexcept = default;
        explicit CharacterBase(int key) noexcept;

        virtual ~CharacterBase() noexcept = default;
        CharacterBase(const CharacterBase& rhs) noexcept = default;
        CharacterBase& operator=(const CharacterBase& rhs) noexcept = default;
        CharacterBase(CharacterBase&& rhs) noexcept = default;
        CharacterBase& operator=(CharacterBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetCountry() const noexcept;
        NODISCARD virtual ConstCountrySharedPtr GetCountry(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetIdentity() const noexcept;
        NODISCARD virtual ConstIdentitySharedPtr GetIdentity(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual String GetFamily() const;

        NODISCARD virtual String GetName() const;

        NODISCARD virtual String GetFullName() const;

        NODISCARD virtual StringContainer GetAlias() const;
        NODISCARD virtual int GetAliasCount() const;
        NODISCARD virtual String GetAlias(int index) const;
        NODISCARD virtual StringContainerConstIter GetAliasBegin() const;
        NODISCARD virtual StringContainerConstIter GetAliasEnd() const;

        NODISCARD virtual String GetStyleName() const;

        NODISCARD virtual int GetSex() const noexcept;

        NODISCARD virtual int GetFather() const noexcept;
        NODISCARD virtual ConstCharacterSharedPtr GetFather(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetMother() const noexcept;
        NODISCARD virtual ConstCharacterSharedPtr GetMother(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual IntContainer GetFosterFather() const;
        NODISCARD virtual int GetFosterFatherCount() const;
        NODISCARD virtual int GetFosterFather(int index) const;
        NODISCARD virtual IntContainerConstIter GetFosterFatherBegin() const;
        NODISCARD virtual IntContainerConstIter GetFosterFatherEnd() const;
        NODISCARD virtual CharacterContainer GetFosterFather(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual IntContainer GetFosterMother() const;
        NODISCARD virtual int GetFosterMotherCount() const;
        NODISCARD virtual int GetFosterMother(int index) const;
        NODISCARD virtual IntContainerConstIter GetFosterMotherBegin() const;
        NODISCARD virtual IntContainerConstIter GetFosterMotherEnd() const;
        NODISCARD virtual CharacterContainer GetFosterMother(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBirthYear() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetBirthYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBirthMonth() const noexcept;
        NODISCARD virtual ConstMonthSharedPtr GetBirthMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBirthSexagenaryCycle() const noexcept;
        NODISCARD virtual ConstSexagenaryCycleSharedPtr GetBirthSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBirthDay() const noexcept;
        NODISCARD virtual ConstDaySharedPtr GetBirthDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetDeathYear() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetDeathYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetDeathMonth() const noexcept;
        NODISCARD virtual ConstMonthSharedPtr GetDeathMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetDeathSexagenaryCycle() const noexcept;
        NODISCARD virtual ConstSexagenaryCycleSharedPtr GetDeathSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetDeathDay() const noexcept;
        NODISCARD virtual ConstDaySharedPtr GetDeathDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual StringContainer GetUnansweredQuestion() const;
        NODISCARD virtual int GetUnansweredQuestionCount() const;
        NODISCARD virtual String GetUnansweredQuestion(int index) const;
        NODISCARD virtual StringContainerConstIter GetUnansweredQuestionBegin() const;
        NODISCARD virtual StringContainerConstIter GetUnansweredQuestionEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_CHARACTER_BASE_H
