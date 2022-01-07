// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:26)

#ifndef RENDERING_DETAIL_COLLAPSE_RECORD_IMPL_H
#define RENDERING_DETAIL_COLLAPSE_RECORD_IMPL_H

#include "Rendering/RenderingDll.h"

#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{	
	class RENDERING_HIDDEN_DECLARE CollapseRecordImpl
	{
	public:
		using ClassType = CollapseRecordImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;

	public:
		explicit CollapseRecordImpl (int vKeep = -1, int vThrow = -1,int numVertices = 0, int numTriangles = 0) noexcept;

		CLASS_INVARIANT_DECLARE;

		void SetIndices(const std::vector<int>& indices);
		const std::vector<int> GetIndices() const;
		int GetIndex(int index) const;
		int GetIndicesSize() const;
		void ClearIndices() noexcept;

		int GetVKeep() const noexcept;
		void SetVKeep(int vKeep) noexcept;
		int GetVThrow() const noexcept;
		void SetVThrow(int vThrow) noexcept;
		int GetNumVertices() const noexcept;
		void SetNumVertices(int numVertices) noexcept;
		int GetNumTriangles() const noexcept;
		void SetNumTriangles(int numTriangles) noexcept;

		void Load(CoreTools::BufferSource& source);
		void Save(CoreTools::BufferTarget& target) const;
		int GetStreamingSize() const;

	private:
		// ��<VKeep��VThrow>�۵�ʹVThrow��VKeepȡ����
		int m_VKeep;	
		int m_VThrow;
		
		// ���۵���Ķ�������
		int m_NumVertices;	

		// ���۵������������
		int m_NumTriangles;	

		// [0..NumTriangles-1]�а���VThrow����������
		std::vector<int> m_Indices;
	};
}

#endif // RENDERING_DETAIL_COLLAPSE_RECORD_IMPL_H
