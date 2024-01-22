/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:26)

#include "Framework/FrameworkExport.h"

#include "MousePositionImpl.h"
#include "WindowMousePosition.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Framework, MousePositionImpl)

Framework::MousePositionImpl::MousePositionImplSharedPtr Framework::MousePositionImpl::Create(WindowsHWnd hWnd)
{
    return std::make_shared<WindowMousePosition>(hWnd);
}
