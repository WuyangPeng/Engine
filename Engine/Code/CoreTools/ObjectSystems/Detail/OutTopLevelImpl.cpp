// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:50)

#include "CoreTools/CoreToolsExport.h"

#include "OutTopLevelImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

CoreTools::OutTopLevelImpl
	::OutTopLevelImpl()
	:m_TopLevel{}, m_UniqueID{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OutTopLevelImpl)

bool CoreTools::OutTopLevelImpl
	::IsTopLevel(uint64_t uniqueID) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_UniqueID.find(uniqueID) != m_UniqueID.cend();
}

int CoreTools::OutTopLevelImpl
	::GetTopLevelSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_TopLevel.size());
}

const CoreTools::ConstObjectInterfaceSmartPointer& CoreTools::OutTopLevelImpl
	::operator[](int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;
	CORE_TOOLS_ASSERTION_0(0 <= index && index < GetTopLevelSize(), "À˜“˝¥ÌŒÛ£°");

	return m_TopLevel[index];
}

void CoreTools::OutTopLevelImpl
	::Insert(const ObjectInterfaceSmartPointer& objectPtr)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_TopLevel.push_back(objectPtr);
}

void CoreTools::OutTopLevelImpl
	::SetUniqueID(int index, uint64_t uniqueID)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_TopLevel[index]->SetUniqueID(uniqueID);
	m_UniqueID.insert(uniqueID);
}

