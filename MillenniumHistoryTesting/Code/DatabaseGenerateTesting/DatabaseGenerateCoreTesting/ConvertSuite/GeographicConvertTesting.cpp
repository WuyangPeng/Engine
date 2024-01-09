/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:18)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Geographic.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GeographicContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/GeographicEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "GeographicConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::GeographicConvertTesting::GeographicConvertTesting(const OStreamShared& stream, GeographicContainer geographicContainer)
    : ParentType{ stream }, geographicContainer{ std::move(geographicContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, GeographicConvertTesting)

void DatabaseGenerateCoreTesting::GeographicConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& geographic : geographicContainer.GetContainer())
    {
        const auto geographicEntity = convertEntity.Convert(*geographic);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *geographic, geographicEntity);
    }
}

void DatabaseGenerateCoreTesting::GeographicConvertTesting::EqualTest(const Geographic& geographic, const GeographicEntity& geographicEntity)
{
    ASSERT_EQUAL(geographicEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(geographic.GetName()));
}
