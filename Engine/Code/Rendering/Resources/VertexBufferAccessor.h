///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 18:47)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_H

#include "Rendering/RenderingDll.h"

#include "VertexBuffer.h"
#include "VertexFormat.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(VertexBufferAccessor, VertexBufferAccessorImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexBufferAccessor
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(VertexBufferAccessor);

    public:
        VertexBufferAccessor(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer);
        explicit VertexBufferAccessor(const Visual& visual);

        CLASS_INVARIANT_DECLARE;

        void ApplyTo(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer);
        void ApplyTo(const Visual& visual);

        NODISCARD const char* GetData() const noexcept;
        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD int GetStride() const noexcept;

        // 通用访问顶点缓冲区中的数据。
        // The Get*Channels()函数仅用于FLOAT{1,2,3,4}的数据有效，并返回浮点数属性的数目。
        template <typename T>
        NODISCARD T GetPosition(int index) const noexcept;
        NODISCARD const char* GetPosition(int index) const noexcept;
        NODISCARD bool HasPosition() const noexcept;
        NODISCARD int GetPositionChannels() const noexcept;
        NODISCARD const float* GetPositionTuple(int index) const noexcept;
        NODISCARD int GetPositionExcursion(int index) const;

        template <typename T>
        NODISCARD T GetNormal(int index) const noexcept;
        NODISCARD const char* GetNormal(int index) const noexcept;
        NODISCARD bool HasNormal() const noexcept;
        NODISCARD int GetNormalChannels() const noexcept;
        NODISCARD const float* GetNormalTuple(int index) const noexcept;
        NODISCARD int GetNormalExcursion(int index) const;

        template <typename T>
        NODISCARD T GetTangent(int index) const noexcept;
        NODISCARD const char* GetTangent(int index) const noexcept;
        NODISCARD bool HasTangent() const noexcept;
        NODISCARD int GetTangentChannels() const noexcept;
        NODISCARD const float* GetTangentTuple(int index) const noexcept;
        NODISCARD int GetTangentExcursion(int index) const;

        template <typename T>
        NODISCARD T GetBinormal(int index) const noexcept;
        NODISCARD const char* GetBinormal(int index) const noexcept;
        NODISCARD bool HasBinormal() const noexcept;
        NODISCARD int GetBinormalChannels() const noexcept;
        NODISCARD const float* GetBinormalTuple(int index) const noexcept;
        NODISCARD int GetBinormalExcursion(int index) const;

        template <typename T>
        NODISCARD T GetTextureCoord(int unit, int index) const;
        NODISCARD const char* GetTextureCoord(int unit, int index) const;
        NODISCARD bool HasTextureCoord(int unit) const;
        NODISCARD int GetTextureCoordChannels(int unit) const;
        NODISCARD const float* GetTextureCoordTuple(int unit, int index) const;
        NODISCARD int GetTextureCoordExcursion(int unit, int index) const;

        template <typename T>
        NODISCARD T GetColor(int unit, int index) const;
        NODISCARD const char* GetColor(int unit, int index) const;
        NODISCARD bool HasColor(int unit) const;
        NODISCARD int GetColorChannels(int unit) const;
        NODISCARD const float* GetColorTuple(int unit, int index) const;

        template <typename T>
        NODISCARD T GetBlendIndices(int index) const;
        NODISCARD const char* GetBlendIndices(int index) const noexcept;
        NODISCARD bool HasBlendIndices() const noexcept;

        template <typename T>
        NODISCARD T GetBlendWeight(int index) const;
        NODISCARD const char* GetBlendWeight(int index) const noexcept;
        NODISCARD bool HasBlendWeight() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_H
