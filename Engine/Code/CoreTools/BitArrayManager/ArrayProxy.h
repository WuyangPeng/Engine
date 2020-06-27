// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:22)

#ifndef CORE_TOOLS_BIT_ARRAY_ARRAY_PROXY_H
#define CORE_TOOLS_BIT_ARRAY_ARRAY_PROXY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CoreTools
{
	class BitArray2D;

	class CORE_TOOLS_DEFAULT_DECLARE ArrayProxy
	{
	public:
		using ClassType = ArrayProxy;

	public:
		ArrayProxy(BitArray2D& arrayProxy, int position) noexcept;

		BitProxy operator[](int position);

		ArrayProxy(const ArrayProxy& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

		ArrayProxy& operator=(const ArrayProxy& rhs) = delete;

		ArrayProxy(ArrayProxy&& rhs) noexcept = delete;
		ArrayProxy& operator=(ArrayProxy&& rhs) noexcept = delete;

	private:
		BitArray2D& m_Array;
		int m_Position;
	};
}

#endif // CORE_TOOLS_BIT_ARRAY_ARRAY_PROXY_H
