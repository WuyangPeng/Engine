///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 23:01)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectLinkImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <algorithm>

CoreTools::ObjectLinkImpl::ObjectLinkImpl() noexcept
    : linked{}, ordered{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::ObjectLinkImpl::IsValid() const noexcept
{
    if (linked.size() == ordered.size())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::ObjectInterfaceSharedPtr CoreTools::ObjectLinkImpl::GetObjectInterface(uint64_t uniqueID)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto iter = linked.find(uniqueID);

    if (iter != linked.cend())
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

    return boost::numeric_cast<int>(ordered.size());
}

void CoreTools::ObjectLinkImpl::Insert(uint64_t uniqueID, const ObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    linked.insert({ uniqueID, object });
    ordered.emplace_back(object);
}

void CoreTools::ObjectLinkImpl::Sort()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    sort(ordered.begin(), ordered.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return lhs->GetUniqueID() < rhs->GetUniqueID();
    });
}

CoreTools::ObjectLinkImpl::LinkSequentialContainerConstIter CoreTools::ObjectLinkImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ordered.begin();
}

CoreTools::ObjectLinkImpl::LinkSequentialContainerIter CoreTools::ObjectLinkImpl::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ordered.begin();
}

CoreTools::ObjectLinkImpl::LinkSequentialContainerConstIter CoreTools::ObjectLinkImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ordered.end();
}

CoreTools::ObjectLinkImpl::LinkSequentialContainerIter CoreTools::ObjectLinkImpl::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ordered.end();
}
