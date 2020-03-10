// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:28)

#ifndef RENDERING_DETAIL_COLLAPSE_RECORD_H
#define RENDERING_DETAIL_COLLAPSE_RECORD_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

RENDERING_EXPORT_SHARED_PTR(CollapseRecordImpl);

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE CollapseRecord
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(CollapseRecord);
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		
	public:		
		explicit CollapseRecord (int vKeep = -1, int vThrow = -1,int numVertices = 0, int numTriangles = 0);

	 CLASS_INVARIANT_DECLARE;

	 void SetIndices(const std::vector<int>& indices);
	 const std::vector<int> GetIndices() const;
	 int GetIndex(int index) const;
	 int GetIndicesSize() const;
	 void ClearIndices();

	 int GetVKeep() const;
	 void SetVKeep(int vKeep);
	 int GetVThrow() const;
	 void SetVThrow(int vThrow);
	 int GetNumVertices() const;
	 void SetNumVertices(int numVertices);
	 int GetNumTriangles() const;
	 void SetNumTriangles(int numTriangles);

	 void Load(BufferSource& source);
	 void Save(BufferTarget& target) const;
	 int GetStreamingSize() const;

	private:
		;
		IMPL_TYPE_DECLARE(CollapseRecord);
	};

	bool RENDERING_DEFAULT_DECLARE operator==(const CollapseRecord& lhs, const CollapseRecord& rhs);
}

#endif // RENDERING_DETAIL_COLLAPSE_RECORD_H
