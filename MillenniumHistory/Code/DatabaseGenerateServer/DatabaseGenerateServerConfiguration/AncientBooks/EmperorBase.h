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
        NODISCARD virtual std::shared_ptr<const CharacterMappingType> GetCharacter(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetName() const;

        NODISCARD virtual System::String GetDynasticTitle() const;

        NODISCARD virtual std::vector<System::String> GetDynasticTitleAlias() const;
        NODISCARD virtual int GetDynasticTitleAliasCount() const;
        NODISCARD virtual System::String GetDynasticTitleAlias(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetDynasticTitleAliasBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetDynasticTitleAliasEnd() const;

        NODISCARD virtual System::String GetPosthumousTitle() const;

        NODISCARD virtual std::vector<System::String> GetPosthumousTitleAlias() const;
        NODISCARD virtual int GetPosthumousTitleAliasCount() const;
        NODISCARD virtual System::String GetPosthumousTitleAlias(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetPosthumousTitleAliasBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetPosthumousTitleAliasEnd() const;

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

        NODISCARD virtual int GetAgainBeginYear() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetAgainBeginYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainBeginMonth() const noexcept;
        NODISCARD virtual std::shared_ptr<const MonthMappingType> GetAgainBeginMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainBeginSexagenaryCycle() const noexcept;
        NODISCARD virtual std::shared_ptr<const SexagenaryCycleMappingType> GetAgainBeginSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainBeginDay() const noexcept;
        NODISCARD virtual std::shared_ptr<const DayMappingType> GetAgainBeginDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEndYear() const noexcept;
        NODISCARD virtual std::shared_ptr<const YearMappingType> GetAgainEndYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEndMonth() const noexcept;
        NODISCARD virtual std::shared_ptr<const MonthMappingType> GetAgainEndMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEndSexagenaryCycle() const noexcept;
        NODISCARD virtual std::shared_ptr<const SexagenaryCycleMappingType> GetAgainEndSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetAgainEndDay() const noexcept;
        NODISCARD virtual std::shared_ptr<const DayMappingType> GetAgainEndDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual std::vector<System::String> GetUnansweredQuestion() const;
        NODISCARD virtual int GetUnansweredQuestionCount() const;
        NODISCARD virtual System::String GetUnansweredQuestion(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_EMPEROR_BASE_H
