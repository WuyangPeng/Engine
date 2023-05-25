///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.9 (2023/05/25 11:25)

#include "Chapter.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseContainerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/FieldName.h"

DatabaseEntity::Chapter::Chapter(const BasisDatabaseContainer& entity)
    : ParentType{ entity },
      userId{ entity.GetValue<DataType::Int64>(userIdDescribe) },
      chapterId{ entity.GetValue<DataType::Int32>(chapterIdDescribe) },
      chapterName{ entity.GetValue<DataType::String>(chapterNameDescribe) },
      chanceWinning{ entity.GetValue<DataType::Double>(chanceWinningDescribe) },
      isWinning{ entity.GetValue<DataType::Bool>(isWinningDescribe) },
      currency{ entity.GetValue<DataType::Int64Count>(currencyDescribe) },
      count{ entity.GetValue<DataType::Int32Count>(countDescribe) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::Chapter::Chapter(Database::WrappersStrategy wrappersStrategy, boost::call_traits<Database::Traits::Int64>::param_type userId)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(userId) },
      userId{ userId },
      chapterId{ Database::Traits::Int32{} },
      chapterName{ Database::Traits::String{} },
      chanceWinning{ Database::Traits::Double{} },
      isWinning{ Database::Traits::Bool{} },
      currency{ Database::Traits::Int64Count{} },
      count{ Database::Traits::Int32Count{} }
{
    AddModify(userIdDescribe, userId);

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, Chapter)

Database::Traits::Int64 DatabaseEntity::Chapter::GetUserId() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return userId.GetValue();
}

Database::Traits::Int32 DatabaseEntity::Chapter::GetChapterId() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return chapterId.GetValue();
}

Database::Traits::String DatabaseEntity::Chapter::GetChapterName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return chapterName.GetValue();
}

Database::Traits::Double DatabaseEntity::Chapter::GetChanceWinning() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return chanceWinning.GetValue();
}

Database::Traits::Bool DatabaseEntity::Chapter::IsChanceWinning() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return isWinning.GetValue();
}

Database::Traits::Int64Count DatabaseEntity::Chapter::GetCurrency() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return currency.GetValue();
}

Database::Traits::Int32Count DatabaseEntity::Chapter::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return count.GetValue();
}

void DatabaseEntity::Chapter::SetChapterId(boost::call_traits<Database::Traits::Int32>::param_type aChapterId)
{
    DATABASE_CLASS_IS_VALID_9;

    chapterId.SetValue(aChapterId);

    AddModify(chapterIdDescribe, aChapterId);
}

void DatabaseEntity::Chapter::SetChapterName(boost::call_traits<Database::Traits::String>::param_type aChapterName)
{
    DATABASE_CLASS_IS_VALID_9;

    chapterName.SetValue(aChapterName);

    AddModify(chapterNameDescribe, aChapterName);
}

void DatabaseEntity::Chapter::SetChanceWinning(boost::call_traits<Database::Traits::Double>::param_type aChanceWinning)
{
    DATABASE_CLASS_IS_VALID_9;

    chanceWinning.SetValue(aChanceWinning);

    AddModify(chanceWinningDescribe, aChanceWinning);
}

void DatabaseEntity::Chapter::SetChanceWinning(boost::call_traits<Database::Traits::Bool>::param_type aIsWinning)
{
    DATABASE_CLASS_IS_VALID_9;

    isWinning.SetValue(aIsWinning);

    AddModify(isWinningDescribe, aIsWinning);
}

void DatabaseEntity::Chapter::SetCurrency(boost::call_traits<Database::Traits::Int64Count>::param_type aCurrency)
{
    DATABASE_CLASS_IS_VALID_9;

    currency.SetValue(aCurrency);

    AddModify(currencyDescribe, aCurrency);
}

void DatabaseEntity::Chapter::ModifyCurrency(boost::call_traits<Database::Traits::Int64Count>::param_type aCurrency)
{
    DATABASE_CLASS_IS_VALID_9;

    currency.ModifyValue(aCurrency);

    AddModify(currencyDescribe, currency.GetValue());
}

void DatabaseEntity::Chapter::SetCount(boost::call_traits<Database::Traits::Int32Count>::param_type aCount)
{
    DATABASE_CLASS_IS_VALID_9;

    count.SetValue(aCount);

    AddModify(countDescribe, aCount);
}

void DatabaseEntity::Chapter::ModifyCount(boost::call_traits<Database::Traits::Int32Count>::param_type aCount)
{
    DATABASE_CLASS_IS_VALID_9;

    count.ModifyValue(aCount);

    AddModify(countDescribe, GetCount());
}

DatabaseEntity::Chapter::FieldNameContainer DatabaseEntity::Chapter::GetFieldNameContainer() const
{
    static FieldNameContainer fieldNameContainer{ Database::FieldName{ userIdDescribe, DataType::Int64 },
                                                  Database::FieldName{ chapterIdDescribe, DataType::Int32 },
                                                  Database::FieldName{ chapterNameDescribe, DataType::String },
                                                  Database::FieldName{ chanceWinningDescribe, DataType::Double },
                                                  Database::FieldName{ isWinningDescribe, DataType::Bool },
                                                  Database::FieldName{ currencyDescribe, DataType::Int64Count },
                                                  Database::FieldName{ countDescribe, DataType::Int32Count } };

    return fieldNameContainer;
}

Database::DatabaseEntity::ObjectContainer DatabaseEntity::Chapter::GetKeyBasisDatabaseContainer(boost::call_traits<Database::Traits::Int64>::param_type userId)
{
    ObjectContainer objectContainer{ Database::BasisDatabase{ userIdDescribe, userId } };

    return objectContainer;
}
