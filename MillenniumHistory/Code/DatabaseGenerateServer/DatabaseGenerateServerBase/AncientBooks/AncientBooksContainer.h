/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_ANCIENT_BOOKS_CONTAINER_H
#define ANCIENT_BOOKS_ANCIENT_BOOKS_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <filesystem>
#include <memory>

namespace AncientBooks
{
    class AncientBooksContainer final
    {
    public:
        using ClassType = AncientBooksContainer;

        using String = System::String;
        using ConstArticleContainerSharedPtr = std::shared_ptr<const ArticleContainer>;
        using ConstBookContainerSharedPtr = std::shared_ptr<const BookContainer>;
        using ConstCalendarContainerSharedPtr = std::shared_ptr<const CalendarContainer>;
        using ConstCategoryContainerSharedPtr = std::shared_ptr<const CategoryContainer>;
        using ConstCharacterContainerSharedPtr = std::shared_ptr<const CharacterContainer>;
        using ConstCountryContainerSharedPtr = std::shared_ptr<const CountryContainer>;
        using ConstDayContainerSharedPtr = std::shared_ptr<const DayContainer>;
        using ConstEmperorContainerSharedPtr = std::shared_ptr<const EmperorContainer>;
        using ConstGatherContainerSharedPtr = std::shared_ptr<const GatherContainer>;
        using ConstGenusContainerSharedPtr = std::shared_ptr<const GenusContainer>;
        using ConstGeographicContainerSharedPtr = std::shared_ptr<const GeographicContainer>;
        using ConstIdentityContainerSharedPtr = std::shared_ptr<const IdentityContainer>;
        using ConstImperialCourtContainerSharedPtr = std::shared_ptr<const ImperialCourtContainer>;
        using ConstMonthContainerSharedPtr = std::shared_ptr<const MonthContainer>;
        using ConstReignTitleContainerSharedPtr = std::shared_ptr<const ReignTitleContainer>;
        using ConstSexagenaryCycleContainerSharedPtr = std::shared_ptr<const SexagenaryCycleContainer>;
        using ConstSourceContainerSharedPtr = std::shared_ptr<const SourceContainer>;
        using ConstVersionContainerSharedPtr = std::shared_ptr<const VersionContainer>;
        using ConstYearContainerSharedPtr = std::shared_ptr<const YearContainer>;

    public:
        explicit AncientBooksContainer(const String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstArticleContainerSharedPtr GetArticleContainer() const noexcept;
        NODISCARD ConstBookContainerSharedPtr GetBookContainer() const noexcept;
        NODISCARD ConstCalendarContainerSharedPtr GetCalendarContainer() const noexcept;
        NODISCARD ConstCategoryContainerSharedPtr GetCategoryContainer() const noexcept;
        NODISCARD ConstCharacterContainerSharedPtr GetCharacterContainer() const noexcept;
        NODISCARD ConstCountryContainerSharedPtr GetCountryContainer() const noexcept;
        NODISCARD ConstDayContainerSharedPtr GetDayContainer() const noexcept;
        NODISCARD ConstEmperorContainerSharedPtr GetEmperorContainer() const noexcept;
        NODISCARD ConstGatherContainerSharedPtr GetGatherContainer() const noexcept;
        NODISCARD ConstGenusContainerSharedPtr GetGenusContainer() const noexcept;
        NODISCARD ConstGeographicContainerSharedPtr GetGeographicContainer() const noexcept;
        NODISCARD ConstIdentityContainerSharedPtr GetIdentityContainer() const noexcept;
        NODISCARD ConstImperialCourtContainerSharedPtr GetImperialCourtContainer() const noexcept;
        NODISCARD ConstMonthContainerSharedPtr GetMonthContainer() const noexcept;
        NODISCARD ConstReignTitleContainerSharedPtr GetReignTitleContainer() const noexcept;
        NODISCARD ConstSexagenaryCycleContainerSharedPtr GetSexagenaryCycleContainer() const noexcept;
        NODISCARD ConstSourceContainerSharedPtr GetSourceContainer() const noexcept;
        NODISCARD ConstVersionContainerSharedPtr GetVersionContainer() const noexcept;
        NODISCARD ConstYearContainerSharedPtr GetYearContainer() const noexcept;

    private:
        void Parsing(const String& directory);
        void Parsing(const std::filesystem::directory_entry& inputPath);
        void Verify() const;

    private:
        ConstArticleContainerSharedPtr articleContainer;
        ConstBookContainerSharedPtr bookContainer;
        ConstCalendarContainerSharedPtr calendarContainer;
        ConstCategoryContainerSharedPtr categoryContainer;
        ConstCharacterContainerSharedPtr characterContainer;
        ConstCountryContainerSharedPtr countryContainer;
        ConstDayContainerSharedPtr dayContainer;
        ConstEmperorContainerSharedPtr emperorContainer;
        ConstGatherContainerSharedPtr gatherContainer;
        ConstGenusContainerSharedPtr genusContainer;
        ConstGeographicContainerSharedPtr geographicContainer;
        ConstIdentityContainerSharedPtr identityContainer;
        ConstImperialCourtContainerSharedPtr imperialCourtContainer;
        ConstMonthContainerSharedPtr monthContainer;
        ConstReignTitleContainerSharedPtr reignTitleContainer;
        ConstSexagenaryCycleContainerSharedPtr sexagenaryCycleContainer;
        ConstSourceContainerSharedPtr sourceContainer;
        ConstVersionContainerSharedPtr versionContainer;
        ConstYearContainerSharedPtr yearContainer;
    };
}

#endif  // ANCIENT_BOOKS_CONTAINER_H
