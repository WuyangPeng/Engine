///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/10 20:28)

#include "CoreTools/CoreToolsExport.h"

#include "RowRange.h"
#include "Flags/IteratorFlags.h"
#include "Detail/RowRangeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, RowRange)

CoreTools::SimpleCSV::RowRange::RowRange(const ConstXMLDocumentSharedPtr& document, const XMLNode& dataNode, int first, int last, const SharedStringsSharedPtr& sharedStrings)
    : impl{ document, dataNode, first, last, sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowRange)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, RowRange, GetRowCount, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, RowRange, GetFirstRow, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, RowRange, GetLastRow, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowRange, GetSharedStrings, CoreTools::SimpleCSV::RowRange::SharedStringsSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowRange, GetDataNode, CoreTools::SimpleCSV::XMLNode)

CoreTools::SimpleCSV::RowIterator CoreTools::SimpleCSV::RowRange::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return RowIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::Begin };
}

CoreTools::SimpleCSV::RowIterator CoreTools::SimpleCSV::RowRange::end()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return RowIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::End };
}
