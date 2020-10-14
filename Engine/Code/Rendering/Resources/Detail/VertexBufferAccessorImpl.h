// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 10:40)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_IMPL_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_IMPL_H 

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Resources/VertexBufferAccessorData.h"
#include "Rendering/Resources/VertexBufferAccessorArrayData.h"

namespace Rendering
{
	class Visual;
	
	class RENDERING_HIDDEN_DECLARE VertexBufferAccessorImpl
	{
	public:
		using ClassType = VertexBufferAccessorImpl;
			
	public:	 
		VertexBufferAccessorImpl(const ConstVertexFormatSharedPtr& vertexformat,const ConstVertexBufferSharedPtr& vertexbuffer);
		explicit VertexBufferAccessorImpl(Visual* visual);

		CLASS_INVARIANT_DECLARE;

		void ApplyTo(const ConstVertexFormatSharedPtr& vertexformat,const ConstVertexBufferSharedPtr& vertexbuffer);
		void ApplyTo(const Visual* visual);
	
		const char* GetData() const noexcept;
		int GetNumVertices () const noexcept;
		int GetStride () const noexcept;		
  
		// 通用访问顶点缓冲区中的数据。
		// The Get*Channels()函数仅用于FLOAT{1,2,3,4}的数据有效，并返回浮点数属性的数目。
		const char* GetPosition(int index) const noexcept;
		bool HasPosition () const noexcept;
		int GetPositionChannels () const noexcept;
		const float* GetPositionTuple(int index) const noexcept;
		int GetPositionExcursion(int index) const;
    
		const char* GetNormal(int index) const noexcept;
		bool HasNormal () const noexcept;
		int GetNormalChannels () const noexcept;
		const float* GetNormalTuple(int index) const noexcept;
		int GetNormalExcursion(int index) const;		
	    
		const char* GetTangent(int index) const noexcept;
		bool HasTangent () const noexcept;
		int GetTangentChannels () const noexcept;
		const float* GetTangentTuple(int index) const noexcept;
		int GetTangentExcursion(int index) const;
    
		const char* GetBinormal(int index) const noexcept;
		bool HasBinormal () const noexcept;
		int GetBinormalChannels () const noexcept;
		const float* GetBinormalTuple(int index) const noexcept;
		int GetBinormalExcursion(int index) const;
		     
		const char* GetTextureCoord(int unit, int index) const;
		bool HasTextureCoord(int unit) const;
		int GetTextureCoordChannels(int unit) const;
		const float* GetTextureCoordTuple(int unit, int index) const;
		int GetTextureCoordExcursion(int unit, int index) const;

		const char* GetColor(int unit, int index) const;
		bool HasColor (int unit) const;
		int GetColorChannels (int unit) const;
		const float* GetColorTuple(int unit, int index) const;
    
		const char* GetBlendIndices(int index) const noexcept;
		bool HasBlendIndices () const noexcept; 
    
		const char* GetBlendWeight(int index) const noexcept;
		bool HasBlendWeight () const noexcept;
		
	private:		
		void Initialize ();

	private:
		ConstVertexFormatSharedPtr m_VertexFormat;
		ConstVertexBufferSharedPtr m_VertexBuffer;
 
		int m_Stride;
		const char* m_Data;
		
		VertexBufferAccessorData<VertexFormatFlags::AttributeUsage::Position> m_Position;
		VertexBufferAccessorData<VertexFormatFlags::AttributeUsage::Normal>  m_Normal;
		VertexBufferAccessorData<VertexFormatFlags::AttributeUsage::Tangent> m_Tangent;
		VertexBufferAccessorData<VertexFormatFlags::AttributeUsage::Binormal> m_Binormal;
		VertexBufferAccessorArrayData<VertexFormatFlags::AttributeUsage::TextureCoord,VertexFormatFlags::MaximumNumber::TextureCoordinateUnits> m_TextureCoord;
		VertexBufferAccessorArrayData<VertexFormatFlags::AttributeUsage::Color,VertexFormatFlags::MaximumNumber::ColorUnits> m_Color;
		VertexBufferAccessorData<VertexFormatFlags::AttributeUsage::BlendIndices> m_BlendIndices;
		VertexBufferAccessorData<VertexFormatFlags::AttributeUsage::BlendWeight> m_BlendWeight; 
	};
}

#endif // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_IMPL_H
