///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/16 15:55)

#ifndef DATABASE_GENERATE_SERVER_CORE_CONVERT_CONVERT_ENTITY_H
#define DATABASE_GENERATE_SERVER_CORE_CONVERT_CONVERT_ENTITY_H

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooks.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntity.h"
#include "Framework/Helper/UserMacro.h"

EXPORT_SHARED_PTR(DatabaseGenerateServerCore, ConvertEntityImpl, DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE);
EXPORT_NON_COPY(DatabaseGenerateServerCore, ConvertEntityImpl, DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE);

namespace DatabaseGenerateServerCore
{
    using namespace AncientBooks;
    using namespace DatabaseEntity;

    class DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE ConvertEntity final
    {
    public:
        NON_COPY_TYPE_DECLARE(ConvertEntity);

        using DatabaseFlush = Database::DatabaseFlush;
        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlush>;

    public:
        explicit ConvertEntity(const DatabaseFlushSharedPtr& databaseFlush) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ArticleEntity Convert(const ArticleBase& article) const;
        NODISCARD BookEntity Convert(const BookBase& book) const;
        NODISCARD CalendarEntity Convert(const CalendarBase& calendar) const;
        NODISCARD CategoryEntity Convert(const CategoryBase& category) const;
        NODISCARD CharacterEntity Convert(const CharacterBase& character) const;
        NODISCARD CountryEntity Convert(const CountryBase& country) const;
        NODISCARD DayEntity Convert(const DayBase& day) const;
        NODISCARD EmperorEntity Convert(const EmperorBase& emperor) const;
        NODISCARD GatherEntity Convert(const GatherBase& gather) const;
        NODISCARD GenusEntity Convert(const GenusBase& genus) const;
        NODISCARD GeographicEntity Convert(const GeographicBase& geographic) const;
        NODISCARD IdentityEntity Convert(const IdentityBase& identity) const;
        NODISCARD ImperialCourtEntity Convert(const ImperialCourtBase& imperialCourt) const;
        NODISCARD MonthEntity Convert(const MonthBase& month) const;
        NODISCARD ReignTitleEntity Convert(const ReignTitleBase& reignTitle) const;
        NODISCARD SexagenaryCycleEntity Convert(const SexagenaryCycleBase& sexagenaryCycle) const;
        NODISCARD SourceEntity Convert(const SourceBase& source) const;
        NODISCARD VersionEntity Convert(const VersionBase& version) const;
        NODISCARD YearEntity Convert(const YearBase& year) const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_CONVERT_CONVERT_ENTITY_H