/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_EMPEROR_BASE_H
#define ANCIENT_BOOKS_EMPEROR_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>


namespace AncientBooks
{
    class EmperorBase
    {
    public:
        using ClassType = EmperorBase;

        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstMonthSharedPtr = std::shared_ptr<const MonthMappingType>;
        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using ConstDaySharedPtr = std::shared_ptr<const DayMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstMonthSharedPtr = std::shared_ptr<const MonthMappingType>;
        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using ConstDaySharedPtr = std::shared_ptr<const DayMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstMonthSharedPtr = std::shared_ptr<const MonthMappingType>;
        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using ConstDaySharedPtr = std::shared_ptr<const DayMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstMonthSharedPtr = std::shared_ptr<const MonthMappingType>;
        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using ConstDaySharedPtr = std::shared_ptr<const DayMappingType>;

    public:
        EmperorBase() noexcept = default;
        explicit EmperorBase(int key) noexcept;

        virtual ~EmperorBase() noexcept = default;
        EmperorBase(const EmperorBase& rhs) noexcept = default;
        EmperorBase& operator=(const EmperorBase& rhs) noexcept = default;
        EmperorBase(EmperorBase&& rhs) noexcept = default;
        EmperorBase& operator=(EmperorBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetCharacter() const noexcept;
        NODISCARD virtual ConstCharacterSharedPtr GetCharacter(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual String GetName() const;

        NODISCARD virtual String GetDynasticTitle() const;

        NODISCARD virtual StringContainer GetDynasticTitleAlias() const;
        NODISCARD virtual int GetDynasticTitleAliasCount() const;
        NODISCARD virtual String GetDynasticTitleAlias(int index) const;
        NODISCARD virtual StringContainerConstIter GetDynasticTitleAliasBegin() const;
        NODISCARD virtual StringContainerConstIter GetDynasticTitleAliasEnd() const;

        NODISCARD virtual String GetPosthumousTitle() const;

        NODISCARD virtual StringContainer GetPosthumousTitleAlias() const;
        NODISCARD virtual int GetPosthumousTitleAliasCount() const;
        NODISCARD virtual String GetPosthumousTitleAlias(int index) const;
        NODISCARD virtual StringContainerConstIter GetPosthumousTitleAliasBegin() const;
        NODISCARD virtual StringContainerConstIter GetPosthumousTitleAliasEnd() const;

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

        NODISCARD virtual int GetAgainBeginYear() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetAgainBeginYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainBeginMonth() const noexcept;
        NODISCARD virtual ConstMonthSharedPtr GetAgainBeginMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainBeginSexagenaryCycle() const noexcept;
        NODISCARD virtual ConstSexagenaryCycleSharedPtr GetAgainBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainBeginDay() const noexcept;
        NODISCARD virtual ConstDaySharedPtr GetAgainBeginDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEndYear() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetAgainEndYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEndMonth() const noexcept;
        NODISCARD virtual ConstMonthSharedPtr GetAgainEndMonth(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEndSexagenaryCycle() const noexcept;
        NODISCARD virtual ConstSexagenaryCycleSharedPtr GetAgainEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEndDay() const noexcept;
        NODISCARD virtual ConstDaySharedPtr GetAgainEndDay(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual StringContainer GetUnansweredQuestion() const;
        NODISCARD virtual int GetUnansweredQuestionCount() const;
        NODISCARD virtual String GetUnansweredQuestion(int index) const;
        NODISCARD virtual StringContainerConstIter GetUnansweredQuestionBegin() const;
        NODISCARD virtual StringContainerConstIter GetUnansweredQuestionEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_EMPEROR_BASE_H
