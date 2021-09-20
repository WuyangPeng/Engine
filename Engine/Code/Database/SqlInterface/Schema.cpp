//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:43)

#include "Database/DatabaseExport.h"

#include "Schema.h"
#include "Detail/SchemaFactory.h"
#include "Detail/SchemaImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Database::Schema::Schema(const Session& session)
    : impl{ CoreTools::ImplCreateUseFactory::Default, session }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::Schema::Schema(const Session& session, int dbIndex)
    : impl{ CoreTools::ImplCreateUseFactory::Default, session, dbIndex }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Database, Schema)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Schema, GetConfigurationStrategy, Database::ConfigurationStrategy)

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::Schema::SchemaWeakPtr Database::Schema::GetImplType() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return SchemaWeakPtr{};
}

Database::Schema::Schema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, mysqlxSchema }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)