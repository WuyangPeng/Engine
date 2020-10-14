// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 16:27)

#include "Rendering/RenderingExport.h"

#include "ParticlesImpl.h"
#include "Rendering/SceneGraph/Culler.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::vector;
#include "System/Helper/PragmaWarning.h" 
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::ParticlesImpl
	::ParticlesImpl( const std::vector<APoint>& positions,const std::vector<float>& sizes,float sizeAdjust )
	:m_Positions{ positions }, m_Sizes{ sizes }, m_SizeAdjust{ sizeAdjust }, m_NumActive{ boost::numeric_cast<int>(positions.size()) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ParticlesImpl
	::ParticlesImpl()
	:m_Positions{}, m_Sizes{}, m_SizeAdjust{ 1.0f }, m_NumActive{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::ParticlesImpl
	::IsValid() const noexcept
{
	if (0.0f < m_SizeAdjust && m_NumActive <= static_cast<int>(m_Positions.size()) &&
		m_Positions.size() == m_Sizes.size())
	{
		return true;
	}	
	else
	{
		return false;
	}		
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::ParticlesImpl
	::GetNumParticles() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Positions.size());
}

const Rendering::ParticlesImpl::APoint
	Rendering::ParticlesImpl
	::GetPosition( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Positions.size()), "索引越界！");
	 
	return m_Positions[index];
}

float Rendering::ParticlesImpl
	::GetSize(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Positions.size()),  "索引越界！");

	return m_Sizes[index];
}

void Rendering::ParticlesImpl
	::SetPosition(int index, const APoint& position)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Positions.size()),  "索引越界！");
	 
	m_Positions[index] = position;
}

void Rendering::ParticlesImpl
	::SetSize(int index, float size)
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Positions.size()), "索引越界！");

	m_Sizes[index] = size;
}

void Rendering::ParticlesImpl
	::SetSizeAdjust(float sizeAdjust)
{
	RENDERING_CLASS_IS_VALID_1;

	CoreTools::DisableNoexcept();

	if (0.0f < sizeAdjust)
	{
		m_SizeAdjust = sizeAdjust;
	}
	else
	{
		RENDERING_ASSERTION_1(false, "无效的大小调整参数。\n");
		m_SizeAdjust = 1.0f;
	}
}

float Rendering::ParticlesImpl
	::GetSizeAdjust() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SizeAdjust;
}

void Rendering::ParticlesImpl
	::SetNumActive(int numActive)
{
	RENDERING_CLASS_IS_VALID_1;

	auto numParticles = boost::numeric_cast<int>(m_Positions.size());
	if (0 <= numActive && numActive <= numParticles)
	{
		m_NumActive = numActive;
	}
	else
	{
		m_NumActive = numParticles;
	}
}

int Rendering::ParticlesImpl ::GetNumActive() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumActive;
}

void Rendering::ParticlesImpl ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_1;

	uint32_t size{ 0 };
	source->Read(size);

	m_Positions.resize(size);
	m_Sizes.resize(size);

	source->ReadAggregate(size, &m_Positions[0]);
	source->Read(size, &m_Sizes[0]);

	source->Read(m_SizeAdjust);
	source->Read(m_NumActive);
}

void Rendering::ParticlesImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = boost::numeric_cast<uint32_t>(m_Positions.size());

	target->Write(size);

	//target.WriteAggregateWithoutNumber(size,&m_Positions[0]);
        target->WriteContainerWithNumber(m_Sizes);

	target->Write(m_SizeAdjust);
	target->Write(m_NumActive);
}

int Rendering::ParticlesImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(int());
	size += boost::numeric_cast<int>(MATHEMATICS_STREAM_SIZE(m_Positions[0]) * m_Positions.size());
	size += boost::numeric_cast<int>(CORE_TOOLS_STREAM_SIZE(m_Sizes[0]) * m_Sizes.size());
	size += CORE_TOOLS_STREAM_SIZE(m_SizeAdjust);
	size += CORE_TOOLS_STREAM_SIZE(m_NumActive);

	return size;
}

float Rendering::ParticlesImpl
	::GetTrueSize(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SizeAdjust * GetSize(index);
}

#include STSTEM_WARNING_POP


