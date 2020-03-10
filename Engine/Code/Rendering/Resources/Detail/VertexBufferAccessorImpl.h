// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 10:40)

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
		VertexBufferAccessorImpl(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer);
		explicit VertexBufferAccessorImpl(Visual* visual);

		CLASS_INVARIANT_DECLARE;

		void ApplyTo(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer);
		void ApplyTo(Visual* visual);
	
		const char* GetData() const;
		int GetNumVertices () const;
		int GetStride () const;		
  
		// ͨ�÷��ʶ��㻺�����е����ݡ�
		// The Get*Channels()����������FLOAT{1,2,3,4}��������Ч�������ظ��������Ե���Ŀ��
		const char* GetPosition(int index) const;
		bool HasPosition () const;
		int GetPositionChannels () const;
		const float* GetPositionTuple(int index) const;
		int GetPositionExcursion(int index) const;
    
		const char* GetNormal(int index) const;
		bool HasNormal () const;
		int GetNormalChannels () const;
		const float* GetNormalTuple(int index) const;
		int GetNormalExcursion(int index) const;		
	    
		const char* GetTangent(int index) const;
		bool HasTangent () const;
		int GetTangentChannels () const;
		const float* GetTangentTuple(int index) const;
		int GetTangentExcursion(int index) const;
    
		const char* GetBinormal(int index) const;
		bool HasBinormal () const;
		int GetBinormalChannels () const;
		const float* GetBinormalTuple(int index) const;
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
    
		const char* GetBlendIndices(int index) const;
		bool HasBlendIndices () const;
    
		const char* GetBlendWeight(int index) const;
		bool HasBlendWeight () const;
		
	private:		
		void Initialize ();

	private:
		ConstVertexFormatSmartPointer m_VertexFormat;
		ConstVertexBufferSmartPointer m_VertexBuffer;
 
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
