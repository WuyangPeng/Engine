///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:29)

#include "CoreTools/CoreToolsExport.h"

#include "XmlFile.h"
#include "Detail/XmlFileImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, XmlFile)

CoreTools::SimpleCSV::XmlFile::XmlFile(const XmlDataSharedPtr& xmlData)
    : impl{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, XmlFile)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetXmlData, string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, XmlFile, SetXmlData, string, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetRelationshipID, string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetParentDocument, CoreTools::SimpleCSV::XmlFile::DocumentSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetParentDocument, CoreTools::SimpleCSV::XmlFile::ConstDocumentSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetXmlDocument, CoreTools::SimpleCSV::XMLDocumentSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetXmlDocument, CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetSheetData, CoreTools::SimpleCSV::XMLNode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetFirstChildColumns, CoreTools::SimpleCSV::XMLNode)
