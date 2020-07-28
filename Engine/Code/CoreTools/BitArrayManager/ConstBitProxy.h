// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:26)

#ifndef CORE_TOOLS_BIT_ARRAY_CONST_BIT_PROXY_H
#define CORE_TOOLS_BIT_ARRAY_CONST_BIT_PROXY_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class BitArray;

	class CORE_TOOLS_DEFAULT_DECLARE ConstBitProxy
	{
	public:
		using ClassType = ConstBitProxy;

	public:
		ConstBitProxy(const BitArray& bitArray, int position) noexcept;
		~ConstBitProxy() = default;

		ConstBitProxy(const ConstBitProxy& bitProxy) noexcept;

		CLASS_INVARIANT_DECLARE;

		operator bool() const noexcept;

		ConstBitProxy& operator=(const ConstBitProxy& rhs) = delete;

		ConstBitProxy& operator=(ConstBitProxy&& rhs) noexcept = default;
		ConstBitProxy(ConstBitProxy&& bitProxy) noexcept = default;

	private:
		const BitArray& m_Array;
		int  m_Position;
	};
}

#endif // CORE_TOOLS_BIT_ARRAY_CONST_BIT_PROXY_H
