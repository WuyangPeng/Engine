///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 21:08)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Geographic.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GeographicContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/GeographicEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "GeographicConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::GeographicConvertTesting::GeographicConvertTesting(const OStreamShared& stream, const GeographicContainer& geographicContainer)
    : ParentType{ stream }, geographicContainer{ geographicContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, GeographicConvertTesting)

void DatabaseGenerateServerCoreTesting::GeographicConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& geographic : geographicContainer.GetContainer())
    {
        const auto geographicEntity = convertEntity.Convert(*geographic);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *geographic, geographicEntity);
    }
}

void DatabaseGenerateServerCoreTesting::GeographicConvertTesting::EqualTest(const Geographic& geographic, const GeographicEntity& geographicEntity)
{
    ASSERT_EQUAL(geographicEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(geographic.GetName()));
}
