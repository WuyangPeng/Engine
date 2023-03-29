///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 11:22)

#include "CoreTools/CoreToolsExport.h"

#include "CellRange.h"
#include "Flags/IteratorFlags.h"
#include "Detail/CellRangeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, CellRange)

CoreTools::SimpleCSV::CellRange::CellRange(const ConstXMLDocumentSharedPtr& document, const XMLNode& dataNode, const CellReference& topLeft, const CellReference& bottomRight, const SharedStringsSharedPtr& sharedStrings)
    : impl{ document, dataNode, topLeft, bottomRight, sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellRange)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, CellRange, GetNumRows, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, CellRange, GetNumColumns, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellRange, GetDocument, CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellRange, GetDataNode, CoreTools::SimpleCSV::XMLNode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, CellRange, GetTopLeft, CoreTools::SimpleCSV::CellReference)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, CellRange, GetBottomRight, CoreTools::SimpleCSV::CellReference)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellRange, GetSharedStrings, CoreTools::SimpleCSV::CellRange::SharedStringsSharedPtr)

CoreTools::SimpleCSV::CellIterator CoreTools::SimpleCSV::CellRange::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return CellIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::Begin };
}

CoreTools::SimpleCSV::CellIterator CoreTools::SimpleCSV::CellRange::end()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return CellIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::End };
}
