/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "GeographicEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::GeographicEntity DatabaseEntity::GeographicEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? GeographicEntity{ entity } : GeographicEntity{ wrappersStrategy, id };
}

DatabaseEntity::GeographicEntity::GeographicEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::GeographicEntity::GeographicEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      name{ Database::Traits::String{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, GeographicEntity)

Database::Traits::Int32 DatabaseEntity::GeographicEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::String DatabaseEntity::GeographicEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

void DatabaseEntity::GeographicEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::GeographicEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

const DatabaseEntity::GeographicEntity::DatabaseFieldContainer& DatabaseEntity::GeographicEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::GeographicEntity::BasisDatabaseManager DatabaseEntity::GeographicEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::GeographicEntity::BasisDatabaseManager DatabaseEntity::GeographicEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::GeographicEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
