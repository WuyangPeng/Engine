//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:42)

#include "Database/DatabaseExport.h"

#include "DatabaseObject.h"
#include "Detail/DatabaseObjectFactory.h"
#include "Detail/DatabaseObjectImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Database::DatabaseObject::DatabaseObject(const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ DatabaseObjectFactory::Create(configurationStrategy) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, DatabaseObject)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, DatabaseObject, GetConfigurationStrategy, Database::ConfigurationStrategy)

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::DatabaseObject::DatabaseObjectWeakPtr Database::DatabaseObject::GetImplType() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return m_Impl;
}
#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)