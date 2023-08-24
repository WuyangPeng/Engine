///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/05 21:10)

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
