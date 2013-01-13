#ifndef _H_PUNK_RENDER_SIMPLE_RENDER
#define _H_PUNK_RENDER_SIMPLE_RENDER

#include "../config.h"
#include "../system/smart_pointers/proxy.h"
#include "../scene/scene_graph.h"

namespace OpenGL { class Frame; }
namespace OpenGL { class RenderTarget; }
namespace Virtual { class World; }
namespace Virtual { namespace Cameras { class Camera; } }
namespace Scene { class Node; }

namespace Render
{
	class PUNK_ENGINE SimpleRender
	{
		Virtual::Camera* m_active_camera;		
		OpenGL::RenderTarget* m_target;
	public:
		SimpleRender(System::Proxy<Scene::SceneGraph> scene);

		bool Render(const Virtual::World& world, OpenGL::Frame& frame);

		void SetActiveCamera(Virtual::Camera* value) { m_active_camera = value; }
		Virtual::Camera* GetActiveCamera() { return m_active_camera; }
		const Virtual::Camera* GetActiveCamera() const { return m_active_camera; }

		void SetRenderTarget(OpenGL::RenderTarget* value) { m_target = value; }
		OpenGL::RenderTarget* GetRenderTarget() { return m_target; }
		const OpenGL::RenderTarget* GetRenderTarget() const { return m_target; }

	private:
	};
}

#endif	//	_H_PUNK_RENDER_SIMPLE_RENDER