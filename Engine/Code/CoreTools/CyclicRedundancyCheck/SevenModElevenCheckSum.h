// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:49)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SEVEN_MOD_ELEVEN_CHECK_SUM_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SEVEN_MOD_ELEVEN_CHECK_SUM_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE SevenModElevenCheckSum
	{
	public:
		using ClassType = SevenModElevenCheckSum;

	public:
		SevenModElevenCheckSum(const char* data, int length);

		CLASS_INVARIANT_DECLARE;

		int GetCheckSum() const;

	private:
		void Calculation(const char* data, int length);

	private:
		static constexpr auto sm_PowersSize = 10;
		static const int sm_Powers[sm_PowersSize];

	private:
		int m_CheckSum;
	};
}

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SEVEN_MOD_ELEVEN_CHECK_SUM_H
