// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 14:10)

#include "Rendering/RenderingExport.h"

#include "SkinControllerImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;

Rendering::SkinControllerImpl
	::SkinControllerImpl(int numVertices, int numBones)
	:m_NumVertices{ numVertices },m_NumBones{ numBones },m_Size{ numVertices * numBones },
	 m_Bones(numBones),m_Weights(m_Size),m_Offsets(m_Size)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SkinControllerImpl
	::SkinControllerImpl() 
	:m_NumVertices{ 0 }, m_NumBones{ 0 }, m_Size{ 0 },
	 m_Bones{}, m_Weights{}, m_Offsets{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::SkinControllerImpl
	::IsValid() const noexcept
{
	if (0 <= m_Size && m_NumBones * m_NumVertices == m_Size)
		return true;
	else		
		return false;		
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::SkinControllerImpl
	::GetNumVertices() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumVertices;
}

int Rendering::SkinControllerImpl
	::GetNumBones() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumBones;
}

const Rendering::ConstNodeSmartPointer Rendering::SkinControllerImpl
	::GetBones(int bonesIndex) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "Ë÷Òý´íÎó£¡");

	return m_Bones[bonesIndex];
}

float Rendering::SkinControllerImpl
	::GetWeights(int bonesIndex,int verticesIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "Ë÷Òý´íÎó£¡");
	RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < m_NumVertices, "Ë÷Òý´íÎó£¡");

	auto index = verticesIndex + bonesIndex * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < m_Size, "Ë÷Òý´íÎó£¡");

	return m_Weights[index];
}

const Rendering::SkinControllerImpl::APoint Rendering::SkinControllerImpl
	::GetOffsets(int bonesIndex,int verticesIndex) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "Ë÷Òý´íÎó£¡");
	RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < m_NumVertices, "Ë÷Òý´íÎó£¡");

	auto index = verticesIndex + bonesIndex * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < m_Size, "Ë÷Òý´íÎó£¡");

	return m_Offsets[index];
}

void Rendering::SkinControllerImpl
	::SetBones(int bonesIndex, const ConstNodeSmartPointer& node)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "Ë÷Òý´íÎó£¡");

	m_Bones[bonesIndex] = node;
}

void Rendering::SkinControllerImpl
	::SetBones(const std::vector<ConstNodeSmartPointer>& bones)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(boost::numeric_cast<int>(bones.size()) == m_NumBones, "´«ÈëµÄ¹Ç÷À´óÐ¡´íÎó");

	m_Bones = bones;
}

void Rendering::SkinControllerImpl
	::SetWeights(int bonesIndex,int verticesIndex, float weights)
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "Ë÷Òý´íÎó£¡");
	RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < m_NumVertices, "Ë÷Òý´íÎó£¡");

	auto index = verticesIndex + bonesIndex * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < m_Size, "Ë÷Òý´íÎó£¡");

	m_Weights[index] = weights;
}

void Rendering::SkinControllerImpl
	::SetWeights(int bonesIndex, const vector<float>& weights) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(boost::numeric_cast<int>(weights.size()) == m_NumVertices, "´«ÈëµÄ¹Ç÷À´óÐ¡´íÎó");

	auto beginIndex = bonesIndex * m_NumVertices;
	RENDERING_ASSERTION_0(0 <= beginIndex && beginIndex < m_Size, "Ë÷Òý´íÎó£¡");

	RENDERING_ASSERTION_0(0 <= beginIndex + m_NumVertices - 1 &&  beginIndex + m_NumVertices - 1 < m_Size, "Ë÷Òý´íÎó£¡");

	for (auto i = 0; i < m_NumVertices; ++i)
	{
		m_Weights[i + beginIndex] = weights[i];
	}
}

void Rendering::SkinControllerImpl
	::SetOffsets(int bonesIndex,int verticesIndex, const APoint& offsets) 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "Ë÷Òý´íÎó£¡");
	RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < m_NumVertices, "Ë÷Òý´íÎó£¡");

	auto index = verticesIndex + bonesIndex * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < m_Size, "Ë÷Òý´íÎó£¡");

	m_Offsets[index] = offsets;
}

void Rendering::SkinControllerImpl
	::SetOffsets(int bonesIndex, const vector<APoint>& offsets)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(boost::numeric_cast<int>(offsets.size()) == m_NumVertices, "´«ÈëµÄ¹Ç÷À´óÐ¡´íÎó");

	auto beginIndex = bonesIndex * m_NumVertices;
	RENDERING_ASSERTION_0(0 <= beginIndex && beginIndex < m_Size, "Ë÷Òý´íÎó£¡");
	RENDERING_ASSERTION_0(0 <= beginIndex + m_NumVertices - 1 && beginIndex + m_NumVertices - 1 < m_Size, "Ë÷Òý´íÎó£¡");

	for (auto i = 0; i < m_NumVertices; ++i)
	{
		m_Offsets[i + beginIndex] = offsets[i];
	}
}

int Rendering::SkinControllerImpl
	::GetStreamingSize() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_NumVertices);
	size += CORE_TOOLS_STREAM_SIZE(m_NumBones);
	 
	size += m_NumBones * RENDERING_STREAM_SIZE(m_Bones[0]);
	size += m_Size * MATHEMATICS_STREAM_SIZE(m_Weights[0]);
	size += m_Size * CORE_TOOLS_STREAM_SIZE(m_Offsets[0]);	

	return size;
}

void Rendering::SkinControllerImpl
	::Save(CoreTools::BufferTarget& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target.Write(m_NumVertices);
	target.Write(m_NumBones);

	target.WriteSmartPointerWithoutNumber(m_NumBones, &m_Bones[0]);
	target.WriteWithoutNumber(m_Size, &m_Weights[0]);
	target.WriteAggregateWithoutNumber(m_Size, &m_Offsets[0]);
}

void Rendering::SkinControllerImpl
	::Load(CoreTools::BufferSource& source) 
{
	RENDERING_CLASS_IS_VALID_1;

	source.Read(m_NumVertices);
	source.Read(m_NumBones);
	m_Size = m_NumVertices * m_NumBones;
	m_Bones.resize(m_NumBones);
	m_Weights.resize(m_Size);
	m_Offsets.resize(m_Size);
	 
	source.ReadSmartPointer(m_NumBones, &m_Bones[0]);
	source.Read(m_Size, &m_Weights[0]);
	source.ReadAggregate(m_Size, &m_Offsets[0]);	
}

void Rendering::SkinControllerImpl
	::Link(CoreTools::ObjectLink& source) 
{
	RENDERING_CLASS_IS_VALID_1;

	source.ResolveObjectConstSmartPointerLink(m_NumBones, &m_Bones[0]);
}

void Rendering::SkinControllerImpl
	::Register(CoreTools::ObjectRegister& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target.RegisterSmartPointer(m_NumBones, &m_Bones[0]);
}
 
