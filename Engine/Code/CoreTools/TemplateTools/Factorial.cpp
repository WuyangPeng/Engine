///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:34)

#include "CoreTools/CoreToolsExport.h"

#include "Factorial.h"

uint32_t CoreTools::RecursiveFactorial(uint32_t integer) noexcept
{
    return ((integer <= 1) ? 1 : (integer * RecursiveFactorial(integer - 1)));
}
