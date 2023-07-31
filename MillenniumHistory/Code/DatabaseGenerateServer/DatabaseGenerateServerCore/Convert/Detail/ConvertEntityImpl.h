///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/16 15:55)

#ifndef DATABASE_GENERATE_SERVER_CORE_CONVERT_CONVERT_ENTITY_IMPL_H
#define DATABASE_GENERATE_SERVER_CORE_CONVERT_CONVERT_ENTITY_IMPL_H

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooks.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntity.h"
#include "Framework/Helper/UserMacro.h"

#include <map>

namespace DatabaseGenerateServerCore
{
    using namespace AncientBooks;
    using namespace DatabaseEntity;

    class DATABASE_GENERATE_SERVER_CORE_HIDDEN_DECLARE ConvertEntityImpl final
    {
    public:
        using ClassType = ConvertEntityImpl;

        using DatabaseFlush = Database::DatabaseFlush;
        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlush>;

    public:
        explicit ConvertEntityImpl(const DatabaseFlushSharedPtr& databaseFlush);

        CLASS_INVARIANT_DECLARE;

        void DeleteInvalidDatabase();

        NODISCARD ArticleEntity Convert(const ArticleBase& article);
        NODISCARD BookEntity Convert(const BookBase& book);
        NODISCARD CalendarEntity Convert(const CalendarBase& calendar);
        NODISCARD CategoryEntity Convert(const CategoryBase& category);
        NODISCARD CharacterEntity Convert(const CharacterBase& character);
        NODISCARD CountryEntity Convert(const CountryBase& country);
        NODISCARD DayEntity Convert(const DayBase& day);
        NODISCARD EmperorEntity Convert(const EmperorBase& emperor);
        NODISCARD GatherEntity Convert(const GatherBase& gather);
        NODISCARD GenusEntity Convert(const GenusBase& genus);
        NODISCARD GeographicEntity Convert(const GeographicBase& geographic);
        NODISCARD IdentityEntity Convert(const IdentityBase& identity);
        NODISCARD ImperialCourtEntity Convert(const ImperialCourtBase& imperialCourt);
        NODISCARD MonthEntity Convert(const MonthBase& month);
        NODISCARD ReignTitleEntity Convert(const ReignTitleBase& reignTitle);
        NODISCARD SexagenaryCycleEntity Convert(const SexagenaryCycleBase& sexagenaryCycle);
        NODISCARD SourceEntity Convert(const SourceBase& source);
        NODISCARD VersionEntity Convert(const VersionBase& version);
        NODISCARD YearEntity Convert(const YearBase& year);

    private:
        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;
        using StringArray = Database::Traits::StringArray;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using ResultContainer = std::vector<BasisDatabaseManager>;
        using ArticleEntityContainer = std::map<int64_t, ArticleEntity>;
        using BookEntityContainer = std::map<int32_t, BookEntity>;
        using CalendarEntityContainer = std::map<int32_t, CalendarEntity>;
        using CategoryEntityContainer = std::map<int32_t, CategoryEntity>;
        using CharacterEntityContainer = std::map<int32_t, CharacterEntity>;
        using CountryEntityContainer = std::map<int32_t, CountryEntity>;
        using DayEntityContainer = std::map<int32_t, DayEntity>;
        using EmperorEntityContainer = std::map<int32_t, EmperorEntity>;
        using GatherEntityContainer = std::map<int32_t, GatherEntity>;
        using GenusEntityContainer = std::map<int32_t, GenusEntity>;
        using GeographicEntityContainer = std::map<int32_t, GeographicEntity>;
        using IdentityEntityContainer = std::map<int32_t, IdentityEntity>;
        using ImperialCourtEntityContainer = std::map<int32_t, ImperialCourtEntity>;
        using MonthEntityContainer = std::map<int32_t, MonthEntity>;
        using ReignTitleEntityContainer = std::map<int64_t, ReignTitleEntity>;
        using SexagenaryCycleEntityContainer = std::map<int32_t, SexagenaryCycleEntity>;
        using SourceEntityContainer = std::map<int32_t, SourceEntity>;
        using VersionEntityContainer = std::map<int32_t, VersionEntity>;
        using YearEntityContainer = std::map<int32_t, YearEntity>;

    private:
        NODISCARD static StringArray Convert(const StringContainerConstIter& begin, const StringContainerConstIter& end);

        template <typename KeyType, typename EntityType>
        NODISCARD std::map<KeyType, EntityType> GetEntityContainer(const ResultContainer& database);

        template <typename EntityContainerType>
        void DeleteInvalidDatabase(const EntityContainerType& entityContainer);

    private:
        DatabaseFlushSharedPtr databaseFlush;
        ArticleEntityContainer articleEntityContainer;
        BookEntityContainer bookEntityContainer;
        CalendarEntityContainer calendarEntityContainer;
        CategoryEntityContainer categoryEntityContainer;
        CharacterEntityContainer characterEntityContainer;
        CountryEntityContainer countryEntityContainer;
        DayEntityContainer dayEntityContainer;
        EmperorEntityContainer emperorEntityContainer;
        GatherEntityContainer gatherEntityContainer;
        GenusEntityContainer genusEntityContainer;
        GeographicEntityContainer geographicEntityContainer;
        IdentityEntityContainer identityEntityContainer;
        ImperialCourtEntityContainer imperialCourtEntityContainer;
        MonthEntityContainer monthEntityContainer;
        ReignTitleEntityContainer reignTitleEntityContainer;
        SexagenaryCycleEntityContainer sexagenaryCycleEntityContainer;
        SourceEntityContainer sourceEntityContainer;
        VersionEntityContainer versionEntityContainer;
        YearEntityContainer yearEntityContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_CONVERT_CONVERT_ENTITY_IMPL_H