///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:22)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_DATABASE_ENTITY_DETAIL_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_DATABASE_ENTITY_DETAIL_H

#include "BasisDatabase.h"
#include "DatabaseEntity.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

template <typename T>
void Database::DatabaseEntity::AddModify(const std::string_view& fieldName, T value)
{
    DATABASE_CLASS_IS_VALID_9;

    AddModify(BasisDatabase{ fieldName, value });
}

#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_DATABASE_ENTITY_DETAIL_H
