///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:48)

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
