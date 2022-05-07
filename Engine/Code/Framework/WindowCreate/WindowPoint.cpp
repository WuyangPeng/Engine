///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 16:12)

#include "Framework/FrameworkExport.h"

#include "WindowPoint.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>

using std::ostream;

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowPoint)

ostream& Framework::operator<<(ostream& os, const WindowPoint& windowPoint)
{
    os << "x = "
       << windowPoint.GetWindowX()
       << " y = "
       << windowPoint.GetWindowY();

    return os;
}
