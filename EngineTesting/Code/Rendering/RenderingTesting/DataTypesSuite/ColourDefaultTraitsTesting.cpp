///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:57)

#include "ColourDefaultTraitsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/DataTypes/ColourDefaultTraits.h"

Rendering::ColourDefaultTraitsTesting::ColourDefaultTraitsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ColourDefaultTraitsTesting)

void Rendering::ColourDefaultTraitsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ColourDefaultTraitsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TraitsTest);
}

void Rendering::ColourDefaultTraitsTesting::TraitsTest()
{
    ASSERT_EQUAL(ColourDefaultTraits<uint8_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<uint8_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<uint16_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<uint16_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<uint32_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<uint32_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<uint64_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<uint64_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<int16_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<int16_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<int>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<int>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<int64_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<int64_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<float>::maxValue, 1);
    ASSERT_EQUAL(ColourDefaultTraits<float>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<double>::maxValue, 1);
    ASSERT_EQUAL(ColourDefaultTraits<double>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<long double>::maxValue, 1);
    ASSERT_EQUAL(ColourDefaultTraits<long double>::minValue, 0);

#if 0

    // ���´��벻Ӧ��ͨ������
    ASSERT_EQUAL(ColourDefaultTraits<int8_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<int8_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<char>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<char>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<signed char>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<signed char>::minValue, 0);

#endif  // 0
}
