///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 21:05)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Genus.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GenusContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/GenusEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "GenusConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::GenusConvertTesting::GenusConvertTesting(const OStreamShared& stream, const GenusContainer& genusContainer)
    : ParentType{ stream }, genusContainer{ genusContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, GenusConvertTesting)

void DatabaseGenerateServerCoreTesting::GenusConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& genus : genusContainer.GetContainer())
    {
        const auto genusEntity = convertEntity.Convert(*genus);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *genus, genusEntity);
    }
}

void DatabaseGenerateServerCoreTesting::GenusConvertTesting::EqualTest(const Genus& genus, const GenusEntity& genusEntity)
{
    ASSERT_EQUAL(genusEntity.GetCategory(), genus.GetCategory());
    ASSERT_EQUAL(genusEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(genus.GetName()));
    ASSERT_EQUAL(genusEntity.GetFather(), genus.GetFather());
    ASSERT_EQUAL(genusEntity.GetBegin(), CoreTools::StringConversion::StandardConversionUtf8(genus.GetBegin()));
    ASSERT_EQUAL(genusEntity.GetEnd(), CoreTools::StringConversion::StandardConversionUtf8(genus.GetEnd()));
}
