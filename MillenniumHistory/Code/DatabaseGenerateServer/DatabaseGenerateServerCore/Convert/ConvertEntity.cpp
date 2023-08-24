///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/07/31 21:57)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreExport.h"

#include "ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "Detail/ConvertEntityImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerCore::ConvertEntity::ConvertEntity(const DatabaseFlushSharedPtr& databaseFlush)
    : impl{ databaseFlush }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateServerCore, ConvertEntity)

DatabaseEntity::ArticleEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const ArticleBase& article)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(article);
}

DatabaseEntity::BookEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const BookBase& book)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(book);
}

DatabaseEntity::CalendarEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const CalendarBase& calendar)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(calendar);
}

DatabaseEntity::CategoryEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const CategoryBase& category)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(category);
}

DatabaseEntity::CharacterEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const CharacterBase& character)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(character);
}

DatabaseEntity::CountryEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const CountryBase& country)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(country);
}

DatabaseEntity::DayEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const DayBase& day)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(day);
}

DatabaseEntity::EmperorEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const EmperorBase& emperor)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(emperor);
}

DatabaseEntity::GatherEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const GatherBase& gather)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(gather);
}

DatabaseEntity::GenusEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const GenusBase& genus)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(genus);
}

DatabaseEntity::GeographicEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const GeographicBase& geographic)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(geographic);
}

DatabaseEntity::IdentityEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const IdentityBase& identity)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(identity);
}

DatabaseEntity::ImperialCourtEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const ImperialCourtBase& imperialCourt)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(imperialCourt);
}

DatabaseEntity::MonthEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const MonthBase& month)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(month);
}

DatabaseEntity::ReignTitleEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const ReignTitleBase& reignTitle)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(reignTitle);
}

DatabaseEntity::SexagenaryCycleEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const SexagenaryCycleBase& sexagenaryCycle)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(sexagenaryCycle);
}

DatabaseEntity::SourceEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const SourceBase& source)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(source);
}

DatabaseEntity::VersionEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const VersionBase& version)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(version);
}

DatabaseEntity::YearEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const YearBase& year)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(year);
}

void DatabaseGenerateServerCore::ConvertEntity::DeleteInvalidDatabase()
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_9;

    return impl->DeleteInvalidDatabase();
}