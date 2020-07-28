// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:49)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_32_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_32_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheck32
	{
	public:
		using ClassType = CyclicRedundancyCheck32;

	public:
		CyclicRedundancyCheck32(const char* data, int length);

		CLASS_INVARIANT_DECLARE;

		uint32_t GetCyclicRedundancyCheck32() const noexcept;

	private:
		void Calculation(const char* data, int length);

	private:
		uint32_t m_CyclicRedundancyCheck;
	};
}

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_32_H
