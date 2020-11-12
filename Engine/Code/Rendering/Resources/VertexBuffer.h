// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 11:19)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Buffer.h"
#include "VertexFormat.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{	
	class VertexBufferAccessor;

	class RENDERING_DEFAULT_DECLARE VertexBuffer : public Buffer
	{
	public:
		using ClassType = VertexBuffer;
		using ParentType = Buffer;
		using VertexBufferSharedPtr = std::shared_ptr<ClassType>;
		using ConstVertexBufferSharedPtr = std::shared_ptr<const ClassType>;
		using ClassShareType = CoreTools::CopyUnsharedClasses;
		using AVector = Mathematics::FloatAVector;
		using APoint = Mathematics::FloatAPoint;
		using Vector2D = Mathematics::FloatVector2D;

	public:
                VertexBuffer() noexcept;
		VertexBuffer (int numVertices, int vertexSize,BufferUsage usage = BufferUsage::Static);
		  ~VertexBuffer ();
                VertexBuffer(const VertexBuffer&) = default;
                  VertexBuffer& operator=(const VertexBuffer&) = default;
                VertexBuffer(VertexBuffer&&) = default;
                VertexBuffer& operator=(VertexBuffer&&) = default;

		CLASS_INVARIANT_OVERRIDE_DECLARE;
				
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(VertexBuffer);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 

		// 支持文件读取和写入（字节排列顺序）
		void SaveToFile(WriteFileManager& outFile,const ConstVertexFormatSharedPtr& vertexformat) const;
		void ReadFromFile(ReadFileManager& inFile,const ConstVertexFormatSharedPtr& vertexformat);

		void ClearModelNormals(const VertexBufferAccessor& vertexBufferAccessor);
		void NormalizeModelNormals(const VertexBufferAccessor& vertexBufferAccessor);
		void AddTriangleNormal(const VertexBufferAccessor& vertexBufferAccessor,int index,const AVector& normal);
		void SetTriangleNormal(const VertexBufferAccessor& vertexBufferAccessor, int index,const AVector& normal);

		void SetTriangleTangent(const VertexBufferAccessor& vertexBufferAccessor,int index,const AVector& tangent);
		void SetTriangleBinormal(const VertexBufferAccessor& vertexBufferAccessor,int index,const AVector& binormal);
		void ClearTangent(const VertexBufferAccessor& vertexBufferAccessor);
		void ClearBinormal(const VertexBufferAccessor& vertexBufferAccessor);

		void SetTextureCoordStandard(const VertexBufferAccessor& vertexBufferAccessor);

		void SetPosition(const VertexBufferAccessor& vertexBufferAccessor, int index,const APoint& position);

		void SetTextureCoord(const VertexBufferAccessor& vertexBufferAccessor, int index, const Vector2D& textureCoord,int unit = 0);

		virtual VertexBufferSharedPtr Clone() const;
                ObjectInterfaceSharedPtr CloneObject() const override;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(VertexBuffer);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( VertexBuffer); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_RESOURCES_VERTEX_BUFFER_H
