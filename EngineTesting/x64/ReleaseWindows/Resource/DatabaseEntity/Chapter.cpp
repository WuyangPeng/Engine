/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Chapter.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::Chapter DatabaseEntity::Chapter::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 userId)
{
    return entity.IsModify() ? Chapter{ entity } : Chapter{ wrappersStrategy, userId };
}

DatabaseEntity::Chapter::Chapter(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      userId{ entity.GetValue<DataType::Int64>(userIdDescribe) },
      chapterId{ entity.GetValue<DataType::Int32>(chapterIdDescribe) },
      chapterName{ entity.GetValue<DataType::String>(chapterNameDescribe) },
      chanceWinning{ entity.GetValue<DataType::Double>(chanceWinningDescribe) },
      winning{ entity.GetValue<DataType::Bool>(winningDescribe) },
      currency{ entity.GetValue<DataType::Int64Count>(currencyDescribe) },
      count{ entity.GetValue<DataType::Int32Count>(countDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::Chapter::Chapter(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 userId)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(userId) },
      userId{ userId },
      chapterId{ Database::Traits::Int32{} },
      chapterName{ Database::Traits::String{} },
      chanceWinning{ Database::Traits::Double{} },
      winning{ Database::Traits::Bool{} },
      currency{ Database::Traits::Int64Count{} },
      count{ Database::Traits::Int32Count{} }
{
    AddModify(userIdDescribe, userId);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, Chapter)

Database::Traits::Int64 DatabaseEntity::Chapter::GetUserId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return userId.GetValue();
}

Database::Traits::Int32 DatabaseEntity::Chapter::GetChapterId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapterId.GetValue();
}

Database::Traits::String DatabaseEntity::Chapter::GetChapterName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapterName.GetValue();
}

Database::Traits::Double DatabaseEntity::Chapter::GetChanceWinning() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return chanceWinning.GetValue();
}

Database::Traits::Bool DatabaseEntity::Chapter::IsWinning() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return winning.GetValue();
}

Database::Traits::Int64Count DatabaseEntity::Chapter::GetCurrency() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return currency.GetValue();
}

Database::Traits::Int32Count DatabaseEntity::Chapter::GetCount() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return count.GetValue();
}

void DatabaseEntity::Chapter::SetUserId(Database::Traits::ParamType::Int64 aUserId)
{
    USER_CLASS_IS_VALID_9;

    if (aUserId != GetUserId())
    {
        userId.SetValue(aUserId);

        AddModify(userIdDescribe, GetUserId());
    }
}

void DatabaseEntity::Chapter::SetChapterId(Database::Traits::ParamType::Int32 aChapterId)
{
    USER_CLASS_IS_VALID_9;

    if (aChapterId != GetChapterId())
    {
        chapterId.SetValue(aChapterId);

        AddModify(chapterIdDescribe, GetChapterId());
    }
}

void DatabaseEntity::Chapter::SetChapterName(Database::Traits::ParamType::String aChapterName)
{
    USER_CLASS_IS_VALID_9;

    if (aChapterName != GetChapterName())
    {
        chapterName.SetValue(aChapterName);

        AddModify(chapterNameDescribe, GetChapterName());
    }
}

void DatabaseEntity::Chapter::SetChanceWinning(Database::Traits::ParamType::Double aChanceWinning)
{
    USER_CLASS_IS_VALID_9;

    if (aChanceWinning != GetChanceWinning())
    {
        chanceWinning.SetValue(aChanceWinning);

        AddModify(chanceWinningDescribe, GetChanceWinning());
    }
}

void DatabaseEntity::Chapter::SetWinning(Database::Traits::ParamType::Bool aWinning)
{
    USER_CLASS_IS_VALID_9;

    if (aWinning != IsWinning())
    {
        winning.SetValue(aWinning);

        AddModify(winningDescribe, IsWinning());
    }
}

void DatabaseEntity::Chapter::SetCurrency(Database::Traits::ParamType::Int64Count aCurrency)
{
    USER_CLASS_IS_VALID_9;

    if (aCurrency != GetCurrency())
    {
        currency.SetValue(aCurrency);

        AddModify(currencyDescribe, GetCurrency());
    }
}

void DatabaseEntity::Chapter::SetCount(Database::Traits::ParamType::Int32Count aCount)
{
    USER_CLASS_IS_VALID_9;

    if (aCount != GetCount())
    {
        count.SetValue(aCount);

        AddModify(countDescribe, GetCount());
    }
}

void DatabaseEntity::Chapter::ModifyCurrency(Database::Traits::ParamType::Int64Count aCurrency)
{
    USER_CLASS_IS_VALID_9;

    currency.ModifyValue(aCurrency);

    AddModify(currencyDescribe, GetCurrency());
}

void DatabaseEntity::Chapter::ModifyCount(Database::Traits::ParamType::Int32Count aCount)
{
    USER_CLASS_IS_VALID_9;

    count.ModifyValue(aCount);

    AddModify(countDescribe, GetCount());
}

const DatabaseEntity::Chapter::DatabaseFieldContainer& DatabaseEntity::Chapter::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(userId)::GetDatabaseField(),
                                                            decltype(chapterId)::GetDatabaseField(),
                                                            decltype(chapterName)::GetDatabaseField(),
                                                            decltype(chanceWinning)::GetDatabaseField(),
                                                            decltype(winning)::GetDatabaseField(),
                                                            decltype(currency)::GetDatabaseField(),
                                                            decltype(count)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::Chapter::BasisDatabaseManager DatabaseEntity::Chapter::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 userId)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(userId) };
}

Database::BasisDatabaseContainer DatabaseEntity::Chapter::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int64 userId)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ userIdDescribe, userId } } };

    return basisDatabaseContainer;
}
