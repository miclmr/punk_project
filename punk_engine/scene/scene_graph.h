#ifndef _H_PUNK_SCENE_GRAPH
#define _H_PUNK_SCENE_GRAPH

#include "config.h"
#include "../system/system.h"
#include "../system/string.h"
#include <vector>
#include <set>

namespace Scene
{
	/*! This class is supposed to contain the whole whole world. But instead of holding 
		object instances themselves it contains only their handlers. While in game process
		supposed to be happaned different events. To keep this graph up-to-date objects
		must inform it by sending events of special type. Through the build in mechanism of sending
		and subscribing events this event will be delivered to scene graph if it was subscribed.
		Than for response it will change himself.
		This structure can be used for searching of objects in the world. Requesting list of all objects
		in some region. To render scene. And some other staff maybe.
	*/
	class  LIB_SCENE SceneGraph
	{
	public:
		typedef std::vector<System::Descriptor> Collection;
		typedef std::map<System::Descriptor, Collection> Hierarchy;		
		typedef std::map<System::Descriptor, System::Descriptor> Child_Parent;
	private:
		System::Descriptor m_parent;					// parent region. it can be anything that can contain anything
		Hierarchy m_scene;		// children. It can be another scene graph or a simple object
		Child_Parent m_hash;

		template<class T>
		void internal_visit(System::Descriptor& parent, T visitor)
		{							
			Collection& col = m_scene.at(parent);
			for (Collection::iterator i = col.begin(); i != col.end(); ++i)
			{				
				visitor(*i);
				
				Hierarchy::iterator col_iter = m_scene.lower_bound(*i);
				if (col_iter != m_scene.end())	
					internal_visit(*i, visitor);
			}
		}

	public:

		SceneGraph();
		~SceneGraph();

		template<class T>
		void Visit(T visitor)
		{
			System::Descriptor desc = System::Descriptor::Null();
			internal_visit<T>(desc, visitor);
		}

		void AddInstance(System::Descriptor parent, System::Descriptor instance);

		void OnInstanceChangedParent(System::Event* event);
		void OnNewInstanceAppeared(System::Event* event);
		void OnInstanceDestroyed(System::Event* event);
	};
}

#endif