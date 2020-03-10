// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:17)

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
		BillboardNodeImpl();
		explicit BillboardNodeImpl(const CameraSmartPointer& camera);

		CLASS_INVARIANT_DECLARE;

		void Load(BufferSource& source);
		void Save(BufferTarget& target) const;
		int GetStreamingSize() const;
		void Link(ObjectLink& source);
		void Register(ObjectRegister& target) const;

		CORE_TOOLS_NAMES_IMPL_DECLARE;
	
		void AlignTo(const CameraSmartPointer& camera);

		const ConstCameraSmartPointer GetCamera() const;
 
	private:
		CameraSmartPointer m_Camera;
	};
}

#endif // RENDERING_DETAIL_BILLBOARD_NODE_IMPL_H
