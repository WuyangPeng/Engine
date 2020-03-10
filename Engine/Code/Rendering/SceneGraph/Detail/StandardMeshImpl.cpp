// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 16:37)

#include "Rendering/RenderingExport.h"

#include "StandardMeshImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <vector>

using std::vector;
using std::swap;

Rendering::StandardMeshImpl
	::StandardMeshImpl( const VertexFormatSmartPointer& vertexFormat,bool isStatic , bool inside ,const Transform* transform )
	:m_VertexFormat{ vertexFormat },m_Transform{ transform != nullptr ? *transform : Transform() },m_IsStatic{ isStatic },
	 m_Inside{ inside }, m_HasNormals{ false }, m_Usage{ isStatic ? BufferUsage::Static : BufferUsage::Dynamic }
{
	for (auto i = 0;i < sm_MaxUnits;++i)
	{
		m_HasTextureCoords[i] = false;
	}

	Init();
	
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::StandardMeshImpl
	::StandardMeshImpl(const StandardMeshImpl& rhs)
	:m_VertexFormat{ rhs.m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>() },m_Transform{ rhs.m_Transform },m_IsStatic{ rhs.m_IsStatic },
	 m_Inside{ rhs.m_Inside }, m_HasNormals{ rhs.m_HasNormals },m_Usage{ rhs.m_Usage }
{
	for (auto i = 0;i < sm_MaxUnits;++i)
	{
		m_HasTextureCoords[i] = rhs.m_HasTextureCoords[i];
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::StandardMeshImpl
	::Init()
{
	auto positionIndex = m_VertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Position);

	RENDERING_ASSERTION_1(0 <= positionIndex, "顶点格式必须包含位置。\n");

	auto positionType = m_VertexFormat->GetAttributeType(positionIndex);
	RENDERING_ASSERTION_1(positionType == VertexFormatFlags::AttributeType::Float3, "位置必须是3元组的浮点数。\n");
	SYSTEM_UNUSED_ARG(positionType);

	auto normalIndex = m_VertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Normal);
	if (0 <= normalIndex)
	{
		auto normalType = m_VertexFormat->GetAttributeType(normalIndex);

		if (normalType == VertexFormatFlags::AttributeType::Float3)
		{
			m_HasNormals = true;
		}
		else
		{
			m_HasNormals = false;
		}
	}

	for (auto unit = 0; unit < sm_MaxUnits; ++unit)
	{		 
		auto textureCoordIndex = m_VertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::TextureCoord, unit);
		if (0 <= textureCoordIndex)
		{
			auto textureCoordType = m_VertexFormat->GetAttributeType(textureCoordIndex);

			if (textureCoordType == VertexFormatFlags::AttributeType::Float2)
			{
				m_HasTextureCoords[unit] = true;
			}
			else
			{
				m_HasTextureCoords[unit] = false;
			}
		}
	}
}

Rendering::StandardMeshImpl& Rendering::StandardMeshImpl
	::operator=(const StandardMeshImpl& rhs)
{
	RENDERING_CLASS_IS_VALID_9;
	
	m_VertexFormat = rhs.m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>();
	m_Transform = rhs.m_Transform;
	m_IsStatic = rhs.m_IsStatic;
	m_Inside = rhs.m_Inside;
	m_HasNormals = rhs.m_HasNormals;
	m_Usage = rhs.m_Usage;
	
	for (int i = 0; i < sm_MaxUnits; ++i)
	{
		m_HasTextureCoords[i] = rhs.m_HasTextureCoords[i];
	}

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,StandardMeshImpl)

void Rendering::StandardMeshImpl
	::SetTransform(const Transform& transform)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Transform = transform;
}

const Rendering::Transform& Rendering::StandardMeshImpl
	::GetTransform() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Transform;
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Rectangle(int xSamples, int ySamples, float xExtent, float yExtent) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto numVertices = xSamples * ySamples;
	auto numTriangles = 2 * (xSamples - 1) * (ySamples - 1);
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer{ numVertices, stride, m_Usage } };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };

	// 生成几何数据。
	auto xSamplesInvertor = 1.0f / (xSamples - 1.0f);
	auto ySamplesInvertor = 1.0f / (ySamples - 1.0f);
 
	auto totalIndex = 0;
	for (auto yIndex = 0; yIndex < ySamples; ++yIndex)
	{
		auto vTextureCoord = yIndex * ySamplesInvertor;
		auto yCoordinate = (2.0f * vTextureCoord - 1.0f) * yExtent;
		for (auto xIndex = 0; xIndex < xSamples; ++xIndex)
		{
			auto uTextureCoord = xIndex * xSamplesInvertor;
			auto xCoordinate = (2.0f * uTextureCoord - 1.0f) * xExtent;

			vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex,  APoint(xCoordinate, yCoordinate, 0.0f));
			 
			if (m_HasNormals)
			{
				vertexBuffer->SetTriangleNormal(vertexBufferAccessor,totalIndex, AVector(0.0f, 0.0f, 1.0f));		 
			}

		
			for (auto unit = 0; unit < sm_MaxUnits; ++unit)
			{
				if (m_HasTextureCoords[unit])
				{
					vertexBuffer->SetTextureCoord(vertexBufferAccessor,totalIndex, Vector2D(uTextureCoord, vTextureCoord), unit);						 
				}
			}

			++totalIndex;
		}
	}


	TransformData(vertexBufferAccessor,vertexBuffer);

	// 生成索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numIndices, 4, m_Usage) };
	
	totalIndex = 0;
	for (auto yIndex = 0; yIndex < ySamples - 1; ++yIndex)
	{
		for (auto xIndex = 0; xIndex < xSamples - 1; ++xIndex)
		{
			auto firstIndex = xIndex + xSamples * yIndex;
			auto secondIndex = firstIndex + 1;
			auto thirdIndex = secondIndex + xSamples;
			auto fourthIndex = firstIndex + xSamples;

			indexBuffer->InitIndexBufferInRectangle(totalIndex, firstIndex, secondIndex,  thirdIndex, fourthIndex);
		 
			++totalIndex;
		}
	}

	return TrianglesMeshSmartPointer{ NEW0 TrianglesMesh{ m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(), vertexBuffer, indexBuffer } };
}

// private
void Rendering::StandardMeshImpl
	::TransformData(const VertexBufferAccessor& vertexBufferAccessor,  VertexBufferSmartPointer& vertexBuffer) const
{
	if (!m_Transform.IsIdentity())
	{
		const auto numVertices = vertexBufferAccessor.GetNumVertices();	
		for (auto i = 0; i < numVertices; ++i)
		{
			auto position = vertexBufferAccessor.GetPosition<APoint>(i);
			vertexBuffer->SetPosition(vertexBufferAccessor, i, m_Transform * position);
		}

		if (m_HasNormals)
		{
			vertexBuffer->NormalizeModelNormals(vertexBufferAccessor);		
		}		
	}		
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Disk(int shellSamples, int radialSamples, float radius) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto radialSamplesMinus1 = radialSamples - 1;
	auto shellSamplesMinus1 = shellSamples - 1;
	auto numVertices = 1 + radialSamples * shellSamplesMinus1;
	auto numTriangles = radialSamples * (2 * shellSamplesMinus1 - 1);
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer(numVertices, stride, m_Usage) };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };
 

	// 生成几何数据。

	// 圆盘的中心 
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(0.0f, 0.0f, 0.0f));
 
	if (m_HasNormals)
	{
		vertexBuffer->SetTriangleNormal(vertexBufferAccessor, 0, AVector(0.0f, 0.0f, 1.0f));		 
	}

	for (auto unit = 0; unit < sm_MaxUnits; ++unit)
	{
		if (m_HasTextureCoords[unit])
		{
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 0, Vector2D(0.5f, 0.5f), unit);
		}
	}

	auto shellSamplesMinus1Invertor = 1.0f / static_cast<float>(shellSamplesMinus1);
	auto radialSamplesInvertor = 1.0f / static_cast<float>(radialSamples);
	for (auto radialIndex = 0; radialIndex < radialSamples; ++radialIndex)
	{
		auto angle = Math::sm_TwoPI * radialSamplesInvertor * radialIndex;
		auto angleCos = Math::Cos(angle);
		auto angleSin = Math::Sin(angle);
		APoint radial{ angleCos, angleSin, 0.0f };

		for (auto shellIndex = 1; shellIndex < shellSamples; ++shellIndex)
		{
			auto fraction = shellSamplesMinus1Invertor * shellIndex;  // 在 (0,R]
			auto fracRadial = fraction * radial;
			int i = shellIndex + shellSamplesMinus1 * radialIndex;

			vertexBuffer->SetPosition(vertexBufferAccessor, i, radius * fracRadial);
			 
			if (m_HasNormals)
			{
				vertexBuffer->SetTriangleNormal(vertexBufferAccessor,i,  AVector(0.0f, 0.0f, 1.0f));		 				 
			}

			for (auto unit = 0; unit < sm_MaxUnits; ++unit)
			{
				if (m_HasTextureCoords[unit])
				{
					vertexBuffer->SetTextureCoord(vertexBufferAccessor,i,   Vector2D(0.5f + 0.5f * fracRadial[0],  0.5f + 0.5f * fracRadial[1]), unit);						
				}
			}
		}
	}

	TransformData(vertexBufferAccessor,vertexBuffer);

	// 生成索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numIndices, 4, m_Usage) };
	indexBuffer->InitIndexBufferInDisk(radialSamplesMinus1, shellSamplesMinus1);	 

	return TrianglesMeshSmartPointer{ NEW0 TrianglesMesh{ m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(),vertexBuffer, indexBuffer } };
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Box(float xExtent, float yExtent, float zExtent) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto numVertices = 8;
	auto numTriangles = 12;
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer(numVertices, stride, m_Usage) };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };

	// 生成几何数据。
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint{ -xExtent, -yExtent, -zExtent });
	vertexBuffer->SetPosition(vertexBufferAccessor, 1, APoint{ +xExtent, -yExtent, -zExtent });
	vertexBuffer->SetPosition(vertexBufferAccessor, 2, APoint{ +xExtent, +yExtent, -zExtent });
	vertexBuffer->SetPosition(vertexBufferAccessor, 3, APoint{ -xExtent, +yExtent, -zExtent });
	vertexBuffer->SetPosition(vertexBufferAccessor, 4, APoint{ -xExtent, -yExtent, +zExtent });
	vertexBuffer->SetPosition(vertexBufferAccessor, 5, APoint{ +xExtent, -yExtent, +zExtent });
	vertexBuffer->SetPosition(vertexBufferAccessor, 6, APoint{ +xExtent, +yExtent, +zExtent });
	vertexBuffer->SetPosition(vertexBufferAccessor, 7, APoint{ -xExtent, +yExtent, +zExtent });

	for (auto unit = 0; unit < sm_MaxUnits; ++unit)
	{
		if (m_HasTextureCoords[unit])
		{
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 0, Vector2D{ 0.25f, 0.75f }, unit);
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 1, Vector2D{ 0.75f, 0.75f }, unit);
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 2, Vector2D{ 0.75f, 0.25f }, unit);
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 3, Vector2D{ 0.25f, 0.25f }, unit);
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 4, Vector2D{ 0.0f, 1.0f }, unit);
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 5, Vector2D{ 1.0f, 1.0f }, unit);
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 6, Vector2D{ 1.0f, 0.0f }, unit);
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 7, Vector2D{ 0.0f, 0.0f }, unit);
		}
	}

	TransformData(vertexBufferAccessor,vertexBuffer);

	// 生成索引（外视图）
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer{ numIndices, 4, m_Usage } };
	 
	vector<int> indices(36);
	indices[0] = 0;  indices[1] = 2;  indices[2] = 1;
	indices[3] = 0;  indices[4] = 3;  indices[5] = 2;
	indices[6] = 0;  indices[7] = 1;  indices[8] = 5;
	indices[9] = 0;  indices[10] = 5;  indices[11] = 4;
	indices[12] = 0;  indices[13] = 4;  indices[14] = 7;
	indices[15] = 0;  indices[16] = 7;  indices[17] = 3;
	indices[18] = 6;  indices[19] = 4;  indices[20] = 5;
	indices[21] = 6;  indices[22] = 7;  indices[23] = 4;
	indices[24] = 6;  indices[25] = 5;  indices[26] = 1;
	indices[27] = 6;  indices[28] = 1;  indices[29] = 2;
	indices[30] = 6;  indices[31] = 2;  indices[32] = 3;
	indices[33] = 6;  indices[34] = 3;  indices[35] = 7;

	if (m_Inside)
	{
		ReverseTriangleOrder(numTriangles, &indices[0]);
	}

	indexBuffer->InitIndexBuffer(indices);

	TrianglesMeshSmartPointer mesh{ NEW0 TrianglesMesh(m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(),vertexBuffer, indexBuffer) };
	if (m_HasNormals)
	{
		mesh->UpdateModelSpace(VisualUpdateType::Normals);
	}

	return mesh;
}

// private
void Rendering::StandardMeshImpl
	::ReverseTriangleOrder(int numTriangles, int* indices) const
{
	for (auto i = 0; i < numTriangles; ++i)
	{
		auto lhsIndex = 3 * i + 1;
		auto rhsIndex = lhsIndex + 1;
		swap(indices[lhsIndex], indices[rhsIndex]);
	}
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::CylinderOmittedEndDisks(int axisSamples, int radialSamples, float radius, float height) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto numVertices = axisSamples * (radialSamples + 1);
	auto numTriangles = 2 * (axisSamples - 1) * radialSamples;
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer(numVertices, stride, m_Usage) };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };

 
	// 生成几何数据。 
	auto radialSamplesInvertor = 1.0f / boost::numeric_cast<float>(radialSamples);
	auto radialSamplesMinus1Invertor = 1.0f / boost::numeric_cast<float>(axisSamples - 1);
	auto halfHeight = 0.5f * height;
 
	// 产生单位圆上的点用于计算圆柱切片的网格点。
	vector<float> angleCos(radialSamples + 1);
	vector<float> angleSin(radialSamples + 1);
	for (auto radialIndex = 0; radialIndex < radialSamples; ++radialIndex)
	{
		auto angle = Math::sm_TwoPI * radialSamplesInvertor * radialIndex;
		angleCos[radialIndex] = Math::Cos(angle);
		angleSin[radialIndex] = Math::Sin(angle);
	}
	
	angleCos[radialSamples] = angleCos[0];
	angleSin[radialSamples] = angleSin[0];

	// 生成圆柱本身。
	auto totalIndex = 0;
	for (auto axisIndex = 0; axisIndex < axisSamples; ++axisIndex)
	{
		auto axisFraction = axisIndex * radialSamplesMinus1Invertor;  // 在 [0,1]
		auto zCoordinate = -halfHeight + height * axisFraction;
		
		// 计算中心切片。
		APoint sliceCenter{ 0.0f, 0.0f, zCoordinate };

		// 计算切片顶点在端点的复制。
		auto save = totalIndex;
		for (auto radialIndex = 0; radialIndex < radialSamples; ++radialIndex)
		{
			auto radialFraction = radialIndex * radialSamplesInvertor;  // in [0,1)
			AVector normal{ angleCos[radialIndex], angleSin[radialIndex], 0.0f };
			
			vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex, sliceCenter + radius * normal);		 
			
			if (m_HasNormals)
			{
				if (m_Inside)
				{
					vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, -normal);				
				}
				else
				{
					vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, normal);
				}
			}

			for (auto unit = 0; unit < sm_MaxUnits; ++unit)
			{				
				if (m_HasTextureCoords[unit])
				{
					vertexBuffer->SetTextureCoord(vertexBufferAccessor, totalIndex, Vector2D(radialFraction, axisFraction), unit);
				}
			}
			
			++totalIndex;
		}

		auto position = vertexBufferAccessor.GetPosition<APoint>(save);
		vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex, position);
	 
		if (m_HasNormals)
		{
			auto normal = vertexBufferAccessor.GetNormal<AVector>(save);
			vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, normal);			
		}

		for (auto unit = 0; unit < sm_MaxUnits; ++unit)
		{
			if (m_HasTextureCoords[unit])
			{
				vertexBuffer->SetTextureCoord(vertexBufferAccessor, totalIndex, Vector2D(1.0f, axisFraction), unit);				
			}
		}
		
		++totalIndex;
	}
	
	TransformData(vertexBufferAccessor,vertexBuffer);

	// 产生索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer{ numIndices, 4, m_Usage } };
	vector<int> indices(numIndices);
	auto indicesIndex = 0;

	auto aStart = 0;
	for (auto axisIndex = 0; axisIndex < axisSamples - 1; ++axisIndex)
	{
		auto i0 = aStart;
		auto i1 = i0 + 1;
		aStart += radialSamples + 1;
		auto i2 = aStart;
		auto i3 = i2 + 1;
		for (totalIndex = 0; totalIndex < radialSamples; ++totalIndex, indicesIndex += 6)
		{
			if (m_Inside)
			{
				indices[indicesIndex] = i0++;
				indices[indicesIndex + 1] = i2;
				indices[indicesIndex + 2] = i1;
				indices[indicesIndex + 3] = i1++;
				indices[indicesIndex + 4] = i2++;
				indices[indicesIndex + 5] = i3++;
			}
			else // 外部视图
			{
				indices[indicesIndex + 0] = i0++;
				indices[indicesIndex + 1] = i1;
				indices[indicesIndex + 2] = i2;
				indices[indicesIndex + 3] = i1++;
				indices[indicesIndex + 4] = i3++;
				indices[indicesIndex + 5] = i2++;
			}
		}
	}  

	indexBuffer->InitIndexBuffer(indices);

	TrianglesMeshSmartPointer mesh{ NEW0 TrianglesMesh{ m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(),vertexBuffer, indexBuffer } };
	
	// 重复的顶点裂缝使自动生成的边界体积稍微偏离中心。
	// 重置边界使用真实的信息。
	auto maxDist = Math::Sqrt(radius * radius + height * height);
	mesh->GetModelBound().SetCenter(APoint::sm_Origin);
	mesh->GetModelBound().SetRadius(maxDist);
	
	return mesh;
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::CylinderIncludedEndDisks(int axisSamples, int radialSamples, float radius, float height) const
{		
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto mesh = Sphere(axisSamples, radialSamples, radius);
	auto vertexBuffer = mesh->GetVertexBuffer();
	auto numVertices = vertexBuffer->GetNumElements();
	
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };

	// 平铺球到两极
	auto heightDivide2 = 0.5f * height;
	auto southPosition = vertexBufferAccessor.GetPosition<APoint>(numVertices - 2);
	auto northPosition = vertexBufferAccessor.GetPosition<APoint>(numVertices - 1);

	southPosition[2] = -heightDivide2;  // 南极
	northPosition[2] = +heightDivide2;  // 北极

	vertexBuffer->SetPosition(vertexBufferAccessor, numVertices - 2, southPosition);
	vertexBuffer->SetPosition(vertexBufferAccessor, numVertices - 1, northPosition); 
	
	// 重映射 z值到 [-h / 2,h / 2].
	auto zFactor = 2.0f / (axisSamples - 1);
	auto tmp0 = radius * (-1.0f + zFactor);
	auto tmp1 = 1.0f / (radius * (+1.0f - zFactor));
	for (auto i = 0; i < numVertices - 2; ++i)
	{
		auto position = vertexBufferAccessor.GetPosition<APoint>(i);
		position[2] = heightDivide2 * (-1.0f + tmp1 * (position[2] - tmp0));
		auto adjust = radius * Math::InvSqrt(position[0] * position[0] + position[1] * position[1]);
		position[0] *= adjust;
		position[1] *= adjust;
	}
	
	TransformData(vertexBufferAccessor,vertexBuffer);
	
	if (m_HasNormals)
	{
		mesh->UpdateModelSpace(VisualUpdateType::Normals);
	}

	// 重复的顶点裂缝使自动生成的边界体积稍微偏离中心。
	// 重置边界使用真实的信息。
	auto maxDist = Math::Sqrt(radius * radius + height * height);
	mesh->GetModelBound().SetCenter(APoint::sm_Origin);
	mesh->GetModelBound().SetRadius(maxDist);

	return mesh;
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Sphere(int zSamples, int radialSamples, float radius) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	auto zSamplesMinus1 = zSamples - 1;
	auto	zSamplesMinus2 = zSamples - 2;
	auto	zSamplesMinus3 = zSamples - 3;
	auto radialSamplesPlus1 = radialSamples + 1;
	auto numVertices = zSamplesMinus2 * radialSamplesPlus1 + 2;
	auto numTriangles = 2 * zSamplesMinus2 * radialSamples;
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer{ numVertices, stride, m_Usage } };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };

	// 生成几何数据。
	auto radialSamplesInvertor = 1.0f / boost::numeric_cast<float>(radialSamples);
	auto zFactor = 2.0f / boost::numeric_cast<float>(zSamplesMinus1);

	// 生成单位圆上的点，一个圆柱切片被计算网格点使用。
	vector<float> angleCos(radialSamplesPlus1);
	vector<float> angleSin(radialSamplesPlus1);
	 
	for (auto radialSamplesIndex = 0; radialSamplesIndex < radialSamples; ++radialSamplesIndex)
	{
		auto angle = Math::sm_TwoPI * radialSamplesInvertor * radialSamplesIndex;
		angleCos[radialSamplesIndex] = Math::Cos(angle);
		angleSin[radialSamplesIndex] = Math::Sin(angle);
	}

	angleSin[radialSamples] = angleSin[0];
	angleCos[radialSamples] = angleCos[0];
	
	// 产生圆柱本身。
	auto totalIndex = 0;
	for (auto zSamplesIndex = 1; zSamplesIndex < zSamplesMinus1; ++zSamplesIndex)
	{
		auto zFraction = -1.0f + zFactor * zSamplesIndex;  // in (-1,1)
		auto zValue = radius * zFraction;
		
		// 计算切片的中心
		APoint sliceCenter{ 0.0f, 0.0f, zValue };
		
		// 计算切片的半径
		auto sliceRadius = Math::Sqrt(Math::FAbs(radius * radius - zValue * zValue));
		
		// 计算切片顶点和复制终点。
		auto save = totalIndex;
		for (auto radialSamplesIndex = 0; radialSamplesIndex < radialSamples; ++radialSamplesIndex)
		{
			auto radialFraction = radialSamplesIndex * radialSamplesInvertor;  // in [0,1)
			AVector radial{ angleCos[radialSamplesIndex], angleSin[radialSamplesIndex], 0.0f };

			vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex, sliceCenter + sliceRadius * radial);
				
			if (m_HasNormals)
			{
				auto normal = vertexBufferAccessor.GetPosition<AVector>(totalIndex);
				normal.Normalize();
				if (m_Inside)
				{
					vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex,-normal);				
				}
				else
				{
					vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, normal);					
				}
			}
	 
			for (auto unit = 0; unit < sm_MaxUnits; ++unit)
			{
				if (m_HasTextureCoords[unit])
				{
					vertexBuffer->SetTextureCoord(vertexBufferAccessor, totalIndex, Vector2D(radialFraction, 0.5f * (zFraction + 1.0f)),unit);		
				}
			}
			
			++totalIndex;
		}

		auto position = vertexBufferAccessor.GetPosition<APoint>(save);
		vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex, position);
 
		if (m_HasNormals)
		{
			auto normal = vertexBufferAccessor.GetNormal<AVector>(save);
			vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, normal);		 
		}

		for (auto unit = 0; unit < sm_MaxUnits; ++unit)
		{
			if (m_HasTextureCoords[unit])
			{
				vertexBuffer->SetTextureCoord(vertexBufferAccessor, totalIndex, Vector2D(1.0f,0.5f * (zFraction + 1.0f)),unit);			
			}
		}		
		
		++totalIndex;
	}
	
	// 南极
	vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex, APoint(0.0f, 0.0f, -radius));
 
	if (m_HasNormals)
	{
		if (m_Inside)
		{
			vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, AVector(0.0f, 0.0f, 1.0f));
		}
		else
		{
			vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, AVector(0.0f, 0.0f, -1.0f));
		}
	}

	for (auto unit = 0; unit < sm_MaxUnits; ++unit)
	{
		if (m_HasTextureCoords[unit])
		{
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, totalIndex, Vector2D(0.5f, 0.5f),unit);
		}
	}

	++totalIndex;
	
	// 北极
	vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex, APoint(0.0f, 0.0f, radius));
 
	if (m_HasNormals)
	{
		if (m_Inside)
		{
			vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, AVector(0.0f, 0.0f, -1.0f));
		}
		else
		{
			vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, AVector(0.0f, 0.0f, 1.0f));
		}
	}

	for (auto unit = 0; unit < sm_MaxUnits; ++unit)
	{
		if (m_HasTextureCoords[unit])
		{
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, totalIndex, Vector2D(0.5f, 1.0f),unit);
		}
	} 
	
	++totalIndex;
	
	TransformData(vertexBufferAccessor,vertexBuffer);
	
	// 生成索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numIndices, 4, m_Usage) };
	vector<int> indices(numIndices);
	int indicesIndex = 0;
	 
	auto zStart = 0;
	for (auto zSamplesIndex = 0; zSamplesIndex < zSamplesMinus3; ++zSamplesIndex)
	{
		auto i0 = zStart;
		auto i1 = i0 + 1;
		zStart += radialSamplesPlus1;
		auto i2 = zStart;
		auto i3 = i2 + 1;
		for (auto i = 0; i < radialSamples; ++i)
		{
			if (m_Inside)
			{
				indices[indicesIndex + 0] = i0++;
				indices[indicesIndex + 1] = i2;
				indices[indicesIndex + 2] = i1;
				indices[indicesIndex + 3] = i1++;
				indices[indicesIndex + 4] = i2++;
				indices[indicesIndex + 5] = i3++;
			}
			else  // 内部视图
			{
				indices[indicesIndex + 0] = i0++;
				indices[indicesIndex + 1] = i1;
				indices[indicesIndex + 2] = i2;
				indices[indicesIndex + 3] = i1++;
				indices[indicesIndex + 4] = i3++;
				indices[indicesIndex + 5] = i2++;
			}

			indicesIndex += 6;
		}
	}
	
	// 南极三角形
	auto numVerticesMinus2 = numVertices - 2;
	for (auto i = 0; i < radialSamples; ++i)
	{
		if (m_Inside)
		{
			indices[indicesIndex + 0] = i;
			indices[indicesIndex + 1] = i + 1;
			indices[indicesIndex + 2] = numVerticesMinus2;
		}
		else
		{
			indices[indicesIndex + 0] = i;
			indices[indicesIndex + 1] = numVerticesMinus2;
			indices[indicesIndex + 2] = i + 1;
		}

		indicesIndex += 3;
	}
	
	// 北极三角形
	auto numVerticesMinus1 = numVertices - 1;
	auto offset = zSamplesMinus3 * radialSamplesPlus1;
	for (auto i = 0; i < radialSamples; ++i)
	{
		if (m_Inside)
		{
			indices[indicesIndex + 0] = i + offset;
			indices[indicesIndex + 1] = numVerticesMinus1;
			indices[indicesIndex + 2] = i + 1 + offset;
		}
		else
		{
			indices[indicesIndex + 0] = i + offset;
			indices[indicesIndex + 1] = i + 1 + offset;
			indices[indicesIndex + 2] = numVerticesMinus1;
		}

		indicesIndex += 3;
	}

	indexBuffer->InitIndexBuffer(indices);

 
	// 重复的顶点裂缝使自动生成的边界体积稍微偏离中心。
	// 重置边界使用真实的信息。
	TrianglesMeshSmartPointer mesh{ NEW0 TrianglesMesh(m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(), vertexBuffer, indexBuffer) };
	 
	mesh->GetModelBound().SetCenter(APoint::sm_Origin);
	mesh->GetModelBound().SetRadius(radius);

	return mesh; 
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Torus(int circleSamples, int radialSamples,float outerRadius, float innerRadius) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	auto numVertices = (circleSamples + 1) * (radialSamples + 1);
	auto numTriangles = 2 * circleSamples * radialSamples;
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer(numVertices, stride, m_Usage) };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };


	// 生成几何数据。
	auto circleSamplesInvertor = 1.0f / static_cast<float>(circleSamples);
	auto radialSamplesInvertor = 1.0f / static_cast<float>(radialSamples);

	// 产生圆柱体本身。
	auto totalIndex = 0;
	for (auto circleIndex = 0; circleIndex < circleSamples; ++circleIndex)
	{
		// 计算在规定的角度圆环的圆心。
		auto circleFraction = circleIndex * circleSamplesInvertor;  // 在 [0,1)
		auto theta = Math::sm_TwoPI * circleFraction;
		auto cosTheta = Math::Cos(theta);
		auto sinTheta = Math::Sin(theta);
		APoint radial{ cosTheta, sinTheta, 0.0f };
		auto torusMiddle = outerRadius * radial;

		// Compute slice vertices with duplication at endpoint.
		auto save = totalIndex;
		for (auto radialIndex = 0; radialIndex < radialSamples; ++radialIndex)
		{
			auto radialFraction = radialIndex * radialSamplesInvertor;  // in [0,1)
			auto phi = Math::sm_TwoPI * radialFraction;
			auto cosPhi = Math::Cos(phi);
			auto sinPhi = Math::Sin(phi);
			auto normal = cosPhi * radial - sinPhi * APoint(0.0f,0.0f,-1.0f);
			vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex, torusMiddle + innerRadius * normal);
						 
			if (m_HasNormals)
			{
				if (m_Inside)
				{
					vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, -normal);
				}
				else
				{
					vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, normal);
				}
			}
	
			for (auto unit = 0; unit < sm_MaxUnits; ++unit)
			{
				if (m_HasTextureCoords[unit])
				{
					vertexBuffer->SetTextureCoord(vertexBufferAccessor,totalIndex,Vector2D(radialFraction, circleFraction),unit);					 
				}
			}

			++totalIndex;
		}

		auto position = vertexBufferAccessor.GetPosition<APoint>(save);
		vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex, position);

		if (m_HasNormals)
		{
			auto normal = vertexBufferAccessor.GetNormal<AVector>(save);
			vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, normal);
		}

	    for (auto unit = 0; unit < sm_MaxUnits; ++unit)
		{
			if (m_HasTextureCoords[unit])
			{
				vertexBuffer->SetTextureCoord(vertexBufferAccessor, totalIndex, Vector2D(1.0f, circleFraction),unit);			
			}
		}

		++totalIndex;
	}

	// 重复圆柱体两端以形成一个环面。
	for (auto radialIndex = 0; radialIndex <= radialSamples; ++radialIndex)
	{
		auto position = vertexBufferAccessor.GetPosition<APoint>(radialIndex);
		vertexBuffer->SetPosition(vertexBufferAccessor, totalIndex, position);

		if (m_HasNormals)
		{
			auto normal = vertexBufferAccessor.GetNormal<AVector>(radialIndex);
			vertexBuffer->SetTriangleNormal(vertexBufferAccessor, totalIndex, normal);
		}

	    for (auto unit = 0; unit < sm_MaxUnits; ++unit)
		{
			if (m_HasTextureCoords[unit])
			{
				auto textureCoords = vertexBufferAccessor.GetTextureCoord<Vector2D>(unit,radialIndex);
				vertexBuffer->SetTextureCoord(vertexBufferAccessor, totalIndex,  Vector2D(textureCoords[0], 1.0f),unit);			
			}
		}
	
		++totalIndex;
	}

	TransformData(vertexBufferAccessor,vertexBuffer);

	// 生成索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numIndices, 4, m_Usage) };
	vector<int> indices(numIndices);

	auto indicesIndex = 0;
	auto cStart = 0;
	for (auto circleIndex = 0; circleIndex < circleSamples; ++circleIndex)
	{
		auto i0 = cStart;
		auto i1 = i0 + 1;
		cStart += radialSamples + 1;
		auto i2 = cStart;
		auto i3 = i2 + 1;
		for (auto i = 0; i < radialSamples; ++i)
		{
			if (m_Inside)
			{
				indices[indicesIndex + 0] = i0++;
				indices[indicesIndex + 1] = i1;
				indices[indicesIndex + 2] = i2;
				indices[indicesIndex + 3] = i1++;
				indices[indicesIndex + 4] = i3++;
				indices[indicesIndex + 5] = i2++;
			}
			else  // 内部视图
			{
				indices[indicesIndex + 0] = i0++;
				indices[indicesIndex + 1] = i2;
				indices[indicesIndex + 2] = i1;
				indices[indicesIndex + 3] = i1++;
				indices[indicesIndex + 4] = i2++;
				indices[indicesIndex + 5] = i3++;
			}

			indicesIndex += 6;
		}
	}

	indexBuffer->InitIndexBuffer(indices);

	// 重复的顶点裂缝使自动生成的边界体积稍微偏离中心。
	// 重置边界使用真实的信息。
	TrianglesMeshSmartPointer mesh{ NEW0 TrianglesMesh(m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(),vertexBuffer, indexBuffer) };
	 
	mesh->GetModelBound().SetCenter(APoint::sm_Origin);
	mesh->GetModelBound().SetRadius(outerRadius);

	return mesh; 
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Tetrahedron() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	auto fSqrt2Div3 = Math::Sqrt(2.0f) / 3.0f;
	auto fSqrt6Div3 = Math::Sqrt(6.0f) / 3.0f;
	auto fOneThird = 1.0f / 3.0f;

	auto numVertices = 4;
	auto numTriangles = 4;
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer(numVertices, stride, m_Usage) };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };


	// 生成几何数据。
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(0.0f, 0.0f, 1.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 1, APoint(2.0f * fSqrt2Div3, 0.0f, -fOneThird));
	vertexBuffer->SetPosition(vertexBufferAccessor, 2, APoint(-fSqrt2Div3, fSqrt6Div3, -fOneThird));
	vertexBuffer->SetPosition(vertexBufferAccessor, 3, APoint(-fSqrt2Div3, -fSqrt6Div3, -fOneThird));
 
	CreatePlatonicNormals(vertexBufferAccessor,vertexBuffer);
	CreatePlatonicTextures(vertexBufferAccessor, vertexBuffer);
	TransformData(vertexBufferAccessor, vertexBuffer);

	// 生成索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numIndices, 4, m_Usage) };
	vector<int> indices(12);

	indices[0] = 0;  indices[1] = 1;  indices[2] = 2;
	indices[3] = 0;  indices[4] = 2;  indices[5] = 3;
	indices[6] = 0;  indices[7] = 3;  indices[8] = 1;
	indices[9] = 1;  indices[10] = 3;  indices[11] = 2;

	if (m_Inside)
	{
		ReverseTriangleOrder(numTriangles, &indices[0]);
	}

	indexBuffer->InitIndexBuffer(indices);

	return TrianglesMeshSmartPointer{ NEW0 TrianglesMesh(m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(),vertexBuffer, indexBuffer) };
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Hexahedron() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	auto fSqrtThird = Math::Sqrt(1.0f / 3.0f);

	auto numVertices = 8;
	auto numTriangles = 12;
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer(numVertices, stride, m_Usage) };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };


	// 生成几何数据。
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(-fSqrtThird, -fSqrtThird, -fSqrtThird));
	vertexBuffer->SetPosition(vertexBufferAccessor, 1, APoint(fSqrtThird, -fSqrtThird, -fSqrtThird));
	vertexBuffer->SetPosition(vertexBufferAccessor, 2, APoint(fSqrtThird, fSqrtThird, -fSqrtThird));
	vertexBuffer->SetPosition(vertexBufferAccessor, 3, APoint(-fSqrtThird, fSqrtThird, -fSqrtThird));
	vertexBuffer->SetPosition(vertexBufferAccessor, 4, APoint(-fSqrtThird, -fSqrtThird, fSqrtThird));
	vertexBuffer->SetPosition(vertexBufferAccessor, 5, APoint(fSqrtThird, -fSqrtThird, fSqrtThird));
	vertexBuffer->SetPosition(vertexBufferAccessor, 6, APoint(fSqrtThird, fSqrtThird, fSqrtThird));
	vertexBuffer->SetPosition(vertexBufferAccessor, 7, APoint(-fSqrtThird, fSqrtThird, fSqrtThird));
 
	CreatePlatonicNormals(vertexBufferAccessor, vertexBuffer);
	CreatePlatonicTextures(vertexBufferAccessor, vertexBuffer);
	TransformData(vertexBufferAccessor, vertexBuffer);

	// 生成索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numIndices, 4, m_Usage) };
	vector<int> indices(numIndices);
 
	indices[0] = 0;  indices[1] = 3;  indices[2] = 2;
	indices[3] = 0;  indices[4] = 2;  indices[5] = 1;
	indices[6] = 0;  indices[7] = 1;  indices[8] = 5;
	indices[9] = 0;  indices[10] = 5;  indices[11] = 4;
	indices[12] = 0;  indices[13] = 4;  indices[14] = 7;
	indices[15] = 0;  indices[16] = 7;  indices[17] = 3;
	indices[18] = 6;  indices[19] = 5;  indices[20] = 1;
	indices[21] = 6;  indices[22] = 1;  indices[23] = 2;
	indices[24] = 6;  indices[25] = 2;  indices[26] = 3;
	indices[27] = 6;  indices[28] = 3;  indices[29] = 7;
	indices[30] = 6;  indices[31] = 7;  indices[32] = 4;
	indices[33] = 6;  indices[34] = 4;  indices[35] = 5;

	if (m_Inside)
	{
		ReverseTriangleOrder(numTriangles, &indices[0]);
	}

	indexBuffer->InitIndexBuffer(indices);

	return TrianglesMeshSmartPointer{ NEW0 TrianglesMesh(m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(),vertexBuffer, indexBuffer) };
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Octahedron() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	auto numVertices = 6;
	auto numTriangles = 8;
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer(numVertices, stride, m_Usage) };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };


	// 生成几何数据。
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(1.0f, 0.0f, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 1, APoint(-1.0f, 0.0f, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 2, APoint(0.0f, 1.0f, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 3, APoint(0.0f, -1.0f, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 4, APoint(0.0f, 0.0f, 1.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 5, APoint(0.0f, 0.0f, -1.0f)); 

	CreatePlatonicNormals(vertexBufferAccessor, vertexBuffer);
	CreatePlatonicTextures(vertexBufferAccessor, vertexBuffer);
	TransformData(vertexBufferAccessor, vertexBuffer);

	// 生成索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numIndices, 4, m_Usage) };
	vector<int> indices(numIndices);

	indices[0] = 4;  indices[1] = 0;  indices[2] = 2;
	indices[3] = 4;  indices[4] = 2;  indices[5] = 1;
	indices[6] = 4;  indices[7] = 1;  indices[8] = 3;
	indices[9] = 4;  indices[10] = 3;  indices[11] = 0;
	indices[12] = 5;  indices[13] = 2;  indices[14] = 0;
	indices[15] = 5;  indices[16] = 1;  indices[17] = 2;
	indices[18] = 5;  indices[19] = 3;  indices[20] = 1;
	indices[21] = 5;  indices[22] = 0;  indices[23] = 3;

	if (m_Inside)
	{
		ReverseTriangleOrder(numTriangles, &indices[0]);
	}

	indexBuffer->InitIndexBuffer(indices);

	return TrianglesMeshSmartPointer{ NEW0 TrianglesMesh(m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(),vertexBuffer, indexBuffer) };
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Dodecahedron() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	auto a = 1.0f / Math::Sqrt(3.0f);
	auto b = Math::Sqrt((3.0f - Math::Sqrt(5.0f)) / 6.0f);
	auto c = Math::Sqrt((3.0f + Math::Sqrt(5.0f)) / 6.0f);

	auto numVertices = 20;
	auto numTriangles = 36;
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

	// 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer(numVertices, stride, m_Usage) };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };
	
	// 生成几何数据。
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(a, a, a));	 
	vertexBuffer->SetPosition(vertexBufferAccessor, 1, APoint(a, a, -a));
	vertexBuffer->SetPosition(vertexBufferAccessor, 2, APoint(a, -a, a));
	vertexBuffer->SetPosition(vertexBufferAccessor, 3, APoint(a, -a, -a));
	vertexBuffer->SetPosition(vertexBufferAccessor, 4, APoint(-a, a, a));
	vertexBuffer->SetPosition(vertexBufferAccessor, 5, APoint(-a, a, -a));
	vertexBuffer->SetPosition(vertexBufferAccessor, 6, APoint(-a, -a, a));
	vertexBuffer->SetPosition(vertexBufferAccessor, 7, APoint(-a, -a, -a));
	vertexBuffer->SetPosition(vertexBufferAccessor, 8, APoint(b, c, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 9, APoint(-b, c, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 10, APoint(b, -c, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 11, APoint(-b, -c, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 12, APoint(c, 0.0f, b));
	vertexBuffer->SetPosition(vertexBufferAccessor, 13, APoint(c, 0.0f, -b));
	vertexBuffer->SetPosition(vertexBufferAccessor, 14, APoint(-c, 0.0f, b));
	vertexBuffer->SetPosition(vertexBufferAccessor, 15, APoint(-c, 0.0f, -b));
	vertexBuffer->SetPosition(vertexBufferAccessor, 16, APoint(0.0f, b, c));
	vertexBuffer->SetPosition(vertexBufferAccessor, 17, APoint(0.0f, -b, c));
	vertexBuffer->SetPosition(vertexBufferAccessor, 18, APoint(0.0f, b, -c));
	vertexBuffer->SetPosition(vertexBufferAccessor, 19, APoint(0.0f, -b, -c));

	CreatePlatonicNormals(vertexBufferAccessor, vertexBuffer);
	CreatePlatonicTextures(vertexBufferAccessor, vertexBuffer);
	TransformData(vertexBufferAccessor, vertexBuffer);

	// 生成索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numIndices, 4, m_Usage) };
	vector<int> indices(numIndices);

	indices[0] = 0;  indices[1] = 8;  indices[2] = 9;
	indices[3] = 0;  indices[4] = 9;  indices[5] = 4;
	indices[6] = 0;  indices[7] = 4;  indices[8] = 16;
	indices[9] = 0;  indices[10] = 12;  indices[11] = 13;
	indices[12] = 0;  indices[13] = 13;  indices[14] = 1;
	indices[15] = 0;  indices[16] = 1;  indices[17] = 8;
	indices[18] = 0;  indices[19] = 16;  indices[20] = 17;
	indices[21] = 0;  indices[22] = 17;  indices[23] = 2;
	indices[24] = 0;  indices[25] = 2;  indices[26] = 12;
	indices[27] = 8;  indices[28] = 1;  indices[29] = 18;
	indices[30] = 8;  indices[31] = 18;  indices[32] = 5;
	indices[33] = 8;  indices[34] = 5;  indices[35] = 9;
	indices[36] = 12;  indices[37] = 2;  indices[38] = 10;
	indices[39] = 12;  indices[40] = 10;  indices[41] = 3;
	indices[42] = 12;  indices[43] = 3;  indices[44] = 13;
	indices[45] = 16;  indices[46] = 4;  indices[47] = 14;
	indices[48] = 16;  indices[49] = 14;  indices[50] = 6;
	indices[51] = 16;  indices[52] = 6;  indices[53] = 17;
	indices[54] = 9;  indices[55] = 5;  indices[56] = 15;
	indices[57] = 9;  indices[58] = 15;  indices[59] = 14;
	indices[60] = 9;  indices[61] = 14;  indices[62] = 4;
	indices[63] = 6;  indices[64] = 11;  indices[65] = 10;
	indices[66] = 6;  indices[67] = 10;  indices[68] = 2;
	indices[69] = 6;  indices[70] = 2;  indices[71] = 17;
	indices[72] = 3;  indices[73] = 19;  indices[74] = 18;
	indices[75] = 3;  indices[76] = 18;  indices[77] = 1;
	indices[78] = 3;  indices[79] = 1;  indices[80] = 13;
	indices[81] = 7;  indices[82] = 15;  indices[83] = 5;
	indices[84] = 7;  indices[85] = 5;  indices[86] = 18;
	indices[87] = 7;  indices[88] = 18;  indices[89] = 19;
	indices[90] = 7;  indices[91] = 11;  indices[92] = 6;
	indices[93] = 7;  indices[94] = 6;  indices[95] = 14;
	indices[96] = 7;  indices[97] = 14;  indices[98] = 15;
	indices[99] = 7;  indices[100] = 19;  indices[101] = 3;
	indices[102] = 7;  indices[103] = 3;  indices[104] = 10;
	indices[105] = 7;  indices[106] = 10;  indices[107] = 11;

	if (m_Inside)
	{
		ReverseTriangleOrder(numTriangles, &indices[0]);
	}

	indexBuffer->InitIndexBuffer(indices);

	return TrianglesMeshSmartPointer{ NEW0 TrianglesMesh(m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(),vertexBuffer, indexBuffer) };
}

const Rendering::TrianglesMeshSmartPointer Rendering::StandardMeshImpl
	::Icosahedron() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	auto goldenRatio = 0.5f * (1.0f + Math::Sqrt(5.0f));
	auto invRoot = 1.0f / Math::Sqrt(1.0f + goldenRatio * goldenRatio);
	auto u = goldenRatio * invRoot;
	auto v = invRoot;

	auto numVertices = 12;
	auto numTriangles = 20;
	auto numIndices = 3 * numTriangles;
	auto stride = m_VertexFormat->GetStride();

    // 创建一个顶点缓冲区
	VertexBufferSmartPointer vertexBuffer{ NEW0 VertexBuffer(numVertices, stride, m_Usage) };
	VertexBufferAccessor vertexBufferAccessor{ m_VertexFormat.PolymorphicCastConstObjectSmartPointer<ConstVertexFormatSmartPointer>(),
											   vertexBuffer.PolymorphicCastConstObjectSmartPointer<ConstVertexBufferSmartPointer>() };
	
	// 生成几何数据。
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(u, v, 0.0f));    
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(-u, v, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(u, -v, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(-u, -v, 0.0f));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(v, 0.0f, u));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(v, 0.0f, -u));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(-v, 0.0f, u));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(-v, 0.0f, -u));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(0.0f, u, v));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(0.0f, -u, v));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(0.0f, u, -v));
	vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(0.0f, -u, -v));

	CreatePlatonicNormals(vertexBufferAccessor, vertexBuffer);
	CreatePlatonicTextures(vertexBufferAccessor, vertexBuffer);
	TransformData(vertexBufferAccessor, vertexBuffer);

    // 生成索引
	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numIndices, 4, m_Usage) };
	vector<int> indices(numIndices);

    indices[ 0] =  0;  indices[ 1] =  8;  indices[ 2] =  4;
    indices[ 3] =  0;  indices[ 4] =  5;  indices[ 5] = 10;
    indices[ 6] =  2;  indices[ 7] =  4;  indices[ 8] =  9;
    indices[ 9] =  2;  indices[10] = 11;  indices[11] =  5;
    indices[12] =  1;  indices[13] =  6;  indices[14] =  8;
    indices[15] =  1;  indices[16] = 10;  indices[17] =  7;
    indices[18] =  3;  indices[19] =  9;  indices[20] =  6;
    indices[21] =  3;  indices[22] =  7;  indices[23] = 11;
    indices[24] =  0;  indices[25] = 10;  indices[26] =  8;
    indices[27] =  1;  indices[28] =  8;  indices[29] = 10;
    indices[30] =  2;  indices[31] =  9;  indices[32] = 11;
    indices[33] =  3;  indices[34] = 11;  indices[35] =  9;
    indices[36] =  4;  indices[37] =  2;  indices[38] =  0;
    indices[39] =  5;  indices[40] =  0;  indices[41] =  2;
    indices[42] =  6;  indices[43] =  1;  indices[44] =  3;
    indices[45] =  7;  indices[46] =  3;  indices[47] =  1;
    indices[48] =  8;  indices[49] =  6;  indices[50] =  4;
    indices[51] =  9;  indices[52] =  4;  indices[53] =  6;
    indices[54] = 10;  indices[55] =  5;  indices[56] =  7;
    indices[57] = 11;  indices[58] =  7;  indices[59] =  5;

	if (m_Inside)
	{
		ReverseTriangleOrder(numTriangles, &indices[0]);
	}

	indexBuffer->InitIndexBuffer(indices);

	return TrianglesMeshSmartPointer{ NEW0 TrianglesMesh(m_VertexFormat->Clone().PolymorphicCastObjectSmartPointer<VertexFormatSmartPointer>(),vertexBuffer, indexBuffer) };
}

// private
void Rendering::StandardMeshImpl
	::CreatePlatonicNormals(const VertexBufferAccessor& vertexBufferAccessor,VertexBufferSmartPointer& vertexBuffer) const 
{
	if (m_HasNormals)
	{
		const auto numVertices = vertexBufferAccessor.GetNumVertices();
		for (auto i = 0; i < numVertices; ++i)
		{
			auto position = vertexBufferAccessor.GetPosition<APoint>(i);
			vertexBuffer->SetTriangleNormal(vertexBufferAccessor, i, AVector(position[0], position[1], position[2]));	
		}
	}
}

// private
void Rendering::StandardMeshImpl
	::CreatePlatonicTextures(const VertexBufferAccessor& vertexBufferAccessor,VertexBufferSmartPointer& vertexBuffer) const
{
	for (auto unit = 0; unit < sm_MaxUnits; ++unit)
	{
		if (m_HasTextureCoords[unit])
		{
			const auto numVertices = vertexBufferAccessor.GetNumVertices();
			for (auto i = 0; i < numVertices; ++i)
			{
				auto position = vertexBufferAccessor.GetPosition<APoint>(i);
				Vector2D textures;
				if (Math::FAbs(position[2]) < 1.0f)
				{
					textures[0] = 0.5f * (1.0f + Math::ATan2(position[1],position[0]) * Math::sm_InversePI);
				}
				else
				{
					textures[0] = 0.5f;
				}

				textures[1] = Math::ACos(position[2]) * Math::sm_InversePI;

				vertexBuffer->SetTextureCoord(vertexBufferAccessor, i, textures, unit);
			}
		}
	}
}
 