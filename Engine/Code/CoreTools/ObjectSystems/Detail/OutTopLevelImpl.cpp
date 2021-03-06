//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 14:58)

#include "CoreTools/CoreToolsExport.h"

#include "OutTopLevelImpl.h"
#include "TopLevel.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::OutTopLevelImpl::OutTopLevelImpl() noexcept
    : m_TopLevel{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OutTopLevelImpl)

bool CoreTools::OutTopLevelImpl::IsTopLevel(const ConstObjectInterfaceSharedPtr& object) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto& container = m_TopLevel.get<UniqueObject>();

    return container.find(object) != container.cend();
}

int CoreTools::OutTopLevelImpl::GetTopLevelSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_TopLevel.size());
}

CoreTools::ConstObjectContainerConstIter CoreTools::OutTopLevelImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_TopLevel.begin();
}

CoreTools::ConstObjectContainerConstIter CoreTools::OutTopLevelImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_TopLevel.end();
}

void CoreTools::OutTopLevelImpl::Insert(const ObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_TopLevel.emplace_back(object);
}
