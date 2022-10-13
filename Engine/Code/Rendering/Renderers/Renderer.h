///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 19:03)

#ifndef RENDERING_RENDERERS_RENDERER_H
#define RENDERING_RENDERERS_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "DepthRange.h"
#include "PickRay.h"
#include "RenderersInternalFwd.h"
#include "Viewport.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/DataTypes/DataTypesFwd.h"
#include "Rendering/GlobalEffects/GlobalEffect.h"
#include "Rendering/GlobalEffects/GlobalEffectsFwd.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Textures/DrawTarget.h"
#include "Rendering/Resources/Textures/Texture1D.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Resources/Textures/Texture3D.h"
#include "Rendering/Resources/Textures/TextureCube.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/VisualEffectInstance.h"
#include "Rendering/Shaders/WireState.h"

#include <string>

RENDERING_NON_COPY_EXPORT_IMPL(RendererImpl);
template class RENDERING_DEFAULT_DECLARE std::weak_ptr<Rendering::Renderer>;
template class RENDERING_DEFAULT_DECLARE std::enable_shared_from_this<Rendering::Renderer>;

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Renderer : public std::enable_shared_from_this<Renderer>
    {
    public:
        NON_COPY_TYPE_DECLARE(Renderer);
        using ColourUByte = Colour<uint8_t>;
        using Colour = Colour<float>;
        using Matrix = Mathematics::MatrixF;
        using RendererSharedPtr = std::shared_ptr<ClassType>;
        using ConstRendererSharedPtr = std::shared_ptr<const ClassType>;

    public:
        Renderer(const EnvironmentParameter& environmentParameter, const std::string& fileName);
        Renderer(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter);
        ~Renderer() noexcept;

        Renderer(Renderer&& rhs) noexcept;
        Renderer& operator=(Renderer&& rhs) noexcept;
        Renderer(const Renderer& rhs) noexcept = delete;
        Renderer& operator=(const Renderer& rhs) noexcept = delete;
        Renderer() noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Release();

        void SwapBuffers();

    public:
        // 初始化相关接口（必须手动调用）
        // 创建一个create函数，将构造函数设成私有
        void Init();

        NODISCARD static RendererSharedPtr Create(const std::string& fileName, const EnvironmentParameter& environmentParameter);

    public:
        // 平台无关的接口部分。

        // 访问构造函数的输入。
        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultisamples() const noexcept;

        // 资源管理。该资源被定义为顶点格式，顶点缓冲区，索引缓冲区，纹理（1D，2D，3D，立方体），
        // 渲染目标，顶点着色器和像素着色器。函数执行以下操作。

        // Bind:  创建对应于输入对象的资源。渲染器保存对象和资源之间的映射。
        //        在大多数情况下，视频存储器从物体相应的系统内存中进行分配和拷贝。
        //        如果Enable或Lock在Bind之前调用，渲染器默默地创建了一个资源，而不是导致异常。

        // Unbind:  销毁对应于输入对象的资源。渲染器从映射中删除对象资源。
        //          对象保持其系统存储器的拷贝和属性，所以它总是可以被再次绑定。

        // Enable:  该资源在在当前绘图中调用处于活动状态，但必须在调用DrawPrimitive之前。

        // Disable: 该资源在在当前绘图中调用处于非活动状态，但必须在调用DrawPrimitive之后。

        // Lock: 得到一个指向资源的视频存储器的指针（虽然存储器也可能是在AGP内存或者甚至取决于图形API和资源使用的系统内存）。
        //       使用此函数来更新显存。如果这样做，要知道，没有更新对象的相应系统存储装置中的两个内存拷贝不同步。
        //       您也可以只是为了读而锁定，在这种情况下，显存的内容被保留。保持资源锁定尽可能少的时间。

        // Unlock:  释放指到资源的视频存储器的指针。

        // Update:  锁定资源的视频存储器，复制系统存储器的内容到它，然后解锁视频内存。
        //          这是推荐更新资源的方式（更新系统内存，然后调用Update）。更新是为渲染调用函数。

        // 顶点格式管理。顶点格式对象必须是已经分配，它的属性和跨距由应用程序代码进行设置。
        void Bind(const ConstVertexFormatSharedPtr& vertexFormat);
        void Unbind(const ConstVertexFormatSharedPtr& vertexFormat);
        void Enable(const ConstVertexFormatSharedPtr& vertexFormat);
        void Disable(const ConstVertexFormatSharedPtr& vertexFormat);

        // 顶点缓冲区管理。顶点缓冲区对象必须是已经由应用程序代码分配。
        void Bind(const ConstVertexBufferSharedPtr& vertexBuffer);
        void Unbind(const ConstVertexBufferSharedPtr& vertexBuffer);
        void Enable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex = 0, int offset = 0);
        void Disable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex = 0);
        NODISCARD void* Lock(const ConstVertexBufferSharedPtr& vertexBuffer, BufferLocking mode);
        void Unlock(const ConstVertexBufferSharedPtr& vertexBuffer);
        void Update(const ConstVertexBufferSharedPtr& vertexBuffer);

        // 索引缓冲区管理。索引缓冲区对象必须是已经由应用程序代码分配。
        void Bind(const ConstIndexBufferSharedPtr& indexbuffer);
        void Unbind(const ConstIndexBufferSharedPtr& indexbuffer);
        void Enable(const ConstIndexBufferSharedPtr& indexbuffer);
        void Disable(const ConstIndexBufferSharedPtr& indexbuffer);
        NODISCARD void* Lock(const ConstIndexBufferSharedPtr& indexbuffer, BufferLocking mode);
        void Unlock(const ConstIndexBufferSharedPtr& indexbuffer);
        void Update(const ConstIndexBufferSharedPtr& indexbuffer);

        // 1D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
        void Bind(const ConstTexture1DSharedPtr& texture);
        void Unbind(const ConstTexture1DSharedPtr& texture);
        void Enable(const ConstTexture1DSharedPtr& texture, int textureUnit);
        void Disable(const ConstTexture1DSharedPtr& texture, int textureUnit);
        NODISCARD void* Lock(const ConstTexture1DSharedPtr& texture, int level, BufferLocking mode);
        void Unlock(const ConstTexture1DSharedPtr& texture, int level);
        void Update(const ConstTexture1DSharedPtr& texture, int level);

        // 2D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
        void Bind(const ConstTexture2DSharedPtr& texture);
        void Unbind(const ConstTexture2DSharedPtr& texture);
        void Enable(const ConstTexture2DSharedPtr& texture, int textureUnit);
        void Disable(const ConstTexture2DSharedPtr& texture, int textureUnit);
        NODISCARD void* Lock(const ConstTexture2DSharedPtr& texture, int level, BufferLocking mode);
        void Unlock(const ConstTexture2DSharedPtr& texture, int level);
        void Update(const ConstTexture2DSharedPtr& texture, int level);

        // 3D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
        void Bind(const ConstTexture3DSharedPtr& texture);
        void Unbind(const ConstTexture3DSharedPtr& texture);
        void Enable(const ConstTexture3DSharedPtr& texture, int textureUnit);
        void Disable(const ConstTexture3DSharedPtr& texture, int textureUnit);
        NODISCARD void* Lock(const ConstTexture3DSharedPtr& texture, int level, BufferLocking mode);
        void Unlock(const ConstTexture3DSharedPtr& texture, int level);
        void Update(const ConstTexture3DSharedPtr& texture, int level);

        // Cube纹理对象管理。纹理对象必须是已经由应用程序代码分配。
        void Bind(const ConstTextureCubeSharedPtr& texture);
        void Unbind(const ConstTextureCubeSharedPtr& texture);
        void Enable(const ConstTextureCubeSharedPtr& texture, int textureUnit);
        void Disable(const ConstTextureCubeSharedPtr& texture, int textureUnit);
        NODISCARD void* Lock(const ConstTextureCubeSharedPtr& texture, int face, int level, BufferLocking mode);
        void Unlock(const ConstTextureCubeSharedPtr& texture, int face, int level);
        void Update(const ConstTextureCubeSharedPtr& texture, int face, int level);

        // 渲染目标管理。渲染目标对象必须是已经由应用程序代码分配。
        // 在ReadColor的索引index是在多个渲染目标对象的目标索引。
        void Bind(const ConstDrawTargetSharedPtr& renderTarget);
        void Unbind(const ConstDrawTargetSharedPtr& renderTarget);
        void Enable(const ConstDrawTargetSharedPtr& renderTarget);
        void Disable(const ConstDrawTargetSharedPtr& renderTarget);
        NODISCARD ConstTexture2DSharedPtr ReadColor(int index, const ConstDrawTargetSharedPtr& renderTarget);

        // 顶点着色器管理。顶点着色器对象必须已经由应用程序代码分配。
        void Bind(const ConstVertexShaderSharedPtr& vshader);
        void Unbind(const ConstVertexShaderSharedPtr& vshader);
        void Enable(const ConstVertexShaderSharedPtr& vshader, const ShaderParameters& parameters);
        void Disable(const ConstVertexShaderSharedPtr& vshader, const ShaderParameters& parameters);

        // 像素着色器管理。像素着色器对象必须已经由应用程序代码分配。
        void Bind(const ConstPixelShaderSharedPtr& pshader);
        void Unbind(const ConstPixelShaderSharedPtr& pshader);
        void Enable(const ConstPixelShaderSharedPtr& pshader, const ShaderParameters& parameters);
        void Disable(const ConstPixelShaderSharedPtr& pshader, const ShaderParameters& parameters);

        // 访问当前的全局状态。
        NODISCARD ConstAlphaStateSharedPtr GetAlphaState() const noexcept;
        NODISCARD ConstCullStateSharedPtr GetCullState() const noexcept;
        NODISCARD ConstDepthStateSharedPtr GetDepthState() const noexcept;
        NODISCARD ConstOffsetStateSharedPtr GetOffsetState() const noexcept;
        NODISCARD ConstStencilStateSharedPtr GetStencilState() const noexcept;
        NODISCARD ConstWireStateSharedPtr GetWireState() const noexcept;

        // 覆盖全局状态。 如果被覆盖，则在图形调用期间使用此状态代替VisualPass状态。 要撤消覆盖，请传递空指针。
        NODISCARD ConstAlphaStateSharedPtr GetOverrideAlphaState() const noexcept;
        NODISCARD ConstCullStateSharedPtr GetOverrideCullState() const noexcept;
        NODISCARD ConstDepthStateSharedPtr GetOverrideDepthState() const noexcept;
        NODISCARD ConstOffsetStateSharedPtr GetOverrideOffsetState() const noexcept;
        NODISCARD ConstStencilStateSharedPtr GetOverrideStencilState() const noexcept;
        NODISCARD ConstWireStateSharedPtr GetOverrideWireState() const noexcept;
        void SetOverrideAlphaState(const ConstAlphaStateSharedPtr& alphaState);
        void SetOverrideCullState(const ConstCullStateSharedPtr& cullState);
        void SetOverrideDepthState(const ConstDepthStateSharedPtr& depthState);
        void SetOverrideOffsetState(const ConstOffsetStateSharedPtr& offsetState);
        void SetOverrideStencilState(const ConstStencilStateSharedPtr& stencilState);
        void SetOverrideWireState(const ConstWireStateSharedPtr& wireState);
        void SetReverseCullOrder(bool reverseCullOrder) noexcept;
        bool GetReverseCullOrder() const noexcept;

        // 访问当前相机状态。
        void SetCamera(const CameraSharedPtr& camera) noexcept;
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        NODISCARD CameraSharedPtr GetCamera() noexcept;
        NODISCARD Matrix GetViewMatrix() const;
        NODISCARD Matrix GetProjectionMatrix() const;
        NODISCARD Matrix GetPostProjectionMatrix() const;

        // 根据指定的左手屏幕坐标（x，y）并使用当前相机来计算光线。
        // 输出的“原点”是相机位置，而“方向”是单位长度矢量。
        // 两者都在世界坐标中。 如果（x，y）在当前视口中的则返回值为'true'。
        NODISCARD PickRay GetPickRay(int x, int y) const;

        // 访问颜色，深度和模板缓冲区的当前清除参数。 颜色缓冲区是后缓冲区。
        void SetClearColor(const Colour& clearColor) noexcept;
        NODISCARD Colour GetClearColor() const noexcept;
        void SetClearDepth(float clearDepth) noexcept;
        NODISCARD float GetClearDepth() const noexcept;
        void SetClearStencil(int clearStencil) noexcept;
        NODISCARD int GetClearStencil() const noexcept;

        // 访问当前的颜色通道蒙版
        NODISCARD bool GetAllowRed() const noexcept;
        NODISCARD bool GetAllowGreen() const noexcept;
        NODISCARD bool GetAllowBlue() const noexcept;
        NODISCARD bool GetAllowAlpha() const noexcept;
        void SetAllowRed(bool allowRed) noexcept;
        void SetAllowGreen(bool allowGreen) noexcept;
        void SetAllowBlue(bool allowBlue) noexcept;
        void SetAllowAlpha(bool allowAlpha) noexcept;

        // 绘制场景图的可见集合的入口点。
        void Draw(VisibleSet& visibleSet, GlobalEffect* globalEffect = nullptr);

        // 绘制单个对象的入口点。
        void Draw(const VisualSharedPtr& visual);
        void Draw(const VisualSharedPtr& visual, const VisualEffectInstanceSharedPtr& instance);

    public:
        // 接口的平台相关部分。

        // 视觉状态管理。
        void SetAlphaState(const ConstAlphaStateSharedPtr& alphaState);
        void SetCullState(const ConstCullStateSharedPtr& cullState);
        void SetDepthState(const ConstDepthStateSharedPtr& depthState);
        void SetOffsetState(const ConstOffsetStateSharedPtr& offsetState);
        void SetStencilState(const ConstStencilStateSharedPtr& stencilState);
        void SetWireState(const ConstWireStateSharedPtr& wireState);

        // 视口管理。 视口以右手屏幕坐标指定。 原点是屏幕的左下角，y轴指向上方，x轴指向右侧。
        void SetViewport(const Viewport& viewport);
        NODISCARD Viewport GetViewport() const;
        void SetDepthRange(const DepthRange& depthRange);
        NODISCARD DepthRange GetDepthRange() const;
        void Resize(int width, int height);

        void ResetSize();
        void InitDevice();

        // 支持清除颜色，深度和模板缓冲区。
        void ClearColorBuffer();
        void ClearDepthBuffer();
        void ClearStencilBuffer();
        void ClearBuffers();
        void ClearColorBuffer(int x, int y, int w, int h);
        void ClearDepthBuffer(int x, int y, int w, int h);
        void ClearStencilBuffer(int x, int y, int w, int h);
        void ClearBuffers(int x, int y, int w, int h);
        void DisplayColorBuffer();

        // 支持在绘制过程中掩藏颜色通道。
        void SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha);

        // 支持PreDraw和PostDraw语义。 所有Renderer抽象接口函数和绘图函数必须出现在以PreDraw()和PostDraw()为边界的代码块中。
        // 通用格式为
        // if (renderer->PreDraw())
        // {
        //		<抽象界面渲染器调用和绘制调用>;
        //		renderer->PostDraw();
        //	}
        NODISCARD bool PreDraw();
        void PostDraw();

        // 绘制2D缓冲区的入口点（用于2D应用程序）
        void Draw(const uint8_t* screenBuffer, bool reflectY = false);
        void Draw(const std::vector<ColourUByte>& screenBuffer, bool reflectY = false);

        // 绘制2D文本的入口点。
        void Draw(int x, int y, const Colour& color, const std::string& message);

        NODISCARD bool InTexture2DMap(const ConstTexture2DSharedPtr& texture);
        void InsertInTexture2DMap(const ConstTexture2DSharedPtr& texture, const PlatformTexture2DSharedPtr& platformTexture);

        NODISCARD RendererTypes GetRendererType() const;

    private:
        PackageType impl;
        int64_t rendererID;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(Renderer);
}

#endif  // RENDERING_RENDERERS_RENDERER_H
