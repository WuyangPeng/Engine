// Copyright (c) 2010-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.3.0.1 (2020/05/21 09:46)

#include "Framework/FrameworkExport.h"

#include "WindowPoint.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>

using std::ostream;  

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowPoint)

ostream& Framework
	::operator<<(ostream& os, const WindowPoint& windowPoint)
{
	os << "x = " << windowPoint.GetWindowX()
	   << " y = " << windowPoint.GetWindowY();

	return os;
}

