// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 14:50)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"
#include "TriangleIndex.h"
#include "TrianglePosition.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Rendering
{
	class VertexBufferAccessor;

	class RENDERING_DEFAULT_DECLARE Triangles : public Visual
	{
	public:
		using ClassType = Triangles;
		using ParentType = Visual;
		using ClassShareType = CoreTools::CopyUnsharedClasses;
		using APoint = Mathematics::APointf;
		using AVector = Mathematics::AVectorf;
		using Vector3D = Mathematics::Vector3Df;
		using Vector2D = Mathematics::Vector2Df;
		using Line3 = Mathematics::Line3f;
		using Triangle3 = Mathematics::Triangle3f;
		using TrianglesSmartPointer = CoreTools::SeventhSubclassSmartPointer<ClassType>;
		using ConstTrianglesSmartPointer = CoreTools::ConstSeventhSubclassSmartPointer<ClassType>;

	public:
		explicit Triangles(VisualPrimitiveType type = VisualPrimitiveType::Triangles);
		Triangles(VisualPrimitiveType type,const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer);
		virtual ~Triangles();

		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(Triangles);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;	

		// 这些函数依赖于原始的三角索引缓存的解释。
		// 三角形<V0,V1,V2>是逆时针顺序。	
		// 索引错误将抛出异常。
		virtual int GetNumTriangles () const = 0;
		virtual const TriangleIndex GetTriangle(int index) const = 0;
		const TrianglePosition GetModelTriangle(int index) const;
		const TrianglePosition GetWorldTriangle(int index) const;
		
		// 支持以基本边界树的碰撞检测。输入索引和'vertexIndex'必须包含在索引缓冲器。
		int GetNumVertices () const;
		const Vector3D GetPosition(int vertexIndex) const;
		
		virtual void UpdateModelSpace(VisualUpdateType type) override;

		virtual const PickRecordContainer ExecuteRecursive(const APoint& origin,const AVector& direction, float tMin, float tMax) const override;
		
	private:
		// 支持几何更新
		void UpdateModelNormals(const VertexBufferAccessor& vertexBufferAccessor);
		
		// 专门更新的切线空间。
		void UpdateModelTangentsUseGeometry(const VertexBufferAccessor& vertexBufferAccessor);
		void UpdateModelTangentsUseTextureCoords(const VertexBufferAccessor& vertexBufferAccessor);
		
		// 此函数用于UpdateModelTangentsUseTextureCoords计算一个切矢量在position0。
		// 该三角形的位置position0，position1和position2，以逆时针顺序列出。
		// 相应的纹理坐标textureCoord0，textureCoord1和textureCoord2，
		// 和那些与纹理相关的坐标'通道'传递给UpdateModelTangentsUseTextureCoords的。
		static const AVector ComputeTangent(const APoint& position0, const Vector2D& textureCoord0,const APoint& position1,
											const Vector2D& textureCoord1,const APoint& position2, const Vector2D& textureCoord2);
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(Triangles);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Seventh, Triangles); 
}

#endif // RENDERING_SCENE_GRAPH_TRIANGLES_H
