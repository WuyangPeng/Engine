/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "MonthEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::MonthEntity DatabaseEntity::MonthEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? MonthEntity{ entity } : MonthEntity{ wrappersStrategy, id };
}

DatabaseEntity::MonthEntity::MonthEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::MonthEntity::MonthEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      name{ Database::Traits::String{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, MonthEntity)

Database::Traits::Int32 DatabaseEntity::MonthEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::String DatabaseEntity::MonthEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

void DatabaseEntity::MonthEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::MonthEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

const DatabaseEntity::MonthEntity::DatabaseFieldContainer& DatabaseEntity::MonthEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::MonthEntity::BasisDatabaseManager DatabaseEntity::MonthEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::MonthEntity::BasisDatabaseManager DatabaseEntity::MonthEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::MonthEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
