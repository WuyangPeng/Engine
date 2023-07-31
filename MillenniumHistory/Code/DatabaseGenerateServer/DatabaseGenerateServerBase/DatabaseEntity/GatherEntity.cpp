/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "GatherEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::GatherEntity DatabaseEntity::GatherEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? GatherEntity{ entity } : GatherEntity{ wrappersStrategy, id };
}

DatabaseEntity::GatherEntity::GatherEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      gather{ entity.GetValue<DataType::String>(gatherDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::GatherEntity::GatherEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      gather{ Database::Traits::String{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, GatherEntity)

Database::Traits::Int32 DatabaseEntity::GatherEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::String DatabaseEntity::GatherEntity::GetGather() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return gather.GetValue();
}

void DatabaseEntity::GatherEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::GatherEntity::SetGather(Database::Traits::ParamType::String aGather)
{
    USER_CLASS_IS_VALID_9;

    if (aGather != GetGather())
    {
        gather.SetValue(aGather);

        AddModify(gatherDescribe, GetGather());
    }
}

const DatabaseEntity::GatherEntity::DatabaseFieldContainer& DatabaseEntity::GatherEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(gather)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::GatherEntity::BasisDatabaseManager DatabaseEntity::GatherEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::GatherEntity::BasisDatabaseManager DatabaseEntity::GatherEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::GatherEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
