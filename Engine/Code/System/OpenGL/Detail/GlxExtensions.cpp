/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:23)

#include "System/SystemExport.h"

#include "GLExtensions.h"
#include "GlxExtensions.h"

bool System::InitGlx() noexcept
{
    if (InitGL())
    {
        return true;
    }
    else
    {
        return false;
    }
}
