///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:07)

#include "CoreTools/CoreToolsExport.h"

#include "Document.h"
#include "Detail/DocumentImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::SimpleCSV::Document::DocumentSharedPtr CoreTools::SimpleCSV::Document::Create(const std::string& docPath)
{
    auto document = make_shared<ClassType>(DocumentCreate::Init, docPath);

    document->impl->Create(document);

    return document;
}

CoreTools::SimpleCSV::Document::DocumentSharedPtr CoreTools::SimpleCSV::Document::Open(const std::string& docPath)
{
    auto document = make_shared<ClassType>(DocumentCreate::Init, docPath);

    document->impl->Open(document);

    return document;
}

CoreTools::SimpleCSV::Document::Document(DocumentCreate documentCreate, const std::string& docPath)
    : impl{ docPath }
{
    System::UnusedFunction(documentCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, Document)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Document, Save, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, SaveAs, std::string, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Document, GetName, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Document, GetWorkbook, CoreTools::SimpleCSV::Workbook)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, Document, GetProperty, Property, std::string)

void CoreTools::SimpleCSV::Document::SetProperty(Property prop, const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetProperty(prop, value);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, Document, DeleteProperty, Property, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteCommand, CommandSetSheetName, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteCommand, CommandSetSheetIndex, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteCommand, CommandResetCalcChain, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteCommand, CommandAddSharedStrings, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteCommand, CommandAddWorksheet, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteCommand, CommandDeleteSheet, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteCommand, CommandCloneSheet, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteQuery, QuerySheetName, CoreTools::SimpleCSV::QuerySheetName)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteQuery, QuerySheetVisibility, CoreTools::SimpleCSV::QuerySheetVisibility)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteQuery, QuerySheetType, CoreTools::SimpleCSV::QuerySheetType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteQuery, QuerySheetId, CoreTools::SimpleCSV::QuerySheetId)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteQuery, QuerySheetRelsId, CoreTools::SimpleCSV::QuerySheetRelsId)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteQuery, QuerySheetRelsTarget, CoreTools::SimpleCSV::QuerySheetRelsTarget)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteQuery, QuerySharedStrings, CoreTools::SimpleCSV::QuerySharedStrings)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExecuteQuery, QueryXmlData, CoreTools::SimpleCSV::QueryXmlData)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Document, ExtractXmlFromArchive, std::string, std::string)