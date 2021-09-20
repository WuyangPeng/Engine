///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/16 21:02)

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
