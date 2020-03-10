// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:30)

#ifndef RENDERING_SORTING_CRM_CULLER_H
#define RENDERING_SORTING_CRM_CULLER_H

#include "Rendering/RenderingDll.h"
 
#include "Rendering/SceneGraph/Culler.h"

#include <set>

namespace Rendering
{
	class    CRMCuller : public Culler
	{
	public:
		// Construction and destruction.
		CRMCuller(const ConstCameraSmartPointer& camera = ConstCameraSmartPointer());
		virtual ~CRMCuller();

		// Two portals leading into the room can be visible to the camera.  The
		// Culler would store visible objects twice.  CRMCuller maintains a set
		// of unique objects.
		virtual void Insert(const ConstSpatialSmartPointer& visible);

	protected:
		std::set<ConstSpatialSmartPointer> mUnique;
	};
}

#endif // RENDERING_SORTING_CRM_CULLER_H
