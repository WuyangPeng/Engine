// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:26)

#ifndef CORE_TOOLS_BIT_ARRAY_TWO_BIT_PROXY_H
#define CORE_TOOLS_BIT_ARRAY_TWO_BIT_PROXY_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class TwoBitArray;

	class CORE_TOOLS_DEFAULT_DECLARE TwoBitProxy
	{
	public:
		using ClassType = TwoBitProxy;

	public:
		TwoBitProxy(TwoBitArray& array, int position) noexcept;
		~TwoBitProxy() noexcept = default;

		TwoBitProxy& operator=(const TwoBitProxy& rhs) noexcept;
		TwoBitProxy& operator=(uint32_t value) noexcept;

		TwoBitProxy(const TwoBitProxy& rhs) = delete;

		TwoBitProxy& operator=(TwoBitProxy&& rhs) noexcept = default;
		TwoBitProxy(TwoBitProxy&& rhs) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

		operator uint32_t() const noexcept;

	private:
		TwoBitArray& m_Array;
		int m_Position;
	};
}

#endif // CORE_TOOLS_BIT_ARRAY_TWO_BIT_PROXY_H
