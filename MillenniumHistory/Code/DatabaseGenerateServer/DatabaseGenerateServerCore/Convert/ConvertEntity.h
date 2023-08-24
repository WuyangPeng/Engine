///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/07/31 21:56)

#ifndef DATABASE_GENERATE_SERVER_CORE_CONVERT_CONVERT_ENTITY_H
#define DATABASE_GENERATE_SERVER_CORE_CONVERT_CONVERT_ENTITY_H

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooks.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/ExportMacro.h"
#include "Framework/Helper/UserMacro.h"

DATABASE_GENERATE_SERVER_CORE_EXPORT_NON_COPY(ConvertEntityImpl);

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

#endif  // DATABASE_GENERATE_SERVER_CORE_CONVERT_CONVERT_ENTITY_H