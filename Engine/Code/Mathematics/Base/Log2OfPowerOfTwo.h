// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 19:29)

#ifndef MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H
#define MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H

#include <array>
#include <type_traits> 

namespace Mathematics
{
	template <typename T>
	class Log2OfPowerOfTwo
	{
	public:
		static_assert(std::is_integral<T>::value, "T must be integral.");

		using ClassType = Log2OfPowerOfTwo;

	public:
		explicit Log2OfPowerOfTwo(T powerOfTwo) noexcept;

	#ifdef OPEN_CLASS_INVARIANT
		CLASS_INVARIANT_DECLARE;
		bool IsPowerOfTwoValid() const noexcept;
		bool IsLog2Valid() const noexcept;
		bool IsConvertValid() const noexcept;
		uint32_t GetPowerOfTwoLow() const noexcept;
	#endif // OPEN_CLASS_INVARIANT

		T GetLog2() const;

	private:
		void Convert() noexcept;
		void DetermineWhetherBitExist(int maskIndex) noexcept;
		void PowerOfTwoWithMask(int maskIndex) noexcept;

	private:		
		// 1111 1111 1111 1111 0000 0000 0000 0000
		// 1111 1111 0000 0000 1111 1111 0000 0000 
		// 1111 0000 1111 0000 1111 0000 1111 0000
		// 1100 1100 1100 1100 1100 1100 1100 1100 
		// 1010 1010 1010 1010 1010 1010 1010 1010
		static constexpr auto sm_MaskSize = 5;
		static constexpr std::array<uint32_t, sm_MaskSize> sm_Mask{ 0xFFFF0000,0xFF00FF00,0xF0F0F0F0,0xCCCCCCCC,0xAAAAAAAA };

		T m_PowerOfTwo;
		T m_PowerOfTwoCopy;
		uint32_t m_Log2;
	};
}

#endif // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H
