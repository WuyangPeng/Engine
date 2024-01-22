/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:32)

#include "Framework/FrameworkExport.h"

#include "WindowPoint.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowPoint)

std::ostream& Framework::operator<<(std::ostream& os, const WindowPoint& windowPoint)
{
    os << "x = "
       << windowPoint.GetWindowX()
       << " y = "
       << windowPoint.GetWindowY();

    return os;
}
