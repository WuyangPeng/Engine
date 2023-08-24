///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 15:16)

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
