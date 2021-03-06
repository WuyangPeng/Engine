// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 10:17)

#include "Rendering/RenderingExport.h" 

#include "PlatformVertexBuffer.h"
#include "Renderer.h"
#include "Detail/PlatformVertexBufferImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PlatformVertexBuffer
	::PlatformVertexBuffer(Renderer* renderer, const VertexBuffer* vertexBuffer)
	:m_Impl{ ImplType::Create(renderer,vertexBuffer) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PlatformVertexBuffer
	::~PlatformVertexBuffer()
{
	RENDERING_SELF_CLASS_IS_VALID_1;	
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,PlatformVertexBuffer)

void Rendering::PlatformVertexBuffer
	::Enable( Renderer* renderer, unsigned int vertexSize,unsigned int streamIndex, unsigned int offset )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Enable(renderer,vertexSize,streamIndex,offset);
}

void Rendering::PlatformVertexBuffer
	::Disable( Renderer* renderer, unsigned int streamIndex )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Disable(renderer,streamIndex);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformVertexBuffer,Lock,BufferLocking,void*)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PlatformVertexBuffer,Unlock,void)	