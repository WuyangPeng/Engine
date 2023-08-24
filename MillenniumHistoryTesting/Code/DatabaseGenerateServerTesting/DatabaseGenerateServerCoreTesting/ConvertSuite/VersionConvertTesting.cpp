///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 21:16)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Version.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/VersionContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/VersionEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "VersionConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::VersionConvertTesting::VersionConvertTesting(const OStreamShared& stream, const VersionContainer& versionContainer)
    : ParentType{ stream }, versionContainer{ versionContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, VersionConvertTesting)

void DatabaseGenerateServerCoreTesting::VersionConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& version : versionContainer.GetContainer())
    {
        const auto versionEntity = convertEntity.Convert(*version);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *version, versionEntity);
    }
}

void DatabaseGenerateServerCoreTesting::VersionConvertTesting::EqualTest(const Version& version, const VersionEntity& versionEntity)
{
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
