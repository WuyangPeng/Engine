///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:26)

#include "CoreTools/CoreToolsExport.h"

#include "Column.h"
#include "Detail/ColumnImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, Column)

CoreTools::SimpleCSV::Column::Column(const ConstXMLDocumentSharedPtr& document, const XMLNode& columnNode)
    : impl{ document, columnNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, Column)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Column, GetWidth, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, Column, SetWidth, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Column, IsHidden, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, Column, SetHidden, bool, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Column, GetColumnNode, CoreTools::SimpleCSV::XMLNode)
