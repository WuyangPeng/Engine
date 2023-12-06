/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:52)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Day.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/DayContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DayEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "DayConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::DayConvertTesting::DayConvertTesting(const OStreamShared& stream, const DayContainer& dayContainer)
    : ParentType{ stream }, dayContainer{ dayContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, DayConvertTesting)

void DatabaseGenerateCoreTesting::DayConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& day : dayContainer.GetContainer())
    {
        const auto dayEntity = convertEntity.Convert(*day);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *day, dayEntity);
    }
}

void DatabaseGenerateCoreTesting::DayConvertTesting::EqualTest(const Day& day, const DayEntity& dayEntity)
{
    ASSERT_EQUAL(dayEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(day.GetName()));
}
