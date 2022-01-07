///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:29)

#include "CoreTools/CoreToolsExport.h"

#include "XmlData.h"
#include "Detail/XmlDataImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::SimpleCSV::XmlData::XmlData(const DocumentSharedPtr& parentDocument, const string& xmlPath, const string& xmlID, ContentType xmlType)
    : impl{ parentDocument, xmlPath, xmlID, xmlType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, XmlData)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, XmlData, SetRawData, string, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlData, GetRawData, string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, XmlData, GetParentDocument, CoreTools::SimpleCSV::XmlData::DocumentWeakPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlData, GetXmlPath, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlData, GetXmlID, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, XmlData, GetXmlType, CoreTools::SimpleCSV::ContentType)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, XmlData, GetXmlDocument, CoreTools::SimpleCSV::XMLDocumentSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, XmlData, GetXmlDocument, CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr)