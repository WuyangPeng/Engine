///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 21:20)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ImperialCourt.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ImperialCourtContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/ImperialCourtEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "ImperialCourtConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::ImperialCourtConvertTesting::ImperialCourtConvertTesting(const OStreamShared& stream, const ImperialCourtContainer& imperialCourtContainer)
    : ParentType{ stream }, imperialCourtContainer{ imperialCourtContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, ImperialCourtConvertTesting)

void DatabaseGenerateServerCoreTesting::ImperialCourtConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& imperialCourt : imperialCourtContainer.GetContainer())
    {
        const auto imperialCourtEntity = convertEntity.Convert(*imperialCourt);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *imperialCourt, imperialCourtEntity);
    }
}

void DatabaseGenerateServerCoreTesting::ImperialCourtConvertTesting::EqualTest(const ImperialCourt& imperialCourt, const ImperialCourtEntity& imperialCourtEntity)
{
    ASSERT_EQUAL(imperialCourtEntity.GetCategory(), CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetCategory()));
    ASSERT_EQUAL(imperialCourtEntity.GetBook(), CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetBook()));
    ASSERT_EQUAL(imperialCourtEntity.GetBegin(), imperialCourt.GetBegin());
    ASSERT_EQUAL(imperialCourtEntity.GetEnd(), imperialCourt.GetEnd());
}
