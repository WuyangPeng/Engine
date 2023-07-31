/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "SexagenaryCycleEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::SexagenaryCycleEntity DatabaseEntity::SexagenaryCycleEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? SexagenaryCycleEntity{ entity } : SexagenaryCycleEntity{ wrappersStrategy, id };
}

DatabaseEntity::SexagenaryCycleEntity::SexagenaryCycleEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      heavenly{ entity.GetValue<DataType::String>(heavenlyDescribe) },
      branch{ entity.GetValue<DataType::String>(branchDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::SexagenaryCycleEntity::SexagenaryCycleEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      heavenly{ Database::Traits::String{} },
      branch{ Database::Traits::String{} },
      name{ Database::Traits::String{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, SexagenaryCycleEntity)

Database::Traits::Int32 DatabaseEntity::SexagenaryCycleEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::String DatabaseEntity::SexagenaryCycleEntity::GetHeavenly() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return heavenly.GetValue();
}

Database::Traits::String DatabaseEntity::SexagenaryCycleEntity::GetBranch() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return branch.GetValue();
}

Database::Traits::String DatabaseEntity::SexagenaryCycleEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

void DatabaseEntity::SexagenaryCycleEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::SexagenaryCycleEntity::SetHeavenly(Database::Traits::ParamType::String aHeavenly)
{
    USER_CLASS_IS_VALID_9;

    if (aHeavenly != GetHeavenly())
    {
        heavenly.SetValue(aHeavenly);

        AddModify(heavenlyDescribe, GetHeavenly());
    }
}

void DatabaseEntity::SexagenaryCycleEntity::SetBranch(Database::Traits::ParamType::String aBranch)
{
    USER_CLASS_IS_VALID_9;

    if (aBranch != GetBranch())
    {
        branch.SetValue(aBranch);

        AddModify(branchDescribe, GetBranch());
    }
}

void DatabaseEntity::SexagenaryCycleEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

const DatabaseEntity::SexagenaryCycleEntity::DatabaseFieldContainer& DatabaseEntity::SexagenaryCycleEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(heavenly)::GetDatabaseField(),
                                                            decltype(branch)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::SexagenaryCycleEntity::BasisDatabaseManager DatabaseEntity::SexagenaryCycleEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::SexagenaryCycleEntity::BasisDatabaseManager DatabaseEntity::SexagenaryCycleEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::SexagenaryCycleEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
