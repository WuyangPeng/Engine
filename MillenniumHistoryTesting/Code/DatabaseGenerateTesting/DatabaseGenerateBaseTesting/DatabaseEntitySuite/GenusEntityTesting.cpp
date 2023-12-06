/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:42)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Genus.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GenusContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/GenusEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "GenusEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::GenusEntityTesting::GenusEntityTesting(const OStreamShared& stream, const GenusContainer& genusContainer)
    : ParentType{ stream }, genusContainer{ genusContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, GenusEntityTesting)

void DatabaseGenerateBaseTesting::GenusEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& genus : genusContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *genus);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::GenusEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(GenusEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  GenusEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, GenusEntity>(database);

    for (const auto& genus : genusContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *genus, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::GenusEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(GenusEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  GenusEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), genusContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, GenusEntity>(database);

    for (const auto& genus : genusContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *genus, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::GenusEntityTesting::SetEntity(GenusEntity& genusEntity, const Genus& genus)
{
    genusEntity.SetCategory(genus.GetCategory());
    genusEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(genus.GetName()));
    genusEntity.SetFather(genus.GetFather());
    genusEntity.SetBegin(CoreTools::StringConversion::StandardConversionUtf8(genus.GetBegin()));
    genusEntity.SetEnd(CoreTools::StringConversion::StandardConversionUtf8(genus.GetEnd()));
}

void DatabaseGenerateBaseTesting::GenusEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Genus& genus)
{
    const auto database = databaseFlush.SelectOne(GenusEntity::GetSelect(databaseFlush.GetWrappersStrategy(), genus.GetId()),
                                                  GenusEntity::GetDatabaseFieldContainer());

    auto genusEntity = GenusEntity::Create(database, databaseFlush.GetWrappersStrategy(), genus.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, genusEntity, genus);

    databaseFlush.ChangeDatabase(genus.GetId(), genusEntity.GetModify());
}

void DatabaseGenerateBaseTesting::GenusEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Genus& genus, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(genus.GetId());
    auto genusEntity = result != entityContainer.cend() ? result->second : GenusEntity{ databaseFlush.GetWrappersStrategy(), genus.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, genusEntity, genus);

    databaseFlush.ChangeDatabase(genus.GetId(), genusEntity.GetModify());
}

void DatabaseGenerateBaseTesting::GenusEntityTesting::EqualTest(const Genus& genus, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(genus.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(genus.GetId()));

    const auto& genusEntity = result->second;

    ASSERT_EQUAL(genusEntity.GetCategory(), genus.GetCategory());
    ASSERT_EQUAL(genusEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(genus.GetName()));
    ASSERT_EQUAL(genusEntity.GetFather(), genus.GetFather());
    ASSERT_EQUAL(genusEntity.GetBegin(), CoreTools::StringConversion::StandardConversionUtf8(genus.GetBegin()));
    ASSERT_EQUAL(genusEntity.GetEnd(), CoreTools::StringConversion::StandardConversionUtf8(genus.GetEnd()));
}
