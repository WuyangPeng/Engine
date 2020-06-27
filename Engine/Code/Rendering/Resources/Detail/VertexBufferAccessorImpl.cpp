// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/19 15:06)

#include "Rendering/RenderingExport.h"

#include "VertexBufferAccessorImpl.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/Resources/VertexBufferAccessorDataDetail.h"
#include "Rendering/Resources/VertexBufferAccessorArrayDataDetail.h" 
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

Rendering::VertexBufferAccessorImpl
	::VertexBufferAccessorImpl(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer)
	:m_VertexFormat{ vertexformat }, m_VertexBuffer{ vertexbuffer }, m_Stride{ m_VertexFormat->GetStride() },
	 m_Data{ m_VertexBuffer->GetReadOnlyData() }, m_Position{ m_VertexFormat, m_VertexBuffer }, m_Normal{ m_VertexFormat, m_VertexBuffer },
	 m_Tangent{ m_VertexFormat, m_VertexBuffer }, m_Binormal{ m_VertexFormat, m_VertexBuffer }, m_TextureCoord{ m_VertexFormat, m_VertexBuffer },
	 m_Color{ m_VertexFormat, m_VertexBuffer }, m_BlendIndices{ m_VertexFormat, m_VertexBuffer }, m_BlendWeight{ m_VertexFormat, m_VertexBuffer }
{	
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBufferAccessorImpl
	::VertexBufferAccessorImpl(Visual* visual)
	:m_VertexFormat{ visual->GetConstVertexFormat() }, m_VertexBuffer{ visual->GetConstVertexBuffer() }, m_Stride{ m_VertexFormat->GetStride() },
	 m_Data{ m_VertexBuffer->GetReadOnlyData() }, m_Position{ m_VertexFormat, m_VertexBuffer }, m_Normal{ m_VertexFormat, m_VertexBuffer },
	 m_Tangent{ m_VertexFormat, m_VertexBuffer }, m_Binormal{ m_VertexFormat, m_VertexBuffer }, m_TextureCoord{ m_VertexFormat, m_VertexBuffer },
	 m_Color{ m_VertexFormat, m_VertexBuffer }, m_BlendIndices{ m_VertexFormat, m_VertexBuffer }, m_BlendWeight{ m_VertexFormat, m_VertexBuffer }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::VertexBufferAccessorImpl
	::IsValid() const noexcept
{
	if (!(m_VertexFormat.IsNullPtr() || m_VertexBuffer.IsNullPtr()))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT 


void Rendering::VertexBufferAccessorImpl
	::ApplyTo(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	m_VertexFormat = vertexformat;
	m_VertexBuffer = vertexbuffer;

    Initialize();
}

void Rendering::VertexBufferAccessorImpl
	::ApplyTo(Visual* visual)
{
	RENDERING_CLASS_IS_VALID_1;

	m_VertexFormat = visual->GetConstVertexFormat();
	m_VertexBuffer = visual->GetConstVertexBuffer();

    Initialize();
}

// private
void Rendering::VertexBufferAccessorImpl
	::Initialize()
{
	m_Stride = m_VertexFormat->GetStride();
	m_Data = m_VertexBuffer->GetReadOnlyData();		

	m_Position.Init(m_VertexFormat, m_VertexBuffer);
	m_Normal.Init(m_VertexFormat, m_VertexBuffer);
	m_Tangent.Init(m_VertexFormat, m_VertexBuffer);
	m_Binormal.Init(m_VertexFormat, m_VertexBuffer);
	m_TextureCoord.Init(m_VertexFormat, m_VertexBuffer); 
	m_Color.Init(m_VertexFormat, m_VertexBuffer);
	m_BlendIndices.Init(m_VertexFormat, m_VertexBuffer);
	m_BlendWeight.Init(m_VertexFormat, m_VertexBuffer);	 
}

const char* Rendering::VertexBufferAccessorImpl
	::GetData() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Data;
}

int Rendering::VertexBufferAccessorImpl
	::GetNumVertices() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_VertexBuffer->GetNumElements();
}

int Rendering::VertexBufferAccessorImpl
	::GetStride() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Stride;
}

const char* Rendering::VertexBufferAccessorImpl
	::GetPosition(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Position.GetData(m_Stride,index);
}

bool Rendering::VertexBufferAccessorImpl
	::HasPosition() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Position.HasData();
}

int Rendering::VertexBufferAccessorImpl
	::GetPositionChannels() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	
	return m_Position.GetDataChannels();
}

const float* Rendering::VertexBufferAccessorImpl
	::GetPositionTuple(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Position.GetDataTuple(m_Stride, index);
}

const char* Rendering::VertexBufferAccessorImpl
	::GetNormal(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Normal.GetData(m_Stride, index);
}

bool Rendering::VertexBufferAccessorImpl
	::HasNormal() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Normal.HasData();
}

int Rendering::VertexBufferAccessorImpl
	::GetNormalChannels() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	
	return m_Normal.GetDataChannels();
}

const float* Rendering::VertexBufferAccessorImpl
	::GetNormalTuple(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Normal.GetDataTuple(m_Stride, index);
}

const char* Rendering::VertexBufferAccessorImpl
	::GetTangent(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Tangent.GetData(m_Stride, index);
}

bool Rendering::VertexBufferAccessorImpl
	::HasTangent() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Tangent.HasData();
}

int Rendering::VertexBufferAccessorImpl
	::GetTangentChannels() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Tangent.GetDataChannels();
}

const float* Rendering::VertexBufferAccessorImpl
	::GetTangentTuple(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Tangent.GetDataTuple(m_Stride, index);
}

const char* Rendering::VertexBufferAccessorImpl
	::GetBinormal(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Binormal.GetData(m_Stride, index);
}

bool Rendering::VertexBufferAccessorImpl
	::HasBinormal() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Binormal.HasData();
}

int Rendering::VertexBufferAccessorImpl
	::GetBinormalChannels() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Binormal.GetDataChannels();
}

const float* Rendering::VertexBufferAccessorImpl
	::GetBinormalTuple(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Binormal.GetDataTuple(m_Stride, index);
}

const char* Rendering::VertexBufferAccessorImpl
	::GetTextureCoord(int unit, int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_TextureCoord.GetData(m_Stride, unit, index);
}

bool Rendering::VertexBufferAccessorImpl
	::HasTextureCoord(int unit) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_TextureCoord.HasData(unit);
}

int Rendering::VertexBufferAccessorImpl
	::GetTextureCoordChannels(int unit) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_TextureCoord.GetDataChannels(unit);
}

const float* Rendering::VertexBufferAccessorImpl
	::GetTextureCoordTuple(int unit, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_TextureCoord.GetDataTuple(m_Stride, unit, index);
}

const char* Rendering::VertexBufferAccessorImpl
	::GetColor(int unit, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Color.GetData(m_Stride, unit, index);
}

bool Rendering::VertexBufferAccessorImpl
	::HasColor(int unit) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Color.HasData(unit);
}

int Rendering::VertexBufferAccessorImpl
	::GetColorChannels(int unit) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Color.GetDataChannels(unit);
}

const float* Rendering::VertexBufferAccessorImpl
	::GetColorTuple(int unit, int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Color.GetDataTuple(m_Stride, unit, index);
}

const char* Rendering::VertexBufferAccessorImpl
	::GetBlendIndices(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_BlendIndices.GetData(m_Stride, index);
}

bool Rendering::VertexBufferAccessorImpl
	::HasBlendIndices() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_BlendIndices.HasData();
}

const char* Rendering::VertexBufferAccessorImpl
	::GetBlendWeight(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_BlendWeight.GetData(m_Stride, index);
}

bool Rendering::VertexBufferAccessorImpl
	::HasBlendWeight() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_BlendWeight.HasData();
}

int Rendering::VertexBufferAccessorImpl
	::GetNormalExcursion(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto excursion = boost::numeric_cast<int>(m_Normal.GetData(m_Stride, index) - m_Data);

	return excursion;
}

int Rendering::VertexBufferAccessorImpl
	::GetTangentExcursion(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto excursion = boost::numeric_cast<int>(m_Tangent.GetData(m_Stride, index) - m_Data);

	return excursion;
}

int Rendering::VertexBufferAccessorImpl
	::GetBinormalExcursion(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto excursion = boost::numeric_cast<int>(m_Binormal.GetData(m_Stride, index) - m_Data);

	return excursion;
}

int Rendering::VertexBufferAccessorImpl
	::GetTextureCoordExcursion(int unit,int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto excursion = boost::numeric_cast<int>(m_TextureCoord.GetData(m_Stride, unit, index) - m_Data);

	return excursion;
}

int Rendering::VertexBufferAccessorImpl
	::GetPositionExcursion(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto excursion = boost::numeric_cast<int>(m_Position.GetData(m_Stride,index) - m_Data);

	return excursion;
}

