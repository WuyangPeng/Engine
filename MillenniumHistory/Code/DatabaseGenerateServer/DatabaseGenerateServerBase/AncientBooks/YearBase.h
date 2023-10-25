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

        using String = System::String;
        using IntContainer = std::vector<int>;
        using IntContainerConstIter = IntContainer::const_iterator;
        using Int64Container = std::vector<int64_t>;
        using Int64ContainerConstIter = Int64Container::const_iterator;
        using ConstSexagenaryCycleSharedPtr = std::shared_ptr<const SexagenaryCycleMappingType>;
        using ConstReignTitleSharedPtr = std::shared_ptr<const ReignTitleMappingType>;
        using ConstReignTitleSharedPtr = std::shared_ptr<const ReignTitleMappingType>;
        using ReignTitleContainer = std::vector<ConstReignTitleSharedPtr>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using YearContainer = std::vector<ConstYearSharedPtr>;

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

        NODISCARD virtual String GetName() const;

        NODISCARD virtual int GetSexagenaryCycle() const noexcept;
        NODISCARD virtual ConstSexagenaryCycleSharedPtr GetSexagenaryCycle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int64_t GetReignTitle() const noexcept;
        NODISCARD virtual ConstReignTitleSharedPtr GetReignTitle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetYear() const noexcept;

        NODISCARD virtual Int64Container GetUnorthodoxReignTitle() const;
        NODISCARD virtual int GetUnorthodoxReignTitleCount() const;
        NODISCARD virtual int64_t GetUnorthodoxReignTitle(int index) const;
        NODISCARD virtual Int64ContainerConstIter GetUnorthodoxReignTitleBegin() const;
        NODISCARD virtual Int64ContainerConstIter GetUnorthodoxReignTitleEnd() const;
        NODISCARD virtual ReignTitleContainer GetUnorthodoxReignTitle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual IntContainer GetUnorthodoxYear() const;
        NODISCARD virtual int GetUnorthodoxYearCount() const;
        NODISCARD virtual int GetUnorthodoxYear(int index) const;
        NODISCARD virtual IntContainerConstIter GetUnorthodoxYearBegin() const;
        NODISCARD virtual IntContainerConstIter GetUnorthodoxYearEnd() const;
        NODISCARD virtual YearContainer GetUnorthodoxYear(const AncientBooksContainer& csvContainer) const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_YEAR_BASE_H
