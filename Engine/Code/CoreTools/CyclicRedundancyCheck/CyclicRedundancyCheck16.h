// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:48)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheck16
	{
	public:
		using ClassType = CyclicRedundancyCheck16;

	public:
		CyclicRedundancyCheck16(const char* data, int length);

		CLASS_INVARIANT_DECLARE;

		uint16_t GetCyclicRedundancyCheck16() const;

	private:
		void Calculation(const char* data, int length);

	private:
		uint16_t m_CyclicRedundancyCheck;
	};
}

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_H
