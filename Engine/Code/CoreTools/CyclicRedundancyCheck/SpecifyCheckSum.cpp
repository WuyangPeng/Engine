// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 16:52)

#include "CoreTools/CoreToolsExport.h"

#include "SpecifyCheckSum.h"
#include "Flags/SpecifyCheckSumPowersFlags.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <array>

using std::swap;
using std::array;

const int CoreTools::SpecifyCheckSum
	::sm_SevenPowers[sm_PowersSize]{ 1, 7, 49, 343, 2401,16807, 117649, 823543, 5764801, 40353607 };

const int CoreTools::SpecifyCheckSum
	::sm_NinePowers[sm_PowersSize]{ 1, 9, 81, 729, 6561,59049, 531441, 4782969, 43046721, 387420489 };

CoreTools::SpecifyCheckSum
	::SpecifyCheckSum(const char* data, int length, SpecifyCheckSumPowers powers, int mod)
	:m_OriginalCheckSum{ 0 }, m_Powers{ powers }, m_Mod{ mod }, m_Collisions{ 0 }
{
	Calculation(data, length);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SpecifyCheckSum)

int CoreTools::SpecifyCheckSum
	::GetOriginalCheckSum() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_OriginalCheckSum;
}

int CoreTools::SpecifyCheckSum
	::GetCollisions() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Collisions;
}

// private
void CoreTools::SpecifyCheckSum
	::Calculation(const char* data, int length)
{
	if (sm_PowersSize < length)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("数字不能超过10位数\n"));
	}

	array<char, sm_PowersSize> buffer{};

	// 获得原始数字的校验和
	m_OriginalCheckSum = GetCheckSum(data, length);

	// 现在将数字复制到缓冲区，我们将在那里进行转置。
	System::MemoryCopy(buffer.data(), data, length);

	// 做转置和校验和	
	for (auto index = 0; index < length - 1; ++index)
	{
		// 是否有转置可能？如果两位数相同，则不能转置; 所以跳过这些，否则他们会产生虚假的碰撞。

		auto nextIndex = index + 1;

		if (buffer[index] == buffer[nextIndex])
			continue;

		// 否则，做转置
		swap(buffer[nextIndex], buffer[index]);

		// 得到校验和

		auto transpositionCheckSum = GetCheckSum(buffer.data(), boost::numeric_cast<uint32_t>(buffer.size()));

		if (transpositionCheckSum == m_OriginalCheckSum)
		{
			++m_Collisions;
		}

		// 现在撤消这个转置		
		swap(buffer[nextIndex], buffer[index]);
	}
}

int CoreTools::SpecifyCheckSum
	::GetCheckSum(const char* data, int length)
{
	const int* powers{ nullptr };

	if (m_Powers == SpecifyCheckSumPowers::Nine)
	{
		powers = sm_NinePowers;
	}
	else if (m_Powers == SpecifyCheckSumPowers::Seven)
	{
		powers = sm_SevenPowers;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("只能选择7或9次幂\n"));
	}

	if (sm_PowersSize < length)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("数字不能超过10位数\n"));
	}

	auto sum = 0;
	auto position = 0; // 数据中的数字是什么

	for (auto i = length; 0 < i; --i)
	{
		// 判断是否是数字
		if (!isdigit(data[i - 1]))
		{
			THROW_EXCEPTION(SYSTEM_TEXT("无效数字\n"));
		}

		// 将数字字符转换为数字 
		int digit{ data[i - 1] - '0' };

		// 查找幂，乘以digit，加到和

		sum += powers[position] * digit;

		++position;
	}

	// 根据方法得到总和模数
	sum %= m_Mod;

	if (m_Mod != 11 && m_Mod != 26 && m_Mod != 10)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("模数值错误\n"));
	}

	if (m_Mod == 11 && sum == 10)
	{
		sum = 0;
	}

	return sum;
}


