// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:26)

#ifndef CORE_TOOLS_BIT_ARRAY_CONST_ARRAY_PROXY_H
#define CORE_TOOLS_BIT_ARRAY_CONST_ARRAY_PROXY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "BitArrayManagerFwd.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ConstArrayProxy
	{
	public:
		using ClassType = ConstArrayProxy;

	public:
		ConstArrayProxy(const BitArray2D& bitArray2D, int position) noexcept;
		~ConstArrayProxy() = default;

		ConstBitProxy operator[](int position) const noexcept;

		ConstArrayProxy(const ConstArrayProxy& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

		ConstArrayProxy& operator=(const ConstArrayProxy& rhs) = delete;

		ConstArrayProxy& operator=(ConstArrayProxy&& rhs) noexcept = default;
		ConstArrayProxy(ConstArrayProxy&& bitProxy) noexcept = default;

	private:
		const BitArray2D& m_Array;
		int m_Position;
	};
}

#endif // CORE_TOOLS_BIT_ARRAY_CONST_ARRAY_PROXY_H
