// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 11:32)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_H

#include "Rendering/RenderingDll.h" 

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

RENDERING_EXPORT_SHARED_PTR(PickRecordContainerImpl);

namespace Rendering
{
	class PickRecord;

	class RENDERING_DEFAULT_DECLARE PickRecordContainer
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(PickRecordContainer);

	public:	
		PickRecordContainer();

		CLASS_INVARIANT_DECLARE;

		void InsertPickRecord(const PickRecord& pickRecord);
		void InsertPickRecord(const PickRecordContainer& pickRecordContainerImpl);

		int GetSize() const;
		const PickRecord GetPickRecord(int index) const;
		bool IsEmpty() const noexcept;

	private:
		IMPL_TYPE_DECLARE(PickRecordContainer);
	};
}

#endif // RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_H
