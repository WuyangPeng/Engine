/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:32)

#include "DatabaseGenerate/DatabaseGenerateCore/DatabaseGenerateCoreExport.h"

#include "ConvertEntityImplDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateCore::ConvertEntityImpl::ConvertEntityImpl(const DatabaseFlushSharedPtr& databaseFlush)
    : databaseFlush{ databaseFlush },
      articleEntityContainer{ GetEntityContainer<int64_t, ArticleEntity>(databaseFlush->SelectAll(ArticleEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), ArticleEntity::GetDatabaseFieldContainer())) },
      bookEntityContainer{ GetEntityContainer<int32_t, BookEntity>(databaseFlush->SelectAll(BookEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), BookEntity::GetDatabaseFieldContainer())) },
      calendarEntityContainer{ GetEntityContainer<int32_t, CalendarEntity>(databaseFlush->SelectAll(CalendarEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), CalendarEntity::GetDatabaseFieldContainer())) },
      categoryEntityContainer{ GetEntityContainer<int32_t, CategoryEntity>(databaseFlush->SelectAll(CategoryEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), CategoryEntity::GetDatabaseFieldContainer())) },
      characterEntityContainer{ GetEntityContainer<int32_t, CharacterEntity>(databaseFlush->SelectAll(CharacterEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), CharacterEntity::GetDatabaseFieldContainer())) },
      countryEntityContainer{ GetEntityContainer<int32_t, CountryEntity>(databaseFlush->SelectAll(CountryEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), CountryEntity::GetDatabaseFieldContainer())) },
      dayEntityContainer{ GetEntityContainer<int32_t, DayEntity>(databaseFlush->SelectAll(DayEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), DayEntity::GetDatabaseFieldContainer())) },
      emperorEntityContainer{ GetEntityContainer<int32_t, EmperorEntity>(databaseFlush->SelectAll(EmperorEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), EmperorEntity::GetDatabaseFieldContainer())) },
      gatherEntityContainer{ GetEntityContainer<int32_t, GatherEntity>(databaseFlush->SelectAll(GatherEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), GatherEntity::GetDatabaseFieldContainer())) },
      genusEntityContainer{ GetEntityContainer<int32_t, GenusEntity>(databaseFlush->SelectAll(GenusEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), GenusEntity::GetDatabaseFieldContainer())) },
      geographicEntityContainer{ GetEntityContainer<int32_t, GeographicEntity>(databaseFlush->SelectAll(GeographicEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), GeographicEntity::GetDatabaseFieldContainer())) },
      identityEntityContainer{ GetEntityContainer<int32_t, IdentityEntity>(databaseFlush->SelectAll(IdentityEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), IdentityEntity::GetDatabaseFieldContainer())) },
      imperialCourtEntityContainer{ GetEntityContainer<int32_t, ImperialCourtEntity>(databaseFlush->SelectAll(ImperialCourtEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), ImperialCourtEntity::GetDatabaseFieldContainer())) },
      monthEntityContainer{ GetEntityContainer<int32_t, MonthEntity>(databaseFlush->SelectAll(MonthEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), MonthEntity::GetDatabaseFieldContainer())) },
      reignTitleEntityContainer{ GetEntityContainer<int64_t, ReignTitleEntity>(databaseFlush->SelectAll(ReignTitleEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), ReignTitleEntity::GetDatabaseFieldContainer())) },
      sexagenaryCycleEntityContainer{ GetEntityContainer<int32_t, SexagenaryCycleEntity>(databaseFlush->SelectAll(SexagenaryCycleEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), SexagenaryCycleEntity::GetDatabaseFieldContainer())) },
      sourceEntityContainer{ GetEntityContainer<int32_t, SourceEntity>(databaseFlush->SelectAll(SourceEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), SourceEntity::GetDatabaseFieldContainer())) },
      versionEntityContainer{ GetEntityContainer<int32_t, VersionEntity>(databaseFlush->SelectAll(VersionEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), VersionEntity::GetDatabaseFieldContainer())) },
      yearEntityContainer{ GetEntityContainer<int32_t, YearEntity>(databaseFlush->SelectAll(YearEntity::GetSelectAll(databaseFlush->GetWrappersStrategy()), YearEntity::GetDatabaseFieldContainer())) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool DatabaseGenerateCore::ConvertEntityImpl::IsValid() const noexcept
{
    return databaseFlush != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

DatabaseEntity::ArticleEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const ArticleBase& article)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_1;

    const auto result = articleEntityContainer.find(article.GetId());
    auto articleEntity = result != articleEntityContainer.cend() ? result->second : ArticleEntity{ databaseFlush->GetWrappersStrategy(), article.GetId() };

    articleEntity.SetVersion(article.GetVersion());
    articleEntity.SetChapter(article.GetChapter());
    articleEntity.SetChapterName(CoreTools::StringConversion::StandardConversionUtf8(article.GetChapterName()));
    articleEntity.SetChapterVolume(article.GetChapterVolume());
    articleEntity.SetOtherAuthor(article.GetOtherAuthor());
    articleEntity.SetAuthorNotes(Convert(article.GetAuthorNotesBegin(), article.GetAuthorNotesEnd()));
    articleEntity.SetTitle(CoreTools::StringConversion::StandardConversionUtf8(article.GetTitle()));
    articleEntity.SetAbbreviation(CoreTools::StringConversion::StandardConversionUtf8(article.GetAbbreviation()));
    articleEntity.SetDirectory(CoreTools::StringConversion::StandardConversionUtf8(article.GetDirectory()));

    if (result != articleEntityContainer.cend())
    {
        articleEntityContainer.erase(result);
    }

    return articleEntity;
}

Database::Traits::StringArray DatabaseGenerateCore::ConvertEntityImpl::Convert(const StringContainerConstIter& begin, const StringContainerConstIter& end)
{
    StringArray result{};
    for (auto iter = begin; iter != end; ++iter)
    {
        result.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
    }

    return result;
}

DatabaseEntity::BookEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const BookBase& book)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = bookEntityContainer.find(book.GetId());
    auto bookEntity = result != bookEntityContainer.cend() ? result->second : BookEntity{ databaseFlush->GetWrappersStrategy(), book.GetId() };

    bookEntity.SetGenus(book.GetGenus());
    bookEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(book.GetName()));
    bookEntity.SetAlias(Convert(book.GetAliasBegin(), book.GetAliasEnd()));
    bookEntity.SetVolume(book.GetVolume());
    bookEntity.SetAuthor(book.GetAuthor());
    bookEntity.SetAuthorNotes(Convert(book.GetAuthorNotesBegin(), book.GetAuthorNotesEnd()));
    bookEntity.SetAnnotator(book.GetAnnotator());
    bookEntity.SetAnnotateNotes(Convert(book.GetAnnotateNotesBegin(), book.GetAnnotateNotesEnd()));
    bookEntity.SetCountry(book.GetCountry());
    bookEntity.SetPerson(book.GetPerson());
    bookEntity.SetUnansweredQuestion(Convert(book.GetUnansweredQuestionBegin(), book.GetUnansweredQuestionEnd()));

    if (result != bookEntityContainer.cend())
    {
        bookEntityContainer.erase(result);
    }

    return bookEntity;
}

DatabaseEntity::CalendarEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const CalendarBase& calendar)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = calendarEntityContainer.find(calendar.GetId());
    auto calendarEntity = result != calendarEntityContainer.cend() ? result->second : CalendarEntity{ databaseFlush->GetWrappersStrategy(), calendar.GetId() };

    calendarEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(calendar.GetName()));
    calendarEntity.SetAlias(Convert(calendar.GetAliasBegin(), calendar.GetAliasEnd()));
    calendarEntity.SetSource(calendar.GetSource());
    calendarEntity.SetPublication(CoreTools::StringConversion::StandardConversionUtf8(calendar.GetPublication()));
    calendarEntity.SetCreator(calendar.GetCreator());
    calendarEntity.SetFormulate(calendar.GetFormulate());
    calendarEntity.SetCountry(calendar.GetCountry());
    calendarEntity.SetBegin(calendar.GetBegin());
    calendarEntity.SetEnd(calendar.GetEnd());
    calendarEntity.SetAgainBegin(calendar.GetAgainBegin());
    calendarEntity.SetAgainEnd(calendar.GetAgainEnd());

    if (result != calendarEntityContainer.cend())
    {
        calendarEntityContainer.erase(result);
    }

    return calendarEntity;
}

DatabaseEntity::CategoryEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const CategoryBase& category)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = categoryEntityContainer.find(category.GetId());
    auto categoryEntity = result != categoryEntityContainer.cend() ? result->second : CategoryEntity{ databaseFlush->GetWrappersStrategy(), category.GetId() };

    categoryEntity.SetGather(category.GetGather());
    categoryEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(category.GetCategory()));

    if (result != categoryEntityContainer.cend())
    {
        categoryEntityContainer.erase(result);
    }

    return categoryEntity;
}

DatabaseEntity::CharacterEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const CharacterBase& character)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = characterEntityContainer.find(character.GetId());
    auto characterEntity = result != characterEntityContainer.cend() ? result->second : CharacterEntity{ databaseFlush->GetWrappersStrategy(), character.GetId() };

    characterEntity.SetCountry(character.GetCountry());
    characterEntity.SetIdentity(character.GetIdentity());
    characterEntity.SetFamily(CoreTools::StringConversion::StandardConversionUtf8(character.GetFamily()));
    characterEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(character.GetName()));
    characterEntity.SetFullName(CoreTools::StringConversion::StandardConversionUtf8(character.GetFullName()));
    characterEntity.SetAlias(Convert(character.GetAliasBegin(), character.GetAliasEnd()));
    characterEntity.SetStyleName(CoreTools::StringConversion::StandardConversionUtf8(character.GetStyleName()));
    characterEntity.SetSex(character.GetSex());
    characterEntity.SetFather(character.GetFather());
    characterEntity.SetMother(character.GetMother());
    characterEntity.SetFosterFather(character.GetFosterFather());
    characterEntity.SetFosterMother(character.GetFosterMother());
    characterEntity.SetBirthYear(character.GetBirthYear());
    characterEntity.SetBirthMonth(character.GetBirthMonth());
    characterEntity.SetBirthSexagenaryCycle(character.GetBirthSexagenaryCycle());
    characterEntity.SetBirthDay(character.GetBirthDay());
    characterEntity.SetDeathYear(character.GetDeathYear());
    characterEntity.SetDeathMonth(character.GetDeathMonth());
    characterEntity.SetDeathSexagenaryCycle(character.GetDeathSexagenaryCycle());
    characterEntity.SetDeathDay(character.GetDeathDay());
    characterEntity.SetUnansweredQuestion(Convert(character.GetUnansweredQuestionBegin(), character.GetUnansweredQuestionEnd()));

    if (result != characterEntityContainer.cend())
    {
        characterEntityContainer.erase(result);
    }

    return characterEntity;
}

DatabaseEntity::CountryEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const CountryBase& country)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = countryEntityContainer.find(country.GetId());
    auto countryEntity = result != countryEntityContainer.cend() ? result->second : CountryEntity{ databaseFlush->GetWrappersStrategy(), country.GetId() };

    countryEntity.SetImperialCourt(country.GetImperialCourt());
    countryEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(country.GetCategory()));
    countryEntity.SetBeginYear(country.GetBeginYear());
    countryEntity.SetBeginMonth(country.GetBeginMonth());
    countryEntity.SetBeginSexagenaryCycle(country.GetBeginSexagenaryCycle());
    countryEntity.SetBeginDay(country.GetBeginDay());
    countryEntity.SetEndYear(country.GetEndYear());
    countryEntity.SetEndMonth(country.GetEndMonth());
    countryEntity.SetEndSexagenaryCycle(country.GetEndSexagenaryCycle());
    countryEntity.SetEndDay(country.GetEndDay());
    countryEntity.SetUnansweredQuestion(Convert(country.GetUnansweredQuestionBegin(), country.GetUnansweredQuestionEnd()));

    if (result != countryEntityContainer.cend())
    {
        countryEntityContainer.erase(result);
    }

    return countryEntity;
}

DatabaseEntity::DayEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const DayBase& day)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = dayEntityContainer.find(day.GetId());
    auto dayEntity = result != dayEntityContainer.cend() ? result->second : DayEntity{ databaseFlush->GetWrappersStrategy(), day.GetId() };

    dayEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(day.GetName()));

    if (result != dayEntityContainer.cend())
    {
        dayEntityContainer.erase(result);
    }

    return dayEntity;
}

DatabaseEntity::EmperorEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const EmperorBase& emperor)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = emperorEntityContainer.find(emperor.GetId());
    auto emperorEntity = result != emperorEntityContainer.cend() ? result->second : EmperorEntity{ databaseFlush->GetWrappersStrategy(), emperor.GetId() };

    emperorEntity.SetCharacter(emperor.GetCharacter());
    emperorEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(emperor.GetName()));
    emperorEntity.SetDynasticTitle(CoreTools::StringConversion::StandardConversionUtf8(emperor.GetDynasticTitle()));
    emperorEntity.SetDynasticTitleAlias(Convert(emperor.GetDynasticTitleAliasBegin(), emperor.GetDynasticTitleAliasEnd()));
    emperorEntity.SetPosthumousTitle(CoreTools::StringConversion::StandardConversionUtf8(emperor.GetPosthumousTitle()));
    emperorEntity.SetPosthumousTitleAlias(Convert(emperor.GetPosthumousTitleAliasBegin(), emperor.GetPosthumousTitleAliasEnd()));
    emperorEntity.SetBeginYear(emperor.GetBeginYear());
    emperorEntity.SetBeginMonth(emperor.GetBeginMonth());
    emperorEntity.SetBeginSexagenaryCycle(emperor.GetBeginSexagenaryCycle());
    emperorEntity.SetBeginDay(emperor.GetBeginDay());
    emperorEntity.SetEndYear(emperor.GetEndYear());
    emperorEntity.SetEndMonth(emperor.GetEndMonth());
    emperorEntity.SetEndSexagenaryCycle(emperor.GetEndSexagenaryCycle());
    emperorEntity.SetEndDay(emperor.GetEndDay());
    emperorEntity.SetAgainBeginYear(emperor.GetAgainBeginYear());
    emperorEntity.SetAgainBeginMonth(emperor.GetAgainBeginMonth());
    emperorEntity.SetAgainBeginSexagenaryCycle(emperor.GetAgainBeginSexagenaryCycle());
    emperorEntity.SetAgainBeginDay(emperor.GetAgainBeginDay());
    emperorEntity.SetAgainEndYear(emperor.GetAgainEndYear());
    emperorEntity.SetAgainEndMonth(emperor.GetAgainEndMonth());
    emperorEntity.SetAgainEndSexagenaryCycle(emperor.GetAgainEndSexagenaryCycle());
    emperorEntity.SetAgainEndDay(emperor.GetAgainEndDay());
    emperorEntity.SetUnansweredQuestion(Convert(emperor.GetUnansweredQuestionBegin(), emperor.GetUnansweredQuestionEnd()));

    if (result != emperorEntityContainer.cend())
    {
        emperorEntityContainer.erase(result);
    }

    return emperorEntity;
}

DatabaseEntity::GatherEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const GatherBase& gather)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = gatherEntityContainer.find(gather.GetId());
    auto gatherEntity = result != gatherEntityContainer.cend() ? result->second : GatherEntity{ databaseFlush->GetWrappersStrategy(), gather.GetId() };

    gatherEntity.SetGather(CoreTools::StringConversion::StandardConversionUtf8(gather.GetGather()));

    if (result != gatherEntityContainer.cend())
    {
        gatherEntityContainer.erase(result);
    }

    return gatherEntity;
}

DatabaseEntity::GenusEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const GenusBase& genus)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = genusEntityContainer.find(genus.GetId());
    auto genusEntity = result != genusEntityContainer.cend() ? result->second : GenusEntity{ databaseFlush->GetWrappersStrategy(), genus.GetId() };

    genusEntity.SetCategory(genus.GetCategory());
    genusEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(genus.GetName()));
    genusEntity.SetFather(genus.GetFather());
    genusEntity.SetBegin(CoreTools::StringConversion::StandardConversionUtf8(genus.GetBegin()));
    genusEntity.SetEnd(CoreTools::StringConversion::StandardConversionUtf8(genus.GetEnd()));

    if (result != genusEntityContainer.cend())
    {
        genusEntityContainer.erase(result);
    }

    return genusEntity;
}

DatabaseEntity::GeographicEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const GeographicBase& geographic)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = geographicEntityContainer.find(geographic.GetId());
    auto geographicEntity = result != geographicEntityContainer.cend() ? result->second : GeographicEntity{ databaseFlush->GetWrappersStrategy(), geographic.GetId() };

    geographicEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(geographic.GetName()));

    if (result != geographicEntityContainer.cend())
    {
        geographicEntityContainer.erase(result);
    }

    return geographicEntity;
}

DatabaseEntity::IdentityEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const IdentityBase& identity)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = identityEntityContainer.find(identity.GetId());
    auto identityEntity = result != identityEntityContainer.cend() ? result->second : IdentityEntity{ databaseFlush->GetWrappersStrategy(), identity.GetId() };

    identityEntity.SetIdentity(CoreTools::StringConversion::StandardConversionUtf8(identity.GetIdentity()));

    if (result != identityEntityContainer.cend())
    {
        identityEntityContainer.erase(result);
    }

    return identityEntity;
}

DatabaseEntity::ImperialCourtEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const ImperialCourtBase& imperialCourt)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = imperialCourtEntityContainer.find(imperialCourt.GetId());
    auto imperialCourtEntity = result != imperialCourtEntityContainer.cend() ? result->second : ImperialCourtEntity{ databaseFlush->GetWrappersStrategy(), imperialCourt.GetId() };

    imperialCourtEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetCategory()));
    imperialCourtEntity.SetBook(CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetBook()));
    imperialCourtEntity.SetBegin(imperialCourt.GetBegin());
    imperialCourtEntity.SetEnd(imperialCourt.GetEnd());

    if (result != imperialCourtEntityContainer.cend())
    {
        imperialCourtEntityContainer.erase(result);
    }

    return imperialCourtEntity;
}

DatabaseEntity::MonthEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const MonthBase& month)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = monthEntityContainer.find(month.GetId());
    auto monthEntity = result != monthEntityContainer.cend() ? result->second : MonthEntity{ databaseFlush->GetWrappersStrategy(), month.GetId() };

    monthEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(month.GetName()));

    if (result != monthEntityContainer.cend())
    {
        monthEntityContainer.erase(result);
    }

    return monthEntity;
}

DatabaseEntity::ReignTitleEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const ReignTitleBase& reignTitle)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = reignTitleEntityContainer.find(reignTitle.GetId());
    auto reignTitleEntity = result != reignTitleEntityContainer.cend() ? result->second : ReignTitleEntity{ databaseFlush->GetWrappersStrategy(), reignTitle.GetId() };

    reignTitleEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(reignTitle.GetName()));
    reignTitleEntity.SetEmperor(reignTitle.GetEmperor());
    reignTitleEntity.SetSerial(reignTitle.GetSerial());
    reignTitleEntity.SetBeginYear(reignTitle.GetBeginYear());
    reignTitleEntity.SetBeginMonth(reignTitle.GetBeginMonth());
    reignTitleEntity.SetBeginSexagenaryCycle(reignTitle.GetBeginSexagenaryCycle());
    reignTitleEntity.SetBeginDay(reignTitle.GetBeginDay());
    reignTitleEntity.SetEndYear(reignTitle.GetEndYear());
    reignTitleEntity.SetEndMonth(reignTitle.GetEndMonth());
    reignTitleEntity.SetEndSexagenaryCycle(reignTitle.GetEndSexagenaryCycle());
    reignTitleEntity.SetEndDay(reignTitle.GetEndDay());

    if (result != reignTitleEntityContainer.cend())
    {
        reignTitleEntityContainer.erase(result);
    }

    return reignTitleEntity;
}

DatabaseEntity::SexagenaryCycleEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const SexagenaryCycleBase& sexagenaryCycle)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = sexagenaryCycleEntityContainer.find(sexagenaryCycle.GetId());
    auto sexagenaryCycleEntity = result != sexagenaryCycleEntityContainer.cend() ? result->second : SexagenaryCycleEntity{ databaseFlush->GetWrappersStrategy(), sexagenaryCycle.GetId() };

    sexagenaryCycleEntity.SetHeavenly(CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetHeavenly()));
    sexagenaryCycleEntity.SetBranch(CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetBranch()));
    sexagenaryCycleEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetName()));

    if (result != sexagenaryCycleEntityContainer.cend())
    {
        sexagenaryCycleEntityContainer.erase(result);
    }

    return sexagenaryCycleEntity;
}

DatabaseEntity::SourceEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const SourceBase& source)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = sourceEntityContainer.find(source.GetId());
    auto sourceEntity = result != sourceEntityContainer.cend() ? result->second : SourceEntity{ databaseFlush->GetWrappersStrategy(), source.GetId() };

    sourceEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(source.GetName()));
    sourceEntity.SetSort(source.GetSort());

    if (result != sourceEntityContainer.cend())
    {
        sourceEntityContainer.erase(result);
    }

    return sourceEntity;
}

DatabaseEntity::VersionEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const VersionBase& version)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = versionEntityContainer.find(version.GetId());
    auto versionEntity = result != versionEntityContainer.cend() ? result->second : VersionEntity{ databaseFlush->GetWrappersStrategy(), version.GetId() };

    versionEntity.SetBook(version.GetBook());
    versionEntity.SetSource(version.GetSource());
    versionEntity.SetSourceName(CoreTools::StringConversion::StandardConversionUtf8(version.GetSourceName()));
    versionEntity.SetCountry(version.GetCountry());
    versionEntity.SetReignTitle(version.GetReignTitle());
    versionEntity.SetYear(version.GetYear());
    versionEntity.SetVersion(CoreTools::StringConversion::StandardConversionUtf8(version.GetVersion()));
    versionEntity.SetOtherAuthor(version.GetOtherAuthor());
    versionEntity.SetAuthorNotes(Convert(version.GetAuthorNotesBegin(), version.GetAuthorNotesEnd()));

    if (result != versionEntityContainer.cend())
    {
        versionEntityContainer.erase(result);
    }

    return versionEntity;
}

DatabaseEntity::YearEntity DatabaseGenerateCore::ConvertEntityImpl::Convert(const YearBase& year)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1;

    const auto result = yearEntityContainer.find(year.GetId());
    auto yearEntity = result != yearEntityContainer.cend() ? result->second : YearEntity{ databaseFlush->GetWrappersStrategy(), year.GetId() };

    yearEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(year.GetName()));
    yearEntity.SetSexagenaryCycle(year.GetSexagenaryCycle());
    yearEntity.SetReignTitle(year.GetReignTitle());
    yearEntity.SetYear(year.GetYear());
    yearEntity.SetUnorthodoxReignTitle(year.GetUnorthodoxReignTitle());
    yearEntity.SetUnorthodoxYear(year.GetUnorthodoxYear());

    if (result != yearEntityContainer.cend())
    {
        yearEntityContainer.erase(result);
    }

    return yearEntity;
}

void DatabaseGenerateCore::ConvertEntityImpl::DeleteInvalidDatabase()
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_1;

    DeleteInvalidDatabase(articleEntityContainer);
    DeleteInvalidDatabase(bookEntityContainer);
    DeleteInvalidDatabase(calendarEntityContainer);
    DeleteInvalidDatabase(categoryEntityContainer);
    DeleteInvalidDatabase(characterEntityContainer);
    DeleteInvalidDatabase(countryEntityContainer);
    DeleteInvalidDatabase(dayEntityContainer);
    DeleteInvalidDatabase(emperorEntityContainer);
    DeleteInvalidDatabase(gatherEntityContainer);
    DeleteInvalidDatabase(genusEntityContainer);
    DeleteInvalidDatabase(geographicEntityContainer);
    DeleteInvalidDatabase(identityEntityContainer);
    DeleteInvalidDatabase(imperialCourtEntityContainer);
    DeleteInvalidDatabase(monthEntityContainer);
    DeleteInvalidDatabase(reignTitleEntityContainer);
    DeleteInvalidDatabase(sexagenaryCycleEntityContainer);
    DeleteInvalidDatabase(sourceEntityContainer);
    DeleteInvalidDatabase(versionEntityContainer);
    DeleteInvalidDatabase(yearEntityContainer);
}
