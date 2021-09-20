///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/16 21:02)

#include "EffectiveCppTerminologyTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveCpp/Helper/EffectiveCppClassInvariantMacro.h"
#include "Example/BookCpp/EffectiveCpp/Preface/Terminology.h"

BookExperience::EffectiveCpp::EffectiveCppTerminologyTesting::EffectiveCppTerminologyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveCpp, EffectiveCppTerminologyTesting)

void BookExperience::EffectiveCpp::EffectiveCppTerminologyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::EffectiveCpp::EffectiveCppTerminologyTesting::MainTest()
{
    const Terminology terminology{};

    terminology.Main();
    constexpr auto loop = 10;
    constexpr auto carry = 10;

    auto number = 1;
    for (auto i = 0u; i < loop; ++i)
    {
        ASSERT_EQUAL(terminology.NumDigits(number), i + 1);

        number *= carry;
    }
}
