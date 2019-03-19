#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "IComponent.hpp"
#include "Event/ISubject.hpp"

namespace ecs
{
    using ComponentTypeId = TypeId;

    template<typename T>
    class Component : public IComponent
    {
        public:
            Component(ComponentTypeId componenttypeid) : componenttypeid_(componenttypeid) {}

            inline ComponentTypeId GetComponentTypeId() const { return componenttypeid_; }

        private:
            const ComponentTypeId componenttypeid_;
    };
}

#endif // COMPONENT_HPP

