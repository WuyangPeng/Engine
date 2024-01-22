/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:41)

#include "CoreTools/CoreToolsExport.h"

#include "SevenModElevenCheckSum.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <array>

using namespace std::literals;

int CoreTools::SevenModElevenCheckSum::GetPowers(int index)
{
    static std::array powers{ 1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607 };

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

void CoreTools::SevenModElevenCheckSum::Calculation(const char* data, int length)
{
    if (data == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dataָ��Ϊ��\n"s))
    }

    if (powersSize < length)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ֲ��ܳ���10λ��\n"s))
    }

    auto sum = 0;
    auto position = 0;  // �����е�������ʲô

    for (auto i = length; 0 < i; --i)
    {
        // �ж��Ƿ�������
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        if (!isdigit(data[i - 1]))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��Ч����\n"s))
        }

        // �������ַ�ת��Ϊ����
        const int digit{ data[i - 1] - '0' };

#include SYSTEM_WARNING_POP

        // �����ݣ�����digit���ӵ���

        sum += GetPowers(position) * digit;

        ++position;
    }

    // �õ��ĺ���ģ11
    auto mod = sum % 11;

    if (mod == 10)
    {
        mod = 0;
    }

    checkSum = mod;
}
