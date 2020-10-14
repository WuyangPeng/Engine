// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 14:02)

#include "Rendering/RenderingExport.h"

#include "MorphControllerImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::MorphControllerImpl
	::MorphControllerImpl(int numVertices, int numTargets,int numKeys) 
	: m_NumVertices{ numVertices },m_NumTargets{ numTargets },m_Vertices(numVertices * numTargets),
	  m_NumKeys{ numKeys }, m_Times(numKeys), m_Weights((numTargets - 1) * numKeys), m_LastIndex{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::MorphControllerImpl
	::MorphControllerImpl() noexcept
	: m_NumVertices{ 0 }, m_NumTargets{ 0 }, m_Vertices{}, m_NumKeys{ 0 },
	  m_Times{}, m_Weights{}, m_LastIndex{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::MorphControllerImpl
	::IsValid() const  noexcept
{
	if (0 <= m_NumVertices && 0 <= m_NumTargets && 0 <= m_NumKeys)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

int Rendering::MorphControllerImpl ::GetNumVertices() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumVertices;
}

int Rendering::MorphControllerImpl ::GetNumTargets() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumTargets;
}

int Rendering::MorphControllerImpl ::GetNumKeys() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumKeys;
}

const Rendering::MorphControllerImpl::APoint Rendering::MorphControllerImpl
	::GetVertices(int target, int vertices) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= target && target < m_NumTargets, "Ë÷Òý´íÎó£¡");
	RENDERING_ASSERTION_0(0 <= vertices && vertices < m_NumVertices, "Ë÷Òý´íÎó£¡");

	const int index = vertices + target * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");

	return m_Vertices[index];
}

float Rendering::MorphControllerImpl
	::GetTimes(int key) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= key && key < m_NumKeys, "Ë÷Òý´íÎó£¡");

	return m_Times[key];	
}

float Rendering::MorphControllerImpl
	::GetWeights(int key, int target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= target && target < m_NumTargets - 1, "Ë÷Òý´íÎó£¡");
	RENDERING_ASSERTION_0(0 <= key && key < m_NumKeys, "Ë÷Òý´íÎó£¡");

	const auto index = target + key * (m_NumTargets - 1);

	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Weights.size()), "Ë÷Òý´íÎó£¡");

	return m_Weights[index];
}

void Rendering::MorphControllerImpl
	::SetVertices(int target, int vertices, const APoint& point)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= target && target < m_NumTargets, "Ë÷Òý´íÎó£¡");
	RENDERING_ASSERTION_0(0 <= vertices && vertices < m_NumVertices, "Ë÷Òý´íÎó£¡");

	const auto index = vertices + target * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "Ë÷Òý´íÎó£¡");

	m_Vertices[index] = point;
}

void Rendering::MorphControllerImpl
	::SetTimes(int key, float times)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= key && key < m_NumKeys, "Ë÷Òý´íÎó£¡");

	m_Times[key] = times;
}

void Rendering::MorphControllerImpl
	::SetWeights(int key, int target, float weights) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= target && target < m_NumTargets - 1, "Ë÷Òý´íÎó£¡");
	RENDERING_ASSERTION_0(0 <= key && key < m_NumKeys, "Ë÷Òý´íÎó£¡");

	const auto index = target + key * (m_NumTargets - 1);

	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Weights.size()), "Ë÷Òý´íÎó£¡");

	m_Weights[index] = weights;
}

const Rendering::ControllerKeyInfo Rendering::MorphControllerImpl
	::GetKeyInfo(float ctrlTime) noexcept
{
	if (ctrlTime <= m_Times[0])
    {   
        m_LastIndex = 0;

		return ControllerKeyInfo{};
    }

	if (m_Times[m_NumKeys - 1] <= ctrlTime)
    {    
        m_LastIndex = m_NumKeys - 1;

		return ControllerKeyInfo{ 0.0f, m_LastIndex, m_LastIndex };
    }

 
	if (m_Times[m_LastIndex] < ctrlTime)
    {
		auto nextIndex = m_LastIndex + 1;
		while (m_Times[nextIndex] <= ctrlTime)
        {
            m_LastIndex = nextIndex;
            ++nextIndex;
        }
		      
		const auto normTime = (ctrlTime - m_Times[m_LastIndex]) / (m_Times[nextIndex] - m_Times[m_LastIndex]);

		return ControllerKeyInfo{ normTime, m_LastIndex, nextIndex };
    }
    else if (ctrlTime < m_Times[m_LastIndex])
    {
		auto nextIndex = m_LastIndex - 1;
        while (ctrlTime <= m_Times[nextIndex])
        {
            m_LastIndex = nextIndex;
            --nextIndex;
        }
 
		const auto normTime = (ctrlTime - m_Times[nextIndex]) / (m_Times[m_LastIndex] - m_Times[nextIndex]);

		return ControllerKeyInfo{ normTime, nextIndex, m_LastIndex };
    }
    else
    {
		return ControllerKeyInfo{ 0.0f, m_LastIndex, m_LastIndex };
    }
}

int Rendering::MorphControllerImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_NumVertices);

	size += CORE_TOOLS_STREAM_SIZE(m_NumTargets);
	size += CORE_TOOLS_STREAM_SIZE(m_NumKeys);
	size += boost::numeric_cast<int>(m_Vertices.size() * MATHEMATICS_STREAM_SIZE(m_Vertices[0]));
	size += m_NumKeys * CORE_TOOLS_STREAM_SIZE(m_Times[0]);
	size += boost::numeric_cast<int>(m_Weights.size() * CORE_TOOLS_STREAM_SIZE(m_Weights[0]));

	return size;
}

void Rendering::MorphControllerImpl
	::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target->Write(m_NumVertices);
	target->Write(m_NumTargets);
	target->Write(m_NumKeys);

	target->WriteAggregateContainerWithoutNumber(m_Vertices);
	//target.WriteWithoutNumber(m_NumKeys, &m_Times[0]);
	//target.WriteWithoutNumber(boost::numeric_cast<int>(m_Weights.size()), &m_Weights[0]);
}

void Rendering::MorphControllerImpl
	::Load(const CoreTools::BufferSourceSharedPtr& source )
{
	RENDERING_CLASS_IS_VALID_1;

	source->Read(m_NumVertices);
        source->Read(m_NumTargets);
        source->Read(m_NumKeys);

	const auto numTotalVertices = m_NumVertices * m_NumTargets;
	m_Vertices.resize(numTotalVertices);
        source->ReadAggregate(numTotalVertices, &m_Vertices[0]);

	m_Times.resize(m_NumKeys);
        source->Read(m_NumKeys, &m_Times[0]);

	const auto numTotalWeights = m_NumKeys * (m_NumTargets - 1);
	m_Weights.resize(numTotalWeights);
        source->Read(numTotalWeights, &m_Weights[0]);
}
 #include STSTEM_WARNING_POP