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
 #include "System/Helper/PragmaWarning.h" 
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
		TerrainPage(VertexFormatSharedPtr vformat, int size, unsigned short* heights, const Mathematics::Float2& origin,
				    float minElevation, float maxElevation,float spacing);

		  ~TerrainPage();
		  
		  TerrainPage(const TerrainPage&) = default;
		   TerrainPage& operator=(const TerrainPage&) = default;
			TerrainPage(TerrainPage&&) = default;
		   TerrainPage& operator=(TerrainPage&&) = default;
		   
		// Height field access.
		 int GetSize() const noexcept;
		 const unsigned short* GetHeights() const noexcept;
		 const Mathematics::Float2& GetOrigin() const noexcept;
		 float GetMinElevation() const noexcept;
		 float GetMaxElevation() const noexcept;
		 float GetSpacing() const noexcept;

		// Height field measurements.  If the location is not in the page, the
		// return value is MAX_REAL.
		float GetHeight(float x, float y) const;

	protected:
		// Support for tessellation.
		 float GetX(int x) const;
		 float GetY(int y) const;
		 float GetHeight(int index) const noexcept;

		// Height field parameters.
		int mSize, mSizeM1;
		unsigned short* mHeights;
		Mathematics::Float2 mOrigin;
		float mMinElevation, mMaxElevation, mSpacing;
		float mInvSpacing, mMultiplier;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(TerrainPage);
	CORE_TOOLS_SHARED_PTR_DECLARE( TerrainPage);
	#include STSTEM_WARNING_POP
}

#endif // RENDERING_TERRAIN_TERRAIN_PAGE_H
