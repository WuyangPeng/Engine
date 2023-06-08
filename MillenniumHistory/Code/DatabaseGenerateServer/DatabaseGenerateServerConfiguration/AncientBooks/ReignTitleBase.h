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

        NODISCARD virtual System::String GetName() const;

        NODISCARD virtual std::vector<int> GetEmperor() const;
        NODISCARD virtual int GetEmperorCount() const;
        NODISCARD virtual int GetEmperor(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetEmperorBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetEmperorEnd() const;

        NODISCARD virtual int GetSerial() const noexcept;

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

    private:
        int64_t key{};
    };
}

#endif  // ANCIENT_BOOKS_REIGN_TITLE_BASE_H
