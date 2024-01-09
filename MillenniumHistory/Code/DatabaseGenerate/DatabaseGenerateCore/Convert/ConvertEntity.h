/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:29)

#ifndef DATABASE_GENERATE_CORE_CONVERT_CONVERT_ENTITY_H
#define DATABASE_GENERATE_CORE_CONVERT_CONVERT_ENTITY_H

#include "DatabaseGenerate/DatabaseGenerateCore/DatabaseGenerateCoreDll.h"

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooks.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/ExportMacro.h"

DATABASE_GENERATE_CORE_EXPORT_NON_COPY(ConvertEntityImpl);

namespace DatabaseGenerateCore
{
    using namespace AncientBooks;
    using namespace DatabaseEntity;

    class DATABASE_GENERATE_CORE_DEFAULT_DECLARE ConvertEntity final
    {
    public:
        NON_COPY_TYPE_DECLARE(ConvertEntity);

        using DatabaseFlush = Database::DatabaseFlush;
        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlush>;

    public:
        explicit ConvertEntity(const DatabaseFlushSharedPtr& databaseFlush);

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
        PackageType impl;
    };
}

#endif  // DATABASE_GENERATE_CORE_CONVERT_CONVERT_ENTITY_H