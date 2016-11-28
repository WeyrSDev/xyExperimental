/*********************************************************************
Matt Marchant 2016
http://trederia.blogspot.com

DoodleChum - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#ifndef DC_BUD_CONTROLLER_HPP_
#define DC_BUD_CONTROLLER_HPP_

#include <Task.hpp>

#include <xygine/components/Component.hpp>

#include <list>

class PathFinder;
class BudController final : public xy::Component
{
public:
    BudController(xy::MessageBus&, const PathFinder&, const std::vector<sf::Vector2u>&);
    ~BudController() = default;

    xy::Component::Type type() const override { return xy::Component::Type::Script; }
    void entityUpdate(xy::Entity&, float) override;

private:

    const PathFinder& m_pathFinder;
    const std::vector<sf::Vector2u>& m_wayPoints;

    sf::Vector2u m_currentPosition;
    sf::Vector2u m_destinationPosition;

    std::list<Task::Ptr> m_tasks;
};

#endif //DC_BUD_CONTROLLER_HPP_