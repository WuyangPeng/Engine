/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "CharacterEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::CharacterEntity DatabaseEntity::CharacterEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? CharacterEntity{ entity } : CharacterEntity{ wrappersStrategy, id };
}

DatabaseEntity::CharacterEntity::CharacterEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      country{ entity.GetValue<DataType::Int32>(countryDescribe) },
      identity{ entity.GetValue<DataType::Int32>(identityDescribe) },
      family{ entity.GetValue<DataType::String>(familyDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) },
      fullName{ entity.GetValue<DataType::String>(fullNameDescribe) },
      alias{ entity.GetValue<DataType::StringArray>(aliasDescribe) },
      styleName{ entity.GetValue<DataType::String>(styleNameDescribe) },
      sex{ entity.GetValue<DataType::Int32>(sexDescribe) },
      father{ entity.GetValue<DataType::Int32>(fatherDescribe) },
      mother{ entity.GetValue<DataType::Int32>(motherDescribe) },
      fosterFather{ entity.GetValue<DataType::Int32Array>(fosterFatherDescribe) },
      fosterMother{ entity.GetValue<DataType::Int32Array>(fosterMotherDescribe) },
      birthYear{ entity.GetValue<DataType::Int32>(birthYearDescribe) },
      birthMonth{ entity.GetValue<DataType::Int32>(birthMonthDescribe) },
      birthSexagenaryCycle{ entity.GetValue<DataType::Int32>(birthSexagenaryCycleDescribe) },
      birthDay{ entity.GetValue<DataType::Int32>(birthDayDescribe) },
      deathYear{ entity.GetValue<DataType::Int32>(deathYearDescribe) },
      deathMonth{ entity.GetValue<DataType::Int32>(deathMonthDescribe) },
      deathSexagenaryCycle{ entity.GetValue<DataType::Int32>(deathSexagenaryCycleDescribe) },
      deathDay{ entity.GetValue<DataType::Int32>(deathDayDescribe) },
      unansweredQuestion{ entity.GetValue<DataType::StringArray>(unansweredQuestionDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::CharacterEntity::CharacterEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      country{ Database::Traits::Int32{} },
      identity{ Database::Traits::Int32{} },
      family{ Database::Traits::String{} },
      name{ Database::Traits::String{} },
      fullName{ Database::Traits::String{} },
      alias{ Database::Traits::StringArray{} },
      styleName{ Database::Traits::String{} },
      sex{ Database::Traits::Int32{} },
      father{ Database::Traits::Int32{} },
      mother{ Database::Traits::Int32{} },
      fosterFather{ Database::Traits::Int32Array{} },
      fosterMother{ Database::Traits::Int32Array{} },
      birthYear{ Database::Traits::Int32{} },
      birthMonth{ Database::Traits::Int32{} },
      birthSexagenaryCycle{ Database::Traits::Int32{} },
      birthDay{ Database::Traits::Int32{} },
      deathYear{ Database::Traits::Int32{} },
      deathMonth{ Database::Traits::Int32{} },
      deathSexagenaryCycle{ Database::Traits::Int32{} },
      deathDay{ Database::Traits::Int32{} },
      unansweredQuestion{ Database::Traits::StringArray{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, CharacterEntity)

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetIdentity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return identity.GetValue();
}

Database::Traits::String DatabaseEntity::CharacterEntity::GetFamily() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return family.GetValue();
}

Database::Traits::String DatabaseEntity::CharacterEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

Database::Traits::String DatabaseEntity::CharacterEntity::GetFullName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return fullName.GetValue();
}

Database::Traits::StringArray DatabaseEntity::CharacterEntity::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.GetValue();
}

Database::Traits::String DatabaseEntity::CharacterEntity::GetStyleName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return styleName.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetSex() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return sex.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetFather() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return father.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetMother() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return mother.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::CharacterEntity::GetFosterFather() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterFather.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::CharacterEntity::GetFosterMother() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterMother.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetBirthYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return birthYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetBirthMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return birthMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetBirthSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return birthSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetBirthDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return birthDay.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetDeathYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return deathYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetDeathMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return deathMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetDeathSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return deathSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::CharacterEntity::GetDeathDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return deathDay.GetValue();
}

Database::Traits::StringArray DatabaseEntity::CharacterEntity::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.GetValue();
}

void DatabaseEntity::CharacterEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::CharacterEntity::SetCountry(Database::Traits::ParamType::Int32 aCountry)
{
    USER_CLASS_IS_VALID_9;

    if (aCountry != GetCountry())
    {
        country.SetValue(aCountry);

        AddModify(countryDescribe, GetCountry());
    }
}

void DatabaseEntity::CharacterEntity::SetIdentity(Database::Traits::ParamType::Int32 aIdentity)
{
    USER_CLASS_IS_VALID_9;

    if (aIdentity != GetIdentity())
    {
        identity.SetValue(aIdentity);

        AddModify(identityDescribe, GetIdentity());
    }
}

void DatabaseEntity::CharacterEntity::SetFamily(Database::Traits::ParamType::String aFamily)
{
    USER_CLASS_IS_VALID_9;

    if (aFamily != GetFamily())
    {
        family.SetValue(aFamily);

        AddModify(familyDescribe, GetFamily());
    }
}

void DatabaseEntity::CharacterEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

void DatabaseEntity::CharacterEntity::SetFullName(Database::Traits::ParamType::String aFullName)
{
    USER_CLASS_IS_VALID_9;

    if (aFullName != GetFullName())
    {
        fullName.SetValue(aFullName);

        AddModify(fullNameDescribe, GetFullName());
    }
}

void DatabaseEntity::CharacterEntity::SetAlias(Database::Traits::ParamType::StringArray aAlias)
{
    USER_CLASS_IS_VALID_9;

    if (aAlias != GetAlias())
    {
        alias.SetValue(aAlias);

        AddModify(aliasDescribe, GetAlias());
    }
}

void DatabaseEntity::CharacterEntity::SetStyleName(Database::Traits::ParamType::String aStyleName)
{
    USER_CLASS_IS_VALID_9;

    if (aStyleName != GetStyleName())
    {
        styleName.SetValue(aStyleName);

        AddModify(styleNameDescribe, GetStyleName());
    }
}

void DatabaseEntity::CharacterEntity::SetSex(Database::Traits::ParamType::Int32 aSex)
{
    USER_CLASS_IS_VALID_9;

    if (aSex != GetSex())
    {
        sex.SetValue(aSex);

        AddModify(sexDescribe, GetSex());
    }
}

void DatabaseEntity::CharacterEntity::SetFather(Database::Traits::ParamType::Int32 aFather)
{
    USER_CLASS_IS_VALID_9;

    if (aFather != GetFather())
    {
        father.SetValue(aFather);

        AddModify(fatherDescribe, GetFather());
    }
}

void DatabaseEntity::CharacterEntity::SetMother(Database::Traits::ParamType::Int32 aMother)
{
    USER_CLASS_IS_VALID_9;

    if (aMother != GetMother())
    {
        mother.SetValue(aMother);

        AddModify(motherDescribe, GetMother());
    }
}

void DatabaseEntity::CharacterEntity::SetFosterFather(Database::Traits::ParamType::Int32Array aFosterFather)
{
    USER_CLASS_IS_VALID_9;

    if (aFosterFather != GetFosterFather())
    {
        fosterFather.SetValue(aFosterFather);

        AddModify(fosterFatherDescribe, GetFosterFather());
    }
}

void DatabaseEntity::CharacterEntity::SetFosterMother(Database::Traits::ParamType::Int32Array aFosterMother)
{
    USER_CLASS_IS_VALID_9;

    if (aFosterMother != GetFosterMother())
    {
        fosterMother.SetValue(aFosterMother);

        AddModify(fosterMotherDescribe, GetFosterMother());
    }
}

void DatabaseEntity::CharacterEntity::SetBirthYear(Database::Traits::ParamType::Int32 aBirthYear)
{
    USER_CLASS_IS_VALID_9;

    if (aBirthYear != GetBirthYear())
    {
        birthYear.SetValue(aBirthYear);

        AddModify(birthYearDescribe, GetBirthYear());
    }
}

void DatabaseEntity::CharacterEntity::SetBirthMonth(Database::Traits::ParamType::Int32 aBirthMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aBirthMonth != GetBirthMonth())
    {
        birthMonth.SetValue(aBirthMonth);

        AddModify(birthMonthDescribe, GetBirthMonth());
    }
}

void DatabaseEntity::CharacterEntity::SetBirthSexagenaryCycle(Database::Traits::ParamType::Int32 aBirthSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aBirthSexagenaryCycle != GetBirthSexagenaryCycle())
    {
        birthSexagenaryCycle.SetValue(aBirthSexagenaryCycle);

        AddModify(birthSexagenaryCycleDescribe, GetBirthSexagenaryCycle());
    }
}

void DatabaseEntity::CharacterEntity::SetBirthDay(Database::Traits::ParamType::Int32 aBirthDay)
{
    USER_CLASS_IS_VALID_9;

    if (aBirthDay != GetBirthDay())
    {
        birthDay.SetValue(aBirthDay);

        AddModify(birthDayDescribe, GetBirthDay());
    }
}

void DatabaseEntity::CharacterEntity::SetDeathYear(Database::Traits::ParamType::Int32 aDeathYear)
{
    USER_CLASS_IS_VALID_9;

    if (aDeathYear != GetDeathYear())
    {
        deathYear.SetValue(aDeathYear);

        AddModify(deathYearDescribe, GetDeathYear());
    }
}

void DatabaseEntity::CharacterEntity::SetDeathMonth(Database::Traits::ParamType::Int32 aDeathMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aDeathMonth != GetDeathMonth())
    {
        deathMonth.SetValue(aDeathMonth);

        AddModify(deathMonthDescribe, GetDeathMonth());
    }
}

void DatabaseEntity::CharacterEntity::SetDeathSexagenaryCycle(Database::Traits::ParamType::Int32 aDeathSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aDeathSexagenaryCycle != GetDeathSexagenaryCycle())
    {
        deathSexagenaryCycle.SetValue(aDeathSexagenaryCycle);

        AddModify(deathSexagenaryCycleDescribe, GetDeathSexagenaryCycle());
    }
}

void DatabaseEntity::CharacterEntity::SetDeathDay(Database::Traits::ParamType::Int32 aDeathDay)
{
    USER_CLASS_IS_VALID_9;

    if (aDeathDay != GetDeathDay())
    {
        deathDay.SetValue(aDeathDay);

        AddModify(deathDayDescribe, GetDeathDay());
    }
}

void DatabaseEntity::CharacterEntity::SetUnansweredQuestion(Database::Traits::ParamType::StringArray aUnansweredQuestion)
{
    USER_CLASS_IS_VALID_9;

    if (aUnansweredQuestion != GetUnansweredQuestion())
    {
        unansweredQuestion.SetValue(aUnansweredQuestion);

        AddModify(unansweredQuestionDescribe, GetUnansweredQuestion());
    }
}

const DatabaseEntity::CharacterEntity::DatabaseFieldContainer& DatabaseEntity::CharacterEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(country)::GetDatabaseField(),
                                                            decltype(identity)::GetDatabaseField(),
                                                            decltype(family)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField(),
                                                            decltype(fullName)::GetDatabaseField(),
                                                            decltype(alias)::GetDatabaseField(),
                                                            decltype(styleName)::GetDatabaseField(),
                                                            decltype(sex)::GetDatabaseField(),
                                                            decltype(father)::GetDatabaseField(),
                                                            decltype(mother)::GetDatabaseField(),
                                                            decltype(fosterFather)::GetDatabaseField(),
                                                            decltype(fosterMother)::GetDatabaseField(),
                                                            decltype(birthYear)::GetDatabaseField(),
                                                            decltype(birthMonth)::GetDatabaseField(),
                                                            decltype(birthSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(birthDay)::GetDatabaseField(),
                                                            decltype(deathYear)::GetDatabaseField(),
                                                            decltype(deathMonth)::GetDatabaseField(),
                                                            decltype(deathSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(deathDay)::GetDatabaseField(),
                                                            decltype(unansweredQuestion)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::CharacterEntity::BasisDatabaseManager DatabaseEntity::CharacterEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::CharacterEntity::BasisDatabaseManager DatabaseEntity::CharacterEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::CharacterEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
