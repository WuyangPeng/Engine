/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:52)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ImperialCourt.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ImperialCourtContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/ImperialCourtEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "ImperialCourtConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::ImperialCourtConvertTesting::ImperialCourtConvertTesting(const OStreamShared& stream, const ImperialCourtContainer& imperialCourtContainer)
    : ParentType{ stream }, imperialCourtContainer{ imperialCourtContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, ImperialCourtConvertTesting)

void DatabaseGenerateCoreTesting::ImperialCourtConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& imperialCourt : imperialCourtContainer.GetContainer())
    {
        const auto imperialCourtEntity = convertEntity.Convert(*imperialCourt);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *imperialCourt, imperialCourtEntity);
    }
}

void DatabaseGenerateCoreTesting::ImperialCourtConvertTesting::EqualTest(const ImperialCourt& imperialCourt, const ImperialCourtEntity& imperialCourtEntity)
{
    ASSERT_EQUAL(imperialCourtEntity.GetCategory(), CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetCategory()));
    ASSERT_EQUAL(imperialCourtEntity.GetBook(), CoreTools::StringConversion::StandardConversionUtf8(imperialCourt.GetBook()));
    ASSERT_EQUAL(imperialCourtEntity.GetBegin(), imperialCourt.GetBegin());
    ASSERT_EQUAL(imperialCourtEntity.GetEnd(), imperialCourt.GetEnd());
}
