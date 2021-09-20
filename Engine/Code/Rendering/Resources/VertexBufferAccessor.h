// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 11:20)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_H

#include "Rendering/RenderingDll.h"

#include "VertexBuffer.h"
#include "VertexFormat.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(VertexBufferAccessor,VertexBufferAccessorImpl);

namespace Rendering
{
    class Visual;

    class RENDERING_DEFAULT_DECLARE VertexBufferAccessor
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(VertexBufferAccessor);

    public:
        VertexBufferAccessor(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer);
        explicit VertexBufferAccessor(Visual* visual);

        CLASS_INVARIANT_DECLARE;

        void ApplyTo(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer);
        void ApplyTo(const Visual* visual);

        const char* GetData() const noexcept;
        int GetNumVertices() const noexcept;
        int GetStride() const noexcept;

        // 通用访问顶点缓冲区中的数据。
        // The Get*Channels()函数仅用于FLOAT{1,2,3,4}的数据有效，并返回浮点数属性的数目。
        template <typename T>
        T GetPosition(int index) const noexcept;
        const char* GetPosition(int index) const noexcept;
        bool HasPosition() const noexcept;
        int GetPositionChannels() const noexcept;
        const float* GetPositionTuple(int index) const noexcept;
        int GetPositionExcursion(int index) const;

        template <typename T>
        T GetNormal(int index) const noexcept;
        const char* GetNormal(int index) const noexcept;
        bool HasNormal() const noexcept;
        int GetNormalChannels() const noexcept;
        const float* GetNormalTuple(int index) const noexcept;
        int GetNormalExcursion(int index) const;

        template <typename T>
        T GetTangent(int index) const noexcept;
        const char* GetTangent(int index) const noexcept;
        bool HasTangent() const noexcept;
        int GetTangentChannels() const noexcept;
        const float* GetTangentTuple(int index) const noexcept;
        int GetTangentExcursion(int index) const;

        template <typename T>
        T GetBinormal(int index) const noexcept;
        const char* GetBinormal(int index) const noexcept;
        bool HasBinormal() const noexcept;
        int GetBinormalChannels() const noexcept;
        const float* GetBinormalTuple(int index) const noexcept;
        int GetBinormalExcursion(int index) const;

        template <typename T>
        T GetTextureCoord(int unit, int index) const;
        const char* GetTextureCoord(int unit, int index) const;
        bool HasTextureCoord(int unit) const;
        int GetTextureCoordChannels(int unit) const;
        const float* GetTextureCoordTuple(int unit, int index) const;
        int GetTextureCoordExcursion(int unit, int index) const;

        template <typename T>
        T GetColor(int unit, int index) const;
        const char* GetColor(int unit, int index) const;
        bool HasColor(int unit) const;
        int GetColorChannels(int unit) const;
        const float* GetColorTuple(int unit, int index) const;

        template <typename T>
        T GetBlendIndices(int index) const;
        const char* GetBlendIndices(int index) const noexcept;
        bool HasBlendIndices() const noexcept;

        template <typename T>
        T GetBlendWeight(int index) const;
        const char* GetBlendWeight(int index) const noexcept;
        bool HasBlendWeight() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_H
