/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 10:01)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DEVICE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DEVICE_H

#include "Rendering/RenderingDll.h"

#include "ProgramIndexUnitContainer.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/OpenGLRenderer/InputLayout/OpenGLInputLayoutManager.h"
#include "Rendering/RendererEngine/Detail/RenderingDeviceImpl.h"
#include "Rendering/Resources/Buffers/RawBuffer.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLDevice : public RenderingDeviceImpl
    {
    public:
        using ClassType = OpenGLDevice;
        using ParentType = RenderingDeviceImpl;

    public:
        explicit OpenGLDevice(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingDeviceSharedPtr Clone() const override;

        void DisplayColorBuffer(int syncInterval) override;
        void InitDevice() noexcept override;
        void Release() noexcept override;

        void SetViewport(const Viewport& viewport) noexcept override;
        NODISCARD Viewport GetViewport() const override;
        void SetDepthRange(const DepthRange& depthRange) noexcept override;
        NODISCARD DepthRange GetDepthRange() const override;

        NODISCARD bool HasDepthRange01() const noexcept override;
        NODISCARD std::string GetShaderName(const std::string& name) const override;
        NODISCARD std::string GetShaderExtendName() const override;
        void Resize(int width, int height) override;

        NODISCARD int64_t DrawPrimitive(RendererObjectBridge& rendererObjectBridge,
                                        const VertexBufferSharedPtr& vertexBuffer,
                                        const IndexBufferSharedPtr& indexBuffer,
                                        const VisualEffectSharedPtr& effect) override;

        void ClearColorBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearDepthBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearStencilBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearBuffers(const RendererClear& rendererClear) noexcept override;

        void WaitForFinish() noexcept override;
        void Flush() noexcept override;
        void Execute(RendererObjectBridge& rendererObjectBridge,
                     ComputeProgram& computeProgram,
                     int numXGroups,
                     int numYGroups,
                     int numZGroups) override;

    private:
        using OpenGLUInt = System::OpenGLUnsignedInt;

    private:
        NODISCARD bool EnableShaders(RendererObjectBridge& rendererObjectBridge, VisualEffect& effect, OpenGLUInt program);
        void DisableShaders(RendererObjectBridge& rendererObjectBridge, VisualEffect& effect, OpenGLUInt program);
        void Enable(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void Disable(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void EnableConstantBuffers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void DisableConstantBuffers(Shader& shader, OpenGLUInt program);
        void EnableTextureBuffers(Shader& shader, OpenGLUInt program) noexcept;
        void DisableTextureBuffers(Shader& shader, OpenGLUInt program) noexcept;
        void EnableStructuredBuffers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void DisableStructuredBuffers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void EnableRawBuffers(Shader& shader, OpenGLUInt program) noexcept;
        void DisableRawBuffers(Shader& shader, OpenGLUInt program) noexcept;
        void EnableTextures(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void DisableTextures(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void EnableTextureArrays(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void DisableTextureArrays(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void EnableSamplers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);
        void DisableSamplers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program);

        /// 支持绘图。
        NODISCARD static int64_t DrawPrimitive(const VertexBuffer& vertexBuffer, const IndexBuffer& indexBuffer);

    private:
        using RawBufferContainer = std::vector<RawBufferSharedPtr>;

    private:
        OpenGLInputLayoutManager openGLInputLayoutManager;
        ProgramIndexUnitContainer textureSamplerUnit;
        ProgramIndexUnitContainer textureImageUnit;
        ProgramIndexUnitContainer uniformUnit;
        ProgramIndexUnitContainer shaderStorageUnit;

        /// 为每个声明用于执行的着色器的原子计数器缓冲区对象创建一个前端对象（对用户隐藏）。
        /// 执行之后，这些对象将保留以供下次使用。
        /// 只有当需要更大的缓冲区时，它们才会被销毁以创建新的缓冲区，但缓冲区大小永远不会变小。
        /// 这里使用RawBuffer类型，因为根据定义，它是每个元素4个字节，其中4个字节是每个atomic_uint计数器的大小。
        RawBufferContainer atomicCounterRawBuffers;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEVICE_H
