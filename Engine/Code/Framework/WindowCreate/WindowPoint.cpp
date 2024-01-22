/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:32)

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
