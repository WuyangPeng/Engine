// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:57)

#include "Rendering/RenderingExport.h"

#include "DlodNodeImpl.h"
#include "Rendering/DataTypes/Transform.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446) 
#include SYSTEM_WARNING_DISABLE(26455) 
#include SYSTEM_WARNING_DISABLE(26472) 
 
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
Rendering::DlodNodeImpl
	::DlodNodeImpl()
	: m_ModelLodCenter{}, m_WorldLodCenter{}, m_NumLevelsOfDetail{ 0 }, m_ModelMinDistance{}, m_ModelMaxDistance{}, m_WorldMinDistance{}, m_WorldMaxDistance{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::DlodNodeImpl
	::DlodNodeImpl(int numLevelsOfDetail)
	: m_ModelLodCenter{}, m_WorldLodCenter{}, m_NumLevelsOfDetail(numLevelsOfDetail), m_ModelMinDistance(numLevelsOfDetail),
	  m_ModelMaxDistance(numLevelsOfDetail),m_WorldMinDistance(numLevelsOfDetail), m_WorldMaxDistance(numLevelsOfDetail)
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::DlodNodeImpl
	::IsValid() const noexcept
{
	if (static_cast<size_t>(m_NumLevelsOfDetail) == m_ModelMinDistance.size() &&
		m_ModelMinDistance.size() == m_ModelMaxDistance.size() &&
		m_WorldMinDistance.size() == m_WorldMaxDistance.size() &&
		m_ModelMinDistance.size() == m_WorldMaxDistance.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::DlodNodeImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;

	source.ReadAggregate(m_ModelLodCenter);
	source.ReadAggregate(m_WorldLodCenter);
	source.Read(m_NumLevelsOfDetail);
	source.Read(m_ModelMinDistance);
	source.Read(m_ModelMaxDistance);
	source.Read(m_WorldMinDistance);
	source.Read(m_WorldMaxDistance);
}

void Rendering::DlodNodeImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target->WriteAggregate(m_ModelLodCenter);
        target->WriteAggregate(m_WorldLodCenter);
	target->Write(m_NumLevelsOfDetail);
        target->WriteContainerWithNumber(m_ModelMinDistance);
        target->WriteContainerWithNumber(m_ModelMaxDistance);
        target->WriteContainerWithNumber(m_WorldMinDistance);
        target->WriteContainerWithNumber(m_WorldMaxDistance);
}

int Rendering::DlodNodeImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_ModelLodCenter);

	size += CORE_TOOLS_STREAM_SIZE(m_WorldLodCenter);
	size += CORE_TOOLS_STREAM_SIZE(m_NumLevelsOfDetail);
	size += CORE_TOOLS_STREAM_SIZE(m_ModelMinDistance);
	size += CORE_TOOLS_STREAM_SIZE(m_ModelMaxDistance);
	size += CORE_TOOLS_STREAM_SIZE(m_WorldMinDistance);
	size += CORE_TOOLS_STREAM_SIZE(m_WorldMaxDistance);

	return size;
}

const Rendering::DlodNodeImpl::APoint Rendering::DlodNodeImpl
	::GetModelCenter() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	
	return m_ModelLodCenter;
}

const Rendering::DlodNodeImpl::APoint Rendering::DlodNodeImpl
	::GetWorldCenter() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_WorldLodCenter;
}

void Rendering::DlodNodeImpl
	::SetModelCenter(const APoint& modelCenter) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_ModelLodCenter = modelCenter;
}

int Rendering::DlodNodeImpl
	::GetNumLevelsOfDetail() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumLevelsOfDetail;
}

float Rendering::DlodNodeImpl
	::GetModelMinDistance( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumLevelsOfDetail,"索引越界");

	return m_ModelMinDistance[index];
}

float Rendering::DlodNodeImpl
	::GetModelMaxDistance( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumLevelsOfDetail,"索引越界");

	return m_ModelMaxDistance[index];
}

float Rendering::DlodNodeImpl
	::GetWorldMinDistance( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumLevelsOfDetail,"索引越界");

	return m_WorldMinDistance[index];
}

float Rendering::DlodNodeImpl
	::GetWorldMaxDistance( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumLevelsOfDetail,"索引越界");

	return m_WorldMaxDistance[index];
}

void Rendering::DlodNodeImpl
	::SetModelDistance( int index, float minDistance, float maxDistance )
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumLevelsOfDetail,"索引越界");

	m_ModelMinDistance[index] = minDistance;
	m_ModelMaxDistance[index] = maxDistance;
	m_WorldMinDistance[index] = minDistance;
	m_WorldMaxDistance[index] = minDistance;
}

void Rendering::DlodNodeImpl
	::SetWorldCenter( const FloatTransform& transform ) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_WorldLodCenter = transform * m_ModelLodCenter;
}

void Rendering::DlodNodeImpl
	::SetWorldDistance( float uniformScale ) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	for (auto i = 0; i < m_NumLevelsOfDetail; ++i)
	{
		m_WorldMinDistance[i] = uniformScale * m_ModelMinDistance[i];
		m_WorldMaxDistance[i] = uniformScale * m_ModelMaxDistance[i];
	}
}
#include STSTEM_WARNING_POP