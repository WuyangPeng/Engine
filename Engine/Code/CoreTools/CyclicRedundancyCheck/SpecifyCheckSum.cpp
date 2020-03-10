// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:52)

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
		THROW_EXCEPTION(SYSTEM_TEXT("���ֲ��ܳ���10λ��\n"));
	}

	array<char, sm_PowersSize> buffer{};

	// ���ԭʼ���ֵ�У���
	m_OriginalCheckSum = GetCheckSum(data, length);

	// ���ڽ����ָ��Ƶ������������ǽ����������ת�á�
	System::MemoryCopy(buffer.data(), data, length);

	// ��ת�ú�У���	
	for (auto index = 0; index < length - 1; ++index)
	{
		// �Ƿ���ת�ÿ��ܣ������λ����ͬ������ת��; ����������Щ���������ǻ������ٵ���ײ��

		auto nextIndex = index + 1;

		if (buffer[index] == buffer[nextIndex])
			continue;

		// ������ת��
		swap(buffer[nextIndex], buffer[index]);

		// �õ�У���

		auto transpositionCheckSum = GetCheckSum(buffer.data(), boost::numeric_cast<uint32_t>(buffer.size()));

		if (transpositionCheckSum == m_OriginalCheckSum)
		{
			++m_Collisions;
		}

		// ���ڳ������ת��		
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
		THROW_EXCEPTION(SYSTEM_TEXT("ֻ��ѡ��7��9����\n"));
	}

	if (sm_PowersSize < length)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("���ֲ��ܳ���10λ��\n"));
	}

	auto sum = 0;
	auto position = 0; // �����е�������ʲô

	for (auto i = length; 0 < i; --i)
	{
		// �ж��Ƿ�������
		if (!isdigit(data[i - 1]))
		{
			THROW_EXCEPTION(SYSTEM_TEXT("��Ч����\n"));
		}

		// �������ַ�ת��Ϊ���� 
		int digit{ data[i - 1] - '0' };

		// �����ݣ�����digit���ӵ���

		sum += powers[position] * digit;

		++position;
	}

	// ���ݷ����õ��ܺ�ģ��
	sum %= m_Mod;

	if (m_Mod != 11 && m_Mod != 26 && m_Mod != 10)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("ģ��ֵ����\n"));
	}

	if (m_Mod == 11 && sum == 10)
	{
		sum = 0;
	}

	return sum;
}


