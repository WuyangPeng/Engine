///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 17:22)

#include "Database/DatabaseExport.h"

#include "DatabaseObject.h"
#include "Detail/DatabaseObjectFactory.h"
#include "Detail/DatabaseObjectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Database::DatabaseObject::DatabaseObject(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseObject)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, DatabaseObject, GetConfigurationStrategy, Database::ConfigurationStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, DatabaseObject, GetMysqlxSession, Database::DatabaseObject::MysqlxSessionUniquePtr)
