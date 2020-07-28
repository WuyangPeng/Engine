// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:25)

#ifndef CORE_TOOLS_BIT_ARRAY_BIT_ARRAY_2D_H
#define CORE_TOOLS_BIT_ARRAY_BIT_ARRAY_2D_H

#include "CoreTools/CoreToolsDll.h"

#include "BitArray.h"
#include "ArrayProxy.h"
#include "ConstArrayProxy.h"

#include "System/Helper/PragmaWarning/Operators.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BitArray2D : private boost::equality_comparable<BitArray2D, boost::bitwise<BitArray2D>>
	{
	public:
		using ClassType = BitArray2D;

	public:
		BitArray2D(int firstDimensionality, int secondDimensionality);

		CLASS_INVARIANT_DECLARE;

		ArrayProxy operator[](int position) noexcept;
		ConstArrayProxy operator[](int position) const noexcept;

		bool operator==(const BitArray2D& rhs) const noexcept;

		BitArray2D& operator&=(const BitArray2D& rhs) noexcept;
		BitArray2D& operator|=(const BitArray2D& rhs) noexcept;
		BitArray2D& operator^=(const BitArray2D& rhs) noexcept;

		const BitArray2D operator~() const;

		void Clear() noexcept;

		void SetBit(int firstPosition, int secondPosition) noexcept;

		void ClearBit(int firstPosition, int secondPosition) noexcept;

		void FlipBit(int firstPosition, int secondPosition) noexcept;

		void Set(int firstPosition, int secondPosition, bool value) noexcept;

		bool IsBitSet(int firstPosition, int secondPosition) const noexcept;

		bool AllBitsFalse() const noexcept;

		void FlipAllBits() noexcept;

		int GetWidth() const noexcept;

		const BitArray& GetBitArray() const noexcept;
		BitArray& GetBitArray() noexcept;

	private:
		BitArray m_BitArray;
		int m_Width;
	};
}

#endif // CORE_TOOLS_BIT_ARRAY_BIT_ARRAY_2D_H
