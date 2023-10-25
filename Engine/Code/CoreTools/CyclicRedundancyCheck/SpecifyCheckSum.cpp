///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:33)

#include "CoreTools/CoreToolsExport.h"

#include "SpecifyCheckSum.h"
#include "Flags/SpecifyCheckSumPowersFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <array>

using namespace std::literals;

int CoreTools::SpecifyCheckSum::GetSevenPowers(int index)
{
    static std::array sevenPowers{ 1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607 };

    return sevenPowers.at(index);
}

int CoreTools::SpecifyCheckSum::GetNinePowers(int index)
{
    static std::array ninePowers{ 1, 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721, 387420489 };

    return ninePowers.at(index);
}

CoreTools::SpecifyCheckSum::SpecifyCheckSum(const char* data, int length, SpecifyCheckSumPowers powers, int mod)
    : originalCheckSum{ 0 }, powers{ powers }, mod{ mod }, collisions{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SpecifyCheckSum)

int CoreTools::SpecifyCheckSum::GetOriginalCheckSum() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return originalCheckSum;
}

int CoreTools::SpecifyCheckSum::GetCollisions() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return collisions;
}

void CoreTools::SpecifyCheckSum::Calculation(const char* data, int length)
{
    if (powersSize < length)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数字不能超过10位数\n"s))
    }

    std::array<char, powersSize> buffer{};

    // 获得原始数字的校验和
    originalCheckSum = GetCheckSum(data, length);

    // 现在将数字复制到缓冲区，我们将在那里进行转置。
    System::MemoryCopy(buffer.data(), data, length);

    // 做转置和校验和
    for (auto index = 0; index < length - 1; ++index)
    {
        // 是否有转置可能？如果两位数相同，则不能转置; 所以跳过这些，否则他们会产生虚假的碰撞。
        const auto nextIndex = index + 1;

        if (buffer.at(index) == buffer.at(nextIndex))
            continue;

        // 否则，做转置
        std::swap(buffer.at(nextIndex), buffer.at(index));

        // 得到校验和
        if (const auto transpositionCheckSum = GetCheckSum(buffer.data(), boost::numeric_cast<int>(buffer.size())); transpositionCheckSum == originalCheckSum)
        {
            ++collisions;
        }

        // 现在撤消这个转置

        std::swap(buffer.at(nextIndex), buffer.at(index));
    }
}

int CoreTools::SpecifyCheckSum::GetCheckSum(const char* data, int length)
{
    if (data == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("data指针为空\n"s))
    }

    using Function = int (*)(int index);

    Function function = nullptr;

    if (powers == SpecifyCheckSumPowers::Nine)
    {
        function = &ClassType::GetSevenPowers;
    }
    else if (powers == SpecifyCheckSumPowers::Seven)
    {
        function = &ClassType::GetNinePowers;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("只能选择7或9次幂\n"s))
    }

    if (function == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("powers指针为空\n"s))
    }

    if (powersSize < length)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数字不能超过10位数\n"s))
    }

    int64_t sum{};
    auto position = 0;  // 数据中的数字是什么

    for (auto i = length; 0 < i; --i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        // 判断是否是数字
        if (!isdigit(data[i - 1]))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效数字\n"s))
        }

        // 将数字字符转换为数字
        const int digit{ data[i - 1] - '0' };

#include SYSTEM_WARNING_POP

        // 查找幂，乘以digit，加到和

        sum += function(position) * static_cast<int64_t>(digit);

        ++position;
    }

    // 根据方法得到总和模数
    sum %= mod;

    if (mod != 11 && mod != 26 && mod != 10)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("模数值错误\n"s))
    }

    if (mod == 11 && sum == 10)
    {
        sum = 0;
    }

    return boost::numeric_cast<int>(sum);
}
