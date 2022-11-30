///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:42)

#include "System/SystemExport.h"

#include "GLExtensions.h"
#include "GlxExtensions.h"

bool System::InitGLX() noexcept
{
    if (!InitGL())
    {
        return false;
    }

    return true;
}
