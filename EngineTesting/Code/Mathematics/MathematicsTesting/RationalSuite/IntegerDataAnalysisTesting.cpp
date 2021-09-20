// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 13:57)

#include "IntegerDataAnalysisTesting.h"
#include "Mathematics/Base/MathDetail.h" 
#include "Mathematics/Rational/IntegerDataDetail.h"
#include "Mathematics/Rational/IntegerDataAnalysisDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
 
#include <boost/utility/binary.hpp> 

using std::vector;

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

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntegerDataAnalysisTesting) 

void Mathematics::IntegerDataAnalysisTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ToUnsignedIntTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GetLeadingBitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GetTrailingBitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DivisionModuloTest);	
}

void Mathematics::IntegerDataAnalysisTesting
	::ToUnsignedIntTest()
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
	IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

	for (uint32_t i = 0; i < data.size(); ++i)
	{
		 ASSERT_EQUAL(data[i],firstIntegerDataAnalysis.ToUnsignedInt(i));
		 ASSERT_EQUAL(static_cast<int>(data[i]),firstIntegerDataAnalysis.ToInt(i));

		 uint32_t lower = firstIntegerDataAnalysis.ToUnsignedInt(i);
		 uint32_t high = firstIntegerDataAnalysis.ToUnsignedInt(i);

		 uint32_t value = (lower | (high << 16));
		 uint32_t resultValue = (data[i] | (data[i] << 16));

		 ASSERT_EQUAL(resultValue,value);
	}
}

void Mathematics::IntegerDataAnalysisTesting
	::GetLeadingBitTest() 
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

	vector<uint16_t> result{ uint16_t(15),
			  uint16_t(15),
			  uint16_t(15),
			  uint16_t(15),
			  uint16_t(15),
			  uint16_t(14),
			  uint16_t(14),
			  uint16_t(14),
			  uint16_t(14),
			  uint16_t(13),
			  uint16_t(12),
			  uint16_t(11),
			  uint16_t(10),
			  uint16_t(9),
			  uint16_t(8),
			  uint16_t(7),
			  uint16_t(6),
			  uint16_t(5),
			  uint16_t(4),
			  uint16_t(3),
			  uint16_t(2),
			  uint16_t(1),
			  uint16_t(1),
			  uint16_t(0) };

	IntegerData<12> firstIntegerData(data);
	IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

	int dataBufferSize = boost::numeric_cast<int>(data.size());

	for (int i = 0; i < dataBufferSize; ++i)
	{
		ASSERT_EQUAL(firstIntegerDataAnalysis.GetLeadingBit(i),  result[i]);
	}

	ASSERT_EQUAL(firstIntegerDataAnalysis.GetLeadingBlock(),dataBufferSize - 1);
	ASSERT_EQUAL(firstIntegerDataAnalysis.GetLeadingBit(),dataBufferSize * 16 - 1 - 15);
}


void Mathematics::IntegerDataAnalysisTesting
	::GetTrailingBitTest()
{
	vector<uint16_t> data{ uint16_t(BOOST_BINARY(11111111 11111111)),
			uint16_t(BOOST_BINARY(10111111 11111111)),
			uint16_t(BOOST_BINARY(10000000 11111111)),
			uint16_t(BOOST_BINARY(10000000 00000001)),
			uint16_t(BOOST_BINARY(10000111 00000001)),
			uint16_t(BOOST_BINARY(01111111 11111110)),
			uint16_t(BOOST_BINARY(01011111 11111110)),
			uint16_t(BOOST_BINARY(01000000 11111110)),
			uint16_t(BOOST_BINARY(01000000 00000010)),
			uint16_t(BOOST_BINARY(00100001 00011100)),
			uint16_t(BOOST_BINARY(00010001 00011000)),
			uint16_t(BOOST_BINARY(00001001 00010000)),
			uint16_t(BOOST_BINARY(00000101 00100000)),
			uint16_t(BOOST_BINARY(00000011 01000000)),
			uint16_t(BOOST_BINARY(00000001 10000000)),
			uint16_t(BOOST_BINARY(00000001 00000000)),
			uint16_t(BOOST_BINARY(01011010 00000000)),
			uint16_t(BOOST_BINARY(01011100 00000000)),
			uint16_t(BOOST_BINARY(00011000 00000000)),
			uint16_t(BOOST_BINARY(00010000 00000000)),
			uint16_t(BOOST_BINARY(00110000 00000000)),
			uint16_t(BOOST_BINARY(01100000 00000000)),
			uint16_t(BOOST_BINARY(01000000 00000000)),
			uint16_t(BOOST_BINARY(10000000 00000000)) };

	vector<uint16_t> result{ uint16_t(0),
			  uint16_t(0),
			  uint16_t(0),
			  uint16_t(0),
			  uint16_t(0),
			  uint16_t(1),
			  uint16_t(1),
			  uint16_t(1),
			  uint16_t(1),
			  uint16_t(2),
			  uint16_t(3),
			  uint16_t(4),
			  uint16_t(5),
			  uint16_t(6),
			  uint16_t(7),
			  uint16_t(8),
			  uint16_t(9),
			  uint16_t(10),
			  uint16_t(11),
			  uint16_t(12),
			  uint16_t(12),
			  uint16_t(13),
			  uint16_t(14),
			  uint16_t(15) };

	IntegerData<12> firstIntegerData(data);
	IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

	int dataBufferSize = boost::numeric_cast<int>(data.size());

	for (int i = 0; i < dataBufferSize; ++i)
	{
		ASSERT_EQUAL(firstIntegerDataAnalysis.GetTrailingBit(i), result[i]);
	}

	ASSERT_EQUAL(firstIntegerDataAnalysis.GetTrailingBlock(),0);
	ASSERT_EQUAL(firstIntegerDataAnalysis.GetTrailingBit(),0);
}

void Mathematics::IntegerDataAnalysisTesting
	::OperatorTest()
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
	IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

	IntegerData<12> secondIntegerData = firstIntegerDataAnalysis.GetAbsoluteValue();
	ASSERT_EQUAL(firstIntegerData,secondIntegerData);

	IntegerData<12> thirdIntegerData = -firstIntegerDataAnalysis;
	ASSERT_FALSE(firstIntegerData == thirdIntegerData);

	IntegerDataAnalysis<12> secondIntegerDataAnalysis(thirdIntegerData);
	IntegerData<12> fourthIntegerData = -secondIntegerDataAnalysis;
	ASSERT_EQUAL(fourthIntegerData,firstIntegerData);
}

void Mathematics::IntegerDataAnalysisTesting
	::DivisionModuloTest() 
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
	IntegerDataAnalysis<12> firstIntegerDataAnalysis(firstIntegerData);

	IntegerData<12> secondIntegerData(uint64_t((0x1FFF2FFF2FFFFFFFULL)));

	IntegerDivisionModulo<12> divisionModule =	firstIntegerDataAnalysis.GetDivisionModulo(secondIntegerData);

	IntegerData<12> thirdIntegerData = divisionModule.GetQuotient();
	IntegerData<12> fourthIntegerData = divisionModule.GetRemainder();

	IntegerMultiplication<12> multiplication(thirdIntegerData,secondIntegerData);

	IntegerData<12> fifthIntegerData = multiplication.GetMultiplication() + fourthIntegerData;

	ASSERT_EQUAL(fifthIntegerData,firstIntegerData);
}

