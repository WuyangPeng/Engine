///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/16 21:02)

#include "MoreEffectiveCppTerminologyTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/MoreEffectiveCpp/Helper/MoreEffectiveCppClassInvariantMacro.h"
#include "Example/BookCpp/MoreEffectiveCpp/Preface/Terminology.h"

BookExperience::MoreEffectiveCpp::MoreEffectiveCppTerminologyTesting::MoreEffectiveCppTerminologyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    MORE_EFFECTIVE_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::MoreEffectiveCpp, MoreEffectiveCppTerminologyTesting)

void BookExperience::MoreEffectiveCpp::MoreEffectiveCppTerminologyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::MoreEffectiveCpp::MoreEffectiveCppTerminologyTesting::MainTest()
{
    const Terminology terminology{};

    terminology.Main();    
}
