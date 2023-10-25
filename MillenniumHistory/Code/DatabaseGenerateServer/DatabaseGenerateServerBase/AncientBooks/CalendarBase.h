/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_CALENDAR_BASE_H
#define ANCIENT_BOOKS_CALENDAR_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>


namespace AncientBooks
{
    class CalendarBase
    {
    public:
        using ClassType = CalendarBase;

        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;
        using IntContainer = std::vector<int>;
        using IntContainerConstIter = IntContainer::const_iterator;
        using ConstBookSharedPtr = std::shared_ptr<const BookMappingType>;
        using BookContainer = std::vector<ConstBookSharedPtr>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using CharacterContainer = std::vector<ConstCharacterSharedPtr>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstCountrySharedPtr = std::shared_ptr<const CountryMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;

    public:
        CalendarBase() noexcept = default;
        explicit CalendarBase(int key) noexcept;

        virtual ~CalendarBase() noexcept = default;
        CalendarBase(const CalendarBase& rhs) noexcept = default;
        CalendarBase& operator=(const CalendarBase& rhs) noexcept = default;
        CalendarBase(CalendarBase&& rhs) noexcept = default;
        CalendarBase& operator=(CalendarBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual String GetName() const;

        NODISCARD virtual StringContainer GetAlias() const;
        NODISCARD virtual int GetAliasCount() const;
        NODISCARD virtual String GetAlias(int index) const;
        NODISCARD virtual StringContainerConstIter GetAliasBegin() const;
        NODISCARD virtual StringContainerConstIter GetAliasEnd() const;

        NODISCARD virtual IntContainer GetSource() const;
        NODISCARD virtual int GetSourceCount() const;
        NODISCARD virtual int GetSource(int index) const;
        NODISCARD virtual IntContainerConstIter GetSourceBegin() const;
        NODISCARD virtual IntContainerConstIter GetSourceEnd() const;
        NODISCARD virtual BookContainer GetSource(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual String GetPublication() const;

        NODISCARD virtual IntContainer GetCreator() const;
        NODISCARD virtual int GetCreatorCount() const;
        NODISCARD virtual int GetCreator(int index) const;
        NODISCARD virtual IntContainerConstIter GetCreatorBegin() const;
        NODISCARD virtual IntContainerConstIter GetCreatorEnd() const;
        NODISCARD virtual CharacterContainer GetCreator(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetFormulate() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetFormulate(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetCountry() const noexcept;
        NODISCARD virtual ConstCountrySharedPtr GetCountry(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBegin() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetBegin(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEnd() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetEnd(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainBegin() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetAgainBegin(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEnd() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetAgainEnd(const AncientBooksContainer& csvContainer) const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_CALENDAR_BASE_H
