/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_REIGN_TITLE_BASE_H
#define ANCIENT_BOOKS_REIGN_TITLE_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>


namespace AncientBooks
{
    class ReignTitleBase
    {
    public:
        using ClassType = ReignTitleBase;

        using String = System::String;
        using IntContainer = std::vector<int>;
        using IntContainerConstIter = IntContainer::const_iterator;
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
        ReignTitleBase() noexcept = default;
        explicit ReignTitleBase(int64_t key) noexcept;

        virtual ~ReignTitleBase() noexcept = default;
        ReignTitleBase(const ReignTitleBase& rhs) noexcept = default;
        ReignTitleBase& operator=(const ReignTitleBase& rhs) noexcept = default;
        ReignTitleBase(ReignTitleBase&& rhs) noexcept = default;
        ReignTitleBase& operator=(ReignTitleBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int64_t GetKey() const noexcept;

        NODISCARD virtual int64_t GetId() const noexcept;

        NODISCARD virtual String GetName() const;

        NODISCARD virtual IntContainer GetEmperor() const;
        NODISCARD virtual int GetEmperorCount() const;
        NODISCARD virtual int GetEmperor(int index) const;
        NODISCARD virtual IntContainerConstIter GetEmperorBegin() const;
        NODISCARD virtual IntContainerConstIter GetEmperorEnd() const;
        NODISCARD virtual CharacterContainer GetEmperor(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetSerial() const noexcept;

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

    private:
        int64_t key{};
    };
}

#endif  // ANCIENT_BOOKS_REIGN_TITLE_BASE_H
