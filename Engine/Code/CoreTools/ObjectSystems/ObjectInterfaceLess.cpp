//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 16:30)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectInterfaceLess.h"
#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

bool CoreTools::ObjectInterfaceSmartPointerLess::operator()(const ConstObjectInterfaceSharedPtr& lhs, const ConstObjectInterfaceSharedPtr& rhs) noexcept
{
    return lhs->GetUniqueID() < rhs->GetUniqueID();
}

#include STSTEM_WARNING_POP