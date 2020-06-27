// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:52)

#include "Framework/FrameworkExport.h"

#include "MousePositionImpl.h"
#include "WindowMousePosition.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

CLASS_INVARIANT_STUB_DEFINE(Framework, MousePositionImpl)

Framework::MousePositionImpl::MousePositionImplSharedPtr Framework::MousePositionImpl
	::CreateWindowMousePosition(HWnd hwnd)
{
	return make_shared<WindowMousePosition>(hwnd);
}



