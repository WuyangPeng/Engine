/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:52)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Genus.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GenusContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/GenusEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "GenusConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::GenusConvertTesting::GenusConvertTesting(const OStreamShared& stream, const GenusContainer& genusContainer)
    : ParentType{ stream }, genusContainer{ genusContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, GenusConvertTesting)

void DatabaseGenerateCoreTesting::GenusConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& genus : genusContainer.GetContainer())
    {
        const auto genusEntity = convertEntity.Convert(*genus);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *genus, genusEntity);
    }
}

void DatabaseGenerateCoreTesting::GenusConvertTesting::EqualTest(const Genus& genus, const GenusEntity& genusEntity)
{
    ASSERT_EQUAL(genusEntity.GetCategory(), genus.GetCategory());
    ASSERT_EQUAL(genusEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(genus.GetName()));
    ASSERT_EQUAL(genusEntity.GetFather(), genus.GetFather());
    ASSERT_EQUAL(genusEntity.GetBegin(), CoreTools::StringConversion::StandardConversionUtf8(genus.GetBegin()));
    ASSERT_EQUAL(genusEntity.GetEnd(), CoreTools::StringConversion::StandardConversionUtf8(genus.GetEnd()));
}
