// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:49)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SPECIFY_CHECK_SUM_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SPECIFY_CHECK_SUM_H

#include "CoreTools/CoreToolsDll.h"

#include "CyclicRedundancyCheckFwd.h"

#include <array>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE SpecifyCheckSum
	{
	public:
		using ClassType = SpecifyCheckSum;

	public:
		SpecifyCheckSum(const char* data, int length,SpecifyCheckSumPowers powers, int mod);

		CLASS_INVARIANT_DECLARE;

		int GetOriginalCheckSum() const;
		int GetCollisions() const;

	private:
		void Calculation(const char* data, int length);
		int GetCheckSum(const char* data, int length);

	private:
		static constexpr auto sm_PowersSize = 10;
		static const int sm_SevenPowers[sm_PowersSize];
		static const int sm_NinePowers[sm_PowersSize];

	private:
		int m_OriginalCheckSum;
		SpecifyCheckSumPowers m_Powers;
		int m_Mod; 
		int m_Collisions;
	};
}

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SPECIFY_CHECK_SUM_H
