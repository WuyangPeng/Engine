// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:35)

#include "Rendering/RenderingExport.h"

#include "ClodMeshEdge.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26472)
Rendering::ClodMeshEdge
	::ClodMeshEdge() noexcept
	:m_AdjTriangles{}, m_MinHeapRecordIndex{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshEdge)

void Rendering::ClodMeshEdge
	::InsertTriangleKey(const TriangleKey& triangleKey)
{
	RENDERING_CLASS_IS_VALID_9;

	m_AdjTriangles.insert(triangleKey);
}

int Rendering::ClodMeshEdge
	::GetTriangleKeySize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return static_cast<int>(m_AdjTriangles.size());
}

Rendering::ClodMeshEdge::TriangleKeySetConstIter Rendering::ClodMeshEdge
	::GetTriangleKeyBegin() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_AdjTriangles.begin();
}

Rendering::ClodMeshEdge::TriangleKeySetConstIter Rendering::ClodMeshEdge
	::GetTriangleKeyEnd() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_AdjTriangles.end();
}

int Rendering::ClodMeshEdge
	::GetMinHeapRecordIndex() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_MinHeapRecordIndex;
}

void Rendering::ClodMeshEdge
	::SetMinHeapRecordIndex(int index) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_MinHeapRecordIndex = index;
}

void Rendering::ClodMeshEdge
	::EraseTriangleKey(const TriangleKey& triangleKey)
{
	RENDERING_CLASS_IS_VALID_9;

	m_AdjTriangles.erase(triangleKey);
}

const Rendering::ClodMeshEdge::TriangleKey Rendering::ClodMeshEdge
	::GetBeginTriangleKey() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(!m_AdjTriangles.empty(), "�����μ�ֵ���ϲ���Ϊ�գ�");

	return *m_AdjTriangles.begin();
}

const Rendering::ClodMeshEdge::TriangleKey Rendering::ClodMeshEdge
	::GetEndTriangleKey() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(!m_AdjTriangles.empty(), "�����μ�ֵ���ϲ���Ϊ�գ�");

	return *m_AdjTriangles.rbegin();
}
#include STSTEM_WARNING_POP