/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:18)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Source.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/SourceContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/SourceEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "SourceConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::SourceConvertTesting::SourceConvertTesting(const OStreamShared& stream, SourceContainer sourceContainer)
    : ParentType{ stream }, sourceContainer{ std::move(sourceContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, SourceConvertTesting)

void DatabaseGenerateCoreTesting::SourceConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& source : sourceContainer.GetContainer())
    {
        const auto sourceEntity = convertEntity.Convert(*source);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *source, sourceEntity);
    }
}

void DatabaseGenerateCoreTesting::SourceConvertTesting::EqualTest(const Source& source, const SourceEntity& sourceEntity)
{
    ASSERT_EQUAL(sourceEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(source.GetName()));
    ASSERT_EQUAL(sourceEntity.GetSort(), source.GetSort());
}
