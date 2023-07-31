///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 23:13)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Version.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/VersionContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/VersionEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "VersionEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::VersionEntityTesting::VersionEntityTesting(const OStreamShared& stream, const VersionContainer& versionContainer)
    : ParentType{ stream }, versionContainer{ versionContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, VersionEntityTesting)

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& version : versionContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *version);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(VersionEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  VersionEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, VersionEntity>(database);

    for (const auto& version : versionContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *version, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(VersionEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  VersionEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), versionContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, VersionEntity>(database);

    for (const auto& version : versionContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *version, entityContainer);
    }
}

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::SetEntity(VersionEntity& versionEntity, const Version& version)
{
    versionEntity.SetBook(version.GetBook());
    versionEntity.SetSource(version.GetSource());
    versionEntity.SetSourceName(CoreTools::StringConversion::StandardConversionUtf8(version.GetSourceName()));
    versionEntity.SetCountry(version.GetCountry());
    versionEntity.SetReignTitle(version.GetReignTitle());
    versionEntity.SetYear(version.GetYear());
    versionEntity.SetVersion(CoreTools::StringConversion::StandardConversionUtf8(version.GetVersion()));
    versionEntity.SetOtherAuthor(version.GetOtherAuthor());
    versionEntity.SetAuthorNotes(Convert(version.GetAuthorNotesBegin(), version.GetAuthorNotesEnd()));
}

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Version& version)
{
    const auto database = databaseFlush.SelectOne(VersionEntity::GetSelect(databaseFlush.GetWrappersStrategy(), version.GetId()),
                                                  VersionEntity::GetDatabaseFieldContainer());

    auto versionEntity = VersionEntity::Create(database, databaseFlush.GetWrappersStrategy(), version.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, versionEntity, version);

    databaseFlush.ChangeDatabase(version.GetId(), versionEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Version& version, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(version.GetId());
    auto versionEntity = result != entityContainer.cend() ? result->second : VersionEntity{ databaseFlush.GetWrappersStrategy(), version.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, versionEntity, version);

    databaseFlush.ChangeDatabase(version.GetId(), versionEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::EqualTest(const Version& version, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(version.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(version.GetId()));

    const auto& versionEntity = result->second;

    ASSERT_EQUAL(versionEntity.GetBook(), version.GetBook());
    ASSERT_EQUAL(versionEntity.GetSource(), version.GetSource());
    ASSERT_EQUAL(versionEntity.GetSourceName(), CoreTools::StringConversion::StandardConversionUtf8(version.GetSourceName()));
    ASSERT_EQUAL(versionEntity.GetCountry(), version.GetCountry());
    ASSERT_EQUAL(versionEntity.GetReignTitle(), version.GetReignTitle());
    ASSERT_EQUAL(versionEntity.GetYear(), version.GetYear());
    ASSERT_EQUAL(versionEntity.GetVersion(), CoreTools::StringConversion::StandardConversionUtf8(version.GetVersion()));
    ASSERT_EQUAL(versionEntity.GetOtherAuthor(), version.GetOtherAuthor());
    ASSERT_EQUAL(versionEntity.GetAuthorNotes(), Convert(version.GetAuthorNotesBegin(), version.GetAuthorNotesEnd()));
}
