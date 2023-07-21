/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "VersionEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::VersionEntity DatabaseEntity::VersionEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? VersionEntity{ entity } : VersionEntity{ wrappersStrategy, id };
}

DatabaseEntity::VersionEntity::VersionEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      book{ entity.GetValue<DataType::Int32>(bookDescribe) },
      source{ entity.GetValue<DataType::Int32>(sourceDescribe) },
      sourceName{ entity.GetValue<DataType::String>(sourceNameDescribe) },
      country{ entity.GetValue<DataType::Int32>(countryDescribe) },
      reignTitle{ entity.GetValue<DataType::Int64>(reignTitleDescribe) },
      year{ entity.GetValue<DataType::Int32>(yearDescribe) },
      version{ entity.GetValue<DataType::String>(versionDescribe) },
      otherAuthor{ entity.GetValue<DataType::Int32Array>(otherAuthorDescribe) },
      authorNotes{ entity.GetValue<DataType::StringArray>(authorNotesDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::VersionEntity::VersionEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      book{ Database::Traits::Int32{} },
      source{ Database::Traits::Int32{} },
      sourceName{ Database::Traits::String{} },
      country{ Database::Traits::Int32{} },
      reignTitle{ Database::Traits::Int64{} },
      year{ Database::Traits::Int32{} },
      version{ Database::Traits::String{} },
      otherAuthor{ Database::Traits::Int32Array{} },
      authorNotes{ Database::Traits::StringArray{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, VersionEntity)

Database::Traits::Int32 DatabaseEntity::VersionEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::Int32 DatabaseEntity::VersionEntity::GetBook() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return book.GetValue();
}

Database::Traits::Int32 DatabaseEntity::VersionEntity::GetSource() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return source.GetValue();
}

Database::Traits::String DatabaseEntity::VersionEntity::GetSourceName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return sourceName.GetValue();
}

Database::Traits::Int32 DatabaseEntity::VersionEntity::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.GetValue();
}

Database::Traits::Int64 DatabaseEntity::VersionEntity::GetReignTitle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reignTitle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::VersionEntity::GetYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return year.GetValue();
}

Database::Traits::String DatabaseEntity::VersionEntity::GetVersion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return version.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::VersionEntity::GetOtherAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor.GetValue();
}

Database::Traits::StringArray DatabaseEntity::VersionEntity::GetAuthorNotes() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorNotes.GetValue();
}

void DatabaseEntity::VersionEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::VersionEntity::SetBook(Database::Traits::ParamType::Int32 aBook)
{
    USER_CLASS_IS_VALID_9;

    if (aBook != GetBook())
    {
        book.SetValue(aBook);

        AddModify(bookDescribe, GetBook());
    }
}

void DatabaseEntity::VersionEntity::SetSource(Database::Traits::ParamType::Int32 aSource)
{
    USER_CLASS_IS_VALID_9;

    if (aSource != GetSource())
    {
        source.SetValue(aSource);

        AddModify(sourceDescribe, GetSource());
    }
}

void DatabaseEntity::VersionEntity::SetSourceName(Database::Traits::ParamType::String aSourceName)
{
    USER_CLASS_IS_VALID_9;

    if (aSourceName != GetSourceName())
    {
        sourceName.SetValue(aSourceName);

        AddModify(sourceNameDescribe, GetSourceName());
    }
}

void DatabaseEntity::VersionEntity::SetCountry(Database::Traits::ParamType::Int32 aCountry)
{
    USER_CLASS_IS_VALID_9;

    if (aCountry != GetCountry())
    {
        country.SetValue(aCountry);

        AddModify(countryDescribe, GetCountry());
    }
}

void DatabaseEntity::VersionEntity::SetReignTitle(Database::Traits::ParamType::Int64 aReignTitle)
{
    USER_CLASS_IS_VALID_9;

    if (aReignTitle != GetReignTitle())
    {
        reignTitle.SetValue(aReignTitle);

        AddModify(reignTitleDescribe, GetReignTitle());
    }
}

void DatabaseEntity::VersionEntity::SetYear(Database::Traits::ParamType::Int32 aYear)
{
    USER_CLASS_IS_VALID_9;

    if (aYear != GetYear())
    {
        year.SetValue(aYear);

        AddModify(yearDescribe, GetYear());
    }
}

void DatabaseEntity::VersionEntity::SetVersion(Database::Traits::ParamType::String aVersion)
{
    USER_CLASS_IS_VALID_9;

    if (aVersion != GetVersion())
    {
        version.SetValue(aVersion);

        AddModify(versionDescribe, GetVersion());
    }
}

void DatabaseEntity::VersionEntity::SetOtherAuthor(Database::Traits::ParamType::Int32Array aOtherAuthor)
{
    USER_CLASS_IS_VALID_9;

    if (aOtherAuthor != GetOtherAuthor())
    {
        otherAuthor.SetValue(aOtherAuthor);

        AddModify(otherAuthorDescribe, GetOtherAuthor());
    }
}

void DatabaseEntity::VersionEntity::SetAuthorNotes(Database::Traits::ParamType::StringArray aAuthorNotes)
{
    USER_CLASS_IS_VALID_9;

    if (aAuthorNotes != GetAuthorNotes())
    {
        authorNotes.SetValue(aAuthorNotes);

        AddModify(authorNotesDescribe, GetAuthorNotes());
    }
}

const DatabaseEntity::VersionEntity::DatabaseFieldContainer& DatabaseEntity::VersionEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(book)::GetDatabaseField(),
                                                            decltype(source)::GetDatabaseField(),
                                                            decltype(sourceName)::GetDatabaseField(),
                                                            decltype(country)::GetDatabaseField(),
                                                            decltype(reignTitle)::GetDatabaseField(),
                                                            decltype(year)::GetDatabaseField(),
                                                            decltype(version)::GetDatabaseField(),
                                                            decltype(otherAuthor)::GetDatabaseField(),
                                                            decltype(authorNotes)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::VersionEntity::BasisDatabaseManager DatabaseEntity::VersionEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

Database::BasisDatabaseContainer DatabaseEntity::VersionEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
