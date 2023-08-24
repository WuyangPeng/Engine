///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 21:02)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Gather.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GatherContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/GatherEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "GatherConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::GatherConvertTesting::GatherConvertTesting(const OStreamShared& stream, const GatherContainer& gatherContainer)
    : ParentType{ stream }, gatherContainer{ gatherContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, GatherConvertTesting)

void DatabaseGenerateServerCoreTesting::GatherConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& gather : gatherContainer.GetContainer())
    {
        const auto gatherEntity = convertEntity.Convert(*gather);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *gather, gatherEntity);
    }
}

void DatabaseGenerateServerCoreTesting::GatherConvertTesting::EqualTest(const Gather& gather, const GatherEntity& gatherEntity)
{
    ASSERT_EQUAL(gatherEntity.GetGather(), CoreTools::StringConversion::StandardConversionUtf8(gather.GetGather()));
}
