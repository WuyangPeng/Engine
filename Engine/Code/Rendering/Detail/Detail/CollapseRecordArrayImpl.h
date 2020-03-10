// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:25)

#ifndef RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_IMPL_H
#define RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Detail/CollapseRecord.h"

#include <vector>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE CollapseRecordArrayImpl
	{
	public:
		using ClassType = CollapseRecordArrayImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;

	public:
		CollapseRecordArrayImpl();
		explicit CollapseRecordArrayImpl(const std::vector<CollapseRecord>& collapseRecord);
		
		CLASS_INVARIANT_DECLARE;

		void Load(BufferSource& source);
		void Save(BufferTarget& target) const;
		int GetStreamingSize() const;
		
		int GetNumRecords () const;
		const std::vector<CollapseRecord> GetRecords() const;
		const CollapseRecord GetRecord(int index) const;

	private:
		std::vector<CollapseRecord> m_CollapseRecord;
	};
}

#endif // RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_IMPL_H
