/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:02)

#include "CoreTools/CoreToolsExport.h"

#include "Factorial.h"

uint32_t CoreTools::RecursiveFactorial(uint32_t integer) noexcept
{
    return ((integer <= 1) ? 1 : (integer * RecursiveFactorial(integer - 1)));
}
