///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 21:01)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Emperor.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/EmperorContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/EmperorEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "EmperorConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::EmperorConvertTesting::EmperorConvertTesting(const OStreamShared& stream, const EmperorContainer& emperorContainer)
    : ParentType{ stream }, emperorContainer{ emperorContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, EmperorConvertTesting)

void DatabaseGenerateServerCoreTesting::EmperorConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& emperor : emperorContainer.GetContainer())
    {
        const auto emperorEntity = convertEntity.Convert(*emperor);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *emperor, emperorEntity);
    }
}

void DatabaseGenerateServerCoreTesting::EmperorConvertTesting::EqualTest(const Emperor& emperor, const EmperorEntity& emperorEntity)
{
    ASSERT_EQUAL(emperorEntity.GetCharacter(), emperor.GetCharacter());
    ASSERT_EQUAL(emperorEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(emperor.GetName()));
    ASSERT_EQUAL(emperorEntity.GetDynasticTitle(), CoreTools::StringConversion::StandardConversionUtf8(emperor.GetDynasticTitle()));
    ASSERT_EQUAL(emperorEntity.GetDynasticTitleAlias(), Convert(emperor.GetDynasticTitleAliasBegin(), emperor.GetDynasticTitleAliasEnd()));
    ASSERT_EQUAL(emperorEntity.GetPosthumousTitle(), CoreTools::StringConversion::StandardConversionUtf8(emperor.GetPosthumousTitle()));
    ASSERT_EQUAL(emperorEntity.GetPosthumousTitleAlias(), Convert(emperor.GetPosthumousTitleAliasBegin(), emperor.GetPosthumousTitleAliasEnd()));
    ASSERT_EQUAL(emperorEntity.GetBeginYear(), emperor.GetBeginYear());
    ASSERT_EQUAL(emperorEntity.GetBeginMonth(), emperor.GetBeginMonth());
    ASSERT_EQUAL(emperorEntity.GetBeginSexagenaryCycle(), emperor.GetBeginSexagenaryCycle());
    ASSERT_EQUAL(emperorEntity.GetBeginDay(), emperor.GetBeginDay());
    ASSERT_EQUAL(emperorEntity.GetEndYear(), emperor.GetEndYear());
    ASSERT_EQUAL(emperorEntity.GetEndMonth(), emperor.GetEndMonth());
    ASSERT_EQUAL(emperorEntity.GetEndSexagenaryCycle(), emperor.GetEndSexagenaryCycle());
    ASSERT_EQUAL(emperorEntity.GetEndDay(), emperor.GetEndDay());
    ASSERT_EQUAL(emperorEntity.GetAgainBeginYear(), emperor.GetAgainBeginYear());
    ASSERT_EQUAL(emperorEntity.GetAgainBeginMonth(), emperor.GetAgainBeginMonth());
    ASSERT_EQUAL(emperorEntity.GetAgainBeginSexagenaryCycle(), emperor.GetAgainBeginSexagenaryCycle());
    ASSERT_EQUAL(emperorEntity.GetAgainBeginDay(), emperor.GetAgainBeginDay());
    ASSERT_EQUAL(emperorEntity.GetAgainEndYear(), emperor.GetAgainEndYear());
    ASSERT_EQUAL(emperorEntity.GetAgainEndMonth(), emperor.GetAgainEndMonth());
    ASSERT_EQUAL(emperorEntity.GetAgainEndSexagenaryCycle(), emperor.GetAgainEndSexagenaryCycle());
    ASSERT_EQUAL(emperorEntity.GetAgainEndDay(), emperor.GetAgainEndDay());
    ASSERT_EQUAL(emperorEntity.GetUnansweredQuestion(), Convert(emperor.GetUnansweredQuestionBegin(), emperor.GetUnansweredQuestionEnd()));
}
