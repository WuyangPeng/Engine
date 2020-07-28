// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:49)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_CCITT_USING_TABLE_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_CCITT_USING_TABLE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheckCCITTUsingTable
	{
	public:
		using ClassType = CyclicRedundancyCheckCCITTUsingTable;

	public:
		CyclicRedundancyCheckCCITTUsingTable(const char* data, int length);

		CLASS_INVARIANT_DECLARE;

		uint16_t GetCyclicRedundancyCheck() const noexcept;

	private:
		void Calculation(const char* data, int length);
		uint16_t GetCCITT(uint16_t cyclicRedundancyCheck, uint16_t value);

	private:
		uint16_t m_CyclicRedundancyCheck;
	};
}

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_CCITT_USING_TABLE_H
