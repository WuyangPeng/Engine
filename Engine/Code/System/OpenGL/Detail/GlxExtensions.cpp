///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 18:42)

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
