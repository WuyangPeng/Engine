/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:27)

#include "CoreTools/CoreToolsExport.h"

#include "Document.h"
#include "Detail/DocumentImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

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

void CoreTools::SimpleCSV::Document::Save()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Save();
}

void CoreTools::SimpleCSV::Document::SaveAs(const std::string& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SaveAs(fileName);
}

std::string CoreTools::SimpleCSV::Document::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

CoreTools::SimpleCSV::Workbook CoreTools::SimpleCSV::Document::GetWorkbook() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetWorkbook();
}

std::string CoreTools::SimpleCSV::Document::GetProperty(Property prop) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetProperty(prop);
}

void CoreTools::SimpleCSV::Document::DeleteProperty(Property theProperty)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->DeleteProperty(theProperty);
}

std::string CoreTools::SimpleCSV::Document::ExtractXmlFromArchive(const std::string& path)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ExtractXmlFromArchive(path);
}

void CoreTools::SimpleCSV::Document::ExecuteCommand(const CommandSetSheetName& command)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ExecuteCommand(command);
}

void CoreTools::SimpleCSV::Document::ExecuteCommand(const CommandSetSheetIndex& command)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ExecuteCommand(command);
}

void CoreTools::SimpleCSV::Document::ExecuteCommand(const CommandResetCalcChain& command)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ExecuteCommand(command);
}

void CoreTools::SimpleCSV::Document::ExecuteCommand(const CommandAddSharedStrings& command)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ExecuteCommand(command);
}

void CoreTools::SimpleCSV::Document::ExecuteCommand(const CommandAddWorksheet& command)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ExecuteCommand(command);
}

void CoreTools::SimpleCSV::Document::ExecuteCommand(const CommandDeleteSheet& command)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ExecuteCommand(command);
}

void CoreTools::SimpleCSV::Document::ExecuteCommand(const CommandCloneSheet& command)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ExecuteCommand(command);
}

CoreTools::SimpleCSV::QuerySheetName CoreTools::SimpleCSV::Document::ExecuteQuery(const QuerySheetName& query) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->ExecuteQuery(query);
}

CoreTools::SimpleCSV::QuerySheetVisibility CoreTools::SimpleCSV::Document::ExecuteQuery(const QuerySheetVisibility& query) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->ExecuteQuery(query);
}

CoreTools::SimpleCSV::QuerySheetType CoreTools::SimpleCSV::Document::ExecuteQuery(const QuerySheetType& query) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->ExecuteQuery(query);
}

CoreTools::SimpleCSV::QuerySheetId CoreTools::SimpleCSV::Document::ExecuteQuery(const QuerySheetId& query) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->ExecuteQuery(query);
}

CoreTools::SimpleCSV::QuerySheetRelationshipId CoreTools::SimpleCSV::Document::ExecuteQuery(const QuerySheetRelationshipId& query) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->ExecuteQuery(query);
}

CoreTools::SimpleCSV::QuerySheetRelationshipTarget CoreTools::SimpleCSV::Document::ExecuteQuery(const QuerySheetRelationshipTarget& query) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->ExecuteQuery(query);
}

CoreTools::SimpleCSV::QuerySharedStrings CoreTools::SimpleCSV::Document::ExecuteQuery(const QuerySharedStrings& query) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->ExecuteQuery(query);
}

CoreTools::SimpleCSV::QueryXmlData CoreTools::SimpleCSV::Document::ExecuteQuery(const QueryXmlData& query) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->ExecuteQuery(query);
}

void CoreTools::SimpleCSV::Document::SetProperty(Property prop, const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetProperty(prop, value);
}
