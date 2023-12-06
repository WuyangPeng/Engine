/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "ImperialCourtEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::ImperialCourtEntity DatabaseEntity::ImperialCourtEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? ImperialCourtEntity{ entity } : ImperialCourtEntity{ wrappersStrategy, id };
}

DatabaseEntity::ImperialCourtEntity::ImperialCourtEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      category{ entity.GetValue<DataType::String>(categoryDescribe) },
      book{ entity.GetValue<DataType::String>(bookDescribe) },
      begin{ entity.GetValue<DataType::Int32>(beginDescribe) },
      end{ entity.GetValue<DataType::Int32>(endDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::ImperialCourtEntity::ImperialCourtEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      category{ Database::Traits::String{} },
      book{ Database::Traits::String{} },
      begin{ Database::Traits::Int32{} },
      end{ Database::Traits::Int32{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, ImperialCourtEntity)

Database::Traits::Int32 DatabaseEntity::ImperialCourtEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::String DatabaseEntity::ImperialCourtEntity::GetCategory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return category.GetValue();
}

Database::Traits::String DatabaseEntity::ImperialCourtEntity::GetBook() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return book.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ImperialCourtEntity::GetBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return begin.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ImperialCourtEntity::GetEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return end.GetValue();
}

void DatabaseEntity::ImperialCourtEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::ImperialCourtEntity::SetCategory(Database::Traits::ParamType::String aCategory)
{
    USER_CLASS_IS_VALID_9;

    if (aCategory != GetCategory())
    {
        category.SetValue(aCategory);

        AddModify(categoryDescribe, GetCategory());
    }
}

void DatabaseEntity::ImperialCourtEntity::SetBook(Database::Traits::ParamType::String aBook)
{
    USER_CLASS_IS_VALID_9;

    if (aBook != GetBook())
    {
        book.SetValue(aBook);

        AddModify(bookDescribe, GetBook());
    }
}

void DatabaseEntity::ImperialCourtEntity::SetBegin(Database::Traits::ParamType::Int32 aBegin)
{
    USER_CLASS_IS_VALID_9;

    if (aBegin != GetBegin())
    {
        begin.SetValue(aBegin);

        AddModify(beginDescribe, GetBegin());
    }
}

void DatabaseEntity::ImperialCourtEntity::SetEnd(Database::Traits::ParamType::Int32 aEnd)
{
    USER_CLASS_IS_VALID_9;

    if (aEnd != GetEnd())
    {
        end.SetValue(aEnd);

        AddModify(endDescribe, GetEnd());
    }
}

const DatabaseEntity::ImperialCourtEntity::DatabaseFieldContainer& DatabaseEntity::ImperialCourtEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(category)::GetDatabaseField(),
                                                            decltype(book)::GetDatabaseField(),
                                                            decltype(begin)::GetDatabaseField(),
                                                            decltype(end)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::ImperialCourtEntity::BasisDatabaseManager DatabaseEntity::ImperialCourtEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::ImperialCourtEntity::BasisDatabaseManager DatabaseEntity::ImperialCourtEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::ImperialCourtEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
