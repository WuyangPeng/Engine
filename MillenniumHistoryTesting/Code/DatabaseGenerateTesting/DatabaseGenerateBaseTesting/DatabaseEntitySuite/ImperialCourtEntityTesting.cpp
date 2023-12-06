/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:42)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ImperialCourt.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ImperialCourtContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/ImperialCourtEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "ImperialCourtEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::ImperialCourtEntityTesting::ImperialCourtEntityTesting(const OStreamShared& stream, const ImperialCourtContainer& imperialCourtContainer)
    : ParentType{ stream }, imperialCourtContainer{ imperialCourtContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, ImperialCourtEntityTesting)

void DatabaseGenerateBaseTesting::ImperialCourtEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& imperialCourt : imperialCourtContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *imperialCourt);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::ImperialCourtEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(ImperialCourtEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  ImperialCourtEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, ImperialCourtEntity>(database);

    for (const auto& imperialCourt : imperialCourtContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *imperialCourt, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::ImperialCourtEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(ImperialCourtEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  ImperialCourtEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), imperialCourtContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, ImperialCourtEntity>(database);

    for (const auto& imperialCourt : imperialCourtContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *imperialCourt, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::ImperialCourtEntityTesting::SetEntity(ImperialCourtEntity& imperialCourtEntity, const ImperialCourt& imperialCourt)
{
    imperialCourtEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetCategory()));
    imperialCourtEntity.SetBook(CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetBook()));
    imperialCourtEntity.SetBegin(imperialCourt.GetBegin());
    imperialCourtEntity.SetEnd(imperialCourt.GetEnd());
}

void DatabaseGenerateBaseTesting::ImperialCourtEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const ImperialCourt& imperialCourt)
{
    const auto database = databaseFlush.SelectOne(ImperialCourtEntity::GetSelect(databaseFlush.GetWrappersStrategy(), imperialCourt.GetId()),
                                                  ImperialCourtEntity::GetDatabaseFieldContainer());

    auto imperialCourtEntity = ImperialCourtEntity::Create(database, databaseFlush.GetWrappersStrategy(), imperialCourt.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, imperialCourtEntity, imperialCourt);

    databaseFlush.ChangeDatabase(imperialCourt.GetId(), imperialCourtEntity.GetModify());
}

void DatabaseGenerateBaseTesting::ImperialCourtEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const ImperialCourt& imperialCourt, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(imperialCourt.GetId());
    auto imperialCourtEntity = result != entityContainer.cend() ? result->second : ImperialCourtEntity{ databaseFlush.GetWrappersStrategy(), imperialCourt.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, imperialCourtEntity, imperialCourt);

    databaseFlush.ChangeDatabase(imperialCourt.GetId(), imperialCourtEntity.GetModify());
}

void DatabaseGenerateBaseTesting::ImperialCourtEntityTesting::EqualTest(const ImperialCourt& imperialCourt, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(imperialCourt.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(imperialCourt.GetId()));

    const auto& imperialCourtEntity = result->second;

    ASSERT_EQUAL(imperialCourtEntity.GetCategory(), CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetCategory()));
    ASSERT_EQUAL(imperialCourtEntity.GetBook(), CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetBook()));
    ASSERT_EQUAL(imperialCourtEntity.GetBegin(), imperialCourt.GetBegin());
    ASSERT_EQUAL(imperialCourtEntity.GetEnd(), imperialCourt.GetEnd());
}
