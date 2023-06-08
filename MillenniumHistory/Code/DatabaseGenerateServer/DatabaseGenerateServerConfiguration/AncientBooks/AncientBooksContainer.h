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

#include <memory>

namespace AncientBooks
{
    class AncientBooksContainer final
    {
    public:
        using ClassType = AncientBooksContainer;

    public:
        explicit AncientBooksContainer(const System::String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::shared_ptr<const ArticleContainer> GetArticleContainer() const noexcept;
        NODISCARD std::shared_ptr<const BookContainer> GetBookContainer() const noexcept;
        NODISCARD std::shared_ptr<const CalendarContainer> GetCalendarContainer() const noexcept;
        NODISCARD std::shared_ptr<const CategoryContainer> GetCategoryContainer() const noexcept;
        NODISCARD std::shared_ptr<const ChapterContainer> GetChapterContainer() const noexcept;
        NODISCARD std::shared_ptr<const CharacterContainer> GetCharacterContainer() const noexcept;
        NODISCARD std::shared_ptr<const CountryContainer> GetCountryContainer() const noexcept;
        NODISCARD std::shared_ptr<const DayContainer> GetDayContainer() const noexcept;
        NODISCARD std::shared_ptr<const EmperorContainer> GetEmperorContainer() const noexcept;
        NODISCARD std::shared_ptr<const GatherContainer> GetGatherContainer() const noexcept;
        NODISCARD std::shared_ptr<const GenusContainer> GetGenusContainer() const noexcept;
        NODISCARD std::shared_ptr<const GeographicContainer> GetGeographicContainer() const noexcept;
        NODISCARD std::shared_ptr<const IdentityContainer> GetIdentityContainer() const noexcept;
        NODISCARD std::shared_ptr<const ImperialCourtContainer> GetImperialCourtContainer() const noexcept;
        NODISCARD std::shared_ptr<const MonthContainer> GetMonthContainer() const noexcept;
        NODISCARD std::shared_ptr<const ReignTitleContainer> GetReignTitleContainer() const noexcept;
        NODISCARD std::shared_ptr<const SexagenaryCycleContainer> GetSexagenaryCycleContainer() const noexcept;
        NODISCARD std::shared_ptr<const SourceContainer> GetSourceContainer() const noexcept;
        NODISCARD std::shared_ptr<const VersionContainer> GetVersionContainer() const noexcept;
        NODISCARD std::shared_ptr<const YearContainer> GetYearContainer() const noexcept;

    private:
        void Parsing(const System::String& directory);
        void Verify() const;

    private:
        std::shared_ptr<const ArticleContainer> articleContainer;
        std::shared_ptr<const BookContainer> bookContainer;
        std::shared_ptr<const CalendarContainer> calendarContainer;
        std::shared_ptr<const CategoryContainer> categoryContainer;
        std::shared_ptr<const ChapterContainer> chapterContainer;
        std::shared_ptr<const CharacterContainer> characterContainer;
        std::shared_ptr<const CountryContainer> countryContainer;
        std::shared_ptr<const DayContainer> dayContainer;
        std::shared_ptr<const EmperorContainer> emperorContainer;
        std::shared_ptr<const GatherContainer> gatherContainer;
        std::shared_ptr<const GenusContainer> genusContainer;
        std::shared_ptr<const GeographicContainer> geographicContainer;
        std::shared_ptr<const IdentityContainer> identityContainer;
        std::shared_ptr<const ImperialCourtContainer> imperialCourtContainer;
        std::shared_ptr<const MonthContainer> monthContainer;
        std::shared_ptr<const ReignTitleContainer> reignTitleContainer;
        std::shared_ptr<const SexagenaryCycleContainer> sexagenaryCycleContainer;
        std::shared_ptr<const SourceContainer> sourceContainer;
        std::shared_ptr<const VersionContainer> versionContainer;
        std::shared_ptr<const YearContainer> yearContainer;
    };
}

#endif  // ANCIENT_BOOKS_CONTAINER_H
