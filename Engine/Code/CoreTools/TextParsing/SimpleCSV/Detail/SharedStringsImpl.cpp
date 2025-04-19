/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:25)

#include "CoreTools/CoreToolsExport.h"

#include "SharedStringsImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <ranges>

CoreTools::SimpleCSV::SharedStringsImpl::SharedStringsImpl() noexcept
    : stringCache{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, SharedStringsImpl)

CoreTools::SimpleCSV::SharedStringsImpl::CacheTypeConstIter CoreTools::SimpleCSV::SharedStringsImpl::Find(const std::string& str) const
{
    auto iter = std::ranges::find_if(stringCache, [&](const std::string& value) noexcept {
        return str == value;
    });

    return iter;
}

int CoreTools::SimpleCSV::SharedStringsImpl::GetStringIndex(const std::string& str) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = Find(str);

    return iter == stringCache.cend() ? -1 : boost::numeric_cast<int>(std::distance(stringCache.cbegin(), iter));
}

bool CoreTools::SimpleCSV::SharedStringsImpl::IsStringExists(const std::string& str) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = Find(str);

    return iter != stringCache.cend();
}

bool CoreTools::SimpleCSV::SharedStringsImpl::IsStringExists(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return index < boost::numeric_cast<int>(stringCache.size());
}

const std::string& CoreTools::SimpleCSV::SharedStringsImpl::GetString(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return stringCache.at(index);
}

int CoreTools::SimpleCSV::SharedStringsImpl::AppendString(const std::string& str)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    stringCache.emplace_back(str);

    return boost::numeric_cast<int>(stringCache.size() - 1);
}

void CoreTools::SimpleCSV::SharedStringsImpl::ClearString(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    stringCache.at(index).clear();
}
