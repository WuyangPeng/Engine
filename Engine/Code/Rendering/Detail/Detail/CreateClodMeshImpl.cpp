// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:51)

#include "Rendering/RenderingExport.h"

#include "CreateClodMeshImpl.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::set;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
Rendering::CreateClodMeshImpl
	::CreateClodMeshImpl(TrianglesMeshSharedPtr mesh)
	: m_ClodMeshTriangleMesh{ mesh }, m_Graph{ m_ClodMeshTriangleMesh.GetNumVertices(),m_ClodMeshTriangleMesh.GetNumIndices() }, m_Collapses{}, m_CollapseRecord{}
{
	Compute();

	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CreateClodMeshImpl)

Rendering::CollapseRecordArraySharedPtr Rendering::CreateClodMeshImpl
	::GetCollapseRecordArray() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return CollapseRecordArraySharedPtr{ std::make_shared< CollapseRecordArray>(m_CollapseRecord) };
}

// private
void Rendering::CreateClodMeshImpl
	::Compute()
{	
	// 确保顶点和索引缓冲区是有效在边缘折叠。
    if (!m_ClodMeshTriangleMesh.ValidBuffers())
    {        
        return;
    }

  	// 创建顶点——边——三角形图形
	CreateVertexEdgeTriangleGraph();

	// 顶点是边边界的端点，或是非流形，
	// 它们是由两个边三角形连接的组件共享，不能允许崩塌。
	m_Graph.ClassifyCollapsibleVertices();

    // 更新边的堆。
	for (auto iter = m_Graph.GetEdgeMapBegin(),end = m_Graph.GetEdgeMapEnd(); iter != end;++iter)
	{
		RENDERING_ASSERTION_2(m_Graph.IsUniqueIndexValid(iter->second.GetMinHeapRecordIndex()),"意外情况。\n");
		m_Graph.UpdateEdgeHeap(iter->second.GetMinHeapRecordIndex(), ComputeMetric(iter->first));
	} 

	while (0 < m_Graph.GetMinHeapElementsNumber())
    {        
		auto record = m_Graph.GetMinHeapMinimum();
		auto ekey = record.GetGenerator();
		auto metric = record.GetValue();

        if (Mathematics::FloatMath::Approximate(metric,Mathematics::FloatMath::sm_MaxReal,1e-8f))
        {
       		// 所有剩余的堆元素都是无限的值。
            if (!ValidResults())
            {           
                return;
            }
            break;
        }

		auto indexThrow = CanCollapse(ekey);
        if (0 <= indexThrow)
        {
            Collapse(ekey, indexThrow);
        }
        else
        {
			m_Graph.UpdateEdgeHeapToMaxReal(ekey);
        }
    }

	// 重新排序顶点缓冲区，顶点在由边崩塌去除的时间除序排列。
	// 例如，第一个被边崩塌移除的顶点是在缓冲器中的最后一个顶点。
	// 重新排序索引缓冲区，三角形在由边崩塌去除的时间除序排列。
	// 例如，第一个被边崩塌移除的三角形是在缓冲器中的最后一个三角形。
    ReorderBuffers();

	// 崩塌记录存储增量变化用于动态LOD变化。
    ComputeRecords();
}

// private
void Rendering::CreateClodMeshImpl
	::CreateVertexEdgeTriangleGraph()
{
	auto currentIndex = m_ClodMeshTriangleMesh.GetIndexBufferReadOnlyData();

	for (auto trianglesIndex = 0; trianglesIndex < m_ClodMeshTriangleMesh.GetNumTriangles(); ++trianglesIndex)
	{
		auto first = *currentIndex++;
		auto second = *currentIndex++;
		auto third = *currentIndex++;
		TriangleKey triangleKey{ first, second, third };

		m_Graph.InsertTriangle(triangleKey, trianglesIndex);
	}
}


float Rendering::CreateClodMeshImpl
	::ComputeMetric(const EdgeKey& edgeKey)
{
	// 这些权重可以调整，以任何你喜欢的值。
    constexpr auto lengthWeight = 10.0f;
	constexpr auto angleWeight = 1.0f;

	// 计算的边缘指标。只有多种的边缘（正好两个三角形共享边）被允许崩塌。
	const auto& edge = m_Graph.GetClodMeshEdge(edgeKey);
    if (edge.GetTriangleKeySize() == 2)
    {
        // 长度的贡献。
		auto end0 = m_ClodMeshTriangleMesh.GetPosition(edgeKey.GetKey(0));
		auto end1 = m_ClodMeshTriangleMesh.GetPosition(edgeKey.GetKey(1));
		auto difference = end1 - end0;
        float metric = lengthWeight * Mathematics::FloatVector3DTools::VectorMagnitude(difference);

        // 角度/区域的贡献。
		auto triangleKey = edge.GetBeginTriangleKey();
		auto beginNormal = GetNormal(triangleKey);

		triangleKey = edge.GetEndTriangleKey();
		auto endNormal = GetNormal(triangleKey);

		auto cross = Mathematics::FloatVector3DTools::CrossProduct(beginNormal,endNormal);
		metric += angleWeight * Mathematics::FloatVector3DTools::VectorMagnitude(cross);

        return metric;
    }

	// 边的边界（含有边的一个三角形）和交接边缘（3个或更多个三角形共用边）不允许崩塌。
    return Mathematics::FloatMath::sm_MaxReal;
}


const Mathematics::FloatVector3D Rendering::CreateClodMeshImpl
	::GetNormal( const TriangleKey& triangleKey )
{
	auto position0 = m_ClodMeshTriangleMesh.GetPosition(triangleKey.GetKey(0));
	auto position1 = m_ClodMeshTriangleMesh.GetPosition(triangleKey.GetKey(1));
	auto position2 = m_ClodMeshTriangleMesh.GetPosition(triangleKey.GetKey(2));
	auto edgeDirection0 = position1 - position0;
	auto edgeDirection1 = position2 - position0;

	return Mathematics::FloatVector3DTools::CrossProduct(edgeDirection0,edgeDirection1);
}

int Rendering::CreateClodMeshImpl
	::CanCollapse(const EdgeKey& edgeKey)
{
	const auto& vertex0 = m_Graph.GetClodMeshVertex(edgeKey.GetKey(0));
	const auto& vertex1 = m_Graph.GetClodMeshVertex(edgeKey.GetKey(1));

	// 测试是否可崩塌
	auto indexKeep = 0;
	auto indexThrow = 0;
    if (vertex0.IsCollapsible())
    {
        indexKeep = 1;
        indexThrow = 0;
    }
	else if (vertex1.IsCollapsible())
    {
        indexKeep = 0;
        indexThrow = 1;
    }
    else
    {
        return -1;
    }

	// 如果它导致网状“折叠”崩塌不能被允许的。
	auto vKeep = edgeKey.GetKey(indexKeep);
	auto vThrow = edgeKey.GetKey(indexThrow);
	const auto& vertexThrow = m_Graph.GetClodMeshVertex(vThrow);
	auto positionKeep = m_ClodMeshTriangleMesh.GetPosition(vKeep);
	auto positionThrow = m_ClodMeshTriangleMesh.GetPosition(vThrow);
	     
	for (auto iter = vertexThrow.GetTriangleKeyBegin(), end = vertexThrow.GetTriangleKeyEnd(); iter != end;++iter)
    {
		const auto& trianglKey = *iter;

		// 计算为（使用CCW逆时针顺序）由三角形的顶点确定的平面的法线向量。
		auto middleIndex = trianglKey.GetKeyIndex(vThrow);
		auto minusIndex = (middleIndex + 2) % 3;
		auto plusIndex = (middleIndex + 1) % 3;
		auto positionMinus = m_ClodMeshTriangleMesh.GetPosition(trianglKey.GetKey(minusIndex));
		auto positionPlus = m_ClodMeshTriangleMesh.GetPosition(trianglKey.GetKey(plusIndex));
		auto dirPlus = positionPlus - positionThrow;
		auto dirMinus = positionMinus - positionThrow;
		auto normalThrow = Mathematics::FloatVector3DTools::CrossProduct(dirPlus,dirMinus);

		// 现在由keep位置代替throw位置
		// 并计算由三角形的顶点确定的平面的法线向量（使用CCW顺序）。
        dirPlus = positionPlus - positionKeep;
        dirMinus = positionMinus - positionKeep;
		auto normalKeep = Mathematics::FloatVector3DTools::CrossProduct(dirPlus,dirMinus);

		// 当两个法线之间的角度是大于90度时崩塌是不允许的。
		if (Mathematics::FloatVector3DTools::DotProduct(normalThrow,normalKeep) < 0.0f)
        {
            return -1;
        }
    }

    return indexThrow;
}

void Rendering::CreateClodMeshImpl
	::Collapse(const EdgeKey& edgeKey, int indexThrow)
{
	// 得到的边的端点被崩塌。
	auto vKeep = edgeKey.GetKey(1 - indexThrow);
	auto vThrow = edgeKey.GetKey(indexThrow);
	auto vertexThrow = m_Graph.GetClodMeshVertex(vThrow);
	ClodMeshCollapseInfo collapse{ vKeep, vThrow };

	// 删除所有三角形共享throw顶点。
	// 创建keep顶点的三角形插入后对着的边。
	// 相对的边被保存，保存的顶点顺序。
	// 这个信息可以更容易地确定，当新的三角形被插入图形堆，边必须被更新。
	using Tuple = CoreTools::Tuple<3,int>;
    set<Tuple> keepInfo;
     
	for (auto iter = vertexThrow.GetTriangleKeyBegin(),end = vertexThrow.GetTriangleKeyEnd(); iter != end; ++iter)
    {
            const auto& triangleKey = *iter;

		auto keyIndex = triangleKey.GetKeyIndex(vThrow);
    
        RENDERING_ASSERTION_2(keyIndex < 3, "意外情况。\n");

		CoreTools::Tuple<3, int> tuple;
        tuple[0] = triangleKey.GetKey((keyIndex + 1) % 3);
		tuple[1] = triangleKey.GetKey((keyIndex + 2) % 3);
		tuple[2] = m_Graph.GetTriangle(triangleKey);

        if (tuple[0] != vKeep && tuple[1] != vKeep)
        {
            keepInfo.insert(tuple);
        }
        else
        {
            if (collapse.GetTThrow0() == -1)
            {
                collapse.SetTThrow0(tuple[2]);
            }
            else
            {
				RENDERING_ASSERTION_2(collapse.GetTThrow1() == -1, "意外情况。\n");
                collapse.SetTThrow1(tuple[2]);
                m_Collapses.push_back(collapse);
            }
        }

		m_Graph.RemoveTriangle(triangleKey);
    }

	// 将共享keep顶点插入新的三角形。保存需要在堆要更新的边。
	using EdgeKeySet = std::set<EdgeKey>;
    EdgeKeySet needUpdate;	
 
	for(const auto& tuple:keepInfo)
    {
		auto v0 = vKeep;
		auto v1 = tuple[0];
		auto v2 = tuple[1];
		auto triangle = tuple[2];
		m_Graph.InsertTriangle(TriangleKey(v0, v1, v2), triangle);
        needUpdate.insert(EdgeKey(v0, v1));
        needUpdate.insert(EdgeKey(v1, v2));
        needUpdate.insert(EdgeKey(v2, v0));
    }

    // 更新崩塌边的那些堆。   
	for(const auto& updateKey:needUpdate)
    {
		const auto& clodMeshEdge = m_Graph.GetClodMeshEdge(updateKey);
 
		RENDERING_ASSERTION_2(m_Graph.IsUniqueIndexValid(clodMeshEdge.GetMinHeapRecordIndex()), "意外情况。\n");
	
		m_Graph.UpdateEdgeHeap(clodMeshEdge.GetMinHeapRecordIndex(), ComputeMetric(updateKey));
    }
}

bool Rendering::CreateClodMeshImpl
	::ValidResults()
{
	return m_Graph.ValidResults(m_ClodMeshTriangleMesh.GetNumTriangles(),m_ClodMeshTriangleMesh.GetNumVertices(), static_cast<int>(m_Collapses.size()));
}

void Rendering::CreateClodMeshImpl
	::ReorderBuffers()
{
	// 构建老顶点顺序和新的顶点顺序之间的映射。
	std::vector<int> vertexNewToOld(m_ClodMeshTriangleMesh.GetNumVertices());
	std::vector<int> vertexOldToNew(m_ClodMeshTriangleMesh.GetNumVertices());
	int vertexNew = m_ClodMeshTriangleMesh.GetNumVertices() - 1;

	for(const auto& collapse:m_Collapses)
    {
		int vertexOld = collapse.GetVThrow();
        vertexNewToOld[vertexNew] = vertexOld;
        vertexOldToNew[vertexOld] = vertexNew--;
    }
	
	for (auto iter = m_Graph.GetVerticesRemainingBegin(), end = m_Graph.GetVerticesRemainingEnd(); iter != end; ++iter)
    {
		int vertexOld = *iter;
        vertexNewToOld[vertexNew] = vertexOld;
        vertexOldToNew[vertexOld] = vertexNew--;
    }

    // 重新排序顶点缓冲区。
	auto oldData = m_ClodMeshTriangleMesh.GetVertexBufferReadOnlyData();
	auto stride = m_ClodMeshTriangleMesh.GetStride();
	vector<char> newData(m_ClodMeshTriangleMesh.GetNumVertices() * stride);
     
	for (auto vertexIndex = 0; vertexIndex < m_ClodMeshTriangleMesh.GetNumVertices(); ++vertexIndex)
    {
		auto srcVertex = oldData + stride * vertexNewToOld[vertexIndex];
        memcpy(&newData[stride * vertexIndex], srcVertex, stride);		 
    }
	m_ClodMeshTriangleMesh.SetNewVertexBufferData(newData);  


	// 构建三角形旧顺序和新的三角形顺序的对应关系。
	vector<int> triangleNewToOld(m_ClodMeshTriangleMesh.GetNumTriangles());
	auto trianglesNew = m_ClodMeshTriangleMesh.GetNumTriangles() - 1;

    for(const auto& collapse:m_Collapses)
    {
		auto triangleOld = collapse.GetTThrow0();
        triangleNewToOld[trianglesNew--] = triangleOld;
        triangleOld = collapse.GetTThrow1();
        triangleNewToOld[trianglesNew--] = triangleOld;
    }

    for (auto iter = m_Graph.GetTrianglesRemainingBegin(), end = m_Graph.GetTrianglesRemainingEnd(); iter != end; ++iter)
    {
		auto triangleOld = *iter;
        triangleNewToOld[trianglesNew--] = triangleOld;
    }

    // 重新排序索引缓冲区。
	vector<char> newIndices(m_ClodMeshTriangleMesh.GetNumIndices() * sizeof(int));
	auto trgIndices = reinterpret_cast<int*>(&newIndices[0]);
	for (auto trianglesIndex = 0; trianglesIndex < m_ClodMeshTriangleMesh.GetNumTriangles();  ++trianglesIndex)
    {
		auto triangleOld = triangleNewToOld[trianglesIndex];
		auto srcIndices = m_ClodMeshTriangleMesh.GetIndexBufferReadOnlyData() +  3 * triangleOld;
        for (auto j = 0; j < 3; ++j)
        {
            *trgIndices++ = *srcIndices++;
        }
    }	

    // 映射旧索引到新索引。
	auto newIndicesPtr = reinterpret_cast<int*>(&newIndices[0]);
	for (auto i = 0; i < m_ClodMeshTriangleMesh.GetNumIndices(); ++i)
    {
		newIndicesPtr[i] = vertexOldToNew[newIndicesPtr[i]];
    }

	m_ClodMeshTriangleMesh.SetNewIndexBufferData(newIndices);

	// 映射keep和throw顶点
    for(auto& collapse:m_Collapses)
    {
		collapse.SetVKeep(vertexOldToNew[collapse.GetVKeep()]);
        collapse.SetVThrow(vertexOldToNew[collapse.GetVThrow()]);
    } 
}

void Rendering::CreateClodMeshImpl
	::ComputeRecords()
{
	if(m_Collapses.size() == 0)
		return;

	auto numRecords = boost::numeric_cast<int>(m_Collapses.size() + 1);
    m_CollapseRecord.resize(numRecords);

	// 最初的记录存储只有顶点和三角形的初步值。
    m_CollapseRecord[0].SetNumVertices(m_ClodMeshTriangleMesh.GetNumVertices());
	m_CollapseRecord[0].SetNumTriangles(m_ClodMeshTriangleMesh.GetNumTriangles());

  	// 在索引缓冲区，因为我们处理每一个崩塌记录替换throw顶点。
	vector<int> indices(m_ClodMeshTriangleMesh.GetNumIndices());
	memcpy(&indices[0], m_ClodMeshTriangleMesh.GetIndexBufferReadOnlyData(), m_ClodMeshTriangleMesh.GetNumIndices() * sizeof(int));
	vector<int> verticesThrowIndices(m_ClodMeshTriangleMesh.GetNumIndices());

	// 进行中的崩塌记录。
	auto record = &m_CollapseRecord[1];
	auto numVertices = m_ClodMeshTriangleMesh.GetNumVertices();
	auto numTriangles = m_ClodMeshTriangleMesh.GetNumTriangles();

    for(const auto& collapse:m_Collapses)
    {
        record->SetVKeep(collapse.GetVKeep());
        record->SetVThrow(collapse.GetVThrow());

		// 边缘崩塌失去了一个顶点。
        --numVertices;
        record->SetNumVertices(numVertices);

		// 边缘崩塌失去了两个三角形
        numTriangles -= 2;
        record->SetNumTriangles(numTriangles);

		// 崩塌的边和更新崩塌后索引缓存区索引。
        const auto numIndices = 3 * numTriangles;
		auto recordNumIndices = 0;
        for (auto i = 0; i < numIndices; ++i)
        {
            if (indices[i] == record->GetVThrow())
            {
                verticesThrowIndices[recordNumIndices++] = i;
                indices[i] = record->GetVKeep();
            }
        }

        if (0 < recordNumIndices)
        {
			vector<int> indices2(recordNumIndices);
       
			auto numBytes = recordNumIndices * sizeof(int);
            memcpy(&indices2[0], &verticesThrowIndices[0], numBytes);

			record->SetIndices(indices2);
        }
        else
        {
            record->ClearIndices();
        }

		++record;
    }
}
#include STSTEM_WARNING_POP