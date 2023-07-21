/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "CalendarEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::CalendarEntity DatabaseEntity::CalendarEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? CalendarEntity{ entity } : CalendarEntity{ wrappersStrategy, id };
}

DatabaseEntity::CalendarEntity::CalendarEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) },
      alias{ entity.GetValue<DataType::StringArray>(aliasDescribe) },
      source{ entity.GetValue<DataType::Int32Array>(sourceDescribe) },
      publication{ entity.GetValue<DataType::String>(publicationDescribe) },
      creator{ entity.GetValue<DataType::Int32Array>(creatorDescribe) },
      formulate{ entity.GetValue<DataType::Int32>(formulateDescribe) },
      country{ entity.GetValue<DataType::Int32>(countryDescribe) },
      begin{ entity.GetValue<DataType::Int32>(beginDescribe) },
      end{ entity.GetValue<DataType::Int32>(endDescribe) },
      againBegin{ entity.GetValue<DataType::Int32>(againBeginDescribe) },
      againEnd{ entity.GetValue<DataType::Int32>(againEndDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::CalendarEntity::CalendarEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      name{ Database::Traits::String{} },
      alias{ Database::Traits::StringArray{} },
      source{ Database::Traits::Int32Array{} },
      publication{ Database::Traits::String{} },
      creator{ Database::Traits::Int32Array{} },
      formulate{ Database::Traits::Int32{} },
      country{ Database::Traits::Int32{} },
      begin{ Database::Traits::Int32{} },
      end{ Database::Traits::Int32{} },
      againBegin{ Database::Traits::Int32{} },
      againEnd{ Database::Traits::Int32{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, CalendarEntity)

Database::Traits::Int32 DatabaseEntity::CalendarEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::String DatabaseEntity::CalendarEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

Database::Traits::StringArray DatabaseEntity::CalendarEntity::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::CalendarEntity::GetSource() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return source.GetValue();
}

Database::Traits::String DatabaseEntity::CalendarEntity::GetPublication() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return publication.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::CalendarEntity::GetCreator() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return creator.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CalendarEntity::GetFormulate() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return formulate.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CalendarEntity::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CalendarEntity::GetBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return begin.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CalendarEntity::GetEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return end.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CalendarEntity::GetAgainBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBegin.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CalendarEntity::GetAgainEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEnd.GetValue();
}

void DatabaseEntity::CalendarEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::CalendarEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

void DatabaseEntity::CalendarEntity::SetAlias(Database::Traits::ParamType::StringArray aAlias)
{
    USER_CLASS_IS_VALID_9;

    if (aAlias != GetAlias())
    {
        alias.SetValue(aAlias);

        AddModify(aliasDescribe, GetAlias());
    }
}

void DatabaseEntity::CalendarEntity::SetSource(Database::Traits::ParamType::Int32Array aSource)
{
    USER_CLASS_IS_VALID_9;

    if (aSource != GetSource())
    {
        source.SetValue(aSource);

        AddModify(sourceDescribe, GetSource());
    }
}

void DatabaseEntity::CalendarEntity::SetPublication(Database::Traits::ParamType::String aPublication)
{
    USER_CLASS_IS_VALID_9;

    if (aPublication != GetPublication())
    {
        publication.SetValue(aPublication);

        AddModify(publicationDescribe, GetPublication());
    }
}

void DatabaseEntity::CalendarEntity::SetCreator(Database::Traits::ParamType::Int32Array aCreator)
{
    USER_CLASS_IS_VALID_9;

    if (aCreator != GetCreator())
    {
        creator.SetValue(aCreator);

        AddModify(creatorDescribe, GetCreator());
    }
}

void DatabaseEntity::CalendarEntity::SetFormulate(Database::Traits::ParamType::Int32 aFormulate)
{
    USER_CLASS_IS_VALID_9;

    if (aFormulate != GetFormulate())
    {
        formulate.SetValue(aFormulate);

        AddModify(formulateDescribe, GetFormulate());
    }
}

void DatabaseEntity::CalendarEntity::SetCountry(Database::Traits::ParamType::Int32 aCountry)
{
    USER_CLASS_IS_VALID_9;

    if (aCountry != GetCountry())
    {
        country.SetValue(aCountry);

        AddModify(countryDescribe, GetCountry());
    }
}

void DatabaseEntity::CalendarEntity::SetBegin(Database::Traits::ParamType::Int32 aBegin)
{
    USER_CLASS_IS_VALID_9;

    if (aBegin != GetBegin())
    {
        begin.SetValue(aBegin);

        AddModify(beginDescribe, GetBegin());
    }
}

void DatabaseEntity::CalendarEntity::SetEnd(Database::Traits::ParamType::Int32 aEnd)
{
    USER_CLASS_IS_VALID_9;

    if (aEnd != GetEnd())
    {
        end.SetValue(aEnd);

        AddModify(endDescribe, GetEnd());
    }
}

void DatabaseEntity::CalendarEntity::SetAgainBegin(Database::Traits::ParamType::Int32 aAgainBegin)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainBegin != GetAgainBegin())
    {
        againBegin.SetValue(aAgainBegin);

        AddModify(againBeginDescribe, GetAgainBegin());
    }
}

void DatabaseEntity::CalendarEntity::SetAgainEnd(Database::Traits::ParamType::Int32 aAgainEnd)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainEnd != GetAgainEnd())
    {
        againEnd.SetValue(aAgainEnd);

        AddModify(againEndDescribe, GetAgainEnd());
    }
}

const DatabaseEntity::CalendarEntity::DatabaseFieldContainer& DatabaseEntity::CalendarEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField(),
                                                            decltype(alias)::GetDatabaseField(),
                                                            decltype(source)::GetDatabaseField(),
                                                            decltype(publication)::GetDatabaseField(),
                                                            decltype(creator)::GetDatabaseField(),
                                                            decltype(formulate)::GetDatabaseField(),
                                                            decltype(country)::GetDatabaseField(),
                                                            decltype(begin)::GetDatabaseField(),
                                                            decltype(end)::GetDatabaseField(),
                                                            decltype(againBegin)::GetDatabaseField(),
                                                            decltype(againEnd)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::CalendarEntity::BasisDatabaseManager DatabaseEntity::CalendarEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

Database::BasisDatabaseContainer DatabaseEntity::CalendarEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
