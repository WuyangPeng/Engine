/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:28)

#include "CoreTools/CoreToolsExport.h"

#include "RowIterator.h"
#include "Detail/RowIteratorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, RowIterator)

CoreTools::SimpleCSV::RowIterator::RowIterator(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const RowRange& rowRange, IteratorLocation location)
    : impl{ document, sharedStrings, rowRange, location }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowIterator)

CoreTools::SimpleCSV::RowIterator& CoreTools::SimpleCSV::RowIterator::operator++()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ++(*impl);

    return *this;
}

CoreTools::SimpleCSV::RowIterator CoreTools::SimpleCSV::RowIterator::operator++(int)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto iter = *this;

    ++(*this);

    return iter;
}

CoreTools::SimpleCSV::RowIterator::ReferenceType CoreTools::SimpleCSV::RowIterator::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return **impl;
}

CoreTools::SimpleCSV::RowIterator::PointerType CoreTools::SimpleCSV::RowIterator::operator->() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->operator->();
}

bool CoreTools::SimpleCSV::RowIterator::IsSame(const RowIterator& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsSame(*rhs.impl);
}

bool CoreTools::SimpleCSV::operator==(const RowIterator& lhs, const RowIterator& rhs)
{
    return lhs.IsSame(rhs);
}

bool CoreTools::SimpleCSV::operator!=(const RowIterator& lhs, const RowIterator& rhs)
{
    return !lhs.IsSame(rhs);
}