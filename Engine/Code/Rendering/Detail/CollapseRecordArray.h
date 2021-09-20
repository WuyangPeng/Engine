// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:29)

#ifndef RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_H
#define RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "CollapseRecord.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"


#include <vector>
 
EXPORT_SHARED_PTR(Rendering, CollapseRecordArrayImpl, RENDERING_DEFAULT_DECLARE);
namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE CollapseRecordArray : public CoreTools::Object
	{
	public:
            void Swap(CollapseRecordArray& rhs) noexcept;

        public:
            TYPE_DECLARE(CollapseRecordArray);
            using ClassShareType = CoreTools::CopyUnsharedClasses;
            ~CollapseRecordArray() noexcept = default;
            CollapseRecordArray(const CollapseRecordArray& rhs);
            CollapseRecordArray& operator=(const CollapseRecordArray& rhs);
            CollapseRecordArray(CollapseRecordArray&& rhs) noexcept;
            CollapseRecordArray& operator=(CollapseRecordArray&& rhs) noexcept;
		using ParentType = Object;

	public:		
		explicit CollapseRecordArray(const std::vector<CollapseRecord>& collapseRecord);
 
		 
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CollapseRecordArray); 

		int GetNumRecords() const;
		const std::vector<CollapseRecord> GetRecords() const;
		const CollapseRecord GetRecord(int index) const;
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(CollapseRecordArray);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( CollapseRecordArray);
}

#endif // RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_H
