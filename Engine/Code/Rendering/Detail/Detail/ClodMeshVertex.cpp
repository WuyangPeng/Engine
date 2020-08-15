// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:40)

#include "Rendering/RenderingExport.h"

#include "ClodMeshVertex.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"

Rendering::ClodMeshVertex
	::ClodMeshVertex() noexcept
	:m_AdjEdges{}, m_AdjTriangles{}, m_Collapsible{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshVertex)

void Rendering::ClodMeshVertex
	::InsertTriangleKey(const TriangleKey& triangleKey)
{
	RENDERING_CLASS_IS_VALID_9;

	m_AdjTriangles.insert(triangleKey);
}

void Rendering::ClodMeshVertex
	::InsertEdgeKey(const EdgeKey& edgeKey)
{
	RENDERING_CLASS_IS_VALID_9;

	m_AdjEdges.insert(edgeKey);
}

void Rendering::ClodMeshVertex
	::SetCollapsible(bool collapsible) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Collapsible = collapsible;
}

int Rendering::ClodMeshVertex
	::GetTriangleKeySize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_AdjTriangles.size());
}

int Rendering::ClodMeshVertex
	::GetEdgeKeySize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_AdjEdges.size());
}

bool Rendering::ClodMeshVertex
	::IsCollapsible() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Collapsible;
}

Rendering::ClodMeshVertex::TriangleKeySetConstIter Rendering::ClodMeshVertex
	::GetTriangleKeyBegin() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_AdjTriangles.begin();
}

Rendering::ClodMeshVertex::TriangleKeySetConstIter Rendering::ClodMeshVertex
	::GetTriangleKeyEnd() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_AdjTriangles.end();
}

Rendering::ClodMeshVertex::EdgeKeySetConstIter Rendering::ClodMeshVertex
	::GetEdgeKeyBegin() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_AdjEdges.begin();
}

Rendering::ClodMeshVertex::EdgeKeySetConstIter Rendering::ClodMeshVertex
	::GetEdgeKeyEnd() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_AdjEdges.end();
}

void Rendering::ClodMeshVertex
	::EraseTriangleKey(const TriangleKey& triangleKey)
{
	RENDERING_CLASS_IS_VALID_9;

	m_AdjTriangles.erase(triangleKey);
}

void Rendering::ClodMeshVertex
	::EraseEdgeKey(const EdgeKey& edgeKey)
{
	RENDERING_CLASS_IS_VALID_9;

	m_AdjEdges.erase(edgeKey);
}
