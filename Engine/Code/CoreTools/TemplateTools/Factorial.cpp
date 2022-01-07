///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 15:38)

#include "CoreTools/CoreToolsExport.h"

#include "Factorial.h"

uint32_t CoreTools::RecursiveFactorial(uint32_t integer) noexcept
{
    return ((integer <= 1) ? 1 : (integer * RecursiveFactorial(integer - 1)));
}
