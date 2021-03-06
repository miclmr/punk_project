#include "astar.h"

namespace Math
{
	Node::Node(const Location* location)
		: m_location(location)
		, m_delete_flag(false)
	{
		location->m_node = this;
		m_cost_from_start = 0;
		m_cost_to_goal = 0;
		m_parent = 0;
	}

	void Node::Init()
	{
		if (m_successor.empty() && !m_location->GetNeighbours().empty())
		{	
			m_cost_from_start = 0;
			m_cost_to_goal = 0;
			m_parent = 0;
		}
	}

	void Node::SetParent(Node* node)
	{
		m_parent = node;
	}

	void Node::Clear()
	{
		if (!m_delete_flag)
		{
			m_delete_flag = true;
			for (NodeList::iterator it = m_successor.begin(); it != m_successor.end(); ++it)
			{
				delete *it;
			}
			m_successor.clear();
		}
	}
}