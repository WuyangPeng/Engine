///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:17)

#include "SessionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h" 
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;
using std::vector;

Database::SessionTesting::SessionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, SessionTesting)

void Database::SessionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::SessionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullSessionTest);
}

void Database::SessionTesting::NullSessionTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null, "127.0.0.1", 3306, "tcretest", "root", "123456" };

 
}
