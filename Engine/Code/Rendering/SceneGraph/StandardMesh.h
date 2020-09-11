// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 14:05)

#ifndef RENDERING_SCENE_GRAPH_STANDARD_MESH_H
#define RENDERING_SCENE_GRAPH_STANDARD_MESH_H

#include "Rendering/RenderingDll.h" 

#include "TrianglesMesh.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/Resources/VertexBufferAccessor.h" 

RENDERING_EXPORT_SHARED_PTR(StandardMeshImpl);

namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE StandardMesh
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(StandardMesh);

	public:
		// 标准的网格。每个网格是以(0,0,0)为中心，
		// 并且具有(0,0,1)的up轴。
		// 坐标系统中的其它轴(1,0,0)和 (0,1,0)。
		// 应用程序可以通过提供一个输入'transform'给构造函数以变换网格。
		// 如果一个封闭的网状是要对对象外部观察者可见的，
		// 那么“inside”设置为“false”;否则，设置“inside”到“true”，
		// 使得观察者会看到物体内部时的网格。
		// 设置“isStatic”为“true”具有缓冲区用法BufferUsage::Static。
		// 否则“isStatic'是“false”具有缓冲区用法BufferUsage::Dynamic。
		StandardMesh(const VertexFormatSmartPointer& vertexFormat,bool isStatic = true,bool inside = false,const FloatTransform* transform = nullptr);		 

		CLASS_INVARIANT_DECLARE;

		// 访问网格创造者的转换
		void SetTransform(const FloatTransform& transform);
		const FloatTransform& GetTransform() const noexcept;
	
		// 下面各种对象的注释是当输入“transform”是nullptr(单位transform)。

        // 矩形是在z = 0平面，并是观察者可见的，
		// 是在平面上法线（0,0,1）点的一侧。
		// 它有角(-xExtent, -yExtent, 0)，(+xExtent, -yExtent, 0),
		// (-xExtent, +yExtent, 0)和(+xExtent, +yExtent, 0)。
		// 该网格总共有xSamples顶点在x方向和ySamples顶点在y方向上
		// 所以总共有xSamples * ySamples顶点。
		const TrianglesMeshSmartPointer Rectangle(int xSamples, int ySamples,float xExtent, float yExtent) const;

		// 矩形是在z = 0平面，并是观察者可见的，
		// 是在平面上法线（0,0,1）点的一侧。
		// 它有中心（0,0,0）和指定的“半径”。
		// 该网格具有中心在第一顶点。
		// 样品放置在沿射线的共同原点中心点。
		// 有“radialSamples”条射线。
		// 沿着每条射线的风格具有“shellSamples'个顶点。
		const TrianglesMeshSmartPointer Disk(int shellSamples, int radialSamples,float radius) const;


		// 盒子在中心(0,0,0)，单位长度轴(1,0,0), (0,1,0), 和(0,0,1)
		// 和范围（半长）'xExtent', 'yExtent', 和 'zExtent'。
		// 网格具有8个顶点和12个三角形。
		// 例子，盒子角在第一个八分区是(xExtent, yExtent, zExtent)。
		const TrianglesMeshSmartPointer Box(float xExtent, float yExtent,float zExtent) const;

		// 圆柱有中心(0,0,0)，指定的半径，指定的高度。
		// 圆柱的轴是一条线段(0,0,0)+ t * (0,0,1)，其中|t| <= height/2。
		// 圆柱壁是隐式地定义为 x^2 + y^2 = radius^2.。
		// CylinderOmittedEndDisks,圆柱底盘被省略,你有一个开放的管。
		// CylinderIncludedEndDisks,圆柱底盘被包括在内。
		// 每个底盘是一个规则的正多边形，完全嵌合在包括一个中心为顶点的多边形,
		// 多边形分解为三角形,所有三角形共享中心顶点
		// 和每个三角形包含一个多边形的边。
		const TrianglesMeshSmartPointer CylinderOmittedEndDisks(int axisSamples, int radialSamples,float radius,float height) const;
		const TrianglesMeshSmartPointer CylinderIncludedEndDisks(int axisSamples, int radialSamples,float radius,float height) const;

		// 球体在中心点 (0,0,0) 和指定半径。
		// 北极在(0,0,radius)和南极在(0,0,-radius)。
		// 网格的拓扑结构是一个开放的圆柱
		// (也是一个矩形的拓扑与全方位的一对平行边),然后缝合到南北两极。
		// 三角形分布不均。如果你想要一个更均匀分布,创建一个二十面体和细分它。
		const TrianglesMeshSmartPointer Sphere(int zSamples, int radialSamples,float radius) const;

		// 圆环面有中心点(0,0,0)。
		// 如果你观察环沿线的方向(0,0,1),您将看到一个环。
		// 圆的中心环半径为“outerRadius”。
		// 这个圆的距离的边界环是内半径。
		const TrianglesMeshSmartPointer Torus(int circleSamples, int radialSamples,float outerRadius,float innerRadius) const;

		// 柏拉图立方体，所有内切在一个单位圆，中心在(0,0,0)。
		const TrianglesMeshSmartPointer Tetrahedron() const;
		const TrianglesMeshSmartPointer Hexahedron() const;
		const TrianglesMeshSmartPointer Octahedron() const;
		const TrianglesMeshSmartPointer Dodecahedron() const;
		const TrianglesMeshSmartPointer Icosahedron() const;

	private:
		;
		IMPL_TYPE_DECLARE(PickRecord);
	};
}

#endif // RENDERING_SCENE_GRAPH_STANDARD_MESH_H
