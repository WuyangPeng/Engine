///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:25)

#include "CoreTools/CoreToolsExport.h"

#include "CellIterator.h"
#include "Detail/CellIteratorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, CellIterator)

CoreTools::SimpleCSV::CellIterator::CellIterator(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const CellRange& cellRange, IteratorLocation location)
    : impl{ document, sharedStrings, cellRange, location }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellIterator)

CoreTools::SimpleCSV::CellIterator& CoreTools::SimpleCSV::CellIterator::operator++()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ++(*impl);

    return *this;
}

CoreTools::SimpleCSV::CellIterator CoreTools::SimpleCSV::CellIterator::operator++(int)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto iter = *this;

    ++(*this);

    return iter;
}

CoreTools::SimpleCSV::CellIterator::ReferenceType CoreTools::SimpleCSV::CellIterator::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return **impl;
}

CoreTools::SimpleCSV::CellIterator::PointerType CoreTools::SimpleCSV::CellIterator::operator->() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->operator->();
}

bool CoreTools::SimpleCSV::CellIterator::IsSame(const CellIterator& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsSame(*rhs.impl);
}

int CoreTools::SimpleCSV::CellIterator::Distance(const CellIterator& last) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->Distance(*last.impl);
}

bool CoreTools::SimpleCSV::operator==(const CellIterator& lhs, const CellIterator& rhs)
{
    return lhs.IsSame(rhs);
}

bool CoreTools::SimpleCSV::operator!=(const CellIterator& lhs, const CellIterator& rhs)
{
    return !lhs.IsSame(rhs);
}