///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 10:45)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_DETAIL_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_DETAIL_H

#include "BasisDatabaseContainer.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

template <Database::DataType Type>
typename Database::DataTypeTraits<Type>::Type Database::BasisDatabaseContainer::GetValue(const std::string_view& fieldName) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return std::any_cast<typename DataTypeTraits<Type>::Type>(GetAnyValue(fieldName));
}

#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_DETAIL_H
