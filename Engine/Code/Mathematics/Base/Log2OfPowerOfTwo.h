// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 19:29)

#ifndef MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H
#define MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H

#include <boost/type_traits/is_integral.hpp>
#include <boost/static_assert.hpp>

namespace Mathematics
{
	template <typename T>
	class Log2OfPowerOfTwo
	{
	public:
		BOOST_STATIC_ASSERT((boost::is_integral<T>::value));

		using ClassType = Log2OfPowerOfTwo;

	public:				
		explicit Log2OfPowerOfTwo(T powerOfTwo);			

#ifdef OPEN_CLASS_INVARIANT
		CLASS_INVARIANT_DECLARE;
		bool IsPowerOfTwoValid() const noexcept;
		bool IsLog2Valid() const noexcept;
		bool IsConvertValid() const noexcept;
		uint32_t GetPowerOfTwoLow() const noexcept;
#endif // OPEN_CLASS_INVARIANT

		T GetLog2() const;

	private:
		void Convert();
		void DetermineWhetherBitExist(int maskIndex);
		void PowerOfTwoWithMask(int maskIndex);

	private:
		static constexpr int sm_MaskSize{ 5 };
		static const uint32_t sm_Mask[sm_MaskSize];

		T m_PowerOfTwo;
		T m_PowerOfTwoCopy;
		uint32_t m_Log2;
	};	
}

#endif // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H
