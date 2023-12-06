/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/28 22:29)

#include "DatabaseGenerate/DatabaseGenerateCore/DatabaseGenerateCoreExport.h"

#include "ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "Detail/ConvertEntityImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateCore::ConvertEntity::ConvertEntity(const DatabaseFlushSharedPtr& databaseFlush)
    : impl{ databaseFlush }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateCore, ConvertEntity)

DatabaseEntity::ArticleEntity DatabaseGenerateCore::ConvertEntity::Convert(const ArticleBase& article)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(article);
}

DatabaseEntity::BookEntity DatabaseGenerateCore::ConvertEntity::Convert(const BookBase& book)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(book);
}

DatabaseEntity::CalendarEntity DatabaseGenerateCore::ConvertEntity::Convert(const CalendarBase& calendar)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(calendar);
}

DatabaseEntity::CategoryEntity DatabaseGenerateCore::ConvertEntity::Convert(const CategoryBase& category)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(category);
}

DatabaseEntity::CharacterEntity DatabaseGenerateCore::ConvertEntity::Convert(const CharacterBase& character)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(character);
}

DatabaseEntity::CountryEntity DatabaseGenerateCore::ConvertEntity::Convert(const CountryBase& country)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(country);
}

DatabaseEntity::DayEntity DatabaseGenerateCore::ConvertEntity::Convert(const DayBase& day)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(day);
}

DatabaseEntity::EmperorEntity DatabaseGenerateCore::ConvertEntity::Convert(const EmperorBase& emperor)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(emperor);
}

DatabaseEntity::GatherEntity DatabaseGenerateCore::ConvertEntity::Convert(const GatherBase& gather)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(gather);
}

DatabaseEntity::GenusEntity DatabaseGenerateCore::ConvertEntity::Convert(const GenusBase& genus)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(genus);
}

DatabaseEntity::GeographicEntity DatabaseGenerateCore::ConvertEntity::Convert(const GeographicBase& geographic)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(geographic);
}

DatabaseEntity::IdentityEntity DatabaseGenerateCore::ConvertEntity::Convert(const IdentityBase& identity)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(identity);
}

DatabaseEntity::ImperialCourtEntity DatabaseGenerateCore::ConvertEntity::Convert(const ImperialCourtBase& imperialCourt)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(imperialCourt);
}

DatabaseEntity::MonthEntity DatabaseGenerateCore::ConvertEntity::Convert(const MonthBase& month)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(month);
}

DatabaseEntity::ReignTitleEntity DatabaseGenerateCore::ConvertEntity::Convert(const ReignTitleBase& reignTitle)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(reignTitle);
}

DatabaseEntity::SexagenaryCycleEntity DatabaseGenerateCore::ConvertEntity::Convert(const SexagenaryCycleBase& sexagenaryCycle)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(sexagenaryCycle);
}

DatabaseEntity::SourceEntity DatabaseGenerateCore::ConvertEntity::Convert(const SourceBase& source)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(source);
}

DatabaseEntity::VersionEntity DatabaseGenerateCore::ConvertEntity::Convert(const VersionBase& version)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(version);
}

DatabaseEntity::YearEntity DatabaseGenerateCore::ConvertEntity::Convert(const YearBase& year)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9;

    return impl->Convert(year);
}

void DatabaseGenerateCore::ConvertEntity::DeleteInvalidDatabase()
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_9;

    return impl->DeleteInvalidDatabase();
}