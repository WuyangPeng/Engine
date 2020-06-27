// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 14:50)

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

		// ��Щ����������ԭʼ��������������Ľ��͡�
		// ������<V0,V1,V2>����ʱ��˳��	
		// ���������׳��쳣��
		virtual int GetNumTriangles () const = 0;
		virtual const TriangleIndex GetTriangle(int index) const = 0;
		const TrianglePosition GetModelTriangle(int index) const;
		const TrianglePosition GetWorldTriangle(int index) const;
		
		// ֧���Ի����߽�������ײ��⡣����������'vertexIndex'���������������������
		int GetNumVertices () const;
		const Vector3D GetPosition(int vertexIndex) const;
		
		virtual void UpdateModelSpace(VisualUpdateType type) override;

		virtual const PickRecordContainer ExecuteRecursive(const APoint& origin,const AVector& direction, float tMin, float tMax) const override;
		
	private:
		// ֧�ּ��θ���
		void UpdateModelNormals(const VertexBufferAccessor& vertexBufferAccessor);
		
		// ר�Ÿ��µ����߿ռ䡣
		void UpdateModelTangentsUseGeometry(const VertexBufferAccessor& vertexBufferAccessor);
		void UpdateModelTangentsUseTextureCoords(const VertexBufferAccessor& vertexBufferAccessor);
		
		// �˺�������UpdateModelTangentsUseTextureCoords����һ����ʸ����position0��
		// �������ε�λ��position0��position1��position2������ʱ��˳���г���
		// ��Ӧ����������textureCoord0��textureCoord1��textureCoord2��
		// ����Щ��������ص�����'ͨ��'���ݸ�UpdateModelTangentsUseTextureCoords�ġ�
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
