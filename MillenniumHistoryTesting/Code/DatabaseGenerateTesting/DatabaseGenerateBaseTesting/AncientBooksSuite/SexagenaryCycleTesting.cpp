/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:37)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/SexagenaryCycle.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/SexagenaryCycleContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "SexagenaryCycleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::SexagenaryCycleTesting::SexagenaryCycleTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      sexagenaryCycleContainer{ ancientBooksContainer.GetSexagenaryCycleContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, SexagenaryCycleTesting)

void DatabaseGenerateBaseTesting::SexagenaryCycleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::SexagenaryCycleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::SexagenaryCycleTesting::EffectiveTest()
{
    for (const auto& sexagenaryCycle : sexagenaryCycleContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(HeavenlyTest, *sexagenaryCycle);
        ASSERT_NOT_THROW_EXCEPTION_1(BranchTest, *sexagenaryCycle);
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *sexagenaryCycle);
    }
}

void DatabaseGenerateBaseTesting::SexagenaryCycleTesting::HeavenlyTest(const SexagenaryCycle& sexagenaryCycle)
{
    ASSERT_FALSE(sexagenaryCycle.GetHeavenly().empty());
}

void DatabaseGenerateBaseTesting::SexagenaryCycleTesting::BranchTest(const SexagenaryCycle& sexagenaryCycle)
{
    ASSERT_FALSE(sexagenaryCycle.GetBranch().empty());
}

void DatabaseGenerateBaseTesting::SexagenaryCycleTesting::NameTest(const SexagenaryCycle& sexagenaryCycle)
{
    ASSERT_FALSE(sexagenaryCycle.GetName().empty());
    ASSERT_EQUAL(sexagenaryCycle.GetName(), sexagenaryCycle.GetHeavenly() + sexagenaryCycle.GetBranch());
}
