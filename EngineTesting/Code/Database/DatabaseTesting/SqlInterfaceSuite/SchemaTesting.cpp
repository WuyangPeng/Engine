///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:17)

#include "SchemaTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Schema.h"
#include "Database/SqlInterface/Session.h"

using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, SchemaTesting)

void Database::SchemaTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullSchemaTest);
}

void Database::SchemaTesting::NullSchemaTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    Session session{ configurationStrategy };

    Schema schema1{ session };
    Schema schema2{ session, 0 };
}
