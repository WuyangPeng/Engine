// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 16:52)

#include "CoreTools/CoreToolsExport.h"

#include "SevenModElevenCheckSum.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26446)
using namespace std::literals;

const int CoreTools::SevenModElevenCheckSum
	::sm_Powers[sm_PowersSize]{ 1, 7, 49, 343, 2401,16807, 117649, 823543, 5764801, 40353607 };

CoreTools::SevenModElevenCheckSum
	::SevenModElevenCheckSum(const char* data, int length)
	:m_CheckSum{ 0 }
{
	Calculation(data, length);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SevenModElevenCheckSum)

int CoreTools::SevenModElevenCheckSum
	::GetCheckSum() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CheckSum;
}

// private
void CoreTools::SevenModElevenCheckSum
	::Calculation(const char* data, int length)
{
	if (data == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("data指针为空\n"s));
	}

	if (sm_PowersSize < length)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("数字不能超过10位数\n"s));
	}

	auto sum = 0;
	auto position = 0; // 数据中的数字是什么

	for (auto i = length; 0 < i; --i)
	{
		// 判断是否是数字
		if (!isdigit(static_cast<int>(data[i - 1])))
		{
			THROW_EXCEPTION(SYSTEM_TEXT("无效数字\n"s));
		}

		// 将数字字符转换为数字 
		const int digit{ data[i - 1] - '0' };

		// 查找幂，乘以digit，加到和

		sum += sm_Powers[position] * digit;

		++position;
	}

	// 得到的和求模11 
	auto mod = sum % 11;

	if (mod == 10)
	{
		mod = 0;
	}

	m_CheckSum = mod;
}

#include STSTEM_WARNING_POP