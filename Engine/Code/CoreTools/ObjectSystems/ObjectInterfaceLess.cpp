// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:54)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectInterfaceLess.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

bool CoreTools::ObjectInterfaceSmartPointerLess ::operator()(const ConstObjectInterfaceSharedPtr& lhs, const ConstObjectInterfaceSharedPtr& rhs) noexcept
{
	return lhs->GetUniqueID() < rhs->GetUniqueID();
}
#include STSTEM_WARNING_POP