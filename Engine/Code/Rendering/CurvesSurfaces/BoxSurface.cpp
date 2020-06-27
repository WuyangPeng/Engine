// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 16:18)

#include "Rendering/RenderingExport.h"

#include "BoxSurface.h" 
#include "Mathematics/Base/Float2.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineVolumeDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/TypeCasting.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, BoxSurface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BoxSurface);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BoxSurface);


Rendering::BoxSurface
	::BoxSurface(Mathematics::BSplineVolumef* volume, int numUSamples, int numVSamples, int numWSamples, VertexFormatSmartPointer vformat[6])
	: mVolume{ volume }, mNumUSamples{ numUSamples }, mNumVSamples{ numVSamples }, mNumWSamples{ numWSamples }, mDoSort{ false }
{
	int permute[3];
	TrianglesMeshSmartPointer mesh;

	// u faces
	permute[0] = 1;
	permute[1] = 2;
	permute[2] = 0;

	// u = 0
	mesh = CreateFace(mNumWSamples, mNumVSamples, vformat[0], false, 0.0f,permute);
	mesh->SetName("u0");
	AttachChild(mesh);

	// u = 1
	mesh = CreateFace(mNumWSamples, mNumVSamples, vformat[1], true, 1.0f,permute);
	mesh->SetName("u1");
	AttachChild(mesh);

	// v faces
	permute[0] = 0;
	permute[1] = 2;
	permute[2] = 1;

	// v = 0
	mesh = CreateFace(mNumWSamples, mNumUSamples, vformat[2], true, 0.0f,permute);
	mesh->SetName("v0");
	AttachChild(mesh);

	// v = 1
	mesh = CreateFace(mNumWSamples, mNumUSamples, vformat[3], false, 1.0f,permute);
	mesh->SetName("v1");
	AttachChild(mesh);

	// w faces
	permute[0] = 0;
	permute[1] = 1;
	permute[2] = 2;

	// w = 0
	mesh = CreateFace(mNumVSamples, mNumUSamples, vformat[4], false, 0.0f,permute);
	mesh->SetName("w0");
	AttachChild(mesh);

	// w = 1
	mesh = CreateFace(mNumVSamples, mNumUSamples, vformat[5], true, 1.0f,permute);
	mesh->SetName("w1");
	AttachChild(mesh);
}

Rendering::BoxSurface
	::~BoxSurface()
{
	DELETE0(mVolume);
}

Rendering::TrianglesMeshSmartPointer Rendering::BoxSurface
	::CreateFace(int numRows, int numCols, VertexFormatSmartPointer vformat, bool ccw, float faceValue, int permute[3])
{
	auto numVertices = numRows * numCols;
	auto vstride = vformat->GetStride();
	VertexBufferSmartPointer vbuffer{ NEW0 VertexBuffer(numVertices, vstride) };
	VertexBufferAccessor vba{ vformat, vbuffer };

	float param[3];
	param[permute[2]] = faceValue;
	auto sign = (ccw ? 1.0f : -1.0f);
	auto rowFactor = 1.0f / (float)(numRows - 1);
	auto colFactor = 1.0f / (float)(numCols - 1);
	int row, col, i;
	for (row = 0, i = 0; row < numRows; ++row)
	{
		param[permute[1]] = row * rowFactor;
		for (col = 0; col < numCols; ++col, ++i)
		{
			param[permute[0]] = col * colFactor;
			vbuffer->SetPosition(vba, i, mVolume->GetPosition(param));

			if (vba.HasNormal())
			{
				auto cDer = mVolume->GetDerivative(permute[0], param);
				auto rDer = mVolume->GetDerivative(permute[1], param);
				vbuffer->SetTriangleNormal(vba, i, sign*Mathematics::Vector3DToolsf::UnitCrossProduct(cDer, rDer));

			}

			const auto numUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);
			for (auto unit = 0; unit < numUnits; ++unit)
			{
				Mathematics::Vector2Df tcoord{ param[permute[0]], param[permute[1]] };
				if (vba.HasTextureCoord(unit))
				{
					RENDERING_ASSERTION_0(vba.GetTextureCoordChannels(unit) == 2, "Texture coordinate must be 2D\n");
					vbuffer->SetTextureCoord(vba, i, tcoord, unit);						 
				}
			}
		}
	}

	auto numTriangles = 2 * (numRows - 1)*(numCols - 1);
	IndexBufferSmartPointer ibuffer{ NEW0 IndexBuffer(3 * numTriangles, sizeof(int)) };

	int* indices = (int*)ibuffer.GetData();
	for (row = 0, i = 0; row < numRows - 1; ++row)
	{
		int i0 = i;
		int i1 = i0 + 1;
		i += numCols;
		int i2 = i;
		int i3 = i2 + 1;
		for (col = 0; col < numCols - 1; ++col, indices += 6)
		{
			if (ccw)
			{
				indices[0] = i0++;
				indices[1] = i1;
				indices[2] = i2;
				indices[3] = i1++;
				indices[4] = i3++;
				indices[5] = i2++;
			}
			else
			{
				indices[0] = i0++;
				indices[1] = i2;
				indices[2] = i1;
				indices[3] = i1++;
				indices[4] = i2++;
				indices[5] = i3++;
			}
		}
	}

	TrianglesMeshSmartPointer mesh{ NEW0 TrianglesMesh(vformat, vbuffer, ibuffer) };
	return mesh;
}

void Rendering::BoxSurface
	::UpdateFace(int numRows, int numCols, VertexFormatSmartPointer vformat, VertexBufferSmartPointer vbuffer, bool ccw, float faceValue, int permute[3])
{
	VertexBufferAccessor vba{ vformat, vbuffer };

	float param[3];
	param[permute[2]] = faceValue;
	auto sign = (ccw ? 1.0f : -1.0f);
	auto rowFactor = 1.0f / (float)(numRows - 1);
	auto colFactor = 1.0f / (float)(numCols - 1);
	for (auto row = 0, i = 0; row < numRows; ++row)
	{
		param[permute[1]] = row * rowFactor;
		for (auto col = 0; col < numCols; ++col, ++i)
		{
			param[permute[0]] = col * colFactor;

			vbuffer->SetPosition(vba, i, mVolume->GetPosition(param));

			if (vba.HasNormal())
			{
				auto cDer = mVolume->GetDerivative(permute[0], param);
				auto rDer = mVolume->GetDerivative(permute[1], param);

				vbuffer->SetTriangleNormal(vba, i, sign*Mathematics::Vector3DToolsf::UnitCrossProduct(cDer, rDer));

			}
		}
	}
}

void Rendering::BoxSurface
	::UpdateSurface()
{
	int permute[3];
	TrianglesMeshSmartPointer mesh;
	VertexFormatSmartPointer vformat;
	VertexBufferSmartPointer vbuffer;

	// u faces
	permute[0] = 1;
	permute[1] = 2;
	permute[2] = 0;

	// u = 0
	mesh = GetChild(0).PolymorphicCastObjectSmartPointer<TrianglesMeshSmartPointer>();
	vformat = mesh->GetVertexFormat();
	vbuffer = mesh->GetVertexBuffer();
	UpdateFace(mNumWSamples, mNumVSamples, vformat, vbuffer, false, 0.0f, permute);
	mesh->UpdateModelSpace(VisualUpdateType::Normals);

	RENDERER_MANAGE_SINGLETON.UpdateAll(vbuffer.GetData());

	// u = 1
	mesh = GetChild(1).PolymorphicCastObjectSmartPointer<TrianglesMeshSmartPointer>();
	vformat = mesh->GetVertexFormat();
	vbuffer = mesh->GetVertexBuffer();
	UpdateFace(mNumWSamples, mNumVSamples, vformat, vbuffer, true, 1.0f, permute);
	mesh->UpdateModelSpace(VisualUpdateType::Normals);
	RENDERER_MANAGE_SINGLETON.UpdateAll(vbuffer.GetData());

	// v faces
	permute[0] = 0;
	permute[1] = 2;
	permute[2] = 1;

	// v = 0
	mesh = GetChild(2).PolymorphicCastObjectSmartPointer<TrianglesMeshSmartPointer>();
	vformat = mesh->GetVertexFormat();
	vbuffer = mesh->GetVertexBuffer();
	UpdateFace(mNumWSamples, mNumUSamples, vformat, vbuffer, true, 0.0f, permute);
	mesh->UpdateModelSpace(VisualUpdateType::Normals);
	RENDERER_MANAGE_SINGLETON.UpdateAll(vbuffer.GetData());

	// v = 1
	mesh = GetChild(3).PolymorphicCastObjectSmartPointer<TrianglesMeshSmartPointer>();
	vformat = mesh->GetVertexFormat();
	vbuffer = mesh->GetVertexBuffer();
	UpdateFace(mNumWSamples, mNumUSamples, vformat, vbuffer, false, 1.0f, permute);
	mesh->UpdateModelSpace(VisualUpdateType::Normals);
	RENDERER_MANAGE_SINGLETON.UpdateAll(vbuffer.GetData());

	// w faces
	permute[0] = 0;
	permute[1] = 1;
	permute[2] = 2;

	// w = 0
	mesh = GetChild(4).PolymorphicCastObjectSmartPointer<TrianglesMeshSmartPointer>();
	vformat = mesh->GetVertexFormat();
	vbuffer = mesh->GetVertexBuffer();
	UpdateFace(mNumVSamples, mNumUSamples, vformat, vbuffer, false, 0.0f, permute);
	mesh->UpdateModelSpace(VisualUpdateType::Normals);
	RENDERER_MANAGE_SINGLETON.UpdateAll(vbuffer.GetData());

	// w = 1
	mesh = GetChild(5).PolymorphicCastObjectSmartPointer<TrianglesMeshSmartPointer>();
	vformat = mesh->GetVertexFormat();
	vbuffer = mesh->GetVertexBuffer();
	UpdateFace(mNumVSamples, mNumUSamples, vformat, vbuffer, true, 1.0f, permute);
	mesh->UpdateModelSpace(VisualUpdateType::Normals);
	RENDERER_MANAGE_SINGLETON.UpdateAll(vbuffer.GetData());
}

void Rendering::BoxSurface
	::EnableSorting()
{
	for (auto face = 0; face < 6; face++)
	{
		auto mesh = GetChild(face).PolymorphicCastObjectSmartPointer<TrianglesMeshSmartPointer>();

		auto effect = mesh->GetConstEffectInstance();
		const auto numPasses = effect->GetNumPasses();
		for (auto p = 0; p < numPasses; ++p)
		{
			const auto pass = effect->GetConstPass(p);
			CullState*  cstate = const_cast<CullState*>( pass->GetCullState().GetData());
			cstate->SetEnabled ( false);
			DepthState* dstate = const_cast<DepthState*>(pass->GetDepthState().GetData());
			dstate->SetEnabled ( false);
			dstate->SetWritable ( true);
			dstate->SetCompare(DepthStateFlags::CompareMode::LessEqual);
			 
		}
	}

	mDoSort = true;
}

void Rendering::BoxSurface
	::DisableSorting()
{
	for (auto face = 0; face < 6; face++)
	{
		auto mesh = GetChild(face).PolymorphicCastObjectSmartPointer<TrianglesMeshSmartPointer>();
		auto effect = mesh->GetConstEffectInstance();
		const auto numPasses = effect->GetNumPasses();
		for (auto p = 0; p < numPasses; ++p)
		{
			const auto pass = effect->GetConstPass(p);

			CullState*  cstate = const_cast<CullState*>(pass->GetCullState().GetData());
			cstate->SetEnabled(false);
			DepthState* dstate = const_cast<DepthState*>(pass->GetDepthState().GetData());
			dstate->SetEnabled(false);
			dstate->SetWritable(true);
			dstate->SetCompare(DepthStateFlags::CompareMode::LessEqual);
		}
	}

	mDoSort = false;
}

void Rendering::BoxSurface
	::SortFaces(const AVector& worldViewDirection)
{
	if (!mDoSort)
	{
		// Sorting must be enabled in order to sort.
		return;
	}

	// Inverse transform the world view direction into the local space of
	// the box.
	auto localDir = GetWorldTransform().GetInverseMatrix()*worldViewDirection;

	// Store back-facing faces in the front of the array.  Store front-facing
	// faces in the rear of the array.
	SpatialSmartPointer sorted[6];
	int backFace = 0, frontFace = 5;
 
	for (auto i = 0; i < 6; ++i)
	{
		const auto& name = GetChild(i)->GetName();
		if (name[0] == 'u')
		{
			if (name[1] == '0')
			{
				if (localDir[0] > 0.0f)
				{
					sorted[frontFace--] = GetChild(i);
				}
				else
				{
					sorted[backFace++] = GetChild(i);
				}
			}
			else  // name[1] == '1'
			{
				if (localDir[0] < 0.0f)
				{
					sorted[frontFace--] = GetChild(i);
				}
				else
				{
					sorted[backFace++] = GetChild(i);
				}
			}
		}
		else if (name[0] == 'v')
		{
			if (name[1] == '0')
			{
				if (localDir[1] > 0.0f)
				{
					sorted[frontFace--] = GetChild(i);
				}
				else
				{
					sorted[backFace++] = GetChild(i);
				}
			}
			else  // name[1] == '1'
			{
				if (localDir[1] < 0.0f)
				{
					sorted[frontFace--] = GetChild(i);
				}
				else
				{
					sorted[backFace++] = GetChild(i);
				}
			}
		}
		else // name[0] == 'w'
		{
			if (name[1] == '0')
			{
				if (localDir[2] > 0.0f)
				{
					sorted[frontFace--] = GetChild(i);
				}
				else
				{
					sorted[backFace++] = GetChild(i);
				}
			}
			else  // name[1] == '1'
			{
				if (localDir[2] < 0.0f)
				{
					sorted[frontFace--] = GetChild(i);
				}
				else
				{
					sorted[backFace++] = GetChild(i);
				}
			}
		}
		DetachChildAt(i);
	}
	RENDERING_ASSERTION_0(backFace - frontFace == 1, "Unexpected condition\n");

	// Reassign the sorted children to the node parent.
	for (auto i = 0; i < 6; ++i)
	{
		// SetChild(i, sorted[i]);
	}
}



// Streaming support.

Rendering::BoxSurface
	::BoxSurface(LoadConstructor value)
	:Node(value),mVolume(0),mNumUSamples(0),mNumVSamples(0),mNumWSamples(0),mDoSort(false)
{
}

void Rendering::BoxSurface
	::Load(CoreTools::BufferSource& source)
{
	CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);

	int numUCtrlPoints, numVCtrlPoints, numWCtrlPoints;
	int uDegree, vDegree, wDegree;
	source.Read(numUCtrlPoints);
	source.Read(numVCtrlPoints);
	source.Read(numWCtrlPoints);
	source.Read(uDegree);
	source.Read(vDegree);
	source.Read(wDegree);
	mVolume = NEW0 Mathematics::BSplineVolumef(numUCtrlPoints, numVCtrlPoints, numWCtrlPoints, uDegree, vDegree, wDegree);
	for (int u = 0; u < numUCtrlPoints; ++u)
	{
		for (int v = 0; v < numVCtrlPoints; ++v)
		{
			for (int w = 0; w < numWCtrlPoints; ++w)
			{
				Mathematics::Vector3Df ctrl;
				source.ReadAggregate(ctrl);
				mVolume->SetControlPoint(u, v, w, ctrl);
			}
		}
	}

	source.Read(mNumUSamples);
	source.Read(mNumVSamples);
	source.Read(mNumWSamples);
	mDoSort = source.ReadBool();

	CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::BoxSurface
	::Link(CoreTools::ObjectLink& source)
{
	Node::Link(source);
}

void Rendering::BoxSurface::PostLink()
{
	Node::PostLink();
}

uint64_t Rendering::BoxSurface
	::Register(CoreTools::ObjectRegister& target) const
{
	return Node::Register(target);
}

void Rendering::BoxSurface
	::Save(CoreTools::BufferTarget& target) const
{
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);

	int numUCtrlPoints = mVolume->GetNumCtrlPoints(0);
	int numVCtrlPoints = mVolume->GetNumCtrlPoints(1);
	int numWCtrlPoints = mVolume->GetNumCtrlPoints(2);
	int uDegree = mVolume->GetDegree(0);
	int vDegree = mVolume->GetDegree(1);
	int wDegree = mVolume->GetDegree(2);
	target.Write(numUCtrlPoints);
	target.Write(numVCtrlPoints);
	target.Write(numWCtrlPoints);
	target.Write(uDegree);
	target.Write(vDegree);
	target.Write(wDegree);
	for (int u = 0; u < numUCtrlPoints; ++u)
	{
		for (int v = 0; v < numVCtrlPoints; ++v)
		{
			for (int w = 0; w < numWCtrlPoints; ++w)
			{
				Mathematics::Vector3Df ctrl = mVolume->GetControlPoint(u, v, w);
				target.WriteAggregate(ctrl);
			}
		}
	}

	target.Write(mNumUSamples);
	target.Write(mNumVSamples);
	target.Write(mNumWSamples);
	target.WriteBool(mDoSort);

	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::BoxSurface
	::GetStreamingSize() const
{
	int size = Node::GetStreamingSize();

	int numUCtrlPoints = mVolume->GetNumCtrlPoints(0);
	int numVCtrlPoints = mVolume->GetNumCtrlPoints(1);
	int numWCtrlPoints = mVolume->GetNumCtrlPoints(2);
	size += sizeof(numUCtrlPoints);
	size += sizeof(numVCtrlPoints);
	size += sizeof(numWCtrlPoints);
	size += sizeof(int);  // uDegree
	size += sizeof(int);  // vDegree
	size += sizeof(int);  // wDegree
	size += numUCtrlPoints * numVCtrlPoints*numWCtrlPoints * sizeof(Mathematics::Vector3Df);

	size += sizeof(mNumUSamples);
	size += sizeof(mNumVSamples);
	size += sizeof(mNumWSamples);
	size += CORE_TOOLS_STREAM_SIZE(mDoSort);

	return size;
}


const Mathematics::BSplineVolumef* Rendering::BoxSurface
	::GetVolume() const
{
	return mVolume;
}

int Rendering::BoxSurface
	::GetNumUSamples() const
{
	return mNumUSamples;
}

int Rendering::BoxSurface
	::GetNumVSamples() const
{
	return mNumVSamples;
}

int Rendering::BoxSurface
	::GetNumWSamples() const
{
	return mNumWSamples;
}

