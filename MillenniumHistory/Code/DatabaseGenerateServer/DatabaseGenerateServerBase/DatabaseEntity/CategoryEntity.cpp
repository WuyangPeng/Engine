/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "CategoryEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::CategoryEntity DatabaseEntity::CategoryEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? CategoryEntity{ entity } : CategoryEntity{ wrappersStrategy, id };
}

DatabaseEntity::CategoryEntity::CategoryEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      gather{ entity.GetValue<DataType::Int32>(gatherDescribe) },
      category{ entity.GetValue<DataType::String>(categoryDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::CategoryEntity::CategoryEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      gather{ Database::Traits::Int32{} },
      category{ Database::Traits::String{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, CategoryEntity)

Database::Traits::Int32 DatabaseEntity::CategoryEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CategoryEntity::GetGather() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return gather.GetValue();
}

Database::Traits::String DatabaseEntity::CategoryEntity::GetCategory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return category.GetValue();
}

void DatabaseEntity::CategoryEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::CategoryEntity::SetGather(Database::Traits::ParamType::Int32 aGather)
{
    USER_CLASS_IS_VALID_9;

    if (aGather != GetGather())
    {
        gather.SetValue(aGather);

        AddModify(gatherDescribe, GetGather());
    }
}

void DatabaseEntity::CategoryEntity::SetCategory(Database::Traits::ParamType::String aCategory)
{
    USER_CLASS_IS_VALID_9;

    if (aCategory != GetCategory())
    {
        category.SetValue(aCategory);

        AddModify(categoryDescribe, GetCategory());
    }
}

const DatabaseEntity::CategoryEntity::DatabaseFieldContainer& DatabaseEntity::CategoryEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(gather)::GetDatabaseField(),
                                                            decltype(category)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::CategoryEntity::BasisDatabaseManager DatabaseEntity::CategoryEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::CategoryEntity::BasisDatabaseManager DatabaseEntity::CategoryEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::CategoryEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
