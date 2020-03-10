// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.1 (2019/06/28 14:39)

#ifndef CORE_TOOLS_BIT_ARRAY_BIT_PROXY_H
#define CORE_TOOLS_BIT_ARRAY_BIT_PROXY_H

#include "CoreTools/CoreToolsDll.h"

#include "BitArrayManagerFwd.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BitProxy
	{
	public:
		using ClassType = BitProxy;

	public:
		BitProxy(BitArray& bitArray, int position);

		BitProxy& operator=(bool value);
		BitProxy& operator=(const BitProxy& rhs);

		BitProxy(const BitProxy& bitProxy);

		CLASS_INVARIANT_DECLARE;

		operator bool() const noexcept;

		void Flip() noexcept;

	private:
		BitArray& m_Array;
		int m_Position;
	};
}

#endif // CORE_TOOLS_BIT_ARRAY_BIT_PROXY_H
