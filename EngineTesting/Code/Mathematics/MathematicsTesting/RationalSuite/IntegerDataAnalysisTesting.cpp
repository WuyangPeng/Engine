///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:32)

#include "IntegerDataAnalysisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataAnalysisDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"

namespace Mathematics
{
    template class IntegerData<2>;
    template class IntegerData<3>;
    template class IntegerData<29>;
    template class IntegerData<12>;

    template class IntegerDataAnalysis<2>;
    template class IntegerDataAnalysis<3>;
    template class IntegerDataAnalysis<29>;
    template class IntegerDataAnalysis<12>;
}

Mathematics::IntegerDataAnalysisTesting::IntegerDataAnalysisTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IntegerDataAnalysisTesting)

void Mathematics::IntegerDataAnalysisTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IntegerDataAnalysisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ToUnsignedIntTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetLeadingBitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetTrailingBitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DivisionModuloTest);
}

void Mathematics::IntegerDataAnalysisTesting::ToUnsignedIntTest()
{
    std::vector<uint16_t> data{ 0b11111111'11111111,
                                0b10111111'11111111,
                                0b10000000'11111111,
                                0b10000000'00000001,
                                0b10000000'00000000,
                                0b01111111'11111111,
                                0b01011111'11111111,
                                0b01000000'11111111,
                                0b01000000'00000001,
                                0b00100001'00011001,
                                0b00010001'00011001,
                                0b00001001'00011001,
                                0b00000101'00011001,
                                0b00000011'00011001,
                                0b00000001'00011001,
                                0b00000000'10011001,
                                0b00000000'01011001,
                                0b00000000'00111001,
                                0b00000000'00011001,
                                0b00000000'00001001,
                                0b00000000'00000101,
                                0b00000000'00000011,
                                0b00000000'00000010,
                                0b00000000'00000001 };

    const IntegerData<12> firstIntegerData(data);
    const IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

    for (auto i = 0u; i < data.size(); ++i)
    {
        ASSERT_EQUAL(data.at(i), firstIntegerDataAnalysis.ToUnsignedInt(i));
        ASSERT_EQUAL(static_cast<int>(data.at(i)), firstIntegerDataAnalysis.ToInt(i));

        const auto lower = firstIntegerDataAnalysis.ToUnsignedInt(i);
        const auto high = firstIntegerDataAnalysis.ToUnsignedInt(i);

        const auto value = (lower | (high << 16));
        const uint32_t resultValue = data.at(i) | (data.at(i) << 16);

        ASSERT_EQUAL(resultValue, value);
    }
}

void Mathematics::IntegerDataAnalysisTesting::GetLeadingBitTest()
{
    std::vector<uint16_t> data{ 0b11111111'11111111,
                                0b10111111'11111111,
                                0b10000000'11111111,
                                0b10000000'00000001,
                                0b10000000'00000000,
                                0b01111111'11111111,
                                0b01011111'11111111,
                                0b01000000'11111111,
                                0b01000000'00000001,
                                0b00100001'00011001,
                                0b00010001'00011001,
                                0b00001001'00011001,
                                0b00000101'00011001,
                                0b00000011'00011001,
                                0b00000001'00011001,
                                0b00000000'10011001,
                                0b00000000'01011001,
                                0b00000000'00111001,
                                0b00000000'00011001,
                                0b00000000'00001001,
                                0b00000000'00000101,
                                0b00000000'00000011,
                                0b00000000'00000010,
                                0b00000000'00000001 };

    std::vector<uint16_t> result{ 15,
                                  15,
                                  15,
                                  15,
                                  15,
                                  14,
                                  14,
                                  14,
                                  14,
                                  13,
                                  12,
                                  11,
                                  10,
                                  9,
                                  8,
                                  7,
                                  6,
                                  5,
                                  4,
                                  3,
                                  2,
                                  1,
                                  1,
                                  0 };

    const IntegerData<12> firstIntegerData(data);
    const IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

    auto dataBufferSize = boost::numeric_cast<int>(data.size());

    for (auto i = 0; i < dataBufferSize; ++i)
    {
        ASSERT_EQUAL(firstIntegerDataAnalysis.GetLeadingBit(i), result.at(i));
    }

    ASSERT_EQUAL(firstIntegerDataAnalysis.GetLeadingBlock(), dataBufferSize - 1);
    ASSERT_EQUAL(firstIntegerDataAnalysis.GetLeadingBit(), dataBufferSize * 16 - 1 - 15);
}

void Mathematics::IntegerDataAnalysisTesting::GetTrailingBitTest()
{
    std::vector<uint16_t> data{ 0b11111111'11111111,
                                0b10111111'11111111,
                                0b10000000'11111111,
                                0b10000000'00000001,
                                0b10000111'00000001,
                                0b01111111'11111110,
                                0b01011111'11111110,
                                0b01000000'11111110,
                                0b01000000'00000010,
                                0b00100001'00011100,
                                0b00010001'00011000,
                                0b00001001'00010000,
                                0b00000101'00100000,
                                0b00000011'01000000,
                                0b00000001'10000000,
                                0b00000001'00000000,
                                0b01011010'00000000,
                                0b01011100'00000000,
                                0b00011000'00000000,
                                0b00010000'00000000,
                                0b00110000'00000000,
                                0b01100000'00000000,
                                0b01000000'00000000,
                                0b10000000'00000000 };

    std::vector<uint16_t> result{ 0,
                                  0,
                                  0,
                                  0,
                                  0,
                                  1,
                                  1,
                                  1,
                                  1,
                                  2,
                                  3,
                                  4,
                                  5,
                                  6,
                                  7,
                                  8,
                                  9,
                                  10,
                                  11,
                                  12,
                                  12,
                                  13,
                                  14,
                                  15 };

    const IntegerData<12> firstIntegerData(data);
    const IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

    auto dataBufferSize = boost::numeric_cast<int>(data.size());

    for (auto i = 0; i < dataBufferSize; ++i)
    {
        ASSERT_EQUAL(firstIntegerDataAnalysis.GetTrailingBit(i), result.at(i));
    }

    ASSERT_EQUAL(firstIntegerDataAnalysis.GetTrailingBlock(), 0);
    ASSERT_EQUAL(firstIntegerDataAnalysis.GetTrailingBit(), 0);
}

void Mathematics::IntegerDataAnalysisTesting::OperatorTest()
{
    std::vector<uint16_t> data{ 0b11111111'11111111,
                                0b10111111'11111111,
                                0b10000000'11111111,
                                0b10000000'00000001,
                                0b10000000'00000000,
                                0b01111111'11111111,
                                0b01011111'11111111,
                                0b01000000'11111111,
                                0b01000000'00000001,
                                0b00100001'00011001,
                                0b00010001'00011001,
                                0b00001001'00011001,
                                0b00000101'00011001,
                                0b00000011'00011001,
                                0b00000001'00011001,
                                0b00000000'10011001,
                                0b00000000'01011001,
                                0b00000000'00111001,
                                0b00000000'00011001,
                                0b00000000'00001001,
                                0b00000000'00000101,
                                0b00000000'00000011,
                                0b00000000'00000010,
                                0b00000000'00000001 };

    const IntegerData<12> firstIntegerData(data);
    const IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

    const IntegerData<12> secondIntegerData = firstIntegerDataAnalysis.GetAbsoluteValue();
    ASSERT_EQUAL(firstIntegerData, secondIntegerData);

    const IntegerData<12> thirdIntegerData = -firstIntegerDataAnalysis;
    ASSERT_FALSE(firstIntegerData == thirdIntegerData);

    const IntegerDataAnalysis<12> secondIntegerDataAnalysis(thirdIntegerData);
    const IntegerData<12> fourthIntegerData = -secondIntegerDataAnalysis;
    ASSERT_EQUAL(fourthIntegerData, firstIntegerData);
}

void Mathematics::IntegerDataAnalysisTesting::DivisionModuloTest()
{
    std::vector<uint16_t> data{ 0b11111111'11111111,
                                0b10111111'11111111,
                                0b10000000'11111111,
                                0b10000000'00000001,
                                0b10000000'00000000,
                                0b01111111'11111111,
                                0b01011111'11111111,
                                0b01000000'11111111,
                                0b01000000'00000001,
                                0b00100001'00011001,
                                0b00010001'00011001,
                                0b00001001'00011001,
                                0b00000101'00011001,
                                0b00000011'00011001,
                                0b00000001'00011001,
                                0b00000000'10011001,
                                0b00000000'01011001,
                                0b00000000'00111001,
                                0b00000000'00011001,
                                0b00000000'00001001,
                                0b00000000'00000101,
                                0b00000000'00000011,
                                0b00000000'00000010,
                                0b00000000'00000001 };

    const IntegerData<12> firstIntegerData(data);
    const IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

    const IntegerData<12> secondIntegerData(0x1FFF2FFF2FFFFFFFULL);

    const IntegerDivisionModulo<12> divisionModule = firstIntegerDataAnalysis.GetDivisionModulo(secondIntegerData);

    const IntegerData<12> thirdIntegerData = divisionModule.GetQuotient();
    const IntegerData<12> fourthIntegerData = divisionModule.GetRemainder();

    const IntegerMultiplication<12> multiplication(thirdIntegerData, secondIntegerData);

    const IntegerData<12> fifthIntegerData = multiplication.GetMultiplication() + fourthIntegerData;

    ASSERT_EQUAL(fifthIntegerData, firstIntegerData);
}
