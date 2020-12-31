//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 14:53)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectLinkImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/ObjectInterfaceLess.h"

#include <algorithm>

using std::make_pair;

CoreTools::ObjectLinkImpl::ObjectLinkImpl() noexcept
    : m_Linked{}, m_Ordered{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ObjectLinkImpl::IsValid() const noexcept
{
    if (m_Linked.size() == m_Ordered.size())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::ObjectInterfaceSharedPtr CoreTools::ObjectLinkImpl::GetObjectInterface(uint64_t uniqueID)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto iter = m_Linked.find(uniqueID);

    if (iter != m_Linked.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("准备读取的object指针没有链接！"s));
    }
}

int CoreTools::ObjectLinkImpl::GetOrderedSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Ordered.size());
}

void CoreTools::ObjectLinkImpl::Insert(uint64_t uniqueID, const ObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Linked.insert({ uniqueID, object });
    m_Ordered.emplace_back(object);
}

void CoreTools::ObjectLinkImpl::Sort()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    sort(m_Ordered.begin(), m_Ordered.end(), ObjectInterfaceSmartPointerLess{});
}

CoreTools::ObjectLinkImpl::LinkSequentialContainerConstIter CoreTools::ObjectLinkImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Ordered.begin();
}

CoreTools::ObjectLinkImpl::LinkSequentialContainerIter CoreTools::ObjectLinkImpl::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_Ordered.begin();
}

CoreTools::ObjectLinkImpl::LinkSequentialContainerConstIter CoreTools::ObjectLinkImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Ordered.end();
}

CoreTools::ObjectLinkImpl::LinkSequentialContainerIter CoreTools::ObjectLinkImpl::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_Ordered.end();
}
