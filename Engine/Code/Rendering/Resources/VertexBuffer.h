///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 16:30)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "ResourcesFwd.h"
#include "VertexFormat.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexBuffer : public Buffer
    {
    public:
        using ClassType = VertexBuffer;
        using ParentType = Buffer;
        using VertexBufferSharedPtr = std::shared_ptr<ClassType>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const ClassType>;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;
        using Vector2D = Mathematics::Vector2F;

    public:
        NODISCARD static VertexBufferSharedPtr Create();
        NODISCARD static VertexBufferSharedPtr Create(int numVertices, int vertexSize, BufferUsage usage = BufferUsage::Static);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(VertexBuffer);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        // 支持文件读取和写入（字节排列顺序）
        void SaveToFile(WriteFileManager& outFile, const VertexFormat& vertexformat) const;
        void ReadFromFile(ReadFileManager& inFile, const VertexFormat& vertexformat);

        void ClearModelNormals(const VertexBufferAccessor& vertexBufferAccessor);
        void NormalizeModelNormals(const VertexBufferAccessor& vertexBufferAccessor);
        void AddTriangleNormal(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& normal);
        void SetTriangleNormal(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& normal);

        void SetTriangleTangent(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& tangent);
        void SetTriangleBinormal(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& binormal);
        void ClearTangent(const VertexBufferAccessor& vertexBufferAccessor);
        void ClearBinormal(const VertexBufferAccessor& vertexBufferAccessor);

        void SetTextureCoordStandard(const VertexBufferAccessor& vertexBufferAccessor);

        void SetPosition(const VertexBufferAccessor& vertexBufferAccessor, int index, const APoint& position);

        void SetTextureCoord(const VertexBufferAccessor& vertexBufferAccessor, int index, const Vector2D& textureCoord, int unit = 0);

        NODISCARD virtual VertexBufferSharedPtr Clone() const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        enum class VertexBufferCreate
        {
            Init,
        };

    public:
        explicit VertexBuffer(MAYBE_UNUSED VertexBufferCreate indexBufferCreate);
        VertexBuffer(MAYBE_UNUSED VertexBufferCreate indexBufferCreate, int numVertices, int vertexSize, BufferUsage usage = BufferUsage::Static);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(VertexBuffer);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VertexBuffer);
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_H
