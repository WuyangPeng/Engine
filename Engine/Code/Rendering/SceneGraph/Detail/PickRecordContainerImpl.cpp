// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 16:33)

#include "Rendering/RenderingExport.h"

#include "PickRecordContainerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

Rendering::PickRecordContainerImpl
	::PickRecordContainerImpl()
	:m_PickRecord{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRecordContainerImpl)

void Rendering::PickRecordContainerImpl
	::InsertPickRecord(const PickRecord& pickRecord)
{
	RENDERING_CLASS_IS_VALID_9;

	m_PickRecord.push_back(pickRecord);
}

int Rendering::PickRecordContainerImpl
	::GetSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_PickRecord.size());
}

const Rendering::PickRecord Rendering::PickRecordContainerImpl
	::GetPickRecord(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetSize(), "À˜“˝¥ÌŒÛ£°");

	return m_PickRecord[index];
}

void Rendering::PickRecordContainerImpl
	::InsertPickRecord(const PickRecordContainerImpl& pickRecordContainerImpl)
{
	RENDERING_CLASS_IS_VALID_9;

	m_PickRecord.insert(m_PickRecord.end(), pickRecordContainerImpl.m_PickRecord.begin(), pickRecordContainerImpl.m_PickRecord.end());
}

bool Rendering::PickRecordContainerImpl
	::IsEmpty() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_PickRecord.empty();
}
