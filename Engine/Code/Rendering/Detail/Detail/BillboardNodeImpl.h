// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:17)

#ifndef RENDERING_DETAIL_BILLBOARD_NODE_IMPL_H
#define RENDERING_DETAIL_BILLBOARD_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Camera.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class ObjectRegister;
	class ObjectLink;
	class Object;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE BillboardNodeImpl
	{
	public:
		using ClassType = BillboardNodeImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using ObjectRegister = CoreTools::ObjectRegister;
		using ObjectLink = CoreTools::ObjectLink;
		using Object = CoreTools::Object;

	public:
		BillboardNodeImpl() noexcept;
		explicit BillboardNodeImpl(const CameraSharedPtr& camera) noexcept;

		CLASS_INVARIANT_DECLARE;

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;
                void Link(const CoreTools::ObjectLinkSharedPtr& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

		CORE_TOOLS_NAMES_IMPL_DECLARE;
	
		void AlignTo(const CameraSharedPtr& camera);

		const ConstCameraSharedPtr GetCamera() const;
 
	private:
		CameraSharedPtr m_Camera;
	};
}

#endif // RENDERING_DETAIL_BILLBOARD_NODE_IMPL_H
