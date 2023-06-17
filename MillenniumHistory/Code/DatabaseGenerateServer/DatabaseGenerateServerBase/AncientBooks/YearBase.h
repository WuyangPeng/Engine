/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_YEAR_BASE_H
#define ANCIENT_BOOKS_YEAR_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class YearBase
    {
    public:
        using ClassType = YearBase;

    public:
        YearBase() noexcept = default;
        explicit YearBase(int key) noexcept;

        virtual ~YearBase() noexcept = default;
        YearBase(const YearBase& rhs) noexcept = default;
        YearBase& operator=(const YearBase& rhs) noexcept = default;
        YearBase(YearBase&& rhs) noexcept = default;
        YearBase& operator=(YearBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual System::String GetName() const;

        NODISCARD virtual int GetSexagenaryCycle() const noexcept;
        NODISCARD virtual std::shared_ptr<const SexagenaryCycleMappingType> GetSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int64_t GetReignTitle() const noexcept;
        NODISCARD virtual std::shared_ptr<const ReignTitleMappingType> GetReignTitle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetYear() const noexcept;

        NODISCARD virtual std::vector<int> GetUnorthodoxReignTitle() const;
        NODISCARD virtual int GetUnorthodoxReignTitleCount() const;
        NODISCARD virtual int GetUnorthodoxReignTitle(int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetUnorthodoxReignTitleBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetUnorthodoxReignTitleEnd() const;

        NODISCARD virtual std::vector<int> GetUnorthodoxYear() const;
        NODISCARD virtual int GetUnorthodoxYearCount() const;
        NODISCARD virtual int GetUnorthodoxYear(int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetUnorthodoxYearBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetUnorthodoxYearEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_YEAR_BASE_H
