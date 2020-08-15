// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:45)

#ifndef RENDERING_TERRAIN_TERRAIN_BASE_H
#define RENDERING_TERRAIN_TERRAIN_BASE_H

#include "Rendering/RenderingDll.h"

#include "TerrainPage.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/Camera.h"
#include "System/Helper/UnicodeUsing.h"

namespace Rendering
{
	class   TerrainBase : public Node
	{
	public:
		using ClassType = TerrainBase;
		using ParentType = Node;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TerrainBase);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

	public:
		// Construction and destruction.
		TerrainBase(const System::String& heightName, VertexFormatSmartPointer vformat, CameraSmartPointer camera );

		  ~TerrainBase();
		  
		  TerrainBase(const TerrainBase&) = default;
		   TerrainBase& operator=(const TerrainBase&) = default;
			TerrainBase(TerrainBase&&) = default;
		   TerrainBase& operator=(TerrainBase&&) = default;

		// Member access.
		 int GetRowQuantity() const noexcept;
		 int GetColQuantity() const noexcept;
		 int GetSize() const noexcept;
		 float GetMinElevation() const noexcept;
		 float GetMaxElevation() const noexcept;
		 float GetSpacing() const noexcept;

		// Page management.
		 TerrainPageSmartPointer GetPage(int row, int col);
		 TerrainPageSmartPointer GetCurrentPage(float x, float y) const noexcept;
		float GetHeight(float x, float y) const;

		// Estimate a normal vector at (x,y) by using the neighbors (x+dx,y+dy),
		// where (dx,dy) in {(s,0),(-s,0),(0,s),(0,-s)}.  The value s is the
		// spacing (returned by GetSpacing()).
		AVector GetNormal(float x, float y) const;

		// Allow a page to be replaced.  The code unstitches the old page, loads
		// the new page and stitches it, then returns the old page in case the
		// application wants to cache it for quick reuse.
		TerrainPageSmartPointer ReplacePage(int row, int col, const System::String& heightName, const System::String& heightSuffix);

		TerrainPageSmartPointer ReplacePage(int row, int col, TerrainPageSmartPointer newPage);

		// Update of active set of terrain pages.
		void OnCameraMotion();

	protected:
		void LoadHeader(const System::String& heightName);

		void LoadPage(int row, int col, const System::String& heightName, const System::String& heightSuffix);

		// Read mode for the height header file and the terrain page data.
		int mMode;

		// Shared by the pages.
		VertexFormatSmartPointer mVFormat;

		// Page information.
		int mNumRows, mNumCols;
		int mSize;
		float mMinElevation, mMaxElevation, mSpacing;
		TerrainPageSmartPointer** mPages;

		// Current page containing the camera.
		int mCameraRow, mCameraCol;
		CameraSmartPointer mCamera;
	};
	#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(TerrainBase);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Seventh, TerrainBase);
		#include STSTEM_WARNING_POP
}

#endif // RENDERING_TERRAIN_TERRAIN_BASE_H
