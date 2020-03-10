// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:54)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectInterfaceLess.h"

bool CoreTools::ObjectInterfaceSmartPointerLess
	::operator()(const ConstObjectInterfaceSmartPointer& lhs, const ConstObjectInterfaceSmartPointer& rhs)
{
	return lhs->GetUniqueID() < rhs->GetUniqueID();
}