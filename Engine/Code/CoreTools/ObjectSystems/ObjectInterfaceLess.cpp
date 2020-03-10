// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/21 15:54)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectInterfaceLess.h"

bool CoreTools::ObjectInterfaceSmartPointerLess
	::operator()(const ConstObjectInterfaceSmartPointer& lhs, const ConstObjectInterfaceSmartPointer& rhs)
{
	return lhs->GetUniqueID() < rhs->GetUniqueID();
}