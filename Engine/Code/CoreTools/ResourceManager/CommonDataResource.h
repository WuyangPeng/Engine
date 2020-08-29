// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 13:06)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_COMMON_DATA_RESOURCE_H
#define CORE_TOOLS_RESOURCE_MANAGER_COMMON_DATA_RESOURCE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "BaseResource.h"

CORE_TOOLS_EXPORT_SHARED_PTR(CommonDataResourceImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CommonDataResource : public BaseResource
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(CommonDataResource);
		using ParentType = BaseResource;

	public:
		CommonDataResource(PriorityType priority, uint32_t size);
		~CommonDataResource() = default;
		CommonDataResource(CommonDataResource&&) noexcept = default;
		CommonDataResource& operator=(CommonDataResource&&) noexcept = default;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		uint32_t GetSize() const noexcept override;
		bool IsDisposed() const noexcept override;

		void Recreate() override;
		void Dispose() noexcept override;

		void SetData(int index, uint8_t value) override;
		uint8_t GetData(int index) const override;

	private:
		IMPL_TYPE_DECLARE(CommonDataResource);
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_COMMON_DATA_RESOURCE_H