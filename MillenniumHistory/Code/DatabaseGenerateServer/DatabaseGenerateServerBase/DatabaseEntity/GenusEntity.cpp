/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "GenusEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::GenusEntity DatabaseEntity::GenusEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? GenusEntity{ entity } : GenusEntity{ wrappersStrategy, id };
}

DatabaseEntity::GenusEntity::GenusEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      category{ entity.GetValue<DataType::Int32>(categoryDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) },
      father{ entity.GetValue<DataType::Int32>(fatherDescribe) },
      begin{ entity.GetValue<DataType::String>(beginDescribe) },
      end{ entity.GetValue<DataType::String>(endDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::GenusEntity::GenusEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      category{ Database::Traits::Int32{} },
      name{ Database::Traits::String{} },
      father{ Database::Traits::Int32{} },
      begin{ Database::Traits::String{} },
      end{ Database::Traits::String{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, GenusEntity)

Database::Traits::Int32 DatabaseEntity::GenusEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::Int32 DatabaseEntity::GenusEntity::GetCategory() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return category.GetValue();
}

Database::Traits::String DatabaseEntity::GenusEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

Database::Traits::Int32 DatabaseEntity::GenusEntity::GetFather() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return father.GetValue();
}

Database::Traits::String DatabaseEntity::GenusEntity::GetBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return begin.GetValue();
}

Database::Traits::String DatabaseEntity::GenusEntity::GetEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return end.GetValue();
}

void DatabaseEntity::GenusEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::GenusEntity::SetCategory(Database::Traits::ParamType::Int32 aCategory)
{
    USER_CLASS_IS_VALID_9;

    if (aCategory != GetCategory())
    {
        category.SetValue(aCategory);

        AddModify(categoryDescribe, GetCategory());
    }
}

void DatabaseEntity::GenusEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

void DatabaseEntity::GenusEntity::SetFather(Database::Traits::ParamType::Int32 aFather)
{
    USER_CLASS_IS_VALID_9;

    if (aFather != GetFather())
    {
        father.SetValue(aFather);

        AddModify(fatherDescribe, GetFather());
    }
}

void DatabaseEntity::GenusEntity::SetBegin(Database::Traits::ParamType::String aBegin)
{
    USER_CLASS_IS_VALID_9;

    if (aBegin != GetBegin())
    {
        begin.SetValue(aBegin);

        AddModify(beginDescribe, GetBegin());
    }
}

void DatabaseEntity::GenusEntity::SetEnd(Database::Traits::ParamType::String aEnd)
{
    USER_CLASS_IS_VALID_9;

    if (aEnd != GetEnd())
    {
        end.SetValue(aEnd);

        AddModify(endDescribe, GetEnd());
    }
}

const DatabaseEntity::GenusEntity::DatabaseFieldContainer& DatabaseEntity::GenusEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(category)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField(),
                                                            decltype(father)::GetDatabaseField(),
                                                            decltype(begin)::GetDatabaseField(),
                                                            decltype(end)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::GenusEntity::BasisDatabaseManager DatabaseEntity::GenusEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

Database::BasisDatabaseContainer DatabaseEntity::GenusEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
