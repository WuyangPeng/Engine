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
        NODISCARD virtual std::shared_ptr<const CountryMappingType> GetCountry(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetIdentity() const noexcept;
        NODISCARD virtual std::shared_ptr<const IdentityMappingType> GetIdentity(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetFamily() const;

        NODISCARD virtual System::String GetName() const;

        NODISCARD virtual System::String GetFullName() const;

        NODISCARD virtual std::vector<System::String> GetAlias() const;
        NODISCARD virtual int GetAliasCount() const;
        NODISCARD virtual System::String GetAlias(int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAliasBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAliasEnd() const;

        NODISCARD virtual System::String GetStyleName() const;

        NODISCARD virtual int GetSex() const noexcept;

        NODISCARD virtual int GetFather() const noexcept;

        NODISCARD virtual int GetMother() const noexcept;

        NODISCARD virtual std::vector<int> GetFosterFather() const;
        NODISCARD virtual int GetFosterFatherCount() const;
        NODISCARD virtual int GetFosterFather(int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetFosterFatherBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetFosterFatherEnd() const;

        NODISCARD virtual std::vector<int> GetFosterMother() const;
        NODISCARD virtual int GetFosterMotherCount() const;
        NODISCARD virtual int GetFosterMother(int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetFosterMotherBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetFosterMotherEnd() const;

        NODISCARD virtual int GetBirthYear() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetBirthYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBirthMonth() const noexcept;
        NODISCARD virtual std::shared_ptr<const MonthMappingType> GetBirthMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBirthSexagenaryCycle() const noexcept;
        NODISCARD virtual std::shared_ptr<const SexagenaryCycleMappingType> GetBirthSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBirthDay() const noexcept;
        NODISCARD virtual std::shared_ptr<const DayMappingType> GetBirthDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetDeathYear() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetDeathYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetDeathMonth() const noexcept;
        NODISCARD virtual std::shared_ptr<const MonthMappingType> GetDeathMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetDeathSexagenaryCycle() const noexcept;
        NODISCARD virtual std::shared_ptr<const SexagenaryCycleMappingType> GetDeathSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetDeathDay() const noexcept;
        NODISCARD virtual std::shared_ptr<const DayMappingType> GetDeathDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual std::vector<System::String> GetUnansweredQuestion() const;
        NODISCARD virtual int GetUnansweredQuestionCount() const;
        NODISCARD virtual System::String GetUnansweredQuestion(int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_CHARACTER_BASE_H
