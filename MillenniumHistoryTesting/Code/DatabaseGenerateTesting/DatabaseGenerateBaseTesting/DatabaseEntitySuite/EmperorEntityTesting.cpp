/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:24)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Emperor.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/EmperorContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/EmperorEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "EmperorEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::EmperorEntityTesting::EmperorEntityTesting(const OStreamShared& stream, EmperorContainer emperorContainer)
    : ParentType{ stream }, emperorContainer{ std::move(emperorContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, EmperorEntityTesting)

void DatabaseGenerateBaseTesting::EmperorEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& emperor : emperorContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *emperor);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::EmperorEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(EmperorEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  EmperorEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, EmperorEntity>(database);

    for (const auto& emperor : emperorContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *emperor, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::EmperorEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(EmperorEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  EmperorEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), emperorContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, EmperorEntity>(database);

    for (const auto& emperor : emperorContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *emperor, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::EmperorEntityTesting::SetEntity(EmperorEntity& emperorEntity, const Emperor& emperor)
{
    emperorEntity.SetCharacter(emperor.GetCharacter());
    emperorEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(emperor.GetName()));
    emperorEntity.SetDynasticTitle(CoreTools::StringConversion::StandardConversionUtf8(emperor.GetDynasticTitle()));
    emperorEntity.SetDynasticTitleAlias(Convert(emperor.GetDynasticTitleAliasBegin(), emperor.GetDynasticTitleAliasEnd()));
    emperorEntity.SetPosthumousTitle(CoreTools::StringConversion::StandardConversionUtf8(emperor.GetPosthumousTitle()));
    emperorEntity.SetPosthumousTitleAlias(Convert(emperor.GetPosthumousTitleAliasBegin(), emperor.GetPosthumousTitleAliasEnd()));
    emperorEntity.SetBeginYear(emperor.GetBeginYear());
    emperorEntity.SetBeginMonth(emperor.GetBeginMonth());
    emperorEntity.SetBeginSexagenaryCycle(emperor.GetBeginSexagenaryCycle());
    emperorEntity.SetBeginDay(emperor.GetBeginDay());
    emperorEntity.SetEndYear(emperor.GetEndYear());
    emperorEntity.SetEndMonth(emperor.GetEndMonth());
    emperorEntity.SetEndSexagenaryCycle(emperor.GetEndSexagenaryCycle());
    emperorEntity.SetEndDay(emperor.GetEndDay());
    emperorEntity.SetAgainBeginYear(emperor.GetAgainBeginYear());
    emperorEntity.SetAgainBeginMonth(emperor.GetAgainBeginMonth());
    emperorEntity.SetAgainBeginSexagenaryCycle(emperor.GetAgainBeginSexagenaryCycle());
    emperorEntity.SetAgainBeginDay(emperor.GetAgainBeginDay());
    emperorEntity.SetAgainEndYear(emperor.GetAgainEndYear());
    emperorEntity.SetAgainEndMonth(emperor.GetAgainEndMonth());
    emperorEntity.SetAgainEndSexagenaryCycle(emperor.GetAgainEndSexagenaryCycle());
    emperorEntity.SetAgainEndDay(emperor.GetAgainEndDay());
    emperorEntity.SetUnansweredQuestion(Convert(emperor.GetUnansweredQuestionBegin(), emperor.GetUnansweredQuestionEnd()));
}

void DatabaseGenerateBaseTesting::EmperorEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Emperor& emperor)
{
    const auto database = databaseFlush.SelectOne(EmperorEntity::GetSelect(databaseFlush.GetWrappersStrategy(), emperor.GetId()),
                                                  EmperorEntity::GetDatabaseFieldContainer());

    auto emperorEntity = EmperorEntity::Create(database, databaseFlush.GetWrappersStrategy(), emperor.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, emperorEntity, emperor);

    databaseFlush.ChangeDatabase(emperor.GetId(), emperorEntity.GetModify());
}

void DatabaseGenerateBaseTesting::EmperorEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Emperor& emperor, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(emperor.GetId());
    auto emperorEntity = result != entityContainer.cend() ? result->second : EmperorEntity{ databaseFlush.GetWrappersStrategy(), emperor.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, emperorEntity, emperor);

    databaseFlush.ChangeDatabase(emperor.GetId(), emperorEntity.GetModify());
}

void DatabaseGenerateBaseTesting::EmperorEntityTesting::EqualTest(const Emperor& emperor, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(emperor.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(emperor.GetId()));

    const auto& emperorEntity = result->second;

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
