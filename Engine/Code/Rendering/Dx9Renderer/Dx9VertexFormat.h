// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 11:40)

#ifndef RENDERING_RENDERERS_DX9_VERTEX_FORMAT_H
#define RENDERING_RENDERERS_DX9_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/PlatformVertexFormatImpl.h" 

namespace Rendering
{
	class Renderer;
	class VertexFormat;

	class RENDERING_HIDDEN_DECLARE Dx9VertexFormat : public PlatformVertexFormatImpl
	{
	public:
		using ClassType = Dx9VertexFormat;
		using ParentType = PlatformVertexFormatImpl;	 

	public:
		Dx9VertexFormat(Renderer* renderer,const VertexFormat* vertexFormat);
		virtual ~Dx9VertexFormat();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// 顶点格式操作。
		virtual void Enable(Renderer* renderer) override;
		virtual void Disable(Renderer* renderer) override;
	};
}

#endif // RENDERING_RENDERERS_DX9_VERTEX_FORMAT_H

/*

#include "Wm5Dx9RendererLIB.h"
#include "Wm5VertexFormat.h"

namespace Wm5
{

class Renderer;

class PdrVertexFormat
{
public:
    // Construction and destruction.
    PdrVertexFormat (Renderer* renderer, const VertexFormat* vformat);
    ~PdrVertexFormat ();

    // Vertex format operations.
    void Enable (Renderer* renderer);
    void Disable (Renderer* renderer);

private:
    D3DVERTEXELEMENT9 mElements[VertexFormat::AM_MAX_ATTRIBUTES + 1];
    IDirect3DVertexDeclaration9* mDeclaration;
};

}

#endif
*/