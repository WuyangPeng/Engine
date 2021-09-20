// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 13:42)

#include "IntegerDataAmendTesting.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"
#include "Mathematics/Rational/IntegerDataAmendDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <boost/utility/binary.hpp>

using std::vector;

namespace Mathematics
{
	template class IntegerData<1>;
	template class IntegerData<2>;
	template class IntegerData<19>;
	template class IntegerData<22>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntegerDataAmendTesting) 

void Mathematics::IntegerDataAmendTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FromUnsignedIntTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NegativeTest);
}

void Mathematics::IntegerDataAmendTesting
	::FromUnsignedIntTest()
{
	vector<uint16_t> data{ uint16_t(BOOST_BINARY(11111111 11111111)),
						   uint16_t(BOOST_BINARY(10111111 11111111)),
						   uint16_t(BOOST_BINARY(10000000 11111111)),
						   uint16_t(BOOST_BINARY(10000000 00000001)),
						   uint16_t(BOOST_BINARY(10000000 00000000)),
						   uint16_t(BOOST_BINARY(01111111 11111111)),
						   uint16_t(BOOST_BINARY(01011111 11111111)),
						   uint16_t(BOOST_BINARY(01000000 11111111)),
						   uint16_t(BOOST_BINARY(01000000 00000001)),
						   uint16_t(BOOST_BINARY(00100001 00011001)),
						   uint16_t(BOOST_BINARY(00010001 00011001)),
						   uint16_t(BOOST_BINARY(00001001 00011001)),
						   uint16_t(BOOST_BINARY(00000101 00011001)),
						   uint16_t(BOOST_BINARY(00000011 00011001)),
						   uint16_t(BOOST_BINARY(00000001 00011001)),
						   uint16_t(BOOST_BINARY(00000000 10011001)),
						   uint16_t(BOOST_BINARY(00000000 01011001)),
						   uint16_t(BOOST_BINARY(00000000 00111001)),
						   uint16_t(BOOST_BINARY(00000000 00011001)),
						   uint16_t(BOOST_BINARY(00000000 00001001)),
						   uint16_t(BOOST_BINARY(00000000 00000101)),
						   uint16_t(BOOST_BINARY(00000000 00000011)),
						   uint16_t(BOOST_BINARY(00000000 00000010)),
						   uint16_t(BOOST_BINARY(00000000 00000001)) };
			
	IntegerData<12> firstIntegerData(data);
	IntegerDataAmend<12> firstIntegerDataAmend(firstIntegerData);

	firstIntegerDataAmend.FromUnsignedInt(0, uint16_t(BOOST_BINARY_U(00011110 00000001)));

	ASSERT_EQUAL(BOOST_BINARY_U(00011110 00000001),firstIntegerData[0]);
}

void Mathematics::IntegerDataAmendTesting
	::NegativeTest()
{
	IntegerData<4> firstIntegerData(int64_t((0xF000F458F7892523LL)));

	ASSERT_EQUAL(firstIntegerData[0],uint16_t(0x2523));
	ASSERT_EQUAL(firstIntegerData[1],uint16_t(0xF789));
	ASSERT_EQUAL(firstIntegerData[2],uint16_t(0xF458));
	ASSERT_EQUAL(firstIntegerData[3],uint16_t(0xF000));

	ASSERT_ENUM_EQUAL(firstIntegerData.GetSign(),NumericalValueSymbol::Negative);
	ASSERT_FALSE(firstIntegerData.IsZero());

	IntegerDataAmend<4> firstIntegerDataAmend(firstIntegerData);
	firstIntegerDataAmend.Negative();

	ASSERT_ENUM_EQUAL(firstIntegerData.GetSign(),NumericalValueSymbol::Positive);
	ASSERT_FALSE(firstIntegerData.IsZero());

	IntegerData<5> secondIntegerData(uint64_t(0));

	ASSERT_TRUE(secondIntegerData.IsZero());
	ASSERT_ENUM_EQUAL(secondIntegerData.GetSign(),NumericalValueSymbol::Positive);

	IntegerDataAmend<5> secondIntegerDataAmend(secondIntegerData);
	secondIntegerDataAmend.Negative();

	ASSERT_ENUM_EQUAL(secondIntegerData.GetSign(),NumericalValueSymbol::Positive);
	ASSERT_TRUE(secondIntegerData.IsZero());
}

