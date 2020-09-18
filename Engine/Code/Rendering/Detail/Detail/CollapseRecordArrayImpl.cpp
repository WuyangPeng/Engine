// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:44)

#include "Rendering/RenderingExport.h"

#include "CollapseRecordArrayImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

#include <algorithm>

using std::for_each;

Rendering::CollapseRecordArrayImpl
	::CollapseRecordArrayImpl() noexcept
	:m_CollapseRecord{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CollapseRecordArrayImpl
	::CollapseRecordArrayImpl(const std::vector<CollapseRecord>& collapseRecord)
	:m_CollapseRecord{ collapseRecord }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CollapseRecordArrayImpl)


int Rendering::CollapseRecordArrayImpl
	::GetNumRecords() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_CollapseRecord.size());
}

const std::vector<Rendering::CollapseRecord> Rendering::CollapseRecordArrayImpl
	::GetRecords() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_CollapseRecord;
}

const Rendering::CollapseRecord Rendering::CollapseRecordArrayImpl
	::GetRecord(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumRecords(), "À˜“˝¥ÌŒÛ£°");

	return m_CollapseRecord.at(index);
}

void Rendering::CollapseRecordArrayImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	int numRecords{ 0 };
	source.Read(numRecords);

	m_CollapseRecord.resize(numRecords);

	for_each(m_CollapseRecord.begin(),m_CollapseRecord.end(),std::bind(&CollapseRecord::Load,std::placeholders::_1, std::ref(source)));
}

void Rendering::CollapseRecordArrayImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target->Write(GetNumRecords());

	for_each(m_CollapseRecord.begin(),m_CollapseRecord.end(),std::bind(&CollapseRecord::Save, std::placeholders::_1, std::ref(target)));
}

int Rendering::CollapseRecordArrayImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto numRecords = boost::numeric_cast<int>(m_CollapseRecord.size());
	auto size = CORE_TOOLS_STREAM_SIZE(numRecords);

	for(const auto& record:m_CollapseRecord)
	{
		size += record.GetStreamingSize();
	}

	return size;
}
 