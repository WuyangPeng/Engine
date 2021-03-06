// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 14:10)

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

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
Rendering::SkinControllerImpl
	::SkinControllerImpl(int numVertices, int numBones)
	:m_NumVertices{ numVertices },m_NumBones{ numBones },m_Size{ numVertices * numBones },
	 m_Bones(numBones),m_Weights(m_Size),m_Offsets(m_Size)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SkinControllerImpl ::SkinControllerImpl() noexcept
    : m_NumVertices{ 0 }, m_NumBones{ 0 }, m_Size{ 0 },
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

int Rendering::SkinControllerImpl ::GetNumVertices() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumVertices;
}

int Rendering::SkinControllerImpl ::GetNumBones() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumBones;
}

const Rendering::ConstNodeSharedPtr Rendering::SkinControllerImpl
	::GetBones(int bonesIndex) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "��������");

	return m_Bones[bonesIndex];
}

float Rendering::SkinControllerImpl
	::GetWeights(int bonesIndex,int verticesIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "��������");
	RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < m_NumVertices, "��������");

	const auto index = verticesIndex + bonesIndex * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < m_Size, "��������");

	return m_Weights[index];
}

const Rendering::SkinControllerImpl::APoint Rendering::SkinControllerImpl
	::GetOffsets(int bonesIndex,int verticesIndex) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "��������");
	RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < m_NumVertices, "��������");

	const auto index = verticesIndex + bonesIndex * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < m_Size, "��������");

	return m_Offsets[index];
}

void Rendering::SkinControllerImpl
	::SetBones(int bonesIndex, const ConstNodeSharedPtr& node)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "��������");

	m_Bones[bonesIndex] = node;
}

void Rendering::SkinControllerImpl
	::SetBones(const std::vector<ConstNodeSharedPtr>& bones)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(boost::numeric_cast<int>(bones.size()) == m_NumBones, "����Ĺ�����С����");

	m_Bones = bones;
}

void Rendering::SkinControllerImpl
	::SetWeights(int bonesIndex,int verticesIndex, float weights)
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "��������");
	RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < m_NumVertices, "��������");

	const auto index = verticesIndex + bonesIndex * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < m_Size, "��������");

	m_Weights[index] = weights;
}

void Rendering::SkinControllerImpl
	::SetWeights(int bonesIndex, const vector<float>& weights) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(boost::numeric_cast<int>(weights.size()) == m_NumVertices, "����Ĺ�����С����");

	const auto beginIndex = bonesIndex * m_NumVertices;
	RENDERING_ASSERTION_0(0 <= beginIndex && beginIndex < m_Size, "��������");

	RENDERING_ASSERTION_0(0 <= beginIndex + m_NumVertices - 1 &&  beginIndex + m_NumVertices - 1 < m_Size, "��������");

	for (auto i = 0; i < m_NumVertices; ++i)
	{
		m_Weights[i + beginIndex] = weights[i];
	}
}

void Rendering::SkinControllerImpl
	::SetOffsets(int bonesIndex,int verticesIndex, const APoint& offsets) 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < m_NumBones, "��������");
	RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < m_NumVertices, "��������");

	const auto index = verticesIndex + bonesIndex * m_NumVertices;

	RENDERING_ASSERTION_0(0 <= index && index < m_Size, "��������");

	m_Offsets[index] = offsets;
}

void Rendering::SkinControllerImpl
	::SetOffsets(int bonesIndex, const vector<APoint>& offsets)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(boost::numeric_cast<int>(offsets.size()) == m_NumVertices, "����Ĺ�����С����");

	const auto beginIndex = bonesIndex * m_NumVertices;
	RENDERING_ASSERTION_0(0 <= beginIndex && beginIndex < m_Size, "��������");
	RENDERING_ASSERTION_0(0 <= beginIndex + m_NumVertices - 1 && beginIndex + m_NumVertices - 1 < m_Size, "��������");

	for (auto i = 0; i < m_NumVertices; ++i)
	{
		m_Offsets[i + beginIndex] = offsets[i];
	}
}

int Rendering::SkinControllerImpl
	::GetStreamingSize() const noexcept
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
	::Save(const CoreTools::BufferTargetSharedPtr& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target->Write(m_NumVertices);
	target->Write(m_NumBones);

//	target.WriteSharedPtrWithoutNumber(m_NumBones, &m_Bones[0]);
	//target.WriteWithoutNumber(m_Size, &m_Weights[0]);
	//target.WriteAggregateWithoutNumber(m_Size, &m_Offsets[0]);
}

void Rendering::SkinControllerImpl
	::Load(const CoreTools::BufferSourceSharedPtr& source) 
{
	RENDERING_CLASS_IS_VALID_1;

	source->Read(m_NumVertices);
        source->Read(m_NumBones);
	m_Size = m_NumVertices * m_NumBones;
	m_Bones.resize(m_NumBones);
	m_Weights.resize(m_Size);
	m_Offsets.resize(m_Size);
	 
//	source.ReadSharedPtr(m_NumBones, &m_Bones[0]);
        m_Weights = source->ReadVectorWithNumber<float>(m_Size);
        source->ReadAggregateContainer(m_Size, m_Offsets);
}

void Rendering::SkinControllerImpl
	::Link(const CoreTools::ObjectLinkSharedPtr& source) 
{
	RENDERING_CLASS_IS_VALID_1;
    CoreTools::DisableNoexcept();
    source;
    //	source.ResolveObjectConstSharedPtrLink(m_NumBones, &m_Bones[0]);
}

void Rendering::SkinControllerImpl
	::Register(const CoreTools::ObjectRegisterSharedPtr& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    target;
    CoreTools::DisableNoexcept();
	//target.RegisterSharedPtr(m_NumBones, &m_Bones[0]);
}
 
#include STSTEM_WARNING_POP