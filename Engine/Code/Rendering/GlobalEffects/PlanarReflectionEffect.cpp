// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/25 15:30)

#include "Rendering/RenderingExport.h"

#include "PlanarReflectionEffect.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/SceneGraph/VisibleSet.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, PlanarReflectionEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, PlanarReflectionEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, PlanarReflectionEffect);

Rendering::PlanarReflectionEffect
	::PlanarReflectionEffect(int numPlanes)
	:mNumPlanes{ numPlanes }, mAlphaState{ NEW0 AlphaState() }, mDepthState{ NEW0 DepthState() }, mStencilState{ NEW0 StencilState() }
{
	mPlanes = NEW1<TrianglesMeshSmartPointer>(mNumPlanes);
    mReflectances = NEW1<float>(mNumPlanes);  
}

Rendering::PlanarReflectionEffect
	::~PlanarReflectionEffect()
{
    DELETE1(mPlanes);
    DELETE1(mReflectances);
}

void Rendering::PlanarReflectionEffect
	::Draw(Renderer* renderer,   const VisibleSet& visibleSet)
{
    // Save the current global state overrides for restoration later.
    const auto saveDState = renderer->GetOverrideDepthState();
	const auto saveSState = renderer->GetOverrideStencilState();

    // Override the global state to support this effect.
    renderer->SetOverrideDepthState(mDepthState);
    renderer->SetOverrideStencilState(mStencilState);

    // The depth range will be modified during drawing, so save the current
    // depth range for restoration later.
    float minDepth, maxDepth;
    renderer->GetDepthRange(minDepth, maxDepth);

    // Get the camera to store post-world transformations.
    ConstCameraSmartPointer camera = renderer->GetCamera();

    const auto numVisible = visibleSet.GetNumVisible();
    int i, j;
    for (i = 0; i < mNumPlanes; ++i)
    {
        // Render the mirror into the stencil plane.  All visible mirror
        // pixels will have the stencil value of the mirror.  Make sure that
        // no pixels are written to the depth buffer or color buffer, but use
        // depth buffer testing so that the stencil will not be written where
        // the plane is behind something already in the depth buffer.
        mStencilState->SetEnabled(true);
		mStencilState->SetCompare(StencilStateFlags::CompareMode::Always);
		mStencilState->SetReference ( boost::numeric_cast<uint32_t>(i + 1));
		mStencilState->SetOnFail(StencilStateFlags::OperationType::Keep);     // irrelevant
		mStencilState->SetOnZFail(StencilStateFlags::OperationType::Keep);    // invisible to 0
		mStencilState->SetOnZPass(StencilStateFlags::OperationType::Replace); // visible to i+1

        // Enable depth reads but disable depth writes.
        mDepthState->SetEnabled ( true);
		mDepthState->SetWritable(false);
		mDepthState->SetCompare(DepthStateFlags::CompareMode::LessEqual);

        // Disable color writes.
        renderer->SetColorMask(false, false, false, false);

        renderer->Draw(mPlanes[i].GetData());

        // Enable color writes.
        renderer->SetColorMask(true, true, true, true);

        // Render the mirror plane again by only processing pixels where the
        // stencil buffer contains the reference value.  This time there are
        // no changes to the stencil buffer and the depth buffer value is
        // reset to the far clipping plane.  This is done by setting the range
        // of depth values in the viewport volume to be [1,1].  Since the
        // mirror plane cannot also be semi-transparent, we do not care what
        // is behind the mirror plane in the depth buffer.  We need to move
        // the depth buffer values back where the mirror plane will be
        // rendered so that when the reflected object is rendered, it can be
        // depth buffered correctly.  Note that the rendering of the reflected
        // object will cause depth value to be written, which will appear to
        // be behind the mirror plane.  Enable writes to the color buffer.
        // Later when we want to render the reflecting plane and have it blend
        // with the background, which should contain the reflected caster, we
        // want to use the same blending function so that the pixels where the
        // reflected object was not rendered will contain the reflecting plane
        // colors.  In that case, the blending result will have the reflecting
        // plane appear to be opaque when in reality it was blended with
        // blending coefficients adding to one.
        mStencilState->SetEnabled ( true);
		mStencilState->SetCompare(StencilStateFlags::CompareMode::Equal);
		mStencilState->SetReference ( (unsigned int)(i + 1));
		mStencilState->SetOnFail(StencilStateFlags::OperationType::Keep);
		mStencilState->SetOnZFail(StencilStateFlags::OperationType::Keep);
		mStencilState->SetOnZPass(StencilStateFlags::OperationType::Keep);

        // Set the depth buffer to "infinity" at those pixels for which the
        // stencil buffer is the reference value i+1.
        renderer->SetDepthRange(1.0f, 1.0f);
        mDepthState->SetEnabled ( true);
		mDepthState->SetWritable ( true);
		mDepthState->SetCompare(DepthStateFlags::CompareMode::Always);

		renderer->Draw(mPlanes[i].GetData());

        // Restore the depth range and depth testing function.
		mDepthState->SetCompare ( DepthStateFlags::CompareMode::LessEqual);
        renderer->SetDepthRange(minDepth, maxDepth);

        // Compute the equation for the mirror plane in model coordinates
        // and get the reflection matrix in world coordinates.
        Mathematics::Matrixf reflection;
		Mathematics::Planef modelPlane;
        GetReflectionMatrixAndModelPlane(i, reflection, modelPlane);

        // TODO:  Add clip plane support to the renderer.
        // Enable a clip plane so that only objects above the mirror plane
        // are reflected.  This occurs before SetTransformation because it
        // needs the current geometric pipeline matrices to compute the clip
        // plane in the correct coordinate system.
        //pkRenderer->EnableUserClipPlane(0,kPlane);

        // This temporarily modifies the world matrix to apply the reflection
        // after the model-to-world transformation.
		// 先通过编译
        //camera->SetPreViewMatrix(reflection);

        // Reverse the cull direction.  Allow for models that are not
        // necessarily set up with front or back face culling.
        renderer->SetReverseCullOrder(true);

        // Render the reflected object.  Only render where the stencil buffer
        // contains the reference value.
        for (j = 0; j < numVisible; ++j)
        {
			renderer->Draw((const Visual*)visibleSet.GetVisible(j).GetData());
        }                       

        renderer->SetReverseCullOrder(false);

		// 先通过编译
       //  camera->SetPreViewMatrix(Mathematics::Matrixf::sm_Identity);
        // TODO:  Add clip plane support to the renderer.
        //pkRenderer->DisableUserClipPlane(0);

        // We are about to render the reflecting plane again.  Reset to the
        // global state for the reflecting plane.  We want to blend the
        // reflecting plane with what is already in the color buffer,
        // particularly either the image of the reflected caster or the
        // reflecting plane.  All we want for the reflecting plane at this
        // stage is to force the alpha channel to always be the reflectance
        // value for the reflecting plane.  Render the reflecting plane
        // wherever the stencil buffer is set to the reference value.  This
        // time clear the stencil buffer reference value where it is set.
        // Perform the normal depth buffer testing and writes.  Allow the
        // color buffer to be written to, but this time blend the reflecting
        // plane with the values in the color buffer based on the reflectance
        // value.  Note that where the stencil buffer is set, the color buffer
        // has either color values from the reflecting plane or the reflected
        // object.  Blending will use src=1-alpha (reflecting plane) and
        // dest=alpha background (reflecting plane or reflected object).
        const auto saveAState = renderer->GetOverrideAlphaState();
        renderer->SetOverrideAlphaState(mAlphaState);
		mAlphaState->SetBlendEnabled(true);
		mAlphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::OneMinusConstantAlpha);
		mAlphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::ConstantAlpha);
		mAlphaState->SetConstantColor(Colour<float>(0.0f, 0.0f, 0.0f, mReflectances[i]));

		mStencilState->SetCompare(StencilStateFlags::CompareMode::Equal);
		mStencilState->SetReference ( (unsigned int)(i + 1));
		mStencilState->SetOnFail(StencilStateFlags::OperationType::Keep);
		mStencilState->SetOnZFail(StencilStateFlags::OperationType::Keep);
		mStencilState->SetOnZPass(StencilStateFlags::OperationType::Invert);

		renderer->Draw(mPlanes[i].GetData());

        renderer->SetOverrideAlphaState(saveAState);
    }

    // Restore the global state that existed before this function call.
    renderer->SetOverrideStencilState(saveSState);
    renderer->SetOverrideDepthState(saveDState);

    // Render the objects as usual, this time drawing only the potentially
    // visible objects.
    for (j = 0; j < numVisible; ++j)
    {
		renderer->Draw((const Visual*)visibleSet.GetVisible(j).GetData());
    }
}

void Rendering::PlanarReflectionEffect
	::GetReflectionMatrixAndModelPlane(int i, Mathematics::Matrixf& reflection, Mathematics::Planef& modelPlane)
{
    // Compute the equation for the mirror plane in world coordinates.
	auto vertex =  mPlanes[i]->GetWorldTriangle(0);
	Mathematics::Planef worldPlane{ vertex.GetFirstPosition(), vertex.GetSecondPosition(), vertex.GetThirdPosition() };

    // Compute the reflection matrix.
	reflection.MakeReflection(Mathematics::APointf(vertex.GetFirstPosition()[0], vertex.GetFirstPosition()[1], vertex.GetFirstPosition()[2]), worldPlane.GetNormal());

	vertex =  mPlanes[i]->GetModelTriangle(0);
	modelPlane = Mathematics::Planef{ vertex.GetFirstPosition(), vertex.GetSecondPosition(), vertex.GetThirdPosition() };
}

// Name support.
const CoreTools::ObjectSmartPointer Rendering::PlanarReflectionEffect::
	GetObjectByName(const std::string& name)
{
	auto found = ParentType::GetObjectByName(name);
	if (found.IsValidPtr())
	{
		return found;
	}

	for (auto i = 0; i < mNumPlanes; ++i)
	{
		auto found2 = mPlanes[i]->GetObjectByName(name);
		if (found2.IsValidPtr())
		{
			return found2;
		}			
	}
	
	return CoreTools::ObjectSmartPointer();
}     

const std::vector<CoreTools::ObjectSmartPointer> Rendering::PlanarReflectionEffect
	::GetAllObjectsByName(const std::string& name)
{
	std::vector<CoreTools::ObjectSmartPointer> objects;
	auto found = ParentType::GetObjectByName(name);
	if (found.IsValidPtr())
	{
		objects.push_back(found);
	}

	for (auto i = 0; i < mNumPlanes; ++i)
	{
		auto pointerObjects = mPlanes[i]->GetAllObjectsByName(name);

		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}

	return objects;	
}   

const CoreTools::ConstObjectSmartPointer Rendering::PlanarReflectionEffect
	::GetConstObjectByName(const std::string& name) const
{	
	auto found = ParentType::GetConstObjectByName(name);
	if (found.IsValidPtr())
	{
		return found;
	}

	for (int i = 0; i < mNumPlanes; ++i)
	{
		auto found2 = mPlanes[i]->GetConstObjectByName(name);
		if (found2.IsValidPtr())
		{
			return found2;
		}			
	}

	return CoreTools::ConstObjectSmartPointer();
} 

const std::vector<CoreTools::ConstObjectSmartPointer> Rendering::PlanarReflectionEffect
	::GetAllConstObjectsByName(const std::string& name) const 
{
	auto objects = ParentType::GetAllConstObjectsByName(name);

	for (auto i = 0; i < mNumPlanes; ++i)
	{
		auto pointerObjects = mPlanes[i]->GetAllObjectsByName(name);

		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}

	return objects;
}


// Streaming support.

Rendering::PlanarReflectionEffect
	::PlanarReflectionEffect(LoadConstructor value)
	:ParentType{ value }, mNumPlanes{ 0 }, mPlanes{ 0 }, mReflectances{ 0 }
{
}

int Rendering::PlanarReflectionEffect
	::GetStreamingSize() const
{
	auto size = ParentType::GetStreamingSize();
	size += CORE_TOOLS_STREAM_SIZE(mNumPlanes);
	size += mNumPlanes * CORE_TOOLS_STREAM_SIZE(mReflectances[0]);
	size += mNumPlanes * RENDERING_STREAM_SIZE(mPlanes[0]);
	return size;	 
}

uint64_t Rendering::PlanarReflectionEffect
	::Register(CoreTools::ObjectRegister& target) const
{
	auto id = ParentType::Register(target);
	if (0 < id)
	{
		target.RegisterSmartPointer(mNumPlanes, mPlanes);
		return id;
	}

	return id;	
}

void Rendering::PlanarReflectionEffect
	::Save(CoreTools::BufferTarget& target) const
{
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	ParentType::Save(target);

	target.WriteWithNumber(mNumPlanes, mReflectances);
	target.WriteSmartPointerWithNumber(mNumPlanes, mPlanes);

	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);	
}

void Rendering::PlanarReflectionEffect
	::Link(CoreTools::ObjectLink& source)
{
	SYSTEM_UNUSED_ARG(source);
}

void Rendering::PlanarReflectionEffect
	::PostLink()
{	
}

void Rendering::PlanarReflectionEffect
	::Load(CoreTools::BufferSource& source)
{

	CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

	GlobalEffect::Load(source);

	source.Read(mNumPlanes, mReflectances);
	source.ReadSmartPointer(mNumPlanes, mPlanes);

	CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

 

int Rendering::PlanarReflectionEffect
	::GetNumPlanes() const
{
	return mNumPlanes;
}

void Rendering::PlanarReflectionEffect
	::SetPlane(int i, TrianglesMeshSmartPointer plane)
{
	// The culling flag is set to "always" because this effect is responsible
	// for drawing the TriMesh.  This prevents drawing attempts by another
	// scene graph for which 'plane' is a leaf node.
	mPlanes[i] = plane;
	mPlanes[i]->SetCullingMode(CullingMode::Always);
}

Rendering::ConstTrianglesMeshSmartPointer Rendering::PlanarReflectionEffect
	::GetPlane(int i) const
{
	return mPlanes[i];
}

void Rendering::PlanarReflectionEffect
	::SetReflectance(int i, float reflectance)
{
	mReflectances[i] = reflectance;
}

float Rendering::PlanarReflectionEffect
	::GetReflectance(int i) const
{
	return mReflectances[i];
}
