/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:52)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Month.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/MonthContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/MonthEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "MonthConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::MonthConvertTesting::MonthConvertTesting(const OStreamShared& stream, const MonthContainer& monthContainer)
    : ParentType{ stream }, monthContainer{ monthContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, MonthConvertTesting)

void DatabaseGenerateCoreTesting::MonthConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& month : monthContainer.GetContainer())
    {
        const auto monthEntity = convertEntity.Convert(*month);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *month, monthEntity);
    }
}

void DatabaseGenerateCoreTesting::MonthConvertTesting::EqualTest(const Month& month, const MonthEntity& monthEntity)
{
    ASSERT_EQUAL(monthEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(month.GetName()));
}
