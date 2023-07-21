/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "CountryEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::CountryEntity DatabaseEntity::CountryEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? CountryEntity{ entity } : CountryEntity{ wrappersStrategy, id };
}

DatabaseEntity::CountryEntity::CountryEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      imperialCourt{ entity.GetValue<DataType::Int32>(imperialCourtDescribe) },
      category{ entity.GetValue<DataType::String>(categoryDescribe) },
      beginYear{ entity.GetValue<DataType::Int32>(beginYearDescribe) },
      beginMonth{ entity.GetValue<DataType::Int32>(beginMonthDescribe) },
      beginSexagenaryCycle{ entity.GetValue<DataType::Int32>(beginSexagenaryCycleDescribe) },
      beginDay{ entity.GetValue<DataType::Int32>(beginDayDescribe) },
      endYear{ entity.GetValue<DataType::Int32>(endYearDescribe) },
      endMonth{ entity.GetValue<DataType::Int32>(endMonthDescribe) },
      endSexagenaryCycle{ entity.GetValue<DataType::Int32>(endSexagenaryCycleDescribe) },
      endDay{ entity.GetValue<DataType::Int32>(endDayDescribe) },
      unansweredQuestion{ entity.GetValue<DataType::StringArray>(unansweredQuestionDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::CountryEntity::CountryEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      imperialCourt{ Database::Traits::Int32{} },
      category{ Database::Traits::String{} },
      beginYear{ Database::Traits::Int32{} },
      beginMonth{ Database::Traits::Int32{} },
      beginSexagenaryCycle{ Database::Traits::Int32{} },
      beginDay{ Database::Traits::Int32{} },
      endYear{ Database::Traits::Int32{} },
      endMonth{ Database::Traits::Int32{} },
      endSexagenaryCycle{ Database::Traits::Int32{} },
      endDay{ Database::Traits::Int32{} },
      unansweredQuestion{ Database::Traits::StringArray{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, CountryEntity)

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetImperialCourt() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return imperialCourt.GetValue();
}

Database::Traits::String DatabaseEntity::CountryEntity::GetCategory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return category.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginDay.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CountryEntity::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endDay.GetValue();
}

Database::Traits::StringArray DatabaseEntity::CountryEntity::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.GetValue();
}

void DatabaseEntity::CountryEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::CountryEntity::SetImperialCourt(Database::Traits::ParamType::Int32 aImperialCourt)
{
    USER_CLASS_IS_VALID_9;

    if (aImperialCourt != GetImperialCourt())
    {
        imperialCourt.SetValue(aImperialCourt);

        AddModify(imperialCourtDescribe, GetImperialCourt());
    }
}

void DatabaseEntity::CountryEntity::SetCategory(Database::Traits::ParamType::String aCategory)
{
    USER_CLASS_IS_VALID_9;

    if (aCategory != GetCategory())
    {
        category.SetValue(aCategory);

        AddModify(categoryDescribe, GetCategory());
    }
}

void DatabaseEntity::CountryEntity::SetBeginYear(Database::Traits::ParamType::Int32 aBeginYear)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginYear != GetBeginYear())
    {
        beginYear.SetValue(aBeginYear);

        AddModify(beginYearDescribe, GetBeginYear());
    }
}

void DatabaseEntity::CountryEntity::SetBeginMonth(Database::Traits::ParamType::Int32 aBeginMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginMonth != GetBeginMonth())
    {
        beginMonth.SetValue(aBeginMonth);

        AddModify(beginMonthDescribe, GetBeginMonth());
    }
}

void DatabaseEntity::CountryEntity::SetBeginSexagenaryCycle(Database::Traits::ParamType::Int32 aBeginSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginSexagenaryCycle != GetBeginSexagenaryCycle())
    {
        beginSexagenaryCycle.SetValue(aBeginSexagenaryCycle);

        AddModify(beginSexagenaryCycleDescribe, GetBeginSexagenaryCycle());
    }
}

void DatabaseEntity::CountryEntity::SetBeginDay(Database::Traits::ParamType::Int32 aBeginDay)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginDay != GetBeginDay())
    {
        beginDay.SetValue(aBeginDay);

        AddModify(beginDayDescribe, GetBeginDay());
    }
}

void DatabaseEntity::CountryEntity::SetEndYear(Database::Traits::ParamType::Int32 aEndYear)
{
    USER_CLASS_IS_VALID_9;

    if (aEndYear != GetEndYear())
    {
        endYear.SetValue(aEndYear);

        AddModify(endYearDescribe, GetEndYear());
    }
}

void DatabaseEntity::CountryEntity::SetEndMonth(Database::Traits::ParamType::Int32 aEndMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aEndMonth != GetEndMonth())
    {
        endMonth.SetValue(aEndMonth);

        AddModify(endMonthDescribe, GetEndMonth());
    }
}

void DatabaseEntity::CountryEntity::SetEndSexagenaryCycle(Database::Traits::ParamType::Int32 aEndSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aEndSexagenaryCycle != GetEndSexagenaryCycle())
    {
        endSexagenaryCycle.SetValue(aEndSexagenaryCycle);

        AddModify(endSexagenaryCycleDescribe, GetEndSexagenaryCycle());
    }
}

void DatabaseEntity::CountryEntity::SetEndDay(Database::Traits::ParamType::Int32 aEndDay)
{
    USER_CLASS_IS_VALID_9;

    if (aEndDay != GetEndDay())
    {
        endDay.SetValue(aEndDay);

        AddModify(endDayDescribe, GetEndDay());
    }
}

void DatabaseEntity::CountryEntity::SetUnansweredQuestion(Database::Traits::ParamType::StringArray aUnansweredQuestion)
{
    USER_CLASS_IS_VALID_9;

    if (aUnansweredQuestion != GetUnansweredQuestion())
    {
        unansweredQuestion.SetValue(aUnansweredQuestion);

        AddModify(unansweredQuestionDescribe, GetUnansweredQuestion());
    }
}

const DatabaseEntity::CountryEntity::DatabaseFieldContainer& DatabaseEntity::CountryEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(imperialCourt)::GetDatabaseField(),
                                                            decltype(category)::GetDatabaseField(),
                                                            decltype(beginYear)::GetDatabaseField(),
                                                            decltype(beginMonth)::GetDatabaseField(),
                                                            decltype(beginSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(beginDay)::GetDatabaseField(),
                                                            decltype(endYear)::GetDatabaseField(),
                                                            decltype(endMonth)::GetDatabaseField(),
                                                            decltype(endSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(endDay)::GetDatabaseField(),
                                                            decltype(unansweredQuestion)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::CountryEntity::BasisDatabaseManager DatabaseEntity::CountryEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

Database::BasisDatabaseContainer DatabaseEntity::CountryEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
