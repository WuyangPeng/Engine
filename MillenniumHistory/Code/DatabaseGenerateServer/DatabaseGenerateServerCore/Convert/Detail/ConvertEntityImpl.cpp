///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/16 15:56)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreExport.h"

#include "ConvertEntityImpl.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerCore::ConvertEntityImpl::ConvertEntityImpl(const DatabaseFlushSharedPtr& databaseFlush) noexcept
    : databaseFlush{ databaseFlush }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool DatabaseGenerateServerCore::ConvertEntityImpl::IsValid() const noexcept
{
    return databaseFlush != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

DatabaseEntity::ArticleEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const ArticleBase& article) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(ArticleEntity::GetSelect(databaseFlush->GetWrappersStrategy(), article.GetId()),
                                                   ArticleEntity::GetDatabaseFieldContainer());

    auto articleEntity = ArticleEntity::Create(database, databaseFlush->GetWrappersStrategy(), article.GetId());

    articleEntity.SetVersion(article.GetVersion());
    articleEntity.SetChapter(article.GetChapter());
    articleEntity.SetChapterName(CoreTools::StringConversion::StandardConversionUtf8(article.GetChapterName()));
    articleEntity.SetChapterVolume(article.GetChapterVolume());
    articleEntity.SetOtherAuthor(article.GetOtherAuthor());
    articleEntity.SetAuthorNotes(Convert(article.GetAuthorNotesBegin(), article.GetAuthorNotesEnd()));
    articleEntity.SetTitle(CoreTools::StringConversion::StandardConversionUtf8(article.GetTitle()));
    articleEntity.SetAbbreviation(CoreTools::StringConversion::StandardConversionUtf8(article.GetAbbreviation()));
    articleEntity.SetDirectory(CoreTools::StringConversion::StandardConversionUtf8(article.GetDirectory()));

    return articleEntity;
}

Database::Traits::StringArray DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const StringContainerConstIter& begin, const StringContainerConstIter& end)
{
    Database::Traits::StringArray result{};
    for (auto iter = begin; iter != end; ++iter)
    {
        result.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
    }

    return result;
}

DatabaseEntity::BookEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const BookBase& book) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(BookEntity::GetSelect(databaseFlush->GetWrappersStrategy(), book.GetId()),
                                                   BookEntity::GetDatabaseFieldContainer());

    auto bookEntity = BookEntity::Create(database, databaseFlush->GetWrappersStrategy(), book.GetId());

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

    return bookEntity;
}

DatabaseEntity::CalendarEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const CalendarBase& calendar) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(CalendarEntity::GetSelect(databaseFlush->GetWrappersStrategy(), calendar.GetId()),
                                                   CalendarEntity::GetDatabaseFieldContainer());

    auto calendarEntity = CalendarEntity::Create(database, databaseFlush->GetWrappersStrategy(), calendar.GetId());

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

    return calendarEntity;
}

DatabaseEntity::CategoryEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const CategoryBase& category) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(CategoryEntity::GetSelect(databaseFlush->GetWrappersStrategy(), category.GetId()),
                                                   CategoryEntity::GetDatabaseFieldContainer());

    auto categoryEntity = CategoryEntity::Create(database, databaseFlush->GetWrappersStrategy(), category.GetId());

    categoryEntity.SetGather(category.GetGather());
    categoryEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(category.GetCategory()));

    return categoryEntity;
}

DatabaseEntity::CharacterEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const CharacterBase& character) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(CharacterEntity::GetSelect(databaseFlush->GetWrappersStrategy(), character.GetId()),
                                                   CharacterEntity::GetDatabaseFieldContainer());

    auto characterEntity = CharacterEntity::Create(database, databaseFlush->GetWrappersStrategy(), character.GetId());

    characterEntity.SetCountry(character.GetCountry());
    characterEntity.SetIdentity(character.GetIdentity());
    characterEntity.SetFamily(CoreTools::StringConversion::StandardConversionUtf8(character.GetFamily()));
    characterEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(character.GetName()));
    characterEntity.SetFullName(CoreTools::StringConversion::StandardConversionUtf8(character.GetFullName()));
    characterEntity.SetAlias(Convert(character.GetAliasBegin(), character.GetAliasBegin()));
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

    return characterEntity;
}

DatabaseEntity::CountryEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const CountryBase& country) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(CountryEntity::GetSelect(databaseFlush->GetWrappersStrategy(), country.GetId()),
                                                   CountryEntity::GetDatabaseFieldContainer());

    auto countryEntity = CountryEntity::Create(database, databaseFlush->GetWrappersStrategy(), country.GetId());

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

    return countryEntity;
}

DatabaseEntity::DayEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const DayBase& day) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(DayEntity::GetSelect(databaseFlush->GetWrappersStrategy(), day.GetId()),
                                                   DayEntity::GetDatabaseFieldContainer());

    auto dayEntity = DayEntity::Create(database, databaseFlush->GetWrappersStrategy(), day.GetId());

    dayEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(day.GetName()));

    return dayEntity;
}

DatabaseEntity::EmperorEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const EmperorBase& emperor) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(EmperorEntity::GetSelect(databaseFlush->GetWrappersStrategy(), emperor.GetId()),
                                                   EmperorEntity::GetDatabaseFieldContainer());

    auto emperorEntity = EmperorEntity::Create(database, databaseFlush->GetWrappersStrategy(), emperor.GetId());

    emperorEntity.SetCharacter(emperor.GetCharacter());
    emperorEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(emperor.GetName()));
    emperorEntity.SetDynasticTitle(CoreTools::StringConversion::StandardConversionUtf8(emperor.GetDynasticTitle()));
    Database::Traits::StringArray dynasticTitleAlias{};
    for (auto iter = emperor.GetDynasticTitleAliasBegin(); iter != emperor.GetDynasticTitleAliasEnd(); ++iter)
    {
        dynasticTitleAlias.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
    }
    emperorEntity.SetDynasticTitleAlias(dynasticTitleAlias);

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

    return emperorEntity;
}

DatabaseEntity::GatherEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const GatherBase& gather) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(GatherEntity::GetSelect(databaseFlush->GetWrappersStrategy(), gather.GetId()),
                                                   GatherEntity::GetDatabaseFieldContainer());

    auto gatherEntity = GatherEntity::Create(database, databaseFlush->GetWrappersStrategy(), gather.GetId());

    gatherEntity.SetGather(CoreTools::StringConversion::StandardConversionUtf8(gather.GetGather()));

    return gatherEntity;
}

DatabaseEntity::GenusEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const GenusBase& genus) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(GenusEntity::GetSelect(databaseFlush->GetWrappersStrategy(), genus.GetId()),
                                                   GenusEntity::GetDatabaseFieldContainer());

    auto genusEntity = GenusEntity::Create(database, databaseFlush->GetWrappersStrategy(), genus.GetId());

    genusEntity.SetCategory(genus.GetCategory());
    genusEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(genus.GetName()));
    genusEntity.SetFather(genus.GetFather());
    genusEntity.SetBegin(CoreTools::StringConversion::StandardConversionUtf8(genus.GetBegin()));
    genusEntity.SetEnd(CoreTools::StringConversion::StandardConversionUtf8(genus.GetEnd()));

    return genusEntity;
}

DatabaseEntity::GeographicEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const GeographicBase& geographic) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(GeographicEntity::GetSelect(databaseFlush->GetWrappersStrategy(), geographic.GetId()),
                                                   GeographicEntity::GetDatabaseFieldContainer());

    auto geographicEntity = GeographicEntity::Create(database, databaseFlush->GetWrappersStrategy(), geographic.GetId());

    geographicEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(geographic.GetName()));

    return geographicEntity;
}

DatabaseEntity::IdentityEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const IdentityBase& identity) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(IdentityEntity::GetSelect(databaseFlush->GetWrappersStrategy(), identity.GetId()),
                                                   IdentityEntity::GetDatabaseFieldContainer());

    auto identityEntity = IdentityEntity::Create(database, databaseFlush->GetWrappersStrategy(), identity.GetId());

    identityEntity.SetIdentity(CoreTools::StringConversion::StandardConversionUtf8(identity.GetIdentity()));

    return identityEntity;
}

DatabaseEntity::ImperialCourtEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const ImperialCourtBase& imperialCourt) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(ImperialCourtEntity::GetSelect(databaseFlush->GetWrappersStrategy(), imperialCourt.GetId()),
                                                   ImperialCourtEntity::GetDatabaseFieldContainer());

    auto imperialCourtEntity = ImperialCourtEntity::Create(database, databaseFlush->GetWrappersStrategy(), imperialCourt.GetId());

    imperialCourtEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetCategory()));
    imperialCourtEntity.SetBook(CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetBook()));
    imperialCourtEntity.SetBegin(imperialCourt.GetBegin());
    imperialCourtEntity.SetEnd(imperialCourt.GetEnd());

    return imperialCourtEntity;
}

DatabaseEntity::MonthEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const MonthBase& month) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(MonthEntity::GetSelect(databaseFlush->GetWrappersStrategy(), month.GetId()),
                                                   MonthEntity::GetDatabaseFieldContainer());

    auto monthEntity = MonthEntity::Create(database, databaseFlush->GetWrappersStrategy(), month.GetId());

    monthEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(month.GetName()));

    return monthEntity;
}

DatabaseEntity::ReignTitleEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const ReignTitleBase& reignTitle) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(ReignTitleEntity::GetSelect(databaseFlush->GetWrappersStrategy(), reignTitle.GetId()),
                                                   ReignTitleEntity::GetDatabaseFieldContainer());

    auto reignTitleEntity = ReignTitleEntity::Create(database, databaseFlush->GetWrappersStrategy(), reignTitle.GetId());

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

    return reignTitleEntity;
}

DatabaseEntity::SexagenaryCycleEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const SexagenaryCycleBase& sexagenaryCycle) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(SexagenaryCycleEntity::GetSelect(databaseFlush->GetWrappersStrategy(), sexagenaryCycle.GetId()),
                                                   SexagenaryCycleEntity::GetDatabaseFieldContainer());

    auto sexagenaryCycleEntity = SexagenaryCycleEntity::Create(database, databaseFlush->GetWrappersStrategy(), sexagenaryCycle.GetId());

    sexagenaryCycleEntity.SetHeavenly(CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetHeavenly()));
    sexagenaryCycleEntity.SetBranch(CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetBranch()));
    sexagenaryCycleEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetName()));

    return sexagenaryCycleEntity;
}

DatabaseEntity::SourceEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const SourceBase& source) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(SourceEntity::GetSelect(databaseFlush->GetWrappersStrategy(), source.GetId()),
                                                   SourceEntity::GetDatabaseFieldContainer());

    auto sourceEntity = SourceEntity::Create(database, databaseFlush->GetWrappersStrategy(), source.GetId());

    sourceEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(source.GetName()));
    sourceEntity.SetSort(source.GetSort());

    return sourceEntity;
}

DatabaseEntity::VersionEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const VersionBase& version) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(VersionEntity::GetSelect(databaseFlush->GetWrappersStrategy(), version.GetId()),
                                                   VersionEntity::GetDatabaseFieldContainer());

    auto versionEntity = VersionEntity::Create(database, databaseFlush->GetWrappersStrategy(), version.GetId());

    versionEntity.SetBook(version.GetBook());
    versionEntity.SetSource(version.GetSource());
    versionEntity.SetSourceName(CoreTools::StringConversion::StandardConversionUtf8(version.GetSourceName()));
    versionEntity.SetCountry(version.GetCountry());
    versionEntity.SetReignTitle(version.GetReignTitle());
    versionEntity.SetYear(version.GetYear());
    versionEntity.SetVersion(CoreTools::StringConversion::StandardConversionUtf8(version.GetVersion()));
    versionEntity.SetOtherAuthor(version.GetOtherAuthor());
    versionEntity.SetAuthorNotes(Convert(version.GetAuthorNotesBegin(), version.GetAuthorNotesEnd()));

    return versionEntity;
}

DatabaseEntity::YearEntity DatabaseGenerateServerCore::ConvertEntityImpl::Convert(const YearBase& year) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_1;

    const auto database = databaseFlush->SelectOne(YearEntity::GetSelect(databaseFlush->GetWrappersStrategy(), year.GetId()),
                                                   YearEntity::GetDatabaseFieldContainer());

    auto yearEntity = YearEntity::Create(database, databaseFlush->GetWrappersStrategy(), year.GetId());

    yearEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(year.GetName()));
    yearEntity.SetSexagenaryCycle(year.GetSexagenaryCycle());
    yearEntity.SetReignTitle(year.GetReignTitle());
    yearEntity.SetYear(year.GetYear());
    yearEntity.SetUnorthodoxReignTitle(year.GetUnorthodoxReignTitle());
    yearEntity.SetUnorthodoxYear(year.GetUnorthodoxYear());

    return yearEntity;
}
