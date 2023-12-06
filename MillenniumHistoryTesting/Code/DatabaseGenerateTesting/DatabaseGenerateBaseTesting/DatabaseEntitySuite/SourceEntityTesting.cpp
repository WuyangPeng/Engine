/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:43)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Source.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/SourceContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/SourceEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "SourceEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::SourceEntityTesting::SourceEntityTesting(const OStreamShared& stream, const SourceContainer& sourceContainer)
    : ParentType{ stream }, sourceContainer{ sourceContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, SourceEntityTesting)

void DatabaseGenerateBaseTesting::SourceEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& source : sourceContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *source);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::SourceEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(SourceEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  SourceEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, SourceEntity>(database);

    for (const auto& source : sourceContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *source, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::SourceEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(SourceEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  SourceEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), sourceContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, SourceEntity>(database);

    for (const auto& source : sourceContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *source, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::SourceEntityTesting::SetEntity(SourceEntity& sourceEntity, const Source& source)
{
    sourceEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(source.GetName()));
    sourceEntity.SetSort(source.GetSort());
}

void DatabaseGenerateBaseTesting::SourceEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Source& source)
{
    const auto database = databaseFlush.SelectOne(SourceEntity::GetSelect(databaseFlush.GetWrappersStrategy(), source.GetId()),
                                                  SourceEntity::GetDatabaseFieldContainer());

    auto sourceEntity = SourceEntity::Create(database, databaseFlush.GetWrappersStrategy(), source.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, sourceEntity, source);

    databaseFlush.ChangeDatabase(source.GetId(), sourceEntity.GetModify());
}

void DatabaseGenerateBaseTesting::SourceEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Source& source, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(source.GetId());
    auto sourceEntity = result != entityContainer.cend() ? result->second : SourceEntity{ databaseFlush.GetWrappersStrategy(), source.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, sourceEntity, source);

    databaseFlush.ChangeDatabase(source.GetId(), sourceEntity.GetModify());
}

void DatabaseGenerateBaseTesting::SourceEntityTesting::EqualTest(const Source& source, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(source.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(source.GetId()));

    const auto& sourceEntity = result->second;

    ASSERT_EQUAL(sourceEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(source.GetName()));
    ASSERT_EQUAL(sourceEntity.GetSort(), source.GetSort());
}
