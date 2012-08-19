#include "vs_skinning.h"
#include "../../../../environment.h"

namespace OpenGL
{
	VertexShaderSkinning::VertexShaderSkinning()
		: Shader(SHADER_VERTEX)
	{
		CookFromFile(System::Environment::Instance()->GetShaderFolder() + L"skinning_330.vert");
	}
}