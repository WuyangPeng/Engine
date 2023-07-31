/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "EmperorEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::EmperorEntity DatabaseEntity::EmperorEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? EmperorEntity{ entity } : EmperorEntity{ wrappersStrategy, id };
}

DatabaseEntity::EmperorEntity::EmperorEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      character{ entity.GetValue<DataType::Int32>(characterDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) },
      dynasticTitle{ entity.GetValue<DataType::String>(dynasticTitleDescribe) },
      dynasticTitleAlias{ entity.GetValue<DataType::StringArray>(dynasticTitleAliasDescribe) },
      posthumousTitle{ entity.GetValue<DataType::String>(posthumousTitleDescribe) },
      posthumousTitleAlias{ entity.GetValue<DataType::StringArray>(posthumousTitleAliasDescribe) },
      beginYear{ entity.GetValue<DataType::Int32>(beginYearDescribe) },
      beginMonth{ entity.GetValue<DataType::Int32>(beginMonthDescribe) },
      beginSexagenaryCycle{ entity.GetValue<DataType::Int32>(beginSexagenaryCycleDescribe) },
      beginDay{ entity.GetValue<DataType::Int32>(beginDayDescribe) },
      endYear{ entity.GetValue<DataType::Int32>(endYearDescribe) },
      endMonth{ entity.GetValue<DataType::Int32>(endMonthDescribe) },
      endSexagenaryCycle{ entity.GetValue<DataType::Int32>(endSexagenaryCycleDescribe) },
      endDay{ entity.GetValue<DataType::Int32>(endDayDescribe) },
      againBeginYear{ entity.GetValue<DataType::Int32>(againBeginYearDescribe) },
      againBeginMonth{ entity.GetValue<DataType::Int32>(againBeginMonthDescribe) },
      againBeginSexagenaryCycle{ entity.GetValue<DataType::Int32>(againBeginSexagenaryCycleDescribe) },
      againBeginDay{ entity.GetValue<DataType::Int32>(againBeginDayDescribe) },
      againEndYear{ entity.GetValue<DataType::Int32>(againEndYearDescribe) },
      againEndMonth{ entity.GetValue<DataType::Int32>(againEndMonthDescribe) },
      againEndSexagenaryCycle{ entity.GetValue<DataType::Int32>(againEndSexagenaryCycleDescribe) },
      againEndDay{ entity.GetValue<DataType::Int32>(againEndDayDescribe) },
      unansweredQuestion{ entity.GetValue<DataType::StringArray>(unansweredQuestionDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::EmperorEntity::EmperorEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      character{ Database::Traits::Int32{} },
      name{ Database::Traits::String{} },
      dynasticTitle{ Database::Traits::String{} },
      dynasticTitleAlias{ Database::Traits::StringArray{} },
      posthumousTitle{ Database::Traits::String{} },
      posthumousTitleAlias{ Database::Traits::StringArray{} },
      beginYear{ Database::Traits::Int32{} },
      beginMonth{ Database::Traits::Int32{} },
      beginSexagenaryCycle{ Database::Traits::Int32{} },
      beginDay{ Database::Traits::Int32{} },
      endYear{ Database::Traits::Int32{} },
      endMonth{ Database::Traits::Int32{} },
      endSexagenaryCycle{ Database::Traits::Int32{} },
      endDay{ Database::Traits::Int32{} },
      againBeginYear{ Database::Traits::Int32{} },
      againBeginMonth{ Database::Traits::Int32{} },
      againBeginSexagenaryCycle{ Database::Traits::Int32{} },
      againBeginDay{ Database::Traits::Int32{} },
      againEndYear{ Database::Traits::Int32{} },
      againEndMonth{ Database::Traits::Int32{} },
      againEndSexagenaryCycle{ Database::Traits::Int32{} },
      againEndDay{ Database::Traits::Int32{} },
      unansweredQuestion{ Database::Traits::StringArray{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, EmperorEntity)

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetCharacter() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return character.GetValue();
}

Database::Traits::String DatabaseEntity::EmperorEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

Database::Traits::String DatabaseEntity::EmperorEntity::GetDynasticTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return dynasticTitle.GetValue();
}

Database::Traits::StringArray DatabaseEntity::EmperorEntity::GetDynasticTitleAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return dynasticTitleAlias.GetValue();
}

Database::Traits::String DatabaseEntity::EmperorEntity::GetPosthumousTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return posthumousTitle.GetValue();
}

Database::Traits::StringArray DatabaseEntity::EmperorEntity::GetPosthumousTitleAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return posthumousTitleAlias.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginDay.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endDay.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetAgainBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBeginYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetAgainBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBeginMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetAgainBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBeginSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetAgainBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBeginDay.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetAgainEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEndYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetAgainEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEndMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetAgainEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEndSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::EmperorEntity::GetAgainEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEndDay.GetValue();
}

Database::Traits::StringArray DatabaseEntity::EmperorEntity::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.GetValue();
}

void DatabaseEntity::EmperorEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::EmperorEntity::SetCharacter(Database::Traits::ParamType::Int32 aCharacter)
{
    USER_CLASS_IS_VALID_9;

    if (aCharacter != GetCharacter())
    {
        character.SetValue(aCharacter);

        AddModify(characterDescribe, GetCharacter());
    }
}

void DatabaseEntity::EmperorEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

void DatabaseEntity::EmperorEntity::SetDynasticTitle(Database::Traits::ParamType::String aDynasticTitle)
{
    USER_CLASS_IS_VALID_9;

    if (aDynasticTitle != GetDynasticTitle())
    {
        dynasticTitle.SetValue(aDynasticTitle);

        AddModify(dynasticTitleDescribe, GetDynasticTitle());
    }
}

void DatabaseEntity::EmperorEntity::SetDynasticTitleAlias(Database::Traits::ParamType::StringArray aDynasticTitleAlias)
{
    USER_CLASS_IS_VALID_9;

    if (aDynasticTitleAlias != GetDynasticTitleAlias())
    {
        dynasticTitleAlias.SetValue(aDynasticTitleAlias);

        AddModify(dynasticTitleAliasDescribe, GetDynasticTitleAlias());
    }
}

void DatabaseEntity::EmperorEntity::SetPosthumousTitle(Database::Traits::ParamType::String aPosthumousTitle)
{
    USER_CLASS_IS_VALID_9;

    if (aPosthumousTitle != GetPosthumousTitle())
    {
        posthumousTitle.SetValue(aPosthumousTitle);

        AddModify(posthumousTitleDescribe, GetPosthumousTitle());
    }
}

void DatabaseEntity::EmperorEntity::SetPosthumousTitleAlias(Database::Traits::ParamType::StringArray aPosthumousTitleAlias)
{
    USER_CLASS_IS_VALID_9;

    if (aPosthumousTitleAlias != GetPosthumousTitleAlias())
    {
        posthumousTitleAlias.SetValue(aPosthumousTitleAlias);

        AddModify(posthumousTitleAliasDescribe, GetPosthumousTitleAlias());
    }
}

void DatabaseEntity::EmperorEntity::SetBeginYear(Database::Traits::ParamType::Int32 aBeginYear)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginYear != GetBeginYear())
    {
        beginYear.SetValue(aBeginYear);

        AddModify(beginYearDescribe, GetBeginYear());
    }
}

void DatabaseEntity::EmperorEntity::SetBeginMonth(Database::Traits::ParamType::Int32 aBeginMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginMonth != GetBeginMonth())
    {
        beginMonth.SetValue(aBeginMonth);

        AddModify(beginMonthDescribe, GetBeginMonth());
    }
}

void DatabaseEntity::EmperorEntity::SetBeginSexagenaryCycle(Database::Traits::ParamType::Int32 aBeginSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginSexagenaryCycle != GetBeginSexagenaryCycle())
    {
        beginSexagenaryCycle.SetValue(aBeginSexagenaryCycle);

        AddModify(beginSexagenaryCycleDescribe, GetBeginSexagenaryCycle());
    }
}

void DatabaseEntity::EmperorEntity::SetBeginDay(Database::Traits::ParamType::Int32 aBeginDay)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginDay != GetBeginDay())
    {
        beginDay.SetValue(aBeginDay);

        AddModify(beginDayDescribe, GetBeginDay());
    }
}

void DatabaseEntity::EmperorEntity::SetEndYear(Database::Traits::ParamType::Int32 aEndYear)
{
    USER_CLASS_IS_VALID_9;

    if (aEndYear != GetEndYear())
    {
        endYear.SetValue(aEndYear);

        AddModify(endYearDescribe, GetEndYear());
    }
}

void DatabaseEntity::EmperorEntity::SetEndMonth(Database::Traits::ParamType::Int32 aEndMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aEndMonth != GetEndMonth())
    {
        endMonth.SetValue(aEndMonth);

        AddModify(endMonthDescribe, GetEndMonth());
    }
}

void DatabaseEntity::EmperorEntity::SetEndSexagenaryCycle(Database::Traits::ParamType::Int32 aEndSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aEndSexagenaryCycle != GetEndSexagenaryCycle())
    {
        endSexagenaryCycle.SetValue(aEndSexagenaryCycle);

        AddModify(endSexagenaryCycleDescribe, GetEndSexagenaryCycle());
    }
}

void DatabaseEntity::EmperorEntity::SetEndDay(Database::Traits::ParamType::Int32 aEndDay)
{
    USER_CLASS_IS_VALID_9;

    if (aEndDay != GetEndDay())
    {
        endDay.SetValue(aEndDay);

        AddModify(endDayDescribe, GetEndDay());
    }
}

void DatabaseEntity::EmperorEntity::SetAgainBeginYear(Database::Traits::ParamType::Int32 aAgainBeginYear)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainBeginYear != GetAgainBeginYear())
    {
        againBeginYear.SetValue(aAgainBeginYear);

        AddModify(againBeginYearDescribe, GetAgainBeginYear());
    }
}

void DatabaseEntity::EmperorEntity::SetAgainBeginMonth(Database::Traits::ParamType::Int32 aAgainBeginMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainBeginMonth != GetAgainBeginMonth())
    {
        againBeginMonth.SetValue(aAgainBeginMonth);

        AddModify(againBeginMonthDescribe, GetAgainBeginMonth());
    }
}

void DatabaseEntity::EmperorEntity::SetAgainBeginSexagenaryCycle(Database::Traits::ParamType::Int32 aAgainBeginSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainBeginSexagenaryCycle != GetAgainBeginSexagenaryCycle())
    {
        againBeginSexagenaryCycle.SetValue(aAgainBeginSexagenaryCycle);

        AddModify(againBeginSexagenaryCycleDescribe, GetAgainBeginSexagenaryCycle());
    }
}

void DatabaseEntity::EmperorEntity::SetAgainBeginDay(Database::Traits::ParamType::Int32 aAgainBeginDay)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainBeginDay != GetAgainBeginDay())
    {
        againBeginDay.SetValue(aAgainBeginDay);

        AddModify(againBeginDayDescribe, GetAgainBeginDay());
    }
}

void DatabaseEntity::EmperorEntity::SetAgainEndYear(Database::Traits::ParamType::Int32 aAgainEndYear)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainEndYear != GetAgainEndYear())
    {
        againEndYear.SetValue(aAgainEndYear);

        AddModify(againEndYearDescribe, GetAgainEndYear());
    }
}

void DatabaseEntity::EmperorEntity::SetAgainEndMonth(Database::Traits::ParamType::Int32 aAgainEndMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainEndMonth != GetAgainEndMonth())
    {
        againEndMonth.SetValue(aAgainEndMonth);

        AddModify(againEndMonthDescribe, GetAgainEndMonth());
    }
}

void DatabaseEntity::EmperorEntity::SetAgainEndSexagenaryCycle(Database::Traits::ParamType::Int32 aAgainEndSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainEndSexagenaryCycle != GetAgainEndSexagenaryCycle())
    {
        againEndSexagenaryCycle.SetValue(aAgainEndSexagenaryCycle);

        AddModify(againEndSexagenaryCycleDescribe, GetAgainEndSexagenaryCycle());
    }
}

void DatabaseEntity::EmperorEntity::SetAgainEndDay(Database::Traits::ParamType::Int32 aAgainEndDay)
{
    USER_CLASS_IS_VALID_9;

    if (aAgainEndDay != GetAgainEndDay())
    {
        againEndDay.SetValue(aAgainEndDay);

        AddModify(againEndDayDescribe, GetAgainEndDay());
    }
}

void DatabaseEntity::EmperorEntity::SetUnansweredQuestion(Database::Traits::ParamType::StringArray aUnansweredQuestion)
{
    USER_CLASS_IS_VALID_9;

    if (aUnansweredQuestion != GetUnansweredQuestion())
    {
        unansweredQuestion.SetValue(aUnansweredQuestion);

        AddModify(unansweredQuestionDescribe, GetUnansweredQuestion());
    }
}

const DatabaseEntity::EmperorEntity::DatabaseFieldContainer& DatabaseEntity::EmperorEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(character)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField(),
                                                            decltype(dynasticTitle)::GetDatabaseField(),
                                                            decltype(dynasticTitleAlias)::GetDatabaseField(),
                                                            decltype(posthumousTitle)::GetDatabaseField(),
                                                            decltype(posthumousTitleAlias)::GetDatabaseField(),
                                                            decltype(beginYear)::GetDatabaseField(),
                                                            decltype(beginMonth)::GetDatabaseField(),
                                                            decltype(beginSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(beginDay)::GetDatabaseField(),
                                                            decltype(endYear)::GetDatabaseField(),
                                                            decltype(endMonth)::GetDatabaseField(),
                                                            decltype(endSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(endDay)::GetDatabaseField(),
                                                            decltype(againBeginYear)::GetDatabaseField(),
                                                            decltype(againBeginMonth)::GetDatabaseField(),
                                                            decltype(againBeginSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(againBeginDay)::GetDatabaseField(),
                                                            decltype(againEndYear)::GetDatabaseField(),
                                                            decltype(againEndMonth)::GetDatabaseField(),
                                                            decltype(againEndSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(againEndDay)::GetDatabaseField(),
                                                            decltype(unansweredQuestion)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::EmperorEntity::BasisDatabaseManager DatabaseEntity::EmperorEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::EmperorEntity::BasisDatabaseManager DatabaseEntity::EmperorEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::EmperorEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
