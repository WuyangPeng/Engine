///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/09 14:09)

#include "CoreTools/CoreToolsExport.h"

#include "CellImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

using std::string;
using namespace std::literals;

CoreTools::SimpleCSV::CellImpl::CellImpl(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : m_Document{}, m_CellNode{}, m_SharedStrings{}, m_ValueProxy{ CellValueProxy::CreateEmpty() }, isNull{ true }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellImpl::CellImpl(const CellSharedPtr& cell, const ConstXMLDocumentSharedPtr& document, const XMLNode& cellNode, const SharedStringsSharedPtr& sharedStrings)
    : m_Document{ document }, m_CellNode{ cellNode }, m_SharedStrings{ sharedStrings }, m_ValueProxy{ cell }, isNull{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::SimpleCSV::CellImpl::Init(const CellSharedPtr& cell, const ConstXMLDocumentSharedPtr& document, const XMLNode& cellNode, const SharedStringsSharedPtr& sharedStrings)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Document = document;
    m_CellNode = cellNode;
    m_SharedStrings = sharedStrings;
    m_ValueProxy = CellValueProxy{ cell };
    isNull = false;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellImpl);

CoreTools::SimpleCSV::CellImpl::operator bool() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return !m_Document.expired() && m_CellNode;
}

CoreTools::SimpleCSV::CellValueProxy& CoreTools::SimpleCSV::CellImpl::GetValue() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(CellValueProxy&, GetValue);
}

const CoreTools::SimpleCSV::CellValueProxy& CoreTools::SimpleCSV::CellImpl::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_ValueProxy;
}

CoreTools::SimpleCSV::CellReference CoreTools::SimpleCSV::CellImpl::GetCellReference() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckDocument();

    return CellReference{ m_CellNode.attribute(TextParsing::g_AttributeR.data()).value() };
}

bool CoreTools::SimpleCSV::CellImpl::HasFormula() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetFormulaNode() != nullptr;
}

string CoreTools::SimpleCSV::CellImpl::GetFormula() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto formulaNode = GetFormulaNode();
    auto formula = formulaNode.text().get();
    if (formula != nullptr)
    {
        return formula;
    }
    else
    {
        return ""s;
    }
}

void CoreTools::SimpleCSV::CellImpl::SetFormula(const string& newFormula)
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

        return m_CellNode == rhs.m_CellNode;
    }
    else
    {
        return false;
    }
}

CoreTools::SimpleCSV::CellImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::CellImpl::GetSharedStrings() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto sharedStrings = m_SharedStrings.lock();

    if (!sharedStrings)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("sharedStrings已被释放。"s));
    }

    return sharedStrings;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellImpl::GetXMLNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckDocument();

    return m_CellNode;
}

// private
void CoreTools::SimpleCSV::CellImpl::CheckDocument() const
{
    if (m_Document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }
}

// private
CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellImpl::GetFormulaNode() const
{
    CheckDocument();

    return m_CellNode.child("f");
}

// private
CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellImpl::AppendFormulaChild()
{
    m_CellNode.append_child("f");

    return m_CellNode.child("f");
}
