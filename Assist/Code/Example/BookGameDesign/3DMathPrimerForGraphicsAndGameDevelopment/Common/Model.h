/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Games and Graphics Development
//
// Model.h - Model used for rendering
//
// Visit gamemath.com for the latest version of this file.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __MODEL_H_INCLUDED__
#define __MODEL_H_INCLUDED__

namespace ThreeDMathPrimerForGraphicsAndGameDevelopment
{
	// Forward declarations

	class EditTriMesh;
	class TriMesh;
	struct TextureReference;

	/////////////////////////////////////////////////////////////////////////////
	//
	// class Model
	//
	// Renderable model class.  This class constists of a list of "parts."
	// Each part is a triangle mesh and can have its own texture.
	//
	/////////////////////////////////////////////////////////////////////////////

	class Model
	{
	public:
		Model() noexcept;
		~Model() noexcept;

		Model(const Model&) = delete;
		Model& operator=(const Model&) = delete;
		Model(Model&&) noexcept = delete;
		Model& operator=(Model&&) noexcept = delete;

		// Memory allocation

		void allocateMemory(int nPartCount);
		void freeMemory() noexcept;

		// Part accessors

		int	getPartCount() const noexcept
		{
			return partCount;
		}
		TriMesh* getPartMesh(int index) noexcept;

		// Texture accessors

		TextureReference* getPartTexture(int index) noexcept;
		void setPartTextureName(int index, const char* name) noexcept;

		// Cache textures.  For best performance, always cache your textures
		// before rendering

		void cache() const noexcept;

		// Render the entire model, or a single part.  This will use
		// the current 3D context.  The current texture will be changed.

		void render() const noexcept;
		void renderPart(int index) const noexcept;

		// Conversion to/from an "edit" mesh

		void fromEditMesh(EditTriMesh& mesh);
		void toEditMesh(const EditTriMesh& mesh) const noexcept;

		// Shorthand for importing an S3D.  (Uses EditTriMesh)

		void importS3d(const char* s3dFilename);

	protected:

		// Parts and textures

		int partCount;
		TriMesh* partMeshList;
		TextureReference* partTextureList;
	};
}
/////////////////////////////////////////////////////////////////////////////
#endif // #ifndef __MODEL_H_INCLUDED__
