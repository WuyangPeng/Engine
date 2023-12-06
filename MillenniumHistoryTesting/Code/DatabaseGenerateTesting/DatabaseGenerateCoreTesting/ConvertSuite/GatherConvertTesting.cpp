/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:52)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Gather.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GatherContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/GatherEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "GatherConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::GatherConvertTesting::GatherConvertTesting(const OStreamShared& stream, const GatherContainer& gatherContainer)
    : ParentType{ stream }, gatherContainer{ gatherContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, GatherConvertTesting)

void DatabaseGenerateCoreTesting::GatherConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& gather : gatherContainer.GetContainer())
    {
        const auto gatherEntity = convertEntity.Convert(*gather);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *gather, gatherEntity);
    }
}

void DatabaseGenerateCoreTesting::GatherConvertTesting::EqualTest(const Gather& gather, const GatherEntity& gatherEntity)
{
    ASSERT_EQUAL(gatherEntity.GetGather(), CoreTools::StringConversion::StandardConversionUtf8(gather.GetGather()));
}
