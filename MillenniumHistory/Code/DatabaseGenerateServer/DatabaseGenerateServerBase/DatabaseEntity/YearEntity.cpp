/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "YearEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::YearEntity DatabaseEntity::YearEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? YearEntity{ entity } : YearEntity{ wrappersStrategy, id };
}

DatabaseEntity::YearEntity::YearEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) },
      sexagenaryCycle{ entity.GetValue<DataType::Int32>(sexagenaryCycleDescribe) },
      reignTitle{ entity.GetValue<DataType::Int64>(reignTitleDescribe) },
      year{ entity.GetValue<DataType::Int32>(yearDescribe) },
      unorthodoxReignTitle{ entity.GetValue<DataType::Int64Array>(unorthodoxReignTitleDescribe) },
      unorthodoxYear{ entity.GetValue<DataType::Int32Array>(unorthodoxYearDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::YearEntity::YearEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      name{ Database::Traits::String{} },
      sexagenaryCycle{ Database::Traits::Int32{} },
      reignTitle{ Database::Traits::Int64{} },
      year{ Database::Traits::Int32{} },
      unorthodoxReignTitle{ Database::Traits::Int64Array{} },
      unorthodoxYear{ Database::Traits::Int32Array{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, YearEntity)

Database::Traits::Int32 DatabaseEntity::YearEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::String DatabaseEntity::YearEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

Database::Traits::Int32 DatabaseEntity::YearEntity::GetSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return sexagenaryCycle.GetValue();
}

Database::Traits::Int64 DatabaseEntity::YearEntity::GetReignTitle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reignTitle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::YearEntity::GetYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return year.GetValue();
}

Database::Traits::Int64Array DatabaseEntity::YearEntity::GetUnorthodoxReignTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxReignTitle.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::YearEntity::GetUnorthodoxYear() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxYear.GetValue();
}

void DatabaseEntity::YearEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::YearEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

void DatabaseEntity::YearEntity::SetSexagenaryCycle(Database::Traits::ParamType::Int32 aSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aSexagenaryCycle != GetSexagenaryCycle())
    {
        sexagenaryCycle.SetValue(aSexagenaryCycle);

        AddModify(sexagenaryCycleDescribe, GetSexagenaryCycle());
    }
}

void DatabaseEntity::YearEntity::SetReignTitle(Database::Traits::ParamType::Int64 aReignTitle)
{
    USER_CLASS_IS_VALID_9;

    if (aReignTitle != GetReignTitle())
    {
        reignTitle.SetValue(aReignTitle);

        AddModify(reignTitleDescribe, GetReignTitle());
    }
}

void DatabaseEntity::YearEntity::SetYear(Database::Traits::ParamType::Int32 aYear)
{
    USER_CLASS_IS_VALID_9;

    if (aYear != GetYear())
    {
        year.SetValue(aYear);

        AddModify(yearDescribe, GetYear());
    }
}

void DatabaseEntity::YearEntity::SetUnorthodoxReignTitle(Database::Traits::ParamType::Int64Array aUnorthodoxReignTitle)
{
    USER_CLASS_IS_VALID_9;

    if (aUnorthodoxReignTitle != GetUnorthodoxReignTitle())
    {
        unorthodoxReignTitle.SetValue(aUnorthodoxReignTitle);

        AddModify(unorthodoxReignTitleDescribe, GetUnorthodoxReignTitle());
    }
}

void DatabaseEntity::YearEntity::SetUnorthodoxYear(Database::Traits::ParamType::Int32Array aUnorthodoxYear)
{
    USER_CLASS_IS_VALID_9;

    if (aUnorthodoxYear != GetUnorthodoxYear())
    {
        unorthodoxYear.SetValue(aUnorthodoxYear);

        AddModify(unorthodoxYearDescribe, GetUnorthodoxYear());
    }
}

const DatabaseEntity::YearEntity::DatabaseFieldContainer& DatabaseEntity::YearEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField(),
                                                            decltype(sexagenaryCycle)::GetDatabaseField(),
                                                            decltype(reignTitle)::GetDatabaseField(),
                                                            decltype(year)::GetDatabaseField(),
                                                            decltype(unorthodoxReignTitle)::GetDatabaseField(),
                                                            decltype(unorthodoxYear)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::YearEntity::BasisDatabaseManager DatabaseEntity::YearEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::YearEntity::BasisDatabaseManager DatabaseEntity::YearEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::YearEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
