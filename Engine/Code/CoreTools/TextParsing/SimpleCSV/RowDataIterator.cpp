///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "RowDataIterator.h"
#include "Detail/RowDataIteratorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, RowDataIterator)

CoreTools::SimpleCSV::RowDataIterator::RowDataIterator(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const RowDataRange& rowDataRange, IteratorLocation location)
    : impl{ document, sharedStrings, rowDataRange, location }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowDataIterator)

CoreTools::SimpleCSV::RowDataIterator& CoreTools::SimpleCSV::RowDataIterator::operator++()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ++(*impl);

    return *this;
}

CoreTools::SimpleCSV::RowDataIterator CoreTools::SimpleCSV::RowDataIterator::operator++(int)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto iter = *this;

    ++(*this);

    return iter;
}

CoreTools::SimpleCSV::RowDataIterator::ReferenceType CoreTools::SimpleCSV::RowDataIterator::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return **impl;
}

CoreTools::SimpleCSV::RowDataIterator::PointerType CoreTools::SimpleCSV::RowDataIterator::operator->() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->operator->();
}

bool CoreTools::SimpleCSV::RowDataIterator::IsSame(const RowDataIterator& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsSame(*rhs.impl);
}

bool CoreTools::SimpleCSV::operator==(const RowDataIterator& lhs, const RowDataIterator& rhs)
{
    return lhs.IsSame(rhs);
}

bool CoreTools::SimpleCSV::operator!=(const RowDataIterator& lhs, const RowDataIterator& rhs)
{
    return !lhs.IsSame(rhs);
}