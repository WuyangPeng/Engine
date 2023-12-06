/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"

#include "ArticleContainer.h"
#include "BookContainer.h"
#include "CalendarContainer.h"
#include "CategoryContainer.h"
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
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

using namespace std::literals;

AncientBooks::AncientBooksContainer::AncientBooksContainer(const String& directory)
    : articleContainer{},
      bookContainer{},
      calendarContainer{},
      categoryContainer{},
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

void AncientBooks::AncientBooksContainer::Parsing(const String& directory)
{
    for (const std::filesystem::path path{ directory };
         const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        Parsing(inputPath);
    }
}

void AncientBooks::AncientBooksContainer::Parsing(const std::filesystem::directory_entry& inputPath)
{
    const auto fileName = inputPath.path().native();

    if (fileName.find(L".csv"s) != (fileName.size() - 4))
    {
        return;
    }

    const CoreTools::CSVContent csvContent{ CoreTools::StringConversion::WideCharConversionStandard(fileName) };

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

void AncientBooks::AncientBooksContainer::Verify() const
{
    if (articleContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("article表不存在。"s))
    }

    if (bookContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("book表不存在。"s))
    }

    if (calendarContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("calendar表不存在。"s))
    }

    if (categoryContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("category表不存在。"s))
    }

    if (characterContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("character表不存在。"s))
    }

    if (countryContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("country表不存在。"s))
    }

    if (dayContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("day表不存在。"s))
    }

    if (emperorContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("emperor表不存在。"s))
    }

    if (gatherContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("gather表不存在。"s))
    }

    if (genusContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("genus表不存在。"s))
    }

    if (geographicContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("geographic表不存在。"s))
    }

    if (identityContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("identity表不存在。"s))
    }

    if (imperialCourtContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("imperialCourt表不存在。"s))
    }

    if (monthContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("month表不存在。"s))
    }

    if (reignTitleContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表不存在。"s))
    }

    if (sexagenaryCycleContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("sexagenaryCycle表不存在。"s))
    }

    if (sourceContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("source表不存在。"s))
    }

    if (versionContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("version表不存在。"s))
    }

    if (yearContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("year表不存在。"s))
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("AncientBooks结束载入……"));
}

#ifdef OPEN_CLASS_INVARIANT

bool AncientBooks::AncientBooksContainer::IsValid() const noexcept
{
    if (articleContainer != nullptr &&
        bookContainer != nullptr &&
        calendarContainer != nullptr &&
        categoryContainer != nullptr &&
        characterContainer != nullptr &&
        countryContainer != nullptr &&
        dayContainer != nullptr &&
        emperorContainer != nullptr &&
        gatherContainer != nullptr &&
        genusContainer != nullptr &&
        geographicContainer != nullptr &&
        identityContainer != nullptr &&
        imperialCourtContainer != nullptr &&
        monthContainer != nullptr &&
        reignTitleContainer != nullptr &&
        sexagenaryCycleContainer != nullptr &&
        sourceContainer != nullptr &&
        versionContainer != nullptr &&
        yearContainer != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

AncientBooks::AncientBooksContainer::ConstArticleContainerSharedPtr AncientBooks::AncientBooksContainer::GetArticleContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return articleContainer;
}

AncientBooks::AncientBooksContainer::ConstBookContainerSharedPtr AncientBooks::AncientBooksContainer::GetBookContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return bookContainer;
}

AncientBooks::AncientBooksContainer::ConstCalendarContainerSharedPtr AncientBooks::AncientBooksContainer::GetCalendarContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return calendarContainer;
}

AncientBooks::AncientBooksContainer::ConstCategoryContainerSharedPtr AncientBooks::AncientBooksContainer::GetCategoryContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return categoryContainer;
}

AncientBooks::AncientBooksContainer::ConstCharacterContainerSharedPtr AncientBooks::AncientBooksContainer::GetCharacterContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return characterContainer;
}

AncientBooks::AncientBooksContainer::ConstCountryContainerSharedPtr AncientBooks::AncientBooksContainer::GetCountryContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return countryContainer;
}

AncientBooks::AncientBooksContainer::ConstDayContainerSharedPtr AncientBooks::AncientBooksContainer::GetDayContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return dayContainer;
}

AncientBooks::AncientBooksContainer::ConstEmperorContainerSharedPtr AncientBooks::AncientBooksContainer::GetEmperorContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return emperorContainer;
}

AncientBooks::AncientBooksContainer::ConstGatherContainerSharedPtr AncientBooks::AncientBooksContainer::GetGatherContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return gatherContainer;
}

AncientBooks::AncientBooksContainer::ConstGenusContainerSharedPtr AncientBooks::AncientBooksContainer::GetGenusContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return genusContainer;
}

AncientBooks::AncientBooksContainer::ConstGeographicContainerSharedPtr AncientBooks::AncientBooksContainer::GetGeographicContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return geographicContainer;
}

AncientBooks::AncientBooksContainer::ConstIdentityContainerSharedPtr AncientBooks::AncientBooksContainer::GetIdentityContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return identityContainer;
}

AncientBooks::AncientBooksContainer::ConstImperialCourtContainerSharedPtr AncientBooks::AncientBooksContainer::GetImperialCourtContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return imperialCourtContainer;
}

AncientBooks::AncientBooksContainer::ConstMonthContainerSharedPtr AncientBooks::AncientBooksContainer::GetMonthContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return monthContainer;
}

AncientBooks::AncientBooksContainer::ConstReignTitleContainerSharedPtr AncientBooks::AncientBooksContainer::GetReignTitleContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return reignTitleContainer;
}

AncientBooks::AncientBooksContainer::ConstSexagenaryCycleContainerSharedPtr AncientBooks::AncientBooksContainer::GetSexagenaryCycleContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return sexagenaryCycleContainer;
}

AncientBooks::AncientBooksContainer::ConstSourceContainerSharedPtr AncientBooks::AncientBooksContainer::GetSourceContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return sourceContainer;
}

AncientBooks::AncientBooksContainer::ConstVersionContainerSharedPtr AncientBooks::AncientBooksContainer::GetVersionContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return versionContainer;
}

AncientBooks::AncientBooksContainer::ConstYearContainerSharedPtr AncientBooks::AncientBooksContainer::GetYearContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return yearContainer;
}

