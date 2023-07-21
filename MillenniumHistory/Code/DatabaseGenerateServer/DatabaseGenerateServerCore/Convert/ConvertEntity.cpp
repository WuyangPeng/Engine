///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/16 15:56)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreExport.h"

#include "ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "Detail/ConvertEntityImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerCore::ConvertEntity::ConvertEntity(const DatabaseFlushSharedPtr& databaseFlush) noexcept
    : impl{ databaseFlush }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateServerCore, ConvertEntity)

DatabaseEntity::ArticleEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const ArticleBase& article) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(article);
}

DatabaseEntity::BookEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const BookBase& book) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(book);
}

DatabaseEntity::CalendarEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const CalendarBase& calendar) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(calendar);
}

DatabaseEntity::CategoryEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const CategoryBase& category) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(category);
}

DatabaseEntity::CharacterEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const CharacterBase& character) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(character);
}

DatabaseEntity::CountryEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const CountryBase& country) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(country);
}

DatabaseEntity::DayEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const DayBase& day) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(day);
}

DatabaseEntity::EmperorEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const EmperorBase& emperor) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(emperor);
}

DatabaseEntity::GatherEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const GatherBase& gather) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(gather);
}

DatabaseEntity::GenusEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const GenusBase& genus) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(genus);
}

DatabaseEntity::GeographicEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const GeographicBase& geographic) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(geographic);
}

DatabaseEntity::IdentityEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const IdentityBase& identity) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(identity);
}

DatabaseEntity::ImperialCourtEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const ImperialCourtBase& imperialCourt) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(imperialCourt);
}

DatabaseEntity::MonthEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const MonthBase& month) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(month);
}

DatabaseEntity::ReignTitleEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const ReignTitleBase& reignTitle) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(reignTitle);
}

DatabaseEntity::SexagenaryCycleEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const SexagenaryCycleBase& sexagenaryCycle) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(sexagenaryCycle);
}

DatabaseEntity::SourceEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const SourceBase& source) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(source);
}

DatabaseEntity::VersionEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const VersionBase& version) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(version);
}

DatabaseEntity::YearEntity DatabaseGenerateServerCore::ConvertEntity::Convert(const YearBase& year) const
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(year);
}
