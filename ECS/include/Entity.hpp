#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "IEntity.hpp"

namespace ecs
{
    using EntityTypeId = TypeId;

    template<typename T>
    class Entity : public IEntity
    {
        public:
            Entity(EntityTypeId entitytypeid) : entitytypeid_(entitytypeid) {}

            inline EntityTypeId GetEntityTypeId() const { return entitytypeid_; }

        private:
            EntityTypeId entitytypeid_;
    };
}

#endif // ENTITY_HPP

