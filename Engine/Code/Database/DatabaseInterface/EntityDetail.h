///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:22)

#ifndef DATABASE_DATABASE_INTERFACE_ENTITY_DETAIL_H
#define DATABASE_DATABASE_INTERFACE_ENTITY_DETAIL_H

#include "Entity.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

template <const std::string_view& FieldName, Database::DataType Type, Database::IndexType Index>
Database::Entity<FieldName, Type, Index>::Entity(typename boost::call_traits<EntityType>::param_type entity) noexcept(std::is_arithmetic_v<EntityType>)
    : entity{ entity }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <const std::string_view& FieldName, Database::DataType Type, Database::IndexType Index>
bool Database::Entity<FieldName, Type, Index>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <const std::string_view& FieldName, Database::DataType Type, Database::IndexType Index>
Database::DatabaseField Database::Entity<FieldName, Type, Index>::GetDatabaseField() noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return DatabaseField{ FieldName, Type, Index };
}

template <const std::string_view& FieldName, Database::DataType Type, Database::IndexType Index>
typename Database::Entity<FieldName, Type, Index>::EntityType Database::Entity<FieldName, Type, Index>::GetValue() const noexcept(std::is_arithmetic_v<EntityType>)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return entity;
}

template <const std::string_view& FieldName, Database::DataType Type, Database::IndexType Index>
void Database::Entity<FieldName, Type, Index>::SetValue(typename boost::call_traits<EntityType>::param_type aEntity) noexcept(std::is_arithmetic_v<EntityType>)
{
    DATABASE_CLASS_IS_VALID_9;

    entity = aEntity;
}

template <const std::string_view& FieldName, Database::DataType Type, Database::IndexType Index>
void Database::Entity<FieldName, Type, Index>::ModifyValue(typename boost::call_traits<EntityType>::param_type aEntity) noexcept(std::is_arithmetic_v<EntityType>)
{
    DATABASE_CLASS_IS_VALID_9;

    entity += aEntity;
}

#endif  // DATABASE_DATABASE_INTERFACE_ENTITY_DETAIL_H