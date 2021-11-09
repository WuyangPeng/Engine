///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/04 21:18)

#include "CoreTools/CoreToolsExport.h"

#include "SharedStringsImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <algorithm>

using std::string;

CoreTools::SimpleCSV::SharedStringsImpl::SharedStringsImpl() noexcept
    : stringCache{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, SharedStringsImpl)

auto CoreTools::SimpleCSV::SharedStringsImpl::Find(const string& str) const
{
    auto iter = std::find_if(stringCache.cbegin(), stringCache.cend(), [&](const string& value) noexcept {
        return str == value;
    });

    return iter;
}

int CoreTools::SimpleCSV::SharedStringsImpl::GetStringIndex(const string& str) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto iter = Find(str);

    return iter == stringCache.cend() ? -1 : boost::numeric_cast<int>(std::distance(stringCache.cbegin(), iter));
}

bool CoreTools::SimpleCSV::SharedStringsImpl::IsStringExists(const string& str) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto iter = Find(str);

    return iter != stringCache.cend();
}

bool CoreTools::SimpleCSV::SharedStringsImpl::IsStringExists(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return index < boost::numeric_cast<int>(stringCache.size());
}

const string& CoreTools::SimpleCSV::SharedStringsImpl::GetString(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return stringCache.at(index);
}

int CoreTools::SimpleCSV::SharedStringsImpl::AppendString(const string& str)
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
