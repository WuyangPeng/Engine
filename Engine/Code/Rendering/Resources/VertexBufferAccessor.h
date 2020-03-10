// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 11:20)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_H

#include "Rendering/RenderingDll.h"

#include "VertexBuffer.h"
#include "VertexFormat.h"

#include <boost/shared_ptr.hpp>

RENDERING_EXPORT_SHARED_PTR(VertexBufferAccessorImpl);

namespace Rendering
{
	class Visual;

	class RENDERING_DEFAULT_DECLARE VertexBufferAccessor
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(VertexBufferAccessor);

	public:	 
		VertexBufferAccessor(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer);
		explicit VertexBufferAccessor(Visual* visual);

		CLASS_INVARIANT_DECLARE;

		void ApplyTo(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer);
		void ApplyTo(Visual* visual);

		const char* GetData() const;
		int GetNumVertices() const;
		int GetStride() const;

		// 通用访问顶点缓冲区中的数据。
		// The Get*Channels()函数仅用于FLOAT{1,2,3,4}的数据有效，并返回浮点数属性的数目。
		template <typename T>
		T GetPosition(int index) const;
		const char* GetPosition(int index) const;
		bool HasPosition() const;
		int GetPositionChannels() const;
		const float* GetPositionTuple(int index) const;
		int GetPositionExcursion(int index) const;

		template <typename T>
		T GetNormal(int index) const;
		const char* GetNormal(int index) const;
		bool HasNormal() const;
		int GetNormalChannels() const;
		const float* GetNormalTuple(int index) const;
		int GetNormalExcursion(int index) const;

		template <typename T>
		T GetTangent(int index) const;
		const char* GetTangent(int index) const;
		bool HasTangent() const;
		int GetTangentChannels() const;
		const float* GetTangentTuple(int index) const;
		int GetTangentExcursion(int index) const;

		template <typename T>
		T GetBinormal(int index) const;
		const char* GetBinormal(int index) const;
		bool HasBinormal() const;
		int GetBinormalChannels() const;
		const float* GetBinormalTuple(int index) const;
		int GetBinormalExcursion(int index) const;

		template <typename T>
		T GetTextureCoord(int unit, int index) const;
		const char* GetTextureCoord(int unit, int index) const;
		bool HasTextureCoord(int unit) const;
		int GetTextureCoordChannels(int unit) const;
		const float* GetTextureCoordTuple(int unit, int index) const;
		int GetTextureCoordExcursion(int unit, int index) const;

		template <typename T>
		T GetColor(int unit, int index) const;
		const char* GetColor(int unit, int index) const;
		bool HasColor(int unit) const;
		int GetColorChannels(int unit) const;
		const float* GetColorTuple(int unit, int index) const;

		template <typename T>
		T GetBlendIndices(int index) const;
		const char* GetBlendIndices(int index) const;
		bool HasBlendIndices() const;

		template <typename T>
		T GetBlendWeight(int index) const;
		const char* GetBlendWeight(int index) const;
		bool HasBlendWeight() const;
   
	private:
		IMPL_TYPE_DECLARE(VertexBufferAccessor);
	};
}

#endif // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_H
