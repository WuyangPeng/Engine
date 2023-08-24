///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/03 23:19)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Day.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/DayContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DayEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "DayConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::DayConvertTesting::DayConvertTesting(const OStreamShared& stream, const DayContainer& dayContainer)
    : ParentType{ stream }, dayContainer{ dayContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, DayConvertTesting)

void DatabaseGenerateServerCoreTesting::DayConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& day : dayContainer.GetContainer())
    {
        const auto dayEntity = convertEntity.Convert(*day);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *day, dayEntity);
    }
}

void DatabaseGenerateServerCoreTesting::DayConvertTesting::EqualTest(const Day& day, const DayEntity& dayEntity)
{
    ASSERT_EQUAL(dayEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(day.GetName()));
}
