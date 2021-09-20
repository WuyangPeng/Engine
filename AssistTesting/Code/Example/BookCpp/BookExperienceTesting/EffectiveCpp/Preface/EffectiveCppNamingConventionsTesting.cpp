///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/16 21:02)

#include "EffectiveCppNamingConventionsTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveCpp/Helper/EffectiveCppClassInvariantMacro.h"
#include "Example/BookCpp/EffectiveCpp/Preface/NamingConventions.h"

BookExperience::EffectiveCpp::EffectiveCppNamingConventionsTesting::EffectiveCppNamingConventionsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveCpp, EffectiveCppNamingConventionsTesting)

void BookExperience::EffectiveCpp::EffectiveCppNamingConventionsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::EffectiveCpp::EffectiveCppNamingConventionsTesting::MainTest() noexcept
{
    const NamingConventions namingConventions{};

    namingConventions.Main();
}
