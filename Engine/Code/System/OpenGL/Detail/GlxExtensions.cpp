/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 17:23)

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
