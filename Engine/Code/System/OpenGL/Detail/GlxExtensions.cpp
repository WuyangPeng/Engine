///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 23:39)

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
