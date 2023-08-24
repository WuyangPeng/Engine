///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 21:10)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Source.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/SourceContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/SourceEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "SourceConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::SourceConvertTesting::SourceConvertTesting(const OStreamShared& stream, const SourceContainer& sourceContainer)
    : ParentType{ stream }, sourceContainer{ sourceContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, SourceConvertTesting)

void DatabaseGenerateServerCoreTesting::SourceConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& source : sourceContainer.GetContainer())
    {
        const auto sourceEntity = convertEntity.Convert(*source);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *source, sourceEntity);
    }
}

void DatabaseGenerateServerCoreTesting::SourceConvertTesting::EqualTest(const Source& source, const SourceEntity& sourceEntity)
{
    ASSERT_EQUAL(sourceEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(source.GetName()));
    ASSERT_EQUAL(sourceEntity.GetSort(), source.GetSort());
}
