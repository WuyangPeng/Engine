// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:15)

#include "Framework/FrameworkExport.h"

#include "MousePositionImpl.h"
#include "WindowMousePosition.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::MousePositionImpl
	::MousePositionImpl()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::MousePositionImpl
	::~MousePositionImpl()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,MousePositionImpl)

Framework::MousePositionImpl::MousePositionImplPtr  Framework::MousePositionImpl
   ::CreateWindowMousePositionPtr(HWnd hwnd)
{
	return MousePositionImplPtr(new WindowMousePosition(hwnd));
}



