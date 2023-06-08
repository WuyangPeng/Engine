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

        NODISCARD virtual System::String GetName() const;

        NODISCARD virtual std::vector<System::String> GetAlias() const;
        NODISCARD virtual int GetAliasCount() const;
        NODISCARD virtual System::String GetAlias(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAliasBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAliasEnd() const;

        NODISCARD virtual std::vector<int> GetSource() const;
        NODISCARD virtual int GetSourceCount() const;
        NODISCARD virtual int GetSource(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetSourceBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetSourceEnd() const;

        NODISCARD virtual System::String GetPublication() const;

        NODISCARD virtual std::vector<int> GetCreator() const;
        NODISCARD virtual int GetCreatorCount() const;
        NODISCARD virtual int GetCreator(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetCreatorBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetCreatorEnd() const;

        NODISCARD virtual int GetFormulate() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetFormulate(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetCountry() const noexcept;
        NODISCARD virtual std::shared_ptr<const CountryMappingType> GetCountry(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetBegin() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetBegin(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetEnd() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetEnd(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainBegin() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetAgainBegin(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEnd() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetAgainEnd(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_CALENDAR_BASE_H
