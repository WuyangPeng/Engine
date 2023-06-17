///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:48)

#include "Framework/FrameworkExport.h"

#include "MousePositionImpl.h"
#include "WindowMousePosition.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

CLASS_INVARIANT_STUB_DEFINE(Framework, MousePositionImpl)

Framework::MousePositionImpl::MousePositionImplSharedPtr Framework::MousePositionImpl::Create(WindowsHWnd hwnd)
{
    return make_shared<WindowMousePosition>(hwnd);
}
