/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "ReignTitleEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::ReignTitleEntity DatabaseEntity::ReignTitleEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id)
{
    return entity.IsModify() ? ReignTitleEntity{ entity } : ReignTitleEntity{ wrappersStrategy, id };
}

DatabaseEntity::ReignTitleEntity::ReignTitleEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int64>(idDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) },
      emperor{ entity.GetValue<DataType::Int32Array>(emperorDescribe) },
      serial{ entity.GetValue<DataType::Int32>(serialDescribe) },
      beginYear{ entity.GetValue<DataType::Int32>(beginYearDescribe) },
      beginMonth{ entity.GetValue<DataType::Int32>(beginMonthDescribe) },
      beginSexagenaryCycle{ entity.GetValue<DataType::Int32>(beginSexagenaryCycleDescribe) },
      beginDay{ entity.GetValue<DataType::Int32>(beginDayDescribe) },
      endYear{ entity.GetValue<DataType::Int32>(endYearDescribe) },
      endMonth{ entity.GetValue<DataType::Int32>(endMonthDescribe) },
      endSexagenaryCycle{ entity.GetValue<DataType::Int32>(endSexagenaryCycleDescribe) },
      endDay{ entity.GetValue<DataType::Int32>(endDayDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::ReignTitleEntity::ReignTitleEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      name{ Database::Traits::String{} },
      emperor{ Database::Traits::Int32Array{} },
      serial{ Database::Traits::Int32{} },
      beginYear{ Database::Traits::Int32{} },
      beginMonth{ Database::Traits::Int32{} },
      beginSexagenaryCycle{ Database::Traits::Int32{} },
      beginDay{ Database::Traits::Int32{} },
      endYear{ Database::Traits::Int32{} },
      endMonth{ Database::Traits::Int32{} },
      endSexagenaryCycle{ Database::Traits::Int32{} },
      endDay{ Database::Traits::Int32{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, ReignTitleEntity)

Database::Traits::Int64 DatabaseEntity::ReignTitleEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::String DatabaseEntity::ReignTitleEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::ReignTitleEntity::GetEmperor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return emperor.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ReignTitleEntity::GetSerial() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return serial.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ReignTitleEntity::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ReignTitleEntity::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ReignTitleEntity::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ReignTitleEntity::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginDay.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ReignTitleEntity::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endYear.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ReignTitleEntity::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endMonth.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ReignTitleEntity::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endSexagenaryCycle.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ReignTitleEntity::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endDay.GetValue();
}

void DatabaseEntity::ReignTitleEntity::SetId(Database::Traits::ParamType::Int64 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::ReignTitleEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

void DatabaseEntity::ReignTitleEntity::SetEmperor(Database::Traits::ParamType::Int32Array aEmperor)
{
    USER_CLASS_IS_VALID_9;

    if (aEmperor != GetEmperor())
    {
        emperor.SetValue(aEmperor);

        AddModify(emperorDescribe, GetEmperor());
    }
}

void DatabaseEntity::ReignTitleEntity::SetSerial(Database::Traits::ParamType::Int32 aSerial)
{
    USER_CLASS_IS_VALID_9;

    if (aSerial != GetSerial())
    {
        serial.SetValue(aSerial);

        AddModify(serialDescribe, GetSerial());
    }
}

void DatabaseEntity::ReignTitleEntity::SetBeginYear(Database::Traits::ParamType::Int32 aBeginYear)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginYear != GetBeginYear())
    {
        beginYear.SetValue(aBeginYear);

        AddModify(beginYearDescribe, GetBeginYear());
    }
}

void DatabaseEntity::ReignTitleEntity::SetBeginMonth(Database::Traits::ParamType::Int32 aBeginMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginMonth != GetBeginMonth())
    {
        beginMonth.SetValue(aBeginMonth);

        AddModify(beginMonthDescribe, GetBeginMonth());
    }
}

void DatabaseEntity::ReignTitleEntity::SetBeginSexagenaryCycle(Database::Traits::ParamType::Int32 aBeginSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginSexagenaryCycle != GetBeginSexagenaryCycle())
    {
        beginSexagenaryCycle.SetValue(aBeginSexagenaryCycle);

        AddModify(beginSexagenaryCycleDescribe, GetBeginSexagenaryCycle());
    }
}

void DatabaseEntity::ReignTitleEntity::SetBeginDay(Database::Traits::ParamType::Int32 aBeginDay)
{
    USER_CLASS_IS_VALID_9;

    if (aBeginDay != GetBeginDay())
    {
        beginDay.SetValue(aBeginDay);

        AddModify(beginDayDescribe, GetBeginDay());
    }
}

void DatabaseEntity::ReignTitleEntity::SetEndYear(Database::Traits::ParamType::Int32 aEndYear)
{
    USER_CLASS_IS_VALID_9;

    if (aEndYear != GetEndYear())
    {
        endYear.SetValue(aEndYear);

        AddModify(endYearDescribe, GetEndYear());
    }
}

void DatabaseEntity::ReignTitleEntity::SetEndMonth(Database::Traits::ParamType::Int32 aEndMonth)
{
    USER_CLASS_IS_VALID_9;

    if (aEndMonth != GetEndMonth())
    {
        endMonth.SetValue(aEndMonth);

        AddModify(endMonthDescribe, GetEndMonth());
    }
}

void DatabaseEntity::ReignTitleEntity::SetEndSexagenaryCycle(Database::Traits::ParamType::Int32 aEndSexagenaryCycle)
{
    USER_CLASS_IS_VALID_9;

    if (aEndSexagenaryCycle != GetEndSexagenaryCycle())
    {
        endSexagenaryCycle.SetValue(aEndSexagenaryCycle);

        AddModify(endSexagenaryCycleDescribe, GetEndSexagenaryCycle());
    }
}

void DatabaseEntity::ReignTitleEntity::SetEndDay(Database::Traits::ParamType::Int32 aEndDay)
{
    USER_CLASS_IS_VALID_9;

    if (aEndDay != GetEndDay())
    {
        endDay.SetValue(aEndDay);

        AddModify(endDayDescribe, GetEndDay());
    }
}

const DatabaseEntity::ReignTitleEntity::DatabaseFieldContainer& DatabaseEntity::ReignTitleEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField(),
                                                            decltype(emperor)::GetDatabaseField(),
                                                            decltype(serial)::GetDatabaseField(),
                                                            decltype(beginYear)::GetDatabaseField(),
                                                            decltype(beginMonth)::GetDatabaseField(),
                                                            decltype(beginSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(beginDay)::GetDatabaseField(),
                                                            decltype(endYear)::GetDatabaseField(),
                                                            decltype(endMonth)::GetDatabaseField(),
                                                            decltype(endSexagenaryCycle)::GetDatabaseField(),
                                                            decltype(endDay)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::ReignTitleEntity::BasisDatabaseManager DatabaseEntity::ReignTitleEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

Database::BasisDatabaseContainer DatabaseEntity::ReignTitleEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int64 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}
