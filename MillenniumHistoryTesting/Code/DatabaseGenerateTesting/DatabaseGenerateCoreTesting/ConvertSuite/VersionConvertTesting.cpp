/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:18)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Version.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/VersionContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/VersionEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "VersionConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::VersionConvertTesting::VersionConvertTesting(const OStreamShared& stream, VersionContainer versionContainer)
    : ParentType{ stream }, versionContainer{ std::move(versionContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, VersionConvertTesting)

void DatabaseGenerateCoreTesting::VersionConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& version : versionContainer.GetContainer())
    {
        const auto versionEntity = convertEntity.Convert(*version);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *version, versionEntity);
    }
}

void DatabaseGenerateCoreTesting::VersionConvertTesting::EqualTest(const Version& version, const VersionEntity& versionEntity)
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
