///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 14:17)

#include "CoreTools/CoreToolsExport.h"

#include "XmlFile.h"
#include "Detail/XmlFileImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, XmlFile)

CoreTools::SimpleCSV::XmlFile::XmlFile(const XmlDataSharedPtr& xmlData)
    : impl{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, XmlFile)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetXmlData, std::string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, XmlFile, SetXmlData, std::string, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetRelationshipId, std::string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetParentDocument, CoreTools::SimpleCSV::XmlFile::DocumentSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetParentDocument, CoreTools::SimpleCSV::XmlFile::ConstDocumentSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetXmlDocument, CoreTools::SimpleCSV::XMLDocumentSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetXmlDocument, CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetSheetData, CoreTools::SimpleCSV::XMLNode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, XmlFile, GetFirstChildColumns, CoreTools::SimpleCSV::XMLNode)
