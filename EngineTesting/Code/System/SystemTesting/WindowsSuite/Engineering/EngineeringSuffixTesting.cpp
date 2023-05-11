///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 17:55)

#include "EngineeringSuffixTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EngineeringSuffixTesting::EngineeringSuffixTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EngineeringSuffixTesting)

void System::EngineeringSuffixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EngineeringSuffixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SuffixTest);
}

void System::EngineeringSuffixTesting::SuffixTest()
{
    MAYBE_UNUSED const auto suffix = GetEngineeringSuffix();
    MAYBE_UNUSED const auto typesSuffix = GetEngineeringTypesSuffix();
    MAYBE_UNUSED const auto exeSuffix = GetEngineeringExeSuffix();
    MAYBE_UNUSED const auto directory = GetEngineeringDirectory();
}