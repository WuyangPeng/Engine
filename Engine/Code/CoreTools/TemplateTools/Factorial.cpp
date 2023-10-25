///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:43)

#include "CoreTools/CoreToolsExport.h"

#include "Factorial.h"

uint32_t CoreTools::RecursiveFactorial(uint32_t integer) noexcept
{
    return ((integer <= 1) ? 1 : (integer * RecursiveFactorial(integer - 1)));
}
