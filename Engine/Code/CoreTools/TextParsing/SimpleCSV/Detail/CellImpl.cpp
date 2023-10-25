///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 15:25)

#include "CoreTools/CoreToolsExport.h"

#include "CellImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::CellImpl::CellImpl(DisableNotThrow disableNotThrow)
    : document{}, cellNode{}, sharedStrings{}, valueProxy{ CellValueProxy::CreateEmpty() }, isNull{ true }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellImpl::CellImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& cellNode, const SharedStringsSharedPtr& sharedStrings)
    : document{ document }, cellNode{ cellNode }, sharedStrings{ sharedStrings }, valueProxy{ CellValueProxy::CreateEmpty() }, isNull{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::SimpleCSV::CellImpl::Init(const CellSharedPtr& cell)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    valueProxy = CellValueProxy{ cell };
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellImpl);

CoreTools::SimpleCSV::CellImpl::operator bool() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return !document.expired() && cellNode;
}

CoreTools::SimpleCSV::CellValueProxy& CoreTools::SimpleCSV::CellImpl::GetValue() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(CellValueProxy&, GetValue);
}

const CoreTools::SimpleCSV::CellValueProxy& CoreTools::SimpleCSV::CellImpl::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return valueProxy;
}

CoreTools::SimpleCSV::CellReference CoreTools::SimpleCSV::CellImpl::GetCellReference() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckDocument();

    return CellReference{ cellNode.attribute(TextParsing::gAttributeR.data()).value() };
}

bool CoreTools::SimpleCSV::CellImpl::HasFormula() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetFormulaNode() != nullptr;
}

std::string CoreTools::SimpleCSV::CellImpl::GetFormula() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto formulaNode = GetFormulaNode();

    if (const auto formula = formulaNode.text().get(); formula != nullptr)
    {
        return formula;
    }
    else
    {
        return std::string{};
    }
}

void CoreTools::SimpleCSV::CellImpl::SetFormula(const std::string& newFormula)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto formulaNode = GetFormulaNode();

    if (!formulaNode)
    {
        formulaNode = AppendFormulaChild();
    }

    formulaNode.text().set(newFormula.c_str());
}

bool CoreTools::SimpleCSV::CellImpl::IsSame(const CellImpl& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (isNull && rhs.isNull)
    {
        return true;
    }
    else if (!isNull && !rhs.isNull)
    {
        CheckDocument();
        rhs.CheckDocument();

        return cellNode == rhs.cellNode;
    }
    else
    {
        return false;
    }
}

CoreTools::SimpleCSV::CellImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::CellImpl::GetSharedStrings() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("sharedStrings已被释放。"s))
    }

    return sharedStringsSharedPtr;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellImpl::GetXMLNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckDocument();

    return cellNode;
}

void CoreTools::SimpleCSV::CellImpl::CheckDocument() const
{
    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s))
    }
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellImpl::GetFormulaNode() const
{
    CheckDocument();

    return cellNode.child("f");
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellImpl::AppendFormulaChild()
{
    cellNode.append_child("f");

    return cellNode.child("f");
}
