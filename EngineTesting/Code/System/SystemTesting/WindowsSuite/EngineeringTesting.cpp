///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 16:20)

#include "EngineeringTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

#define SYSTEM_TEST_TYPE_DISPLAYER
#undef SYSTEM_TEST_TYPE_DISPLAYER

System::EngineeringTesting::EngineeringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EngineeringTesting)

void System::EngineeringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EngineeringTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SuffixTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OffsetTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NumDigitsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDisplayerTest);
}

void System::EngineeringTesting::SuffixTest()
{
    MAYBE_UNUSED const auto suffix = GetEngineeringSuffix();
    MAYBE_UNUSED const auto typesSuffix = GetEngineeringTypesSuffix();
    MAYBE_UNUSED const auto exeSuffix = GetEngineeringExeSuffix();
    MAYBE_UNUSED const auto directory = GetEngineeringDirectory();
}

void System::EngineeringTesting::OffsetTest() noexcept
{
    MAYBE_UNUSED constexpr auto offset = GetEngineeringOffsetValue();
}

void System::EngineeringTesting::NumDigitsTest()
{
    ASSERT_EQUAL(NumDigits(1), 1);
    ASSERT_EQUAL(NumDigits(12), 2);
    ASSERT_EQUAL(NumDigits(123), 3);

    for (int i = 0; i < 9; ++i)
    {
        ASSERT_EQUAL(NumDigits(boost::numeric_cast<int>(Mathematics::MathD::Pow(10, i) + 1)), i + 1);
    }
}

void System::EngineeringTesting::TypeDisplayerTest() noexcept
{
#ifdef SYSTEM_TEST_TYPE_DISPLAYER

    TypeDisplayer<ClassType> typeDisplayer{};

#endif  // SYSTEM_TEST_TYPE_DISPLAYER
}
