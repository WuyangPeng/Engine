///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:22)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_MANAGER_DETAIL_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_MANAGER_DETAIL_H

#include "BasisDatabaseManager.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

template <Database::DataType Type>
typename Database::DataTypeTraits<Type>::Type Database::BasisDatabaseManager::GetValue(const std::string_view& fieldName, typename boost::call_traits<typename DataTypeTraits<Type>::Type>::param_type defaultValue) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    if (const auto result = GetAnyValue(fieldName);
        result.has_value())
    {
        return std::any_cast<typename DataTypeTraits<Type>::Type>(GetAnyValue(fieldName));
    }
    else
    {
        return defaultValue;
    }
}

#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_MANAGER_DETAIL_H
