///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 09:33)

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
        THROW_EXCEPTION(SYSTEM_TEXT("���ֲ��ܳ���10λ��\n"s))
    }

    std::array<char, powersSize> buffer{};

    // ���ԭʼ���ֵ�У���
    originalCheckSum = GetCheckSum(data, length);

    // ���ڽ����ָ��Ƶ������������ǽ����������ת�á�
    System::MemoryCopy(buffer.data(), data, length);

    // ��ת�ú�У���
    for (auto index = 0; index < length - 1; ++index)
    {
        // �Ƿ���ת�ÿ��ܣ������λ����ͬ������ת��; ����������Щ���������ǻ������ٵ���ײ��
        const auto nextIndex = index + 1;

        if (buffer.at(index) == buffer.at(nextIndex))
            continue;

        // ������ת��
        std::swap(buffer.at(nextIndex), buffer.at(index));

        // �õ�У���
        if (const auto transpositionCheckSum = GetCheckSum(buffer.data(), boost::numeric_cast<int>(buffer.size())); transpositionCheckSum == originalCheckSum)
        {
            ++collisions;
        }

        // ���ڳ������ת��

        std::swap(buffer.at(nextIndex), buffer.at(index));
    }
}

int CoreTools::SpecifyCheckSum::GetCheckSum(const char* data, int length)
{
    if (data == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dataָ��Ϊ��\n"s))
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
        THROW_EXCEPTION(SYSTEM_TEXT("ֻ��ѡ��7��9����\n"s))
    }

    if (function == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("powersָ��Ϊ��\n"s))
    }

    if (powersSize < length)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ֲ��ܳ���10λ��\n"s))
    }

    int64_t sum{};
    auto position = 0;  // �����е�������ʲô

    for (auto i = length; 0 < i; --i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        // �ж��Ƿ�������
        if (!isdigit(data[i - 1]))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��Ч����\n"s))
        }

        // �������ַ�ת��Ϊ����
        const int digit{ data[i - 1] - '0' };

#include SYSTEM_WARNING_POP

        // �����ݣ�����digit���ӵ���

        sum += function(position) * static_cast<int64_t>(digit);

        ++position;
    }

    // ���ݷ����õ��ܺ�ģ��
    sum %= mod;

    if (mod != 11 && mod != 26 && mod != 10)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ģ��ֵ����\n"s))
    }

    if (mod == 11 && sum == 10)
    {
        sum = 0;
    }

    return boost::numeric_cast<int>(sum);
}
