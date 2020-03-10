// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/21 13:36)

#include "CoreTools/CoreToolsExport.h"

#include "Random.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Random
	::Random()
	:m_State{ 0 }, m_FirstIndex{ 0 }, m_SecondIndex{ 103 }, m_Table{}
{
	GenerateSeeds();

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::Random
	::GenerateSeeds()
{
	for (auto n = sm_TableSize - 1; 0 <= n; --n)
	{
		m_Table[n] = GenerateSimple();
	}

	uint32_t msk{ 0xffffffff };
	uint32_t bit{ 0x80000000 };
	for (auto n = 3; n < sm_TableSize - 1; n += 7)
	{
		if (bit == 0)
		{
			break;
		}

		m_Table[n] = (m_Table[n] & msk) | bit;
		msk >>= 1;
		bit >>= 1;
	}
}

// private
uint32_t CoreTools::Random
	::GenerateSimple()
{
	uint32_t temp = m_State;
	for (auto n = 0u; n < 32; ++n)
	{
		uint32_t bit{ ((temp >> 0) ^ (temp >> 1) ^ (temp >> 2) ^ (temp >> 3) ^ (temp >> 5) ^ (temp >> 7)) & 1 };

		temp = (((temp >> 1) | (temp << 31)) & ~1) | bit;
	}

	m_State = temp;

	return m_State;
}

CoreTools::Random
	::Random(uint32_t seed)
	:m_State{ seed }, m_FirstIndex{ 0 }, m_SecondIndex{ 103 }, m_Table{}
{
	GenerateSeeds();

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Random)

uint32_t CoreTools::Random
	::Generate()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Table[m_FirstIndex] ^= m_Table[m_SecondIndex];
	auto value = m_Table[m_FirstIndex];

	++m_FirstIndex;
	if (m_FirstIndex == sm_TableSize)
	{
		m_FirstIndex = 0;
	}

	++m_SecondIndex;
	if (m_SecondIndex == sm_TableSize)
	{
		m_SecondIndex = 0;
	}

	return value;
}

int CoreTools::Random
	::GeneratePositive()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return Generate() & 0x7FFFFFFF;
}





