// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.3.0 (2020/03/27 11:09)

#ifndef RENDERING_RENDERERS_RENDERER_H
#define RENDERING_RENDERERS_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "PickRay.h"
#include "Viewport.h"
#include "DepthRange.h"
#include "RenderersInternalFwd.h"

#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/Shaders/WireState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/StencilState.h" 
#include "Rendering/Shaders/VisualEffectInstance.h"

#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Resources/Texture3D.h"
#include "Rendering/Resources/TextureCube.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/RenderTarget.h"

#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

#include "Rendering/GlobalEffects/GlobalEffectsFwd.h"
#include "Rendering/GlobalEffects/GlobalEffect.h"

#include "Rendering/DataTypes/DataTypesFwd.h"
#include "Rendering/DataTypes/Colour.h"

#include <boost/noncopyable.hpp>
#include <string>

EXPORT_NONCOPYABLE_CLASS(RENDERING);
RENDERING_EXPORT_SHARED_PTR(RendererImpl);
template class RENDERING_DEFAULT_DECLARE std::weak_ptr<Rendering::Renderer>;
template class RENDERING_DEFAULT_DECLARE std::enable_shared_from_this<Rendering::Renderer>;

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE Renderer : private boost::noncopyable, public std::enable_shared_from_this<Renderer>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Renderer);   
		using ColourUByte = Colour<uint8_t>;
		using Colour = Colour<float>;	
		using Matrix = Mathematics::FloatMatrix;

	public:
		explicit Renderer(const std::string& fileName);
		Renderer(RendererTypes type, const RendererBasis& basis);
		~Renderer();

		Renderer(Renderer&& rhs) noexcept;
		Renderer& operator=(Renderer&& rhs) noexcept;
                Renderer(const Renderer& rhs) noexcept = delete;
                Renderer& operator=(const Renderer& rhs) noexcept = delete;
		Renderer() = delete;

		CLASS_INVARIANT_DECLARE;

	public:
		// ��ʼ����ؽӿڣ������ֶ����ã�
		// ����һ��create�����������캯�����˽��
		void Init();

	public:
		// ƽ̨�޹صĽӿڲ��֡�

		// ���ʹ��캯�������롣
		int GetWidth() const;
		int GetHeight() const;
		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;

		// ��Դ��������Դ������Ϊ�����ʽ�����㻺����������������������1D��2D��3D�������壩��
		// ��ȾĿ�꣬������ɫ����������ɫ��������ִ�����²�����

		// Bind:  ������Ӧ������������Դ����Ⱦ������������Դ֮���ӳ�䡣
		//        �ڴ��������£���Ƶ�洢����������Ӧ��ϵͳ�ڴ��н��з���Ϳ�����
		//        ���Enable��Lock��Bind֮ǰ���ã���Ⱦ��ĬĬ�ش�����һ����Դ�������ǵ����쳣��

		// Unbind:  ���ٶ�Ӧ������������Դ����Ⱦ����ӳ����ɾ��������Դ��
		//          ���󱣳���ϵͳ�洢���Ŀ��������ԣ����������ǿ��Ա��ٴΰ󶨡�

		// Enable:  ����Դ���ڵ�ǰ��ͼ�е��ô��ڻ״̬���������ڵ���DrawPrimitive֮ǰ��

		// Disable: ����Դ���ڵ�ǰ��ͼ�е��ô��ڷǻ״̬���������ڵ���DrawPrimitive֮��

		// Lock: �õ�һ��ָ����Դ����Ƶ�洢����ָ�루��Ȼ�洢��Ҳ��������AGP�ڴ��������ȡ����ͼ��API����Դʹ�õ�ϵͳ�ڴ棩��
		//       ʹ�ô˺����������Դ档�����������Ҫ֪����û�и��¶������Ӧϵͳ�洢װ���е������ڴ濽����ͬ����
		//       ��Ҳ����ֻ��Ϊ�˶�������������������£��Դ�����ݱ�������������Դ�����������ٵ�ʱ�䡣

		// Unlock:  �ͷ�ָ����Դ����Ƶ�洢����ָ�롣

		// Update:  ������Դ����Ƶ�洢��������ϵͳ�洢�������ݵ�����Ȼ�������Ƶ�ڴ档
		//          �����Ƽ�������Դ�ķ�ʽ������ϵͳ�ڴ棬Ȼ�����Update����������Ϊ��Ⱦ���ú�����

		// �����ʽ���������ʽ����������Ѿ����䣬�������ԺͿ����Ӧ�ó������������á�
		void Bind(const ConstVertexFormatSmartPointer& vertexFormat);
		void Unbind(const ConstVertexFormatSmartPointer& vertexFormat);
		void Enable(const ConstVertexFormatSmartPointer& vertexFormat);
		void Disable(const ConstVertexFormatSmartPointer& vertexFormat);

		// ���㻺�����������㻺��������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstVertexBufferSmartPointer& vertexBuffer);
		void Unbind(const ConstVertexBufferSmartPointer& vertexBuffer);
		void Enable(const ConstVertexBufferSmartPointer& vertexBuffer, int streamIndex = 0, int offset = 0);
		void Disable(const ConstVertexBufferSmartPointer& vertexBuffer, int streamIndex = 0);
		void* Lock(const ConstVertexBufferSmartPointer& vertexBuffer, BufferLocking mode);
		void Unlock(const ConstVertexBufferSmartPointer& vertexBuffer);
		void Update(const ConstVertexBufferSmartPointer& vertexBuffer);

		// ����������������������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstIndexBufferSmartPointer& indexbuffer);
		void Unbind(const ConstIndexBufferSmartPointer& indexbuffer);
		void Enable(const ConstIndexBufferSmartPointer& indexbuffer);
		void Disable(const ConstIndexBufferSmartPointer& indexbuffer);
		void* Lock(const ConstIndexBufferSmartPointer& indexbuffer, BufferLocking mode);
		void Unlock(const ConstIndexBufferSmartPointer& indexbuffer);
		void Update(const ConstIndexBufferSmartPointer& indexbuffer);

		// 1D�����������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstTexture1DSmartPointer& texture);
		void Unbind(const ConstTexture1DSmartPointer& texture);
		void Enable(const ConstTexture1DSmartPointer& texture, int textureUnit);
		void Disable(const ConstTexture1DSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTexture1DSmartPointer& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture1DSmartPointer& texture, int level);
		void Update(const ConstTexture1DSmartPointer& texture, int level);

		// 2D�����������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstTexture2DSmartPointer& texture);
		void Unbind(const ConstTexture2DSmartPointer& texture);
		void Enable(const ConstTexture2DSmartPointer& texture, int textureUnit);
		void Disable(const ConstTexture2DSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTexture2DSmartPointer& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture2DSmartPointer& texture, int level);
		void Update(const ConstTexture2DSmartPointer& texture, int level);

		// 3D�����������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstTexture3DSmartPointer& texture);
		void Unbind(const ConstTexture3DSmartPointer& texture);
		void Enable(const ConstTexture3DSmartPointer& texture, int textureUnit);
		void Disable(const ConstTexture3DSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTexture3DSmartPointer& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture3DSmartPointer& texture, int level);
		void Update(const ConstTexture3DSmartPointer& texture, int level);

		// Cube�����������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstTextureCubeSmartPointer& texture);
		void Unbind(const ConstTextureCubeSmartPointer& texture);
		void Enable(const ConstTextureCubeSmartPointer& texture, int textureUnit);
		void Disable(const ConstTextureCubeSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTextureCubeSmartPointer& texture, int face, int level, BufferLocking mode);
		void Unlock(const ConstTextureCubeSmartPointer& texture, int face, int level);
		void Update(const ConstTextureCubeSmartPointer& texture, int face, int level);

		// ��ȾĿ�������ȾĿ�����������Ѿ���Ӧ�ó��������䡣
		// ��ReadColor������index���ڶ����ȾĿ������Ŀ�������� 
		void Bind(const ConstRenderTargetSmartPointer& renderTarget);
		void Unbind(const ConstRenderTargetSmartPointer& renderTarget);
		void Enable(const ConstRenderTargetSmartPointer& renderTarget);
		void Disable(const ConstRenderTargetSmartPointer& renderTarget);
		ConstTexture2DSmartPointer ReadColor(int index, const ConstRenderTargetSmartPointer& renderTarget);	
 
		// ������ɫ������������ɫ����������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstVertexShaderSmartPointer& vshader);
		void Unbind(const ConstVertexShaderSmartPointer& vshader);
		void Enable(const ConstVertexShaderSmartPointer& vshader, const ConstShaderParametersSmartPointer& parameters);
		void Disable(const ConstVertexShaderSmartPointer& vshader, const ConstShaderParametersSmartPointer& parameters);
 
		// ������ɫ������������ɫ����������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstPixelShaderSmartPointer& pshader);
		void Unbind(const ConstPixelShaderSmartPointer& pshader);
		void Enable(const ConstPixelShaderSmartPointer& pshader, const ConstShaderParametersSmartPointer& parameters);
		void Disable(const ConstPixelShaderSmartPointer& pshader, const ConstShaderParametersSmartPointer& parameters);

		// ���ʵ�ǰ��ȫ��״̬��
		const ConstAlphaStateSmartPointer GetAlphaState() const;
		const ConstCullStateSmartPointer GetCullState() const;
		const ConstDepthStateSmartPointer GetDepthState() const;
		const ConstOffsetStateSmartPointer GetOffsetState() const;
		const ConstStencilStateSmartPointer GetStencilState() const;
		const ConstWireStateSmartPointer GetWireState() const;		

		// ����ȫ��״̬�� ��������ǣ�����ͼ�ε����ڼ�ʹ�ô�״̬����VisualPass״̬�� Ҫ�������ǣ��봫�ݿ�ָ�롣
		const ConstAlphaStateSmartPointer GetOverrideAlphaState() const;
		const ConstCullStateSmartPointer GetOverrideCullState() const;
		const ConstDepthStateSmartPointer GetOverrideDepthState() const;
		const ConstOffsetStateSmartPointer GetOverrideOffsetState() const;
		const ConstStencilStateSmartPointer GetOverrideStencilState() const;
		const ConstWireStateSmartPointer GetOverrideWireState() const;
		void SetOverrideAlphaState(const ConstAlphaStateSmartPointer& alphaState);
		void SetOverrideCullState(const ConstCullStateSmartPointer& cullState);
		void SetOverrideDepthState(const ConstDepthStateSmartPointer& depthState);
		void SetOverrideOffsetState(const ConstOffsetStateSmartPointer& offsetState);
		void SetOverrideStencilState(const ConstStencilStateSmartPointer& stencilState);
		void SetOverrideWireState(const ConstWireStateSmartPointer& wireState);		
		void SetReverseCullOrder(bool reverseCullOrder);
		bool GetReverseCullOrder() const;

		// ���ʵ�ǰ���״̬��
		void SetCamera(const CameraSmartPointer& camera);
		const ConstCameraSmartPointer GetCamera() const;
		const CameraSmartPointer GetCamera();
		const Matrix GetViewMatrix() const;
		const Matrix GetProjectionMatrix() const;
		const Matrix GetPostProjectionMatrix() const;

		// ����ָ����������Ļ���꣨x��y����ʹ�õ�ǰ�����������ߡ� 
		// ����ġ�ԭ�㡱�����λ�ã����������ǵ�λ����ʸ���� 
		// ���߶������������С� �����x��y���ڵ�ǰ�ӿ��е��򷵻�ֵΪ'true'��
		PickRay GetPickRay(int x, int y) const;

		// ������ɫ����Ⱥ�ģ�建�����ĵ�ǰ��������� ��ɫ�������Ǻ󻺳�����
		void SetClearColor(const Colour& clearColor);
		const Colour GetClearColor() const;
		void SetClearDepth(float clearDepth);
		float GetClearDepth() const;
		void SetClearStencil(int clearStencil);
		int GetClearStencil() const;

		// ���ʵ�ǰ����ɫͨ���ɰ�
		bool GetAllowRed() const;
		bool GetAllowGreen() const;
		bool GetAllowBlue() const;
		bool GetAllowAlpha() const;
		void SetAllowRed(bool allowRed);
		void SetAllowGreen(bool allowGreen);
		void SetAllowBlue(bool allowBlue);
		void SetAllowAlpha(bool allowAlpha);

		// ���Ƴ���ͼ�Ŀɼ����ϵ���ڵ㡣
		void Draw(VisibleSet& visibleSet, const GlobalEffectSmartPointer& globalEffect = GlobalEffectSmartPointer{});

		// ���Ƶ����������ڵ㡣
		void Draw(const VisualSmartPointer& visual);
		void Draw(const VisualSmartPointer& visual, const VisualEffectInstanceSmartPointer& instance);

	public:
		// �ӿڵ�ƽ̨��ز��֡�

		// �Ӿ�״̬����
		void SetAlphaState(const ConstAlphaStateSmartPointer& alphaState);
		void SetCullState(const ConstCullStateSmartPointer& cullState);
		void SetDepthState(const ConstDepthStateSmartPointer& depthState);
		void SetOffsetState(const ConstOffsetStateSmartPointer& offsetState);
		void SetStencilState(const ConstStencilStateSmartPointer& stencilState);
		void SetWireState(const ConstWireStateSmartPointer& wireState);

		// �ӿڹ��� �ӿ���������Ļ����ָ���� ԭ������Ļ�����½ǣ�y��ָ���Ϸ���x��ָ���Ҳࡣ
		void SetViewport(const Viewport& viewport);
		Viewport GetViewport() const;
		void SetDepthRange(const DepthRange& depthRange);
		DepthRange GetDepthRange() const;
		void Resize(int width, int height);

		// ֧�������ɫ����Ⱥ�ģ�建������
		void ClearColorBuffer();
		void ClearDepthBuffer();
		void ClearStencilBuffer();
		void ClearBuffers();
		void ClearColorBuffer(int x, int y, int w, int h);
		void ClearDepthBuffer(int x, int y, int w, int h);
		void ClearStencilBuffer(int x, int y, int w, int h);
		void ClearBuffers(int x, int y, int w, int h);
		void DisplayColorBuffer(); 

		// ֧���ڻ��ƹ������ڲ���ɫͨ����
		void SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha);

		// ֧��PreDraw��PostDraw���塣 ����Renderer����ӿں����ͻ�ͼ���������������PreDraw()��PostDraw()Ϊ�߽�Ĵ�����С�
		// ͨ�ø�ʽΪ
		// if (renderer->PreDraw())
		// {
		//		<���������Ⱦ�����úͻ��Ƶ���>;
		//		renderer->PostDraw();
		//	}
		bool PreDraw();
		void PostDraw();

		// ����2D����������ڵ㣨����2DӦ�ó��� 
		void Draw(const uint8_t* screenBuffer, bool reflectY = false);
		void Draw(const std::vector<ColourUByte>& screenBuffer, bool reflectY = false);
 
		// ����2D�ı�����ڵ㡣
		void Draw(int x, int y, const Colour& color, const std::string& message);

		bool InTexture2DMap(const ConstTexture2DSmartPointer& texture);
		void InsertInTexture2DMap(const ConstTexture2DSmartPointer& texture,const PlatformTexture2DSharedPtr& platformTexture);

		RendererTypes GetRendererType() const;	 

	private:
		IMPL_TYPE_DECLARE(Renderer); 
		int64_t m_RendererID;
	};

	CORE_TOOLS_SHARED_PTR_DECLARE(Renderer);
}

#endif // RENDERING_RENDERERS_RENDERER_H
