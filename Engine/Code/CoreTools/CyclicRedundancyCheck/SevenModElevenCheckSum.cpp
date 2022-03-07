///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 18:13)

#include "CoreTools/CoreToolsExport.h"

#include "SevenModElevenCheckSum.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <array>

using std::array;
using namespace std::literals;

int CoreTools::SevenModElevenCheckSum::GetPowers(int index)
{
    static array<int, powersSize> powers{ 1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607 };

    return powers.at(index);
}

CoreTools::SevenModElevenCheckSum::SevenModElevenCheckSum(const char* data, int length)
    : checkSum{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SevenModElevenCheckSum)

int CoreTools::SevenModElevenCheckSum::GetCheckSum() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return checkSum;
}

// private
void CoreTools::SevenModElevenCheckSum::Calculation(const char* data, int length)
{
    if (data == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("data指针为空\n"s));
    }

    if (powersSize < length)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数字不能超过10位数\n"s));
    }

    auto sum = 0;
    auto position = 0;  // 数据中的数字是什么

    for (auto i = length; 0 < i; --i)
    {
        // 判断是否是数字
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        if (!isdigit(static_cast<int>(data[i - 1])))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效数字\n"s));
        }

        // 将数字字符转换为数字
        const int digit{ data[i - 1] - '0' };

#include STSTEM_WARNING_POP

        // 查找幂，乘以digit，加到和

        sum += GetPowers(position) * digit;

        ++position;
    }

    // 得到的和求模11
    auto mod = sum % 11;

    if (mod == 10)
    {
        mod = 0;
    }

    checkSum = mod;
}
