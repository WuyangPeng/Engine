///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 09:25)

#ifndef DATABASE_DATABASE_INTERFACE_ENTITY_H
#define DATABASE_DATABASE_INTERFACE_ENTITY_H

#include "Database/DatabaseDll.h"

#include "DataTypeTraits.h"
#include "DatabaseField.h"
#include "System/Helper/PragmaWarning/CallTraits.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <string>

namespace Database
{
    template <const std::string_view& FieldName, DataType Type, IndexType Index = IndexType::Null>
    class Entity
    {
    public:
        using ClassType = Entity<FieldName, Type, Index>;
        using EntityType = typename DataTypeTraits<Type>::Type;

    public:
        explicit Entity(typename boost::call_traits<EntityType>::param_type entity) noexcept(std::is_arithmetic_v<EntityType>);

        CLASS_INVARIANT_DECLARE;

        NODISCARD static constexpr std::string_view GetFieldName() noexcept
        {
            return FieldName;
        }

        NODISCARD static constexpr DataType GetDataType() noexcept
        {
            return Type;
        }

        NODISCARD static constexpr IndexType GetIndexType() noexcept
        {
            return Index;
        }

        NODISCARD static DatabaseField GetDatabaseField() noexcept;

        NODISCARD EntityType GetValue() const noexcept(std::is_arithmetic_v<EntityType>);
        void SetValue(typename boost::call_traits<EntityType>::param_type aEntity) noexcept(std::is_arithmetic_v<EntityType>);
        void ModifyValue(typename boost::call_traits<EntityType>::param_type aEntity) noexcept(std::is_arithmetic_v<EntityType>);

    private:
        EntityType entity;
    };
}
#endif  // DATABASE_DATABASE_INTERFACE_ENTITY_H