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
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h" 
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;
using std::vector;

Database::SchemaTesting::SchemaTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, SchemaTesting)

void Database::SchemaTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::SchemaTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullSchemaTest);
}

void Database::SchemaTesting::NullSchemaTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null, "127.0.0.1", 3306, "tcretest", "root", "123456" };

}
