///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:05)

#include "CoreTools/CoreToolsExport.h"

#include "XmlData.h"
#include "Detail/XmlDataImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::SimpleCSV::XmlData::XmlData(const DocumentSharedPtr& parentDocument, const std::string& xmlPath, const std::string& xmlId, ContentType xmlType)
    : impl{ parentDocument, xmlPath, xmlId, xmlType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, XmlData)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, XmlData, SetRawData, std::string, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlData, GetRawData, std::string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, XmlData, GetParentDocument, CoreTools::SimpleCSV::XmlData::DocumentWeakPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlData, GetXmlPath, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlData, GetXmlId, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, XmlData, GetXmlType, CoreTools::SimpleCSV::ContentType)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, XmlData, GetXmlDocument, CoreTools::SimpleCSV::XMLDocumentSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, XmlData, GetXmlDocument, CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr)