// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 16:09)

#include "Rendering/RenderingExport.h"

#include "Detail/VertexBufferAccessorImpl.h"
#include "VertexBufferAccessorDetail.h"
#include "Rendering/SceneGraph/Visual.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering, VertexBufferAccessor)

Rendering::VertexBufferAccessor
	::VertexBufferAccessor(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer)
	:m_Impl{ make_shared<ImplType>(vertexformat, vertexbuffer) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBufferAccessor
	::VertexBufferAccessor(Visual* visual) 
	:m_Impl{ make_shared<ImplType>(visual) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,VertexBufferAccessor)

void Rendering::VertexBufferAccessor
	::ApplyTo(const ConstVertexFormatSmartPointer& vertexformat, const ConstVertexBufferSmartPointer& vertexbuffer) 
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ApplyTo(vertexformat, vertexbuffer);
}

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor,ApplyTo,Visual*,void)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexBufferAccessor,GetData,const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexBufferAccessor,GetNumVertices,int) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexBufferAccessor,GetStride,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor,GetPosition,int,const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexBufferAccessor,HasPosition,bool)	

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VertexBufferAccessor,GetPositionChannels, int)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor, GetPositionTuple,int,const float*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor,GetNormal,int,const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexBufferAccessor, HasNormal,bool)	

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VertexBufferAccessor,GetNormalChannels, int)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor,GetNormalTuple,int,const float*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor,GetNormalExcursion, int, int)									 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor, GetTangent,int,const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexBufferAccessor,HasTangent,bool)	

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VertexBufferAccessor,GetTangentChannels, int)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor,GetTangentTuple,int,const float*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor,GetBinormal,int,const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexBufferAccessor,HasBinormal,bool)	

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VertexBufferAccessor,GetBinormalChannels, int)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor,GetBinormalTuple,int,const float*)

const char* Rendering::VertexBufferAccessor
	::GetTextureCoord(int unit, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetTextureCoord(unit, index);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor, HasTextureCoord,int,bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor,GetTextureCoordChannels, int, int)

									  
const float* Rendering::VertexBufferAccessor
	::GetTextureCoordTuple(int unit, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetTextureCoordTuple(unit, index);
}

const char* Rendering::VertexBufferAccessor
	::GetColor(int unit, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetColor(unit, index);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor, HasColor,int,bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor,GetColorChannels, int, int)
									  
const float* Rendering::VertexBufferAccessor
	::GetColorTuple(int unit, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetColorTuple(unit, index);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor,GetBlendIndices,int,const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexBufferAccessor,HasBlendIndices,bool)	

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexBufferAccessor,GetBlendWeight, int, const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexBufferAccessor,HasBlendWeight, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor,GetBinormalExcursion, int, int)									  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor,GetTangentExcursion, int, int)	
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor,GetPositionExcursion, int, int)									  
 
template <>
Mathematics::APointf Rendering::VertexBufferAccessor
	::GetPosition(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto firstPosition = *(reinterpret_cast<const float*>(GetPosition(index)));
	auto secondPosition = *(reinterpret_cast<const float*>(GetPosition(index) + sizeof(float)));
	auto thirdPosition = *(reinterpret_cast<const float*>(GetPosition(index) + sizeof(float) * 2));

	Mathematics::APointf position{ firstPosition, secondPosition, thirdPosition };

	return position;
}

template <>
Mathematics::AVectorf Rendering::VertexBufferAccessor
	::GetNormal(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto firstNormal = *(reinterpret_cast<const float*>(GetNormal(index)));
	auto secondNormal = *(reinterpret_cast<const float*>(GetNormal(index) + sizeof(float)));
	auto thirdNormal = *(reinterpret_cast<const float*>(GetNormal(index) + sizeof(float)* 2));

	Mathematics::AVectorf normal{ firstNormal, secondNormal, thirdNormal };

	return normal;
}

template <>
Mathematics::AVectorf Rendering::VertexBufferAccessor
	::GetTangent(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto firstTangent = *(reinterpret_cast<const float*>(GetTangent(index)));
	auto secondTangent = *(reinterpret_cast<const float*>(GetTangent(index) + sizeof(float)));
	auto thirdTangent = *(reinterpret_cast<const float*>(GetTangent(index) + sizeof(float)* 2));

	Mathematics::AVectorf tangent{ firstTangent, secondTangent, thirdTangent };

	return tangent;
}

template <>
Mathematics::AVectorf Rendering::VertexBufferAccessor
	::GetBinormal(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto firstBinormal = *(reinterpret_cast<const float*>(GetBinormal(index)));
	auto secondBinormal = *(reinterpret_cast<const float*>(GetBinormal(index) + sizeof(float)));
	auto thirdBinormal = *(reinterpret_cast<const float*>(GetBinormal(index) + sizeof(float)* 2));

	Mathematics::AVectorf binormal{ firstBinormal, secondBinormal, thirdBinormal };

	return binormal;
}

template <>
Mathematics::Vector2Df Rendering::VertexBufferAccessor
	::GetTextureCoord(int unit, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto firstTextureCoord = *(reinterpret_cast<const float*>(GetTextureCoord(unit, index)));
	auto secondTextureCoord = *(reinterpret_cast<const float*>(GetTextureCoord(unit, index) + sizeof(float)));
	 
	Mathematics::Vector2Df textureCoord{ firstTextureCoord, secondTextureCoord };

	return textureCoord; 
}

int Rendering::VertexBufferAccessor
	::GetTextureCoordExcursion(int unit, int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetTextureCoordExcursion(unit, index);
}
