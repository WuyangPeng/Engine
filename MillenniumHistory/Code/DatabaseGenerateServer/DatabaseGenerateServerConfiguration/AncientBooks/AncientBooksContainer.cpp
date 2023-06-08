/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "AncientBooksContainer.h"

#include "ArticleContainer.h"
#include "BookContainer.h"
#include "CalendarContainer.h"
#include "CategoryContainer.h"
#include "ChapterContainer.h"
#include "CharacterContainer.h"
#include "CountryContainer.h"
#include "DayContainer.h"
#include "EmperorContainer.h"
#include "GatherContainer.h"
#include "GenusContainer.h"
#include "GeographicContainer.h"
#include "IdentityContainer.h"
#include "ImperialCourtContainer.h"
#include "MonthContainer.h"
#include "ReignTitleContainer.h"
#include "SexagenaryCycleContainer.h"
#include "SourceContainer.h"
#include "VersionContainer.h"
#include "YearContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

#include <filesystem>

using namespace std::literals;

AncientBooks::AncientBooksContainer::AncientBooksContainer(const System::String& directory)
    : articleContainer{},
      bookContainer{},
      calendarContainer{},
      categoryContainer{},
      chapterContainer{},
      characterContainer{},
      countryContainer{},
      dayContainer{},
      emperorContainer{},
      gatherContainer{},
      genusContainer{},
      geographicContainer{},
      identityContainer{},
      imperialCourtContainer{},
      monthContainer{},
      reignTitleContainer{},
      sexagenaryCycleContainer{},
      sourceContainer{},
      versionContainer{},
      yearContainer{}
{
    Parsing(directory);
    Verify();

    USER_SELF_CLASS_IS_VALID_1;
}

void AncientBooks::AncientBooksContainer::Parsing(const System::String& directory)
{
    const std::filesystem::path path{ directory };

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        auto fileName = inputPath.path().native();

        if (fileName.find(SYSTEM_TEXT(".csv"s)) != (fileName.size() - 4))
        {
            continue;
        }

        CoreTools::CSVContent csvContent{ fileName };

        const auto csvClassName = csvContent.GetCSVClassName();

        if (csvClassName == SYSTEM_TEXT("Article"s))
        {
            articleContainer = std::make_shared<ArticleContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Book"s))
        {
            bookContainer = std::make_shared<BookContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Calendar"s))
        {
            calendarContainer = std::make_shared<CalendarContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Category"s))
        {
            categoryContainer = std::make_shared<CategoryContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Chapter"s))
        {
            chapterContainer = std::make_shared<ChapterContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Character"s))
        {
            characterContainer = std::make_shared<CharacterContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Country"s))
        {
            countryContainer = std::make_shared<CountryContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Day"s))
        {
            dayContainer = std::make_shared<DayContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Emperor"s))
        {
            emperorContainer = std::make_shared<EmperorContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Gather"s))
        {
            gatherContainer = std::make_shared<GatherContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Genus"s))
        {
            genusContainer = std::make_shared<GenusContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Geographic"s))
        {
            geographicContainer = std::make_shared<GeographicContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Identity"s))
        {
            identityContainer = std::make_shared<IdentityContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("ImperialCourt"s))
        {
            imperialCourtContainer = std::make_shared<ImperialCourtContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Month"s))
        {
            monthContainer = std::make_shared<MonthContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("ReignTitle"s))
        {
            reignTitleContainer = std::make_shared<ReignTitleContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("SexagenaryCycle"s))
        {
            sexagenaryCycleContainer = std::make_shared<SexagenaryCycleContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Source"s))
        {
            sourceContainer = std::make_shared<SourceContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Version"s))
        {
            versionContainer = std::make_shared<VersionContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Year"s))
        {
            yearContainer = std::make_shared<YearContainer>(csvContent);
        }
    }
}

void AncientBooks::AncientBooksContainer::Verify() const
{
    if (!articleContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("article�����ڡ�"s))
    }

    if (!bookContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("book�����ڡ�"s))
    }

    if (!calendarContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("calendar�����ڡ�"s))
    }

    if (!categoryContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("category�����ڡ�"s))
    }

    if (!chapterContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("chapter�����ڡ�"s))
    }

    if (!characterContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("character�����ڡ�"s))
    }

    if (!countryContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("country�����ڡ�"s))
    }

    if (!dayContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("day�����ڡ�"s))
    }

    if (!emperorContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("emperor�����ڡ�"s))
    }

    if (!gatherContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("gather�����ڡ�"s))
    }

    if (!genusContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("genus�����ڡ�"s))
    }

    if (!geographicContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("geographic�����ڡ�"s))
    }

    if (!identityContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("identity�����ڡ�"s))
    }

    if (!imperialCourtContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("imperialCourt�����ڡ�"s))
    }

    if (!monthContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("month�����ڡ�"s))
    }

    if (!reignTitleContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("reignTitle�����ڡ�"s))
    }

    if (!sexagenaryCycleContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("sexagenaryCycle�����ڡ�"s))
    }

    if (!sourceContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("source�����ڡ�"s))
    }

    if (!versionContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("version�����ڡ�"s))
    }

    if (!yearContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("year�����ڡ�"s))
    }

}

#ifdef OPEN_CLASS_INVARIANT

bool AncientBooks::AncientBooksContainer::IsValid() const noexcept
{
    if (articleContainer &&
        bookContainer &&
        calendarContainer &&
        categoryContainer &&
        chapterContainer &&
        characterContainer &&
        countryContainer &&
        dayContainer &&
        emperorContainer &&
        gatherContainer &&
        genusContainer &&
        geographicContainer &&
        identityContainer &&
        imperialCourtContainer &&
        monthContainer &&
        reignTitleContainer &&
        sexagenaryCycleContainer &&
        sourceContainer &&
        versionContainer &&
        yearContainer)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

std::shared_ptr<const AncientBooks::ArticleContainer> AncientBooks::AncientBooksContainer::GetArticleContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return articleContainer;
}

std::shared_ptr<const AncientBooks::BookContainer> AncientBooks::AncientBooksContainer::GetBookContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return bookContainer;
}

std::shared_ptr<const AncientBooks::CalendarContainer> AncientBooks::AncientBooksContainer::GetCalendarContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return calendarContainer;
}

std::shared_ptr<const AncientBooks::CategoryContainer> AncientBooks::AncientBooksContainer::GetCategoryContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return categoryContainer;
}

std::shared_ptr<const AncientBooks::ChapterContainer> AncientBooks::AncientBooksContainer::GetChapterContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return chapterContainer;
}

std::shared_ptr<const AncientBooks::CharacterContainer> AncientBooks::AncientBooksContainer::GetCharacterContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return characterContainer;
}

std::shared_ptr<const AncientBooks::CountryContainer> AncientBooks::AncientBooksContainer::GetCountryContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return countryContainer;
}

std::shared_ptr<const AncientBooks::DayContainer> AncientBooks::AncientBooksContainer::GetDayContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return dayContainer;
}

std::shared_ptr<const AncientBooks::EmperorContainer> AncientBooks::AncientBooksContainer::GetEmperorContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return emperorContainer;
}

std::shared_ptr<const AncientBooks::GatherContainer> AncientBooks::AncientBooksContainer::GetGatherContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return gatherContainer;
}

std::shared_ptr<const AncientBooks::GenusContainer> AncientBooks::AncientBooksContainer::GetGenusContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return genusContainer;
}

std::shared_ptr<const AncientBooks::GeographicContainer> AncientBooks::AncientBooksContainer::GetGeographicContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return geographicContainer;
}

std::shared_ptr<const AncientBooks::IdentityContainer> AncientBooks::AncientBooksContainer::GetIdentityContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return identityContainer;
}

std::shared_ptr<const AncientBooks::ImperialCourtContainer> AncientBooks::AncientBooksContainer::GetImperialCourtContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return imperialCourtContainer;
}

std::shared_ptr<const AncientBooks::MonthContainer> AncientBooks::AncientBooksContainer::GetMonthContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return monthContainer;
}

std::shared_ptr<const AncientBooks::ReignTitleContainer> AncientBooks::AncientBooksContainer::GetReignTitleContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return reignTitleContainer;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleContainer> AncientBooks::AncientBooksContainer::GetSexagenaryCycleContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return sexagenaryCycleContainer;
}

std::shared_ptr<const AncientBooks::SourceContainer> AncientBooks::AncientBooksContainer::GetSourceContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return sourceContainer;
}

std::shared_ptr<const AncientBooks::VersionContainer> AncientBooks::AncientBooksContainer::GetVersionContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return versionContainer;
}

std::shared_ptr<const AncientBooks::YearContainer> AncientBooks::AncientBooksContainer::GetYearContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return yearContainer;
}

