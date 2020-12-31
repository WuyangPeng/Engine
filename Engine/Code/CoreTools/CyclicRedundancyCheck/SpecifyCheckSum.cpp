//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 14:24)

#include "CoreTools/CoreToolsExport.h"

#include "SpecifyCheckSum.h"
#include "Flags/SpecifyCheckSumPowersFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <array>

using std::array;
using std::swap;
using namespace std::literals;

const int CoreTools::SpecifyCheckSum::GetSevenPowers(int index)
{
    static array<int, sm_PowersSize> sevenPowers{ 1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607 };

    return sevenPowers.at(index);
}

const int CoreTools::SpecifyCheckSum::GetNinePowers(int index)
{
    static array<int, sm_PowersSize> ninePowers{ 1, 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721, 387420489 };

    return ninePowers.at(index);
}

CoreTools::SpecifyCheckSum::SpecifyCheckSum(const char* data, int length, SpecifyCheckSumPowers powers, int mod)
    : m_OriginalCheckSum{ 0 }, m_Powers{ powers }, m_Mod{ mod }, m_Collisions{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SpecifyCheckSum)

int CoreTools::SpecifyCheckSum::GetOriginalCheckSum() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_OriginalCheckSum;
}

int CoreTools::SpecifyCheckSum::GetCollisions() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Collisions;
}

// private
void CoreTools::SpecifyCheckSum::Calculation(const char* data, int length)
{
    if (sm_PowersSize < length)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ֲ��ܳ���10λ��\n"s));
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

        const auto nextIndex = index + 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        if (buffer[index] == buffer[nextIndex])
            continue;
#include STSTEM_WARNING_PUSH

            // ������ת��
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        swap(buffer[nextIndex], buffer[index]);
#include STSTEM_WARNING_PUSH

        // �õ�У���

        const auto transpositionCheckSum = GetCheckSum(buffer.data(), boost::numeric_cast<uint32_t>(buffer.size()));

        if (transpositionCheckSum == m_OriginalCheckSum)
        {
            ++m_Collisions;
        }

        // ���ڳ������ת��
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        swap(buffer[nextIndex], buffer[index]);
#include STSTEM_WARNING_PUSH
    }
}

int CoreTools::SpecifyCheckSum::GetCheckSum(const char* data, int length)
{
    if (data == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dataָ��Ϊ��\n"s));
    }

    using Function = const int (*)(int index);

    Function function = nullptr;

    if (m_Powers == SpecifyCheckSumPowers::Nine)
    {
        function = &ClassType::GetSevenPowers;
    }
    else if (m_Powers == SpecifyCheckSumPowers::Seven)
    {
        function = &ClassType::GetNinePowers;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ֻ��ѡ��7��9����\n"s));
    }

    if (function == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("powersָ��Ϊ��\n"s));
    }

    if (sm_PowersSize < length)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ֲ��ܳ���10λ��\n"s));
    }

    auto sum = 0;
    auto position = 0;  // �����е�������ʲô

    for (auto i = length; 0 < i; --i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        // �ж��Ƿ�������
        if (!isdigit(static_cast<int>(data[i - 1])))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��Ч����\n"s));
        }

        // �������ַ�ת��Ϊ����
        const int digit{ data[i - 1] - '0' };
#include STSTEM_WARNING_POP

        // �����ݣ�����digit���ӵ���

        sum += function(position) * digit;

        ++position;
    }

    // ���ݷ����õ��ܺ�ģ��
    sum %= m_Mod;

    if (m_Mod != 11 && m_Mod != 26 && m_Mod != 10)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ģ��ֵ����\n"s));
    }

    if (m_Mod == 11 && sum == 10)
    {
        sum = 0;
    }

    return sum;
}
