///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:12)

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
