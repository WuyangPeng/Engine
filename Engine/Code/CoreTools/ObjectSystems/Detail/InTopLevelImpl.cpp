//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 14:53)

#include "CoreTools/CoreToolsExport.h"

#include "InTopLevelImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::InTopLevelImpl::InTopLevelImpl() noexcept
    : m_TopLevel{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, InTopLevelImpl)

bool CoreTools::InTopLevelImpl::IsTopLevel(const ObjectInterfaceSharedPtr& object) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto& container = m_TopLevel.get<UniqueObject>();

    return container.find(object) != container.cend();
}

int CoreTools::InTopLevelImpl::GetTopLevelSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_TopLevel.size());
}

void CoreTools::InTopLevelImpl::Insert(const ObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (!m_TopLevel.emplace_back(object).second)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("一个object指针只可以被插入一次！"s));
    }
}

CoreTools::ObjectContainerConstIter CoreTools::InTopLevelImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_TopLevel.begin();
}

CoreTools::ObjectContainerConstIter CoreTools::InTopLevelImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_TopLevel.end();
}

CoreTools::ObjectContainerIter CoreTools::InTopLevelImpl::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_TopLevel.begin();
}

CoreTools::ObjectContainerIter CoreTools::InTopLevelImpl::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_TopLevel.end();
}
