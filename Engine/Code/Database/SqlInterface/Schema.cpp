///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 17:22)

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
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::Schema::Schema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, mysqlxSchema }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, Schema)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Schema, GetConfigurationStrategy, Database::ConfigurationStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, Schema, GetCollection, std::string, Database::Schema::MysqlxCollectionUniquePtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, Schema, GetTable, std::string, Database::Schema::MysqlxTableUniquePtr)
