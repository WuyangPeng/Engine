///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 23:03)

#include "CoreTools/CoreToolsExport.h"

#include "OutTopLevelImpl.h"
#include "TopLevel.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::OutTopLevelImpl::OutTopLevelImpl() noexcept
    : topLevel{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OutTopLevelImpl)

bool CoreTools::OutTopLevelImpl::IsTopLevel(const ConstObjectInterfaceSharedPtr& object) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto& container = topLevel.get<UniqueObject>();

    return container.find(object) != container.cend();
}

int CoreTools::OutTopLevelImpl::GetTopLevelSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(topLevel.size());
}

CoreTools::ConstObjectContainerConstIter CoreTools::OutTopLevelImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return topLevel.begin();
}

CoreTools::ConstObjectContainerConstIter CoreTools::OutTopLevelImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return topLevel.end();
}

void CoreTools::OutTopLevelImpl::Insert(const ObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    topLevel.emplace_back(object);
}
