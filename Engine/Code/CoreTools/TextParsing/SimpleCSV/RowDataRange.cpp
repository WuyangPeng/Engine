///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "RowDataRange.h"
#include "Flags/IteratorFlags.h"
#include "Detail/RowDataRangeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, RowDataRange)

CoreTools::SimpleCSV::RowDataRange::RowDataRange(const ConstXMLDocumentSharedPtr& document, const XMLNode& rowNode, int firstColumn, int lastColumn, const SharedStringsSharedPtr& sharedStrings)
    : impl{ document, rowNode, firstColumn, lastColumn, sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowDataRange)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, RowDataRange, GetSize, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowDataRange, GetDocument, CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowDataRange, GetSharedStrings, CoreTools::SimpleCSV::RowDataRange::SharedStringsSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowDataRange, GetRowNode, CoreTools::SimpleCSV::XMLNode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, RowDataRange, GetFirstColumn, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, RowDataRange, GetLastColumn, int)

CoreTools::SimpleCSV::RowDataIterator CoreTools::SimpleCSV::RowDataRange::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return RowDataIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::Begin };
}

CoreTools::SimpleCSV::RowDataIterator CoreTools::SimpleCSV::RowDataRange::end()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return RowDataIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::End };
}
