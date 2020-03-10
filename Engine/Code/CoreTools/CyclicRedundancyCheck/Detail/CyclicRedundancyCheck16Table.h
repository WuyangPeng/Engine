// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:47)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_TABLE_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_TABLE_H

#include "CoreTools/CoreToolsDll.h"

#include <array>

namespace CoreTools
{
	//  0x0000, 0xCC01, 0xD801, 0x1400,
	//  0xF001, 0x3C00, 0x2800, 0xE401,
	//  0xA001, 0x6C00, 0x7800, 0xB401,
	//  0x5000, 0x9C01, 0x8801, 0x4400
	class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheck16Table
	{
	public:
		using ClassType = CyclicRedundancyCheck16Table;

	public:
		CyclicRedundancyCheck16Table();

		CLASS_INVARIANT_DECLARE;

		uint16_t Get16Table(int index) const;

	private:
		static constexpr uint32_t sm_TableSize{ 16 };

	private:
		std::array<uint16_t, sm_TableSize> m_Table;
	};
}

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_TABLE_H
