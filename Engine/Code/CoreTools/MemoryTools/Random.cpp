//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/20 10:22)

#include "CoreTools/CoreToolsExport.h"

#include "Random.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Random::Random() noexcept
    : m_State{ 0 }, m_Index0{ 0 }, m_Index1{ 103 }, m_Table{}
{
    GenerateSeeds();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::Random::GenerateSeeds() noexcept
{
    for (auto n = sm_TableSize - 1; 0 <= n; --n)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        m_Table[n] = GenerateSimple();
#include STSTEM_WARNING_POP
    }

    uint32_t msk{ 0xffffffff };
    uint32_t bit{ 0x80000000 };
    for (auto n = 3; n < sm_TableSize - 1; n += 7)
    {
        if (bit == 0)
        {
            break;
        }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        m_Table[n] = (m_Table[n] & msk) | bit;
#include STSTEM_WARNING_POP

        msk >>= 1;
        bit >>= 1;
    }
}

// private
uint32_t CoreTools::Random::GenerateSimple() noexcept
{
    uint32_t temp = m_State;
    for (auto n = 0u; n < 32; ++n)
    {
        const uint32_t bit{ ((temp >> 0) ^ (temp >> 1) ^ (temp >> 2) ^ (temp >> 3) ^ (temp >> 5) ^ (temp >> 7)) & 1 };

        temp = (((temp >> 1) | (temp << 31)) & ~1) | bit;
    }

    m_State = temp;

    return m_State;
}

CoreTools::Random::Random(uint32_t seed) noexcept
    : m_State{ seed }, m_Index0{ 0 }, m_Index1{ 103 }, m_Table{}
{
    GenerateSeeds();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Random)

uint32_t CoreTools::Random::Generate() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
    m_Table[m_Index0] ^= m_Table[m_Index1];
    auto value = m_Table[m_Index0];
#include STSTEM_WARNING_POP

    ++m_Index0;
    if (m_Index0 == sm_TableSize)
    {
        m_Index0 = 0;
    }

    ++m_Index1;
    if (m_Index1 == sm_TableSize)
    {
        m_Index1 = 0;
    }

    return value;
}

int CoreTools::Random::GeneratePositive() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return Generate() & 0x7FFFFFFF;
}
