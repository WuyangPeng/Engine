// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:47)

#ifndef RENDERING_TERRAIN_TERRAIN_PAGE_H
#define RENDERING_TERRAIN_TERRAIN_PAGE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Mathematics/Base/Float2.h"

namespace Rendering
{
	class   TerrainPage : public TrianglesMesh
	{
	public:
		using ClassType = TerrainPage;
		using ParentType = TrianglesMesh;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TerrainPage); 

	public:
		// Construction and destruction.  The following is required:
		// size = 2^p + 1, p <= 7 (size = 3, 5, 9, 17, 33, 65, 129)
		TerrainPage(VertexFormatSmartPointer vformat, int size, unsigned short* heights, const Mathematics::Float2& origin,
				    float minElevation, float maxElevation,float spacing);

		virtual ~TerrainPage();

		// Height field access.
		 int GetSize() const;
		 const unsigned short* GetHeights() const;
		 const Mathematics::Float2& GetOrigin() const;
		 float GetMinElevation() const;
		 float GetMaxElevation() const;
		 float GetSpacing() const;

		// Height field measurements.  If the location is not in the page, the
		// return value is MAX_REAL.
		float GetHeight(float x, float y) const;

	protected:
		// Support for tessellation.
		 float GetX(int x) const;
		 float GetY(int y) const;
		 float GetHeight(int index) const;

		// Height field parameters.
		int mSize, mSizeM1;
		unsigned short* mHeights;
		Mathematics::Float2 mOrigin;
		float mMinElevation, mMaxElevation, mSpacing;
		float mInvSpacing, mMultiplier;
	};
 
	CORE_TOOLS_STREAM_REGISTER(TerrainPage);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Ninth, TerrainPage);
}

#endif // RENDERING_TERRAIN_TERRAIN_PAGE_H
